#include "framework_viewroot.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* API19 WindowManagerGlobal.ADD_OKAY and ADD_FLAG_APP_VISIBLE.  The local
 * session is the system-server boundary; ViewRoot ownership stays here. */
enum { AGR_ADD_OKAY = 0, AGR_ADD_FLAG_APP_VISIBLE = 2 };

static void emit(agr_viewroot_trace_fn trace, void *user, const char *event) {
    if (trace) trace(user, event);
}

static DxResult set(DxObject *object, const char *name, DxValue value) {
    return dx_vm_set_field(object, name, value);
}

/* requestLayout() makes one first traversal pending.  It deliberately does
 * not execute a traversal, create a Surface, or post a drawing callback. */
static DxResult request_first_layout(agr_viewroot_attach_state *state,
                                     agr_viewroot_trace_fn trace, void *user) {
    if (!state || !state->root || !state->decor) return DX_ERR_INVALID_FORMAT;
    state->layout_requested = 1;
    if (set(state->root, "_layoutRequested", DX_INT_VALUE(1)) != DX_OK)
        return DX_ERR_INVALID_FORMAT;
    emit(trace, user, "viewroot.request_layout");
    if (!state->pending_first_traversal) {
        state->pending_first_traversal = 1;
        state->traversal_phase = AGR_TRAVERSAL_SCHEDULED;
        if (set(state->root, "_traversalPending", DX_INT_VALUE(1)) != DX_OK)
            return DX_ERR_INVALID_FORMAT;
        emit(trace, user, "viewroot.traversal.scheduled");
    }
    return DX_OK;
}

/* In-process API19 IWindowSession.addToDisplay boundary for a normal app
 * window.  A session owns the attached window identity and initial input/
 * inset state; duplicate attachment or an invalid app type is rejected. */
static DxResult session_add_to_display(agr_viewroot_attach_state *state,
                                       agr_viewroot_trace_fn trace, void *user) {
    DxValue type = DX_NULL_VALUE;
    if (!state || !state->session || !state->window || state->attached_window ||
        dx_vm_get_field(state->layout_params, "_type", &type) != DX_OK ||
        type.tag != DX_VAL_INT || type.i != 1)
        return DX_ERR_INVALID_FORMAT;
    if (set(state->session, "_attachedWindow", DX_OBJ_VALUE(state->window)) != DX_OK ||
        set(state->session, "_inputChannelOwned", DX_INT_VALUE(1)) != DX_OK ||
        set(state->session, "_contentInsetLeft", DX_INT_VALUE(0)) != DX_OK ||
        set(state->session, "_contentInsetTop", DX_INT_VALUE(0)) != DX_OK ||
        set(state->session, "_contentInsetRight", DX_INT_VALUE(0)) != DX_OK ||
        set(state->session, "_contentInsetBottom", DX_INT_VALUE(0)) != DX_OK)
        return DX_ERR_INVALID_FORMAT;
    emit(trace, user, "window_session.add_to_display");
    state->attached_window = state->window;
    state->session_result = AGR_ADD_OKAY | AGR_ADD_FLAG_APP_VISIBLE;
    state->input_channel_owned = 1;
    state->touch_mode = 0;
    state->app_visible = 1;
    return DX_OK;
}

