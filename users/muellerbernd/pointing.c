/**
 * https://github.com/qmk/qmk_firmware/blob/master/keyboards/sofle/keymaps/foureight84/keymap.c
 * **/
#include "lib/lib8tion/lib8tion.h"
#include "string.h"
static uint32_t last_mouse_activity = 0;
static report_mouse_t last_mouse_report = {0};
bool isScrolling = false;
// uint16_t default_cpi = 65535;
uint16_t default_cpi = 30000;
// uint16_t default_cpi = 6000;


report_mouse_t smooth_mouse_movement(report_mouse_t mouse_report)
{
    // Linear interpolation and ease-in-out
    static fract8 fract = 0.5;
    int8_t x = 0;
    int8_t y = 0;
    int8_t h = 0;
    int8_t v = 0;

    if (!isScrolling)
    {
        x = ease8InOutApprox(
            lerp8by8(last_mouse_report.x, mouse_report.x, fract));
        y = ease8InOutApprox(
            lerp8by8(last_mouse_report.y, mouse_report.y, fract));
    }
    else
    {
        // h = ease8InOutApprox(lerp8by8(last_mouse_report.x, mouse_report.x,
        // fract)); v = ease8InOutApprox(lerp8by8(last_mouse_report.y,
        // mouse_report.y, fract));

        h = mouse_report.x;
        v = mouse_report.y;
        if (abs(h) > abs(v))
        {
            v = 0;
        }
        if (abs(v) > abs(h))
        {
            h = 0;
        }
    }

    // update the new smoothed report
    mouse_report.x = x;
    mouse_report.y = y;
    mouse_report.h = h;
    mouse_report.v = v;

    return mouse_report;
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report)
{
    // if (!isScrolling)
    // {
    //     // pimoroni_trackball_set_rgbw(180, 180, 180, 1);
    //     pointing_device_set_cpi(default_cpi);
    // }
    if (has_mouse_report_changed(&last_mouse_report, &mouse_report))
    {
        last_mouse_activity = timer_read32();
        memcpy(&last_mouse_report, &mouse_report, sizeof(mouse_report));
    }
    return smooth_mouse_movement(mouse_report);
}


// layer_state_t layer_state_set_user(layer_state_t state)
// {
//     // pointing_device_set_cpi(base_cpi);
//
//     switch (get_highest_layer(state))
//     {
//         case _LOWER: // If we're on the _NAV layer enable scrolling mode
//             isScrolling = true;
//             pointing_device_set_cpi(6000);
//             print("_LOWER");
//             // pointing_device_set_cpi(current_cpi/4);
//             // pimoroni_trackball_set_rgbw(180,180,180,1);
//             pimoroni_trackball_set_rgbw(255, 0, 0, 1);
//             break;
//         // case _QWERTZ:
//         // case _COLDH:
//         //     pointing_device_set_cpi(default_cpi);
//         //     break;
//         // case _NAV:
//         //     report_mouse_t currentReport = pointing_device_get_report();
//         default:
//             if (isScrolling)
//             { // check if we were scrolling before and set disable if so
//                 isScrolling = false;
//                 pimoroni_trackball_set_rgbw(180, 180, 180, 1);
//                 pointing_device_set_cpi(default_cpi);
//             }
//             // pointing_device_set_cpi(default_cpi);
//             break;
//     }
//     return state;
// }

void pointing_device_init_user(void)
{
    // default_cpi = pointing_device_get_cpi();
    // pointing_device_set_cpi(default_cpi);
    pimoroni_trackball_set_rgbw(180, 180, 180, 1);
}
// TODO: tapping like here:
// https://github.com/drashna/qmk_firmware/blob/master/users/drashna/pointing/pointing.c

// #define SIGN(x) ((x > 0) - (x < 0))
// report_mouse_t pointing_device_task_user(report_mouse_t mouse_report)
// {
//     int32_t x = mouse_report.x;
//     int32_t y = mouse_report.y;
//     if (isScrolling)
//     {
//         if (abs(x) > abs(y))
//         {
//             y = 0;
//         }
//         if (abs(y) > abs(x))
//         {
//             x = 0;
//         }
//
//         mouse_report.h = x;
//         mouse_report.v = y;
//         mouse_report.x = 0;
//         mouse_report.y = 0;
//         // mouse_report.buttons |= MOUSE_BTN2;
//     }
//     else
//     {
//         double vector_length = sqrt(pow(x, 2) + pow(y, 2));
//         float scale;
//         // scale = (vector_length > 13. ? 3. : 0.7);
//         if (vector_length < 10.0)
//         {
//             scale = 0.5;
//         }
//         else if (vector_length < 20.0)
//         {
//             scale = 1.0;
//         }
//         else
//         {
//             scale = 2.0;
//         }
//
//         int32_t x_s = (int32_t)(x * scale);
//         int32_t y_s = (int32_t)(y * scale);
//
//         mouse_report.x = SIGN(x) * fmin(100, abs(x_s));
//         mouse_report.y = SIGN(y) * fmin(100, abs(y_s));
//     }
//
//     // if (abs(mouse_report.x) > AUTO_POINTER_LAYER_TRIGGER_THRESHOLD ||
//     //     abs(mouse_report.y) > AUTO_POINTER_LAYER_TRIGGER_THRESHOLD)
//     // {
//     //     if (auto_pointer_layer_timer == 0)
//     //     {
//     //         layer_on(_POINTER);
//     //     }
//     //     auto_pointer_layer_timer = timer_read();
//     // }
//     return mouse_report;
// }
//
// // void matrix_scan_kb(void)
// // {
// //     if (auto_pointer_layer_timer != 0 &&
// //         TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >=
// //             AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS)
// //     {
// //         auto_pointer_layer_timer = 0;
// //         layer_off(_POINTER);
// //     }
// //     matrix_scan_user();
// // }
//
