/* Local unchanged-APK probe. Not a CI target: the APK is not in the repository. */
#include "game_dex_runner.h"
#include "dx_vm.h"
#include "dx_log.h"
#include <GLES2/gl2.h>
#include <stdio.h>
#include <stdlib.h>
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

static void print_witness(const char *label, const DxInvokeWitness *w) {
    printf("%s exec=%u caller=%s pc=%u opcode=0x%02x %s method_idx=%u "
           "resolved=%u class=%s method=%s shorty=%s argc=%u "
           "arg0=%d/%u arg1=%d/%u arg2=%d/%u arg3=%d/%u "
           "has_ret=%u ret_tag=%u ret=%d\n",
           label, w->exec_id, w->caller, w->pc, w->opcode, opcode_name(w->opcode),
           w->method_idx, w->resolved, w->target_class, w->target_name, w->shorty, w->argc,
           w->arg_i[0], w->arg_tag[0], w->arg_i[1], w->arg_tag[1],
           w->arg_i[2], w->arg_tag[2], w->arg_i[3], w->arg_tag[3],
           w->has_ret, w->ret_tag, w->ret_i);
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
    agr_dex_game_destroy(game);
    agr_apk_package_close(package);
    printf("frozen probe: destroyed\n");
    return started == 0 ? 0 : 2;
}
