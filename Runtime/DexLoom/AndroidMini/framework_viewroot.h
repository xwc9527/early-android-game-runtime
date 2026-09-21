#ifndef AGR_FRAMEWORK_VIEWROOT_H
#define AGR_FRAMEWORK_VIEWROOT_H

#include "../Include/dx_types.h"

typedef struct {
    int created;
    int root_assigned;
    int traversal_scheduled;
    int window_session_attached;
    int parent_assigned;
    int attach_completed;
} agr_viewroot_attach_state;

/* API19 ViewRoot attach ownership.  Traversal execution and surface drawing
   deliberately remain outside this phase. */
int agr_viewroot_attach(agr_viewroot_attach_state *state, DxObject *decor,
                        DxObject *window_manager, DxObject *layout_params,
                        DxObject *window_session);

#endif
