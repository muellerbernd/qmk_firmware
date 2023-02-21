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
// #define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_SPLIT // sync LEDs between RIGHT and LEFT hand
#endif // RGBLIGHT_ENABLE

// default but used in macros
#undef TAPPING_TERM
#define TAPPING_TERM 200
// #define TAPPING_TERM_PER_KEY
// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

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
#define NO_ACTION_ONESHOT
// #define NO_ACTION_MACRO
// #define NO_ACTION_FUNCTION
// allow only 8 layers
// #define LAYER_STATE_16BIT
#define LAYER_STATE_8BIT
#define NO_MUSIC_MODE
/* Disable unused and unneeded features to reduce on firmware size */
#ifdef LOCKING_SUPPORT_ENABLE
#    undef LOCKING_SUPPORT_ENABLE
#endif
#ifdef LOCKING_RESYNC_ENABLE
#    undef LOCKING_RESYNC_ENABLE
#endif

#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT

#ifdef OLED_ENABLE
#define SPLIT_WPM_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_OLED_ENABLE
#define SPLIT_MODS_ENABLE
#define OLED_TIMEOUT 60000
#define OLED_FONT_H "users/muellerbernd/glcdfont.c"
// #define CAT_ENABLE
#define LUNA_ENABLE
#define KEYLOGGER_ENABLE
// #define OLED_FADE_OUT true
#endif

// for keyboard-level data sync:
#ifdef CUSTOM_SPLIT_TRANSPORT_SYNC
#define SPLIT_TRANSACTION_IDS_USER RPC_ID_USER_KEYLOG_STR, RPC_ID_USER_LUNA
// Master to slave:
#define RPC_M2S_BUFFER_SIZE 48
// Slave to master:
#define RPC_S2M_BUFFER_SIZE 48
#endif

// #define OLED_BRIGHTNESS 120

// #ifdef COMBO_ENABLE
// #define COMBO_COUNT 6
// #endif

#ifdef LEADER_ENABLE
#define LEADER_TIMEOUT 300
#else
#define DISABLE_LEADER
#endif // LEADER_ENABLE

#ifdef POINTING_DEVICE_ENABLE
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_RIGHT
// #define POINTING_DEVICE_TASK_THROTTLE_MS 8
#define PIMORONI_TRACKBALL_SCALE 10
#endif

#ifdef MOUSEKEY_ENABLE
#define MOUSEKEY_WHEEL_INTERVAL 110 // 100
// #define MOUSEKEY_WHEEL_MAX_SPEED 3 // 8
#endif // MOUSEKEY_ENABLE
