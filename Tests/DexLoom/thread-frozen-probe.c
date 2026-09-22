/* Local unchanged-APK probe. Not a CI target: the APK is not in the repository. */
#include "game_dex_runner.h"
#include "dx_vm.h"
#include "dx_log.h"
#include <GLES2/gl2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void glGenTextures(GLsizei n, GLuint *textures) {
    for (GLsizei i = 0; i < n; i++) if (textures) textures[i] = 1;
}
void glBindTexture(GLenum target, GLuint texture) { (void)target; (void)texture; }
void glTexParameteri(GLenum target, GLenum pname, GLint param) {
    (void)target; (void)pname; (void)param;
}
void glDeleteTextures(GLsizei n, const GLuint *textures) { (void)n; (void)textures; }

static const char *opcode_name(uint8_t opcode) {
    switch (opcode) {
    case 0x6E: return "invoke-virtual";
    case 0x6F: return "invoke-super";
    case 0x70: return "invoke-direct";
    case 0x71: return "invoke-static";
    case 0x72: return "invoke-interface";
    case 0x74: return "invoke-virtual/range";
    case 0x75: return "invoke-super/range";
    case 0x76: return "invoke-direct/range";
    case 0x77: return "invoke-static/range";
    case 0x78: return "invoke-interface/range";
    default: return "invoke";
    }
}

static void print_arg(int index, int32_t bits, uint8_t tag) {
    float value;
    if (tag == DX_VAL_FLOAT) {
        memcpy(&value, &bits, sizeof(value));
        printf(" arg%d=float:%.9g/%u", index, value, tag);
    } else if (tag == DX_VAL_OBJ) {
        printf(" arg%d=obj:%d/%u", index, bits, tag);
    } else {
        printf(" arg%d=%d/%u", index, bits, tag);
    }
}

static void print_witness(const char *label, const DxInvokeWitness *w) {
    uint8_t i;
    printf("%s exec=%u caller=%s pc=%u opcode=0x%02x %s method_idx=%u "
           "resolved=%u class=%s method=%s shorty=%s argc=%u recv=%llu recv_class=%s",
           label, w->exec_id, w->caller, w->pc, w->opcode, opcode_name(w->opcode),
           w->method_idx, w->resolved, w->target_class, w->target_name, w->shorty, w->argc,
           (unsigned long long)w->recv_obj, w->recv_class);
    for (i = 0; i < w->argc && i < 8; i++) print_arg(i, w->arg_i[i], w->arg_tag[i]);
    printf(" has_ret=%u ret_tag=%u ret=%d\n", w->has_ret, w->ret_tag, w->ret_i);
}

static void print_canvas_trace(const agr_dex_game *game) {
    uint32_t n = agr_dex_game_canvas_trace_count(game);
    uint32_t i;
    printf("canvas_trace_count=%u\n", n);
    for (i = 0; i < n; i++) {
        agr_canvas_trace event;
        if (agr_dex_game_copy_canvas_trace(game, i, &event) != 0) continue;
        printf("CANVAS kind=%s exec=%u caller=%s pc=%u opcode=0x%02x %s method_idx=%u "
               "flag=%d returned=%d save_count=%d "
               "clip_before=%d,%d,%d,%d clip_after=%d,%d,%d,%d "
               "coords=%.9g,%.9g,%.9g,%.9g op=%d null=%d op_obj=%llu class=%s "
               "bool=%d wrote=%d write=%d,%d,%d,%d has_write=%d\n",
               event.kind, event.exec_id, event.caller, event.pc, event.opcode,
               opcode_name(event.opcode), event.method_idx,
               event.save_flags, event.save_returned, event.save_count_after,
               event.clip_before[0], event.clip_before[1], event.clip_before[2], event.clip_before[3],
               event.clip_after[0], event.clip_after[1], event.clip_after[2], event.clip_after[3],
               event.left, event.top, event.right, event.bottom,
               event.op_native, event.op_null,
               (unsigned long long)event.op_identity, event.op_class,
               event.bool_result, event.wrote,
               event.write_left, event.write_top, event.write_right, event.write_bottom,
               event.has_write);
    }
}

