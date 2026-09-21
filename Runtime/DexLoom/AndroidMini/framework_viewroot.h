#ifndef AGR_FRAMEWORK_VIEWROOT_H
#define AGR_FRAMEWORK_VIEWROOT_H

#include "../Include/dx_vm.h"

typedef void (*agr_viewroot_trace_fn)(void *user, const char *event);

typedef struct {
    uint8_t *pixels;
    uint32_t width;
    uint32_t height;
    uint32_t stride;
    uint32_t generation;
} agr_viewroot_surface_backing;

typedef enum {
    AGR_TRAVERSAL_IDLE = 0,
    AGR_TRAVERSAL_SCHEDULED,
    AGR_TRAVERSAL_RUNNING,
    AGR_TRAVERSAL_COMPLETED,
} agr_viewroot_traversal_phase;

/* The host supplies display facts. ViewRoot and WindowSession own policy. */
typedef struct {
    uint32_t width_pixels;
    uint32_t height_pixels;
} agr_viewroot_display;

typedef void *(*agr_viewroot_pixel_alloc)(void *user, size_t bytes);
typedef void (*agr_viewroot_pixel_free)(void *user, void *pixels);
/* The host WindowSession endpoint may reject relayout before it changes any
   window or Surface state. Zero accepts the request. */
typedef int (*agr_viewroot_relayout_gate)(void *user, uint32_t width,
                                          uint32_t height, int visibility);

typedef struct {
    DxObject *root;
    DxObject *decor;
    DxObject *layout_params;
    DxObject *window;
    DxObject *session;
    DxObject *attach_info;
    DxObject *attached_window;
    DxObject *surface;
    agr_viewroot_surface_backing backing;
    agr_viewroot_traversal_phase traversal_phase;
    uint32_t traversal_count;
    uint32_t draw_count;
    int hierarchy_attached;
    int measured_width;
    int measured_height;
    int frame_left;
    int frame_top;
    int frame_right;
    int frame_bottom;
    int layout_complete;
    int first_surface_transition;
    int relayout_result;
    agr_viewroot_pixel_alloc pixel_alloc;
    agr_viewroot_pixel_free pixel_free;
    void *pixel_user;
    agr_viewroot_relayout_gate relayout_gate;
    void *relayout_user;
    int layout_requested;
    int pending_first_traversal;
    int session_result;
    int input_channel_owned;
    int touch_mode;
    int app_visible;
    int added;
    int attach_complete;
} agr_viewroot_attach_state;

/* API19 ViewRoot attach ownership. scheduleTraversals does not execute.
   The host frame consumes one posted CALLBACK_TRAVERSAL. Drawing of a
   newly acquired Surface waits for the next frame. */
/* scheduleTraversals after the window is already attached. Idempotent when
   a traversal is already posted. Does not execute doTraversal. */
DxResult agr_viewroot_request_layout(agr_viewroot_attach_state *state,
                                    agr_viewroot_trace_fn trace, void *user);

DxResult agr_viewroot_add_view(DxVM *vm, agr_viewroot_attach_state *state,
                               DxObject *manager, DxObject *decor,
                               DxObject *layout_params, DxObject *window,
                               agr_viewroot_trace_fn trace, void *trace_user);

DxResult agr_viewroot_do_traversal(DxVM *vm, agr_viewroot_attach_state *state,
                                   agr_viewroot_display display,
                                   agr_viewroot_trace_fn trace, void *trace_user);
/* One UIKit/host vsync. Extracts at most one due traversal callback.
   A reschedule inside that callback waits for a later frame. */
DxResult agr_viewroot_choreographer_frame(DxVM *vm, agr_viewroot_attach_state *state,
                                           agr_viewroot_display display,
                                           agr_viewroot_trace_fn trace, void *trace_user);
void agr_viewroot_release(agr_viewroot_attach_state *state);
int agr_viewroot_surface_valid(const agr_viewroot_attach_state *state);

#endif
