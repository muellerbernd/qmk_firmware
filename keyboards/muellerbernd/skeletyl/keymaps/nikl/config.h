/* Select hand configuration */
/* #define MASTER_LEFT */
// #define MASTER_RIGHT
#define EE_HANDS
// #define SPLIT_LED_STATE_ENABLE
#undef RGBLIGHT_ANIMATIONS
#undef RGBLIGHT_EFFECT_BREATHING
#undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#undef RGBLIGHT_EFFECT_SNAKE
#undef RGBLIGHT_EFFECT_KNIGHT
#undef RGBLIGHT_EFFECT_CHRISTMAS
#undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#undef RGBLIGHT_EFFECT_RGB_TEST
#undef RGBLIGHT_EFFECT_ALTERNATING
#undef RGBLIGHT_EFFECT_TWINKLE
#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_SPLIT // sync LEDs between RIGHT and LEFT hand
#endif // RGBLIGHT_ENABLE
// default but used in macros
#undef TAPPING_TERM
#define TAPPING_TERM 200
// #define TAPPING_TERM_PER_KEY
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD
// This makes tap and hold keys (like Layer Tap) work better for fast typists,
// or for high TAPPING_TERM settings.
#define PERMISSIVE_HOLD
// For instance, holding and releasing LT(2, KC_SPACE) without hitting another
// key will result in nothing happening. With this enabled, it will send
// KC_SPACE instead. #define RETRO_TAPPING
// Auto Shift
// #define NO_AUTO_SHIFT_ALPHA
// #define AUTO_SHIFT_TIMEOUT TAPPING_TERM
// #define AUTO_SHIFT_NO_SETUP
// Recommended for heavy chording.
#define QMK_KEYS_PER_SCAN 4
// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 64
// shave off some byte from firmware
// #define NO_ACTION_TAPPING
// #define NO_ACTION_ONESHOT
// #define NO_ACTION_MACRO
// #define NO_ACTION_FUNCTION
// allow only 8 layers
// #define LAYER_STATE_16BIT
#define LAYER_STATE_8BIT
#define NO_MUSIC_MODE
// #undef LOCKING_SUPPORT_ENABLE
// #undef LOCKING_RESYNC_ENABLE
#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT

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

#pragma once
#undef USE_I2C
// #define USE_SERIAL
/* Use I2C or Serial, not both */
// #define USE_SERIAL_PD2
// #define USE_SERIAL
#define SOFT_SERIAL_PIN D2

#undef RGBLED_NUM

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
#define PIMORONI_TRACKBALL_ROTATE
#define POINTING_DEVICE_DEBUG
// #define PIMORONI_TRACKBALL_INVERT_X
// #define PIMORONI_TRACKBALL_INVERT_Y
#endif
// #ifdef POINTING_DEVICE_ENABLE
// #define SPLIT_POINTING_ENABLE
// #define POINTING_DEVICE_RIGHT
// #define MOUSE_EXTENDED_REPORT
// #define POINTING_DEVICE_ROTATION_90
// // #define POINTING_DEVICE_INVERT_X
// // #define POINTING_DEVICE_INVERT_Y
// // #define PIMORONI_TRACKBALL_SCALE 10
// #endif