static void print_vector_trace(const agr_dex_game *game) {
    DxVM *vm = agr_dex_game_vm(game);
    uint32_t n = dx_vm_vector_tally_count(vm);
    uint32_t i;
    printf("vector_tally_count=%u dropped=%u trace=%u\n",
           n, dx_vm_vector_trace_dropped(vm), dx_vm_vector_trace_count(vm));
    for (i = 0; i < n; i++) {
        DxVectorTally tally;
        if (dx_vm_copy_vector_tally(vm, i, &tally) != 0) continue;
        printf("VECTOR_TALLY method=%s shorty=%s count=%u resolved=%u\n",
               tally.method, tally.shorty, tally.count, tally.resolved);
    }
    DxInvokeWitness follow;
    n = dx_vm_vector_after_element_count(vm);
    printf("vector_after_element_count=%u\n", n);
    for (i = 0; i < n; i++) {
        if (dx_vm_copy_vector_after_element(vm, i, &follow) != 0) continue;
        print_witness("VECTOR_NEXT", &follow);
    }
    if (dx_vm_copy_vector_next_unresolved(vm, &follow) == 0)
        print_witness("VECTOR_UNRESOLVED", &follow);
    else
        printf("VECTOR_UNRESOLVED none\n");
    n = dx_vm_unresolved_context_count(vm);
    printf("unresolved_context_count=%u\n", n);
    for (i = 0; i < n; i++) {
        DxUnresolvedContextInfo info;
        uint32_t event_index;
        if (dx_vm_copy_unresolved_context(vm, i, &info) != 0) continue;
        printf("UNRESOLVED_CONTEXT exec=%u count=%u dropped=%u\n",
               info.exec_id, info.count, info.dropped);
        for (event_index = 0; event_index < info.count; event_index++) {
            if (dx_vm_copy_unresolved_event(vm, i, event_index, &follow) != 0) continue;
            print_witness("UNRESOLVED", &follow);
        }
    }
    n = dx_vm_vector_trace_count(vm);
    for (i = 0; i < n; i++) {
        DxVectorTrace event;
        if (dx_vm_copy_vector_trace(vm, i, &event) != 0) continue;
        printf("VECTOR exec=%u caller=%s pc=%u opcode=0x%02x %s method_idx=%u "
               "resolved=%u method=%s shorty=%s argc=%u recv=%llu class=%s "
               "arg_obj=%llu arg_int=%d arg2=%d has_ret=%u ret_tag=%u ret=%d "
               "ret_obj=%llu ret_class=%s\n",
               event.exec_id, event.caller, event.pc, event.opcode, opcode_name(event.opcode),
               event.method_idx, event.resolved, event.method, event.shorty, event.argc,
               (unsigned long long)event.receiver, event.recv_class,
               (unsigned long long)event.arg_obj, event.arg_int, event.arg2_int,
               event.has_ret, event.ret_tag, event.ret_i,
               (unsigned long long)event.ret_obj, event.ret_class);
    }
}

static void print_witnesses(const agr_dex_game *game) {
    DxVM *vm = agr_dex_game_vm(game);
    uint32_t n = dx_vm_witness_fordigit_count(vm);
    DxInvokeWitness w;
    printf("fordigit_count=%u\n", n);
    for (uint32_t i = 0; i < n; i++) {
        if (dx_vm_copy_witness_fordigit(vm, i, &w) == 0) print_witness("FORDIGIT", &w);
    }
    if (dx_vm_copy_witness_continuation(vm, &w) == 0) print_witness("CONTINUATION", &w);
    else printf("CONTINUATION none\n");
    n = dx_vm_witness_unresolved_after_count(vm);
    printf("unresolved_after_count=%u\n", n);
    for (uint32_t i = 0; i < n; i++) {
        if (dx_vm_copy_witness_unresolved_after(vm, i, &w) == 0) print_witness("UNRESOLVED", &w);
    }
}

