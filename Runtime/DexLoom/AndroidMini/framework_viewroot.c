#include "framework_viewroot.h"
#include "../Include/dx_vm.h"

int agr_viewroot_attach(agr_viewroot_attach_state *state, DxObject *decor,
                        DxObject *window_manager, DxObject *layout_params,
                        DxObject *window_session) {
    if (!state || !decor || !window_manager || !layout_params || !window_session)
        return -1;
    state->created = 1;
    state->root_assigned = 1;
    dx_vm_set_field(decor, "_viewRootAttached", DX_INT_VALUE(1));
    dx_vm_set_field(decor, "_windowSession", DX_OBJ_VALUE(window_session));
    state->traversal_scheduled = 1;
    dx_vm_set_field(decor, "_traversalScheduled", DX_INT_VALUE(1));
    state->window_session_attached = 1;
    state->parent_assigned = 1;
    dx_vm_set_field(decor, "_parent", DX_OBJ_VALUE(window_manager));
    state->attach_completed = 1;
    return 0;
}
