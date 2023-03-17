#include "users/muellerbernd/common_conf.h"
/*

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// #pragma once
#include_next <halconf.h>

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
// #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
//
// /* i2c */
// #define I2C_DRIVER I2CD2
//
// /* communication between sides */
// #define SERIAL_PIO_USE_PIO1

// #undef USE_I2C
// #define USE_SERIAL
/* Use I2C or Serial, not both */
// #define USE_SERIAL_PD2
// #define USE_SERIAL
#define SOFT_SERIAL_PIN D2

#undef RGBLED_NUM
// The pin connected to the data pin of the LEDs
#define RGB_DI_PIN D3

#ifdef RGBLIGHT_ENABLE
#define RGBLED_NUM 34 // Total number of LEDs
#define RGBLED_SPLIT                                                           \
    {                                                                          \
        17, 17                                                                 \
    } // LEDs per side
#define RGBLIGHT_SPLIT
// #define RGBLIGHT_LIMIT_VAL 80
// Limit the power draw
#define RGBLIGHT_LIMIT_VAL 150
// #define RGBLIGHT_EFFECT_RGB_TEST
// #define RGBLIGHT_EFFECT_BREATHING
// #define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_CHRISTMAS
// #define RGBLIGHT_EFFECT_SNAKE
// #define RGBLIGHT_EFFECT_KNIGHT
// #define RGBLIGHT_EFFECT_STATIC_GRADIENT
// #define RGBLIGHT_EFFECT_ALTERNATING
// #define RGBLIGHT_EFFECT_TWINKLE
#endif

#ifdef RGB_MATRIX_ENABLE
#define RGBLED_NUM 34 // Total number of LEDs
// The number of LEDs connected
#define RGB_MATRIX_LED_COUNT 34
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS                                          \
    150 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause
        // the controller to crash.
// #define RGB_MATRIX_HUE_STEP 8
// #define RGB_MATRIX_SAT_STEP 8
// #define RGB_MATRIX_VAL_STEP 8
// #define RGB_MATRIX_SPD_STEP 10
#define RGB_MATRIX_KEYRELEASES
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_SPLIT                                                       \
    {                                                                          \
        17, 17                                                                 \
    }
#define ENABLE_RGB_MATRIX_BREATHING
#define ENABLE_RGB_MATRIX_ALPHAS_MODS
#define ENABLE_RGB_MATRIX_BAND_SAT
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 80
#define RGB_MATRIX_TYPING_HEATMAP_SPREAD 60
/* Triggers RGB keypress events on key down. This makes RGB control feel more
 * responsive. This may cause RGB to not function properly on some boards*/
// #define RGB_TRIGGER_ON_KEYDOWN
#endif

#ifdef ENCODER_ENABLE
#define ENCODERS_PAD_A { F5 }
#define ENCODERS_PAD_B { F4 }
// #define ENCODERS_PAD_A_RIGHT { F4 }
// #define ENCODERS_PAD_B_RIGHT { F5 }
#define ENCODER_RESOLUTION 4
#endif // ENCODER_ENABLE

#ifdef POINTING_DEVICE_ENABLE
// #define MOUSE_EXTENDED_REPORT
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT
#define POINTING_DEVICE_ROTATION_270
// #define POINTING_DEVICE_INVERT_X
// #define POINTING_DEVICE_INVERT_Y
#endif