static void print_snapshot(const char *label, const agr_dex_runtime_snapshot *snapshot) {
    printf("%s stage_fields last=%s exception=%s error=%s created=%u changed=%u "
           "content=%llu root=%llu draw=%u stack=%u "
           "lock=%u unlock=%u post=%u locked=%d owner=%u locked_gen=%u post_gen=%u "
           "row=%d hash_before=%llx hash_after=%llx pixels=%u draws=%u format=%d %dx%d gen=%u\n",
           label,
           snapshot->last_method,
           snapshot->exception_class,
           snapshot->error,
           snapshot->content_surface_created_count,
           snapshot->content_surface_changed_count,
           (unsigned long long)snapshot->content_surface_identity,
           (unsigned long long)snapshot->root_surface_identity,
           snapshot->draw_count,
           snapshot->stack_depth,
           snapshot->canvas_lock_count,
           snapshot->canvas_unlock_count,
           snapshot->canvas_post_count,
           snapshot->canvas_locked,
           snapshot->canvas_lock_owner_exec,
           snapshot->canvas_locked_generation,
           snapshot->canvas_last_post_generation,
           snapshot->canvas_row_bytes,
           (unsigned long long)snapshot->canvas_buffer_hash_before,
           (unsigned long long)snapshot->canvas_buffer_hash_after,
           snapshot->canvas_pixel_change_count,
           snapshot->canvas_draw_bitmap_count,
           snapshot->content_surface_format,
           snapshot->content_surface_width,
           snapshot->content_surface_height,
           snapshot->content_surface_generation);
    if (snapshot->method_event_count) {
        const agr_dex_method_event *event = &snapshot->method_events[snapshot->method_event_count - 1];
        printf("%s last_event %s depth=%u\n", label, event->method, event->depth);
    }
    printf("%s feature_event_count=%u\n", label, snapshot->feature_event_count);
    for (uint32_t i = 0; i < snapshot->feature_event_count && i < AGR_FEATURE_EVENT_CAP; i++)
        printf("FEATURE %s\n", snapshot->feature_events[i]);
    printf("%s intent_event_count=%u\n", label, snapshot->intent_event_count);
    for (uint32_t i = 0; i < snapshot->intent_event_count && i < AGR_INTENT_EVENT_CAP; i++)
        printf("INTENT %s\n", snapshot->intent_events[i]);
}

int main(int argc, char **argv) {
    alarm(25);
    dx_log_set_level(DX_LOG_WARN);
    const char *apk_path = argc > 1 ? argv[1] : "/tmp/frozen.apk";
    agr_apk_package *package = agr_apk_package_open(apk_path);
    if (!package) {
        fprintf(stderr, "open failed %s\n", apk_path);
        return 1;
    }
    agr_dex_game *game = agr_dex_game_create_from_apk(package);
    if (!game) {
        fprintf(stderr, "create failed\n");
        return 1;
    }
    agr_dex_game_enable_diagnostics(game, 1);
    if (agr_dex_game_set_host_display(game, 320, 480) != 0) return 1;
    int started = agr_dex_game_start_activity(game);
    agr_activity_launch_stage stage = agr_dex_game_launch_stage(game);
    printf("start_activity=%d launch_stage=%d launch_error=%s\n",
           started, (int)stage, agr_dex_game_launch_error(game));
    agr_dex_runtime_snapshot snapshot;
    if (agr_dex_game_runtime_snapshot(game, &snapshot) == 0)
        print_snapshot("after_start", &snapshot);
    for (int frame = 0; frame < 3; frame++) {
        int frame_rc = agr_dex_game_choreographer_frame(game);
        printf("frame%d=%d\n", frame, frame_rc);
    }
    if (agr_dex_game_runtime_snapshot(game, &snapshot) == 0)
        print_snapshot("after_frames", &snapshot);
    /* The game loop sleeps 40ms per turn. Let it pass the first sleeps
       before teardown so the next guest stop is visible. */
    usleep(300000);
    if (agr_dex_game_runtime_snapshot(game, &snapshot) == 0)
        print_snapshot("after_wait", &snapshot);
    print_witnesses(game);
    print_canvas_trace(game);
    print_vector_trace(game);
    agr_dex_game_destroy(game);
    agr_apk_package_close(package);
    printf("frozen probe: destroyed\n");
    return started == 0 ? 0 : 2;
}