DxResult agr_viewroot_add_view(DxVM *vm, agr_viewroot_attach_state *state,
                               DxObject *manager, DxObject *decor,
                               DxObject *layout_params, DxObject *window,
                               agr_viewroot_trace_fn trace, void *trace_user) {
    if (!vm || !state || !manager || !decor || !layout_params || !window ||
        state->root || state->added)
        return DX_ERR_INVALID_FORMAT;
    DxClass *root_class = dx_vm_find_class(vm, "Landroid/view/ViewRootImpl;");
    DxClass *session_class = dx_vm_find_class(vm, "Landroid/view/IWindowSession;");
    DxClass *attach_info_class = dx_vm_find_class(vm, "Landroid/view/View$AttachInfo;");
    DxClass *surface_class = dx_vm_find_class(vm, "Landroid/view/Surface;");
    if (!root_class || !session_class || !attach_info_class || !surface_class)
        return DX_ERR_CLASS_NOT_FOUND;

    emit(trace, trace_user, "window_manager.add_view.enter");
    emit(trace, trace_user, "window_manager_global.add_view");
    state->root = dx_vm_alloc_object(vm, root_class);
    if (!state->root) return DX_ERR_OUT_OF_MEMORY;
    /* Root it before another allocation can trigger collection. */
    if (set(manager, "_viewRoot", DX_OBJ_VALUE(state->root)) != DX_OK)
        return DX_ERR_INVALID_FORMAT;
    emit(trace, trace_user, "viewroot.create");
    state->session = dx_vm_alloc_object(vm, session_class);
    if (!state->session) return DX_ERR_OUT_OF_MEMORY;
    if (set(state->root, "_session", DX_OBJ_VALUE(state->session)) != DX_OK)
        return DX_ERR_INVALID_FORMAT;
    state->attach_info = dx_vm_alloc_object(vm, attach_info_class);
    if (!state->attach_info ||
        set(state->root, "_attachInfo", DX_OBJ_VALUE(state->attach_info)) != DX_OK ||
        set(state->attach_info, "_rootView", DX_OBJ_VALUE(decor)) != DX_OK)
        return DX_ERR_OUT_OF_MEMORY;
    /* The Surface Java object exists before relayout; its native backing is
       acquired later by IWindowSession.relayout when the window is visible. */
    state->surface = dx_vm_alloc_object(vm, surface_class);
    if (!state->surface ||
        set(state->root, "_surface", DX_OBJ_VALUE(state->surface)) != DX_OK ||
        set(state->attach_info, "_surface", DX_OBJ_VALUE(state->surface)) != DX_OK ||
        set(state->surface, "_ownerWindow", DX_OBJ_VALUE(window)) != DX_OK ||
        set(state->surface, "_valid", DX_INT_VALUE(0)) != DX_OK)
        return DX_ERR_OUT_OF_MEMORY;

    /* ViewRootImpl.setView: establish ownership before scheduling. */
    emit(trace, trace_user, "viewroot.set_view.enter");
    state->decor = decor;
    state->layout_params = layout_params;
    state->window = window;
    if (set(state->root, "_view", DX_OBJ_VALUE(decor)) != DX_OK ||
        set(state->root, "_layoutParams", DX_OBJ_VALUE(layout_params)) != DX_OK ||
        set(decor, "_layoutParams", DX_OBJ_VALUE(layout_params)) != DX_OK ||
        set(state->root, "_added", DX_INT_VALUE(1)) != DX_OK)
        return DX_ERR_INVALID_FORMAT;
    state->added = 1;
    emit(trace, trace_user, "viewroot.root_assigned");
    if (request_first_layout(state, trace, trace_user) != DX_OK)
        return DX_ERR_INVALID_FORMAT;
    if (session_add_to_display(state, trace, trace_user) != DX_OK)
        return DX_ERR_INVALID_FORMAT;
    if (set(decor, "_parent", DX_OBJ_VALUE(state->root)) != DX_OK)
        return DX_ERR_INVALID_FORMAT;
    emit(trace, trace_user, "viewroot.parent_assigned");
    state->attach_complete = 1;
    emit(trace, trace_user, "viewroot.attach.complete");
    return DX_OK;
}

static int32_t field_int(DxObject *object, const char *name, int32_t fallback) {
    DxValue value = DX_NULL_VALUE;
    return object && dx_vm_get_field(object, name, &value) == DX_OK &&
        value.tag == DX_VAL_INT ? value.i : fallback;
}

static void *default_pixel_alloc(void *user, size_t bytes) {
    (void)user;
    return calloc(1, bytes);
}

static void default_pixel_free(void *user, void *pixels) {
    (void)user;
    free(pixels);
}

int agr_viewroot_surface_valid(const agr_viewroot_attach_state *state) {
    return state && state->surface && state->backing.pixels &&
        state->backing.width && state->backing.height &&
        field_int(state->surface, "_valid", 0) == 1;
}

