#ifndef AGR_FRAMEWORK_VIEWROOT_H
#define AGR_FRAMEWORK_VIEWROOT_H

#include "../Include/dx_vm.h"

typedef void (*agr_viewroot_trace_fn)(void *user, const char *event);

typedef struct {
    DxObject *root;
    DxObject *decor;
    DxObject *layout_params;
    DxObject *window;
    DxObject *session;
    DxObject *attach_info;
    DxObject *attached_window;
    int layout_requested;
    int pending_first_traversal;
    int session_result;
    int input_channel_owned;
    int touch_mode;
    int app_visible;
    int added;
    int attach_complete;
} agr_viewroot_attach_state;

/* API19 ViewRoot attach ownership.  Traversal execution and surface drawing
   deliberately remain outside this phase. */
DxResult agr_viewroot_add_view(DxVM *vm, agr_viewroot_attach_state *state,
                               DxObject *manager, DxObject *decor,
                               DxObject *layout_params, DxObject *window,
                               agr_viewroot_trace_fn trace, void *trace_user);

#endif
