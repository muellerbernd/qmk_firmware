#include <string.h>
#include "lib/lib8tion/lib8tion.h"

bool          is_scrolling = false;
layer_state_t layer_state_set_user(layer_state_t state) {
    // pointing_device_set_cpi(base_cpi);

    switch (get_highest_layer(state)) {
        case _LOWER: // If we're on the _NAV layer enable scrolling mode
            is_scrolling = true;
            // pointing_device_set_cpi(6000);
            // print("_LOWER");
            // pointing_device_set_cpi(current_cpi/4);
            // pimoroni_trackball_set_rgbw(180,180,180,1);
            pimoroni_trackball_set_rgbw(255, 0, 0, 1);
            break;
        // case _QWERTZ:
        // case _COLDH:
        //     pointing_device_set_cpi(default_cpi);
        //     break;
        // case _NAV:
        //     report_mouse_t currentReport = pointing_device_get_report();
        default:
            if (is_scrolling) { // check if we were scrolling before and set disable if so
                is_scrolling = false;
                pimoroni_trackball_set_rgbw(180, 180, 180, 1);
                // pointing_device_set_cpi(default_cpi);
            }
            // pointing_device_set_cpi(default_cpi);
            break;
    }
    return state;
}

void pointing_device_init_user(void) {
    // default_cpi = pointing_device_get_cpi();
    // pointing_device_set_cpi(default_cpi);
    pimoroni_trackball_set_rgbw(180, 180, 180, 1);
}

#define NUMBER_OF_REPORTS 8
static const int8_t   shift                                = 3;
static const int8_t   initial_factor                       = 0;
static const uint16_t max_factor                           = 8;
static uint16_t       last_mouse_activity                  = 0;
static uint8_t        current_mouse_report_id              = 0;
static report_mouse_t last_mouse_report[NUMBER_OF_REPORTS] = {0};

void smoothen(int16_t *x, int16_t *y, uint16_t factor) {
    int16_t sum_x = 0;
    int16_t sum_y = 0;
    for (int i = 0; i < (NUMBER_OF_REPORTS - (NUMBER_OF_REPORTS >> 2)); i++) {
        report_mouse_t report = last_mouse_report[(current_mouse_report_id - i) % 8];
        sum_x += report.x;
        sum_y += report.y;
    }
    int16_t tempx = (sum_x >> shift) << factor;
    int16_t tempy = (sum_y >> shift) << factor;
    *x            = tempx;
    *y            = tempy;
}

void append_report(report_mouse_t mouse_report) {
    current_mouse_report_id                    = (current_mouse_report_id + 1) % NUMBER_OF_REPORTS;
    last_mouse_report[current_mouse_report_id] = mouse_report;
}

int16_t normalize(int16_t n) {
    if (n == 0) {
        return 0;
    } else if (n > 0) {
        return -1;
    } else {
        return 1;
    }
}

report_mouse_t smooth_mouse_movement(report_mouse_t mouse_report) {
    // Linear interpolation and ease-in-out
    int16_t x = 0;
    int16_t y = 0;
    int16_t h = 0;
    int16_t v = 0;

    uint16_t activity_diff = timer_elapsed(last_mouse_activity);
    activity_diff          = activity_diff >> 1;
    uint8_t factor         = initial_factor;
    if (activity_diff < max_factor && initial_factor <= activity_diff) {
        factor = max_factor - activity_diff;
    } else if (activity_diff < initial_factor) {
        factor = max_factor;
    }

    if (!is_scrolling) {
        smoothen(&x, &y, factor);
    } else {
        /* smoothen(&h, &v, factor >> 1); */
        h = normalize(mouse_report.x);
        v = normalize(mouse_report.y);
    }

    // update the new smoothed report
    mouse_report.x = x;
    mouse_report.y = y;
    mouse_report.h = h;
    mouse_report.v = v;

    return mouse_report;
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    // append_report(mouse_report);
    // report_mouse_t m_rep = smooth_mouse_movement(mouse_report);
    //
    // if (has_mouse_report_changed(&last_mouse_report[current_mouse_report_id], &mouse_report)) {
    //     last_mouse_activity = timer_read();
    // }
    //
    // return m_rep;
    return mouse_report;
}

// static uint32_t       last_mouse_activity = 0;
// static report_mouse_t last_mouse_report   = {0};
//
// report_mouse_t smooth_mouse_movement(report_mouse_t mouse_report) {
//     // Linear interpolation and ease-in-out
//     static fract8 fract = 0.5;
//     int8_t        x     = 0;
//     int8_t        y     = 0;
//     int8_t        h     = 0;
//     int8_t        v     = 0;
//
//     if (!is_scrolling) {
//         x = ease8InOutApprox(lerp8by8(last_mouse_report.x, mouse_report.x, fract));
//         y = ease8InOutApprox(lerp8by8(last_mouse_report.y, mouse_report.y, fract));
//     } else {
//         h = ease8InOutApprox(lerp8by8(last_mouse_report.x, mouse_report.x, fract));
//         v = ease8InOutApprox(lerp8by8(last_mouse_report.y, mouse_report.y, fract));
//     }
//
//     // update the new smoothed report
//     mouse_report.x = x;
//     mouse_report.y = y;
//     mouse_report.h = h;
//     mouse_report.v = v;
//
//     return mouse_report;
// }
//
// report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
//     if (has_mouse_report_changed(&last_mouse_report, &mouse_report)) {
//         last_mouse_activity = timer_read32();
//         memcpy(&last_mouse_report, &mouse_report, sizeof(mouse_report));
//     }
//
//     return smooth_mouse_movement(mouse_report);
// }