void agr_viewroot_release(agr_viewroot_attach_state *state) {
    if (!state) return;
    if (state->backing.pixels) {
        agr_viewroot_pixel_free release = state->pixel_free ? state->pixel_free : default_pixel_free;
        release(state->pixel_user, state->backing.pixels);
        state->backing.pixels = NULL;
    }
    state->backing.width = state->backing.height = state->backing.stride = 0;
    if (state->surface) set(state->surface, "_valid", DX_INT_VALUE(0));
}

/* API19 getRootMeasureSpec + View.getDefaultSize for the existing Decor root.
   LayoutParams -1 is MATCH_PARENT and -2 is WRAP_CONTENT. The Decor's base
   View.onMeasure uses the constraint size for EXACTLY and AT_MOST. */
static int root_measured_dimension(int display, int param) {
    if (param == -1 || param == -2) return display;
    return param > 0 ? param : 0;
}

static DxResult session_relayout(agr_viewroot_attach_state *state,
                                 agr_viewroot_display display,
                                 agr_viewroot_trace_fn trace, void *user) {
    if (!state->session || !state->attached_window ||
        state->attached_window != state->window || !state->input_channel_owned ||
        field_int(state->layout_params, "_type", 0) != 1)
        return DX_ERR_INVALID_FORMAT;
    emit(trace, user, "window_session.relayout.enter");
    int visible = field_int(state->decor, "_visibility", 4) == 0;
    int width = state->measured_width;
    int height = state->measured_height;
    if (width <= 0 || height <= 0 || (uint32_t)width > display.width_pixels ||
        (uint32_t)height > display.height_pixels)
        return DX_ERR_INVALID_FORMAT;

    if (visible && !agr_viewroot_surface_valid(state)) {
        if ((size_t)width > SIZE_MAX / 4u / (size_t)height)
            return DX_ERR_OUT_OF_MEMORY;
        size_t bytes = (size_t)width * (size_t)height * 4u;
        agr_viewroot_pixel_alloc alloc = state->pixel_alloc ? state->pixel_alloc : default_pixel_alloc;
        void *pixels = alloc(state->pixel_user, bytes);
        if (!pixels) return DX_ERR_OUT_OF_MEMORY;
        state->backing.pixels = pixels;
        state->backing.width = (uint32_t)width;
        state->backing.height = (uint32_t)height;
        state->backing.stride = (uint32_t)width * 4u;
        state->backing.generation++;
        state->first_surface_transition = 1;
        if (set(state->surface, "_valid", DX_INT_VALUE(1)) != DX_OK ||
            set(state->surface, "_generation", DX_INT_VALUE((int32_t)state->backing.generation)) != DX_OK ||
            set(state->surface, "_width", DX_INT_VALUE(width)) != DX_OK ||
            set(state->surface, "_height", DX_INT_VALUE(height)) != DX_OK) {
            agr_viewroot_release(state);
            return DX_ERR_INVALID_FORMAT;
        }
        emit(trace, user, "window_session.surface.acquired");
    } else if (!visible && agr_viewroot_surface_valid(state)) {
        agr_viewroot_release(state);
        emit(trace, user, "window_session.surface.released");
    }

    state->frame_left = state->frame_top = 0;
    state->frame_right = width;
    state->frame_bottom = height;
    state->relayout_result = state->traversal_count == 0 ? 2 : 0; /* RELAYOUT_RES_FIRST_TIME */
    if (set(state->session, "_requestedWidth", DX_INT_VALUE(width)) != DX_OK ||
        set(state->session, "_requestedHeight", DX_INT_VALUE(height)) != DX_OK ||
        set(state->session, "_viewVisibility", DX_INT_VALUE(visible ? 0 : 4)) != DX_OK ||
        set(state->session, "_frameLeft", DX_INT_VALUE(0)) != DX_OK ||
        set(state->session, "_frameTop", DX_INT_VALUE(0)) != DX_OK ||
        set(state->session, "_frameRight", DX_INT_VALUE(width)) != DX_OK ||
        set(state->session, "_frameBottom", DX_INT_VALUE(height)) != DX_OK ||
        set(state->session, "_surface", DX_OBJ_VALUE(state->surface)) != DX_OK)
        return DX_ERR_INVALID_FORMAT;
    emit(trace, user, "window_session.relayout.return");
    return DX_OK;
}

