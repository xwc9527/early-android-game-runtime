#include "framework_viewroot.h"

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
    if (!root_class || !session_class || !attach_info_class) return DX_ERR_CLASS_NOT_FOUND;

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