DxResult agr_viewroot_do_traversal(DxVM *vm, agr_viewroot_attach_state *state,
                                   agr_viewroot_display display,
                                   agr_viewroot_trace_fn trace, void *user) {
    if (!vm || !state || !state->attach_complete || !state->root || !state->decor ||
        !state->pending_first_traversal || state->traversal_phase != AGR_TRAVERSAL_SCHEDULED ||
        !display.width_pixels || !display.height_pixels ||
        display.width_pixels > INT32_MAX || display.height_pixels > INT32_MAX)
        return DX_ERR_INVALID_FORMAT;
    state->pending_first_traversal = 0;
    state->traversal_phase = AGR_TRAVERSAL_RUNNING;
    DxResult failure = DX_ERR_INVALID_FORMAT;
    set(state->root, "_traversalPending", DX_INT_VALUE(0));
    emit(trace, user, "viewroot.traversal.consumed");
    emit(trace, user, "viewroot.do_traversal");
    emit(trace, user, "viewroot.perform_traversals.enter");

    if (!state->hierarchy_attached) {
        if (set(state->decor, "_attachInfo", DX_OBJ_VALUE(state->attach_info)) != DX_OK ||
            set(state->decor, "_attachedToWindow", DX_INT_VALUE(1)) != DX_OK ||
            set(state->attach_info, "_windowVisibility",
                DX_INT_VALUE(field_int(state->decor, "_visibility", 4))) != DX_OK)
            goto failed;
        state->hierarchy_attached = 1;
        emit(trace, user, "view.dispatch_attached_to_window");
    }

    int width = root_measured_dimension((int)display.width_pixels,
                                        field_int(state->layout_params, "_width", -1));
    int height = root_measured_dimension((int)display.height_pixels,
                                         field_int(state->layout_params, "_height", -1));
    if (!width || !height || set(state->decor, "_measuredWidth", DX_INT_VALUE(width)) != DX_OK ||
        set(state->decor, "_measuredHeight", DX_INT_VALUE(height)) != DX_OK)
        goto failed;
    state->measured_width = width;
    state->measured_height = height;
    emit(trace, user, "viewroot.perform_measure");
    failure = session_relayout(state, display, trace, user);
    if (failure != DX_OK) goto failed;
    if (set(state->root, "_frameLeft", DX_INT_VALUE(state->frame_left)) != DX_OK ||
        set(state->root, "_frameTop", DX_INT_VALUE(state->frame_top)) != DX_OK ||
        set(state->root, "_frameRight", DX_INT_VALUE(state->frame_right)) != DX_OK ||
        set(state->root, "_frameBottom", DX_INT_VALUE(state->frame_bottom)) != DX_OK ||
        set(state->decor, "_left", DX_INT_VALUE(0)) != DX_OK ||
        set(state->decor, "_top", DX_INT_VALUE(0)) != DX_OK ||
        set(state->decor, "_right", DX_INT_VALUE(width)) != DX_OK ||
        set(state->decor, "_bottom", DX_INT_VALUE(height)) != DX_OK)
        goto failed;
    state->layout_complete = 1;
    state->layout_requested = 0;
    set(state->root, "_layoutRequested", DX_INT_VALUE(0));
    emit(trace, user, "viewroot.perform_layout");
    state->traversal_count++;
    state->traversal_phase = AGR_TRAVERSAL_COMPLETED;
    emit(trace, user, "viewroot.traversal.completed");
    if (state->first_surface_transition && agr_viewroot_surface_valid(state)) {
        /* KitKat defers drawing a newly acquired surface to the next pass. */
        state->first_surface_transition = 0;
        state->pending_first_traversal = 1;
        state->traversal_phase = AGR_TRAVERSAL_SCHEDULED;
        set(state->root, "_traversalPending", DX_INT_VALUE(1));
        emit(trace, user, "viewroot.traversal.rescheduled");
    }
    if (agr_viewroot_surface_valid(state)) emit(trace, user, "handoff.viewroot_surface_ready");
    return DX_OK;
failed:
    state->pending_first_traversal = 1;
    state->traversal_phase = AGR_TRAVERSAL_SCHEDULED;
    set(state->root, "_traversalPending", DX_INT_VALUE(1));
    emit(trace, user, "viewroot.traversal.failed");
    return failure;
}
