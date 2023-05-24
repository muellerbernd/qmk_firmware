#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include <stdio.h>

#include "users/muellerbernd/muellerbernd.h"
#ifdef TAP_DANCE_ENABLE
#include "users/muellerbernd/tapdance.c"
#endif

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTZ
 * +------+------+------+------+------+                    +------+------+------+------+------+
 * |   Q  |   W  |   E  |   R  |   T  |                    |   Z  |   U  |   I  |   O  |   P  |
 * +------+------+------+------+------+                    +------+------+------+------+------+
 * |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   +  |
 * +------+------+------+------+------+                    +------+------+------+------+------+
 * |   Y  |   X  |   C  |   V  |   B  |                    |   N  |   M  |   ,  |   .  |   -  |
 * +------+------+------+------+------+------+      +------+------+------+------+------+------+
 *                             |T_DEL | T_SPC|      |T_BSPC| T_ENT|
 *                             +------+------+      +------+------+
 */
[_QWERTZ] =  LAYOUT_3x5_2_base_wrapper(
        QWERTZ_L1, QWERTZ_R1,
        QWERTZ_L2, QWERTZ_R2,
        QWERTZ_L3, QWERTZ_R3
),

/* COLDH
 * +------+------+------+------+------+                    +------+------+------+------+------+
 * |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   +  |
 * +------+------+------+------+------+                    +------+------+------+------+------+
 * |   A  |   R  |   S  |   T  |   G  |                    |   M  |   N  |   E  |   I  |   O  |
 * +------+------+------+------+------+                    +------+------+------+------+------+
 * |   Z  |   X  |   C  |   D  |   V  |                    |   K  |   H  |   ,  |   .  |   -  |
 * +------+------+------+------+------+------+      +------+------+------+------+------+------+
 *                             |T_DEL | T_SPC|      |T_BSPC| T_ENT|
 *                             +------+------+      +------+------+
 */
[_COLDH] = LAYOUT_3x5_2_base_wrapper(
        COLDH_L1, COLDH_R1,
        COLDH_L2, COLDH_R2,
        COLDH_L3, COLDH_R3
),

/* LOWER
 * +------+------+------+------+------+                    +------+------+------+------+------+
 * | <F9> |<F10> |<F11> |<F12> |      |                    |   :  |   7  |   8  |   9  |   +  |
 * +------+------+------+------+------+                    +------+------+------+------+------+
 * | <F5> | <F6> | <F7> | <F8> |      |                    |   ;  |   4  |   5  |   6  |   ,  |
 * +------+------+------+------+------+                    +------+------+------+------+------+
 * | <F1> | <F2> | <F3> | <F3> |      |                    |   0  |   1  |   2  |   3  |   +  |
 * +------+------+------+------+------+------+      +------+------+------+------+------+------+
 *                             |T_DEL | T_SPC|      |T_BSPC| T_ENT|
 *                             +------+------+      +------+------+
 */
[_LOWER] = LAYOUT_split_3x5_2_wrapper(
        LOWER_L1, LOWER_R1,
        LOWER_L2, LOWER_R2,
        LOWER_L3, LOWER_R3,
_______, _______, _______, _______
),

/* RAISE
 * +------+------+------+------+------+                    +------+------+------+------+------+
 * |   @  |   _  |   [  |   ]  |   ^  |                    |   !  |   <  |   >  |   =  |   &  |
 * +------+------+------+------+------+                    +------+------+------+------+------+
 * |   \  |   /  |   {  |   }  |   *  |                    |   ?  |   (  |   )  |   -  |   ´  |
 * +------+------+------+------+------+                    +------+------+------+------+------+
 * |   #  |   ~  |   |  |   $  |   €  |                    |   +  |   %  |   "  |   '  |   `  |
 * +------+------+------+------+------+------+      +------+------+------+------+------+------+
 *                             |T_DEL | T_SPC|      |T_BSPC| T_ENT|
 *                             +------+------+      +------+------+
 */
[_RAISE] = LAYOUT_split_3x5_2_wrapper(
        RAISE_L1, RAISE_R1,
        RAISE_L2, RAISE_R2,
        RAISE_L3, RAISE_R3,
// _______, EEP_RST, EEP_RST, _______
_______, _______, _______, _______
),

[_NAV] = LAYOUT_split_3x5_2_wrapper(
        NAV_L1, NAV_R1,
        NAV_L2, NAV_R2,
        NAV_L3, NAV_R3,
_______, _______, _______, _______
),


[_ADJUST] = LAYOUT_split_3x5_2_wrapper(
        ADJUST_L1, ADJUST_R1,
        ADJUST_L2, ADJUST_R2,
        ADJUST_L3, ADJUST_R3,
_______, _______, _______, _______
  ),

[_POINTER] = LAYOUT_split_3x5_2_wrapper(
        POINTER_L1, POINTER_R1,
        POINTER_L2, POINTER_R2,
        POINTER_L3, POINTER_R3,
_______, _______, _______, _______
  )

};
// clang-format on
#ifdef LEADER_ENABLE
#include "users/muellerbernd/leader.c"
#endif // LEADER_ENABLE

// SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in
// rules.mk
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation)
{
    return OLED_ROTATION_270;
}
#include "users/muellerbernd/keylogger.c"
/* static bool display_on = true; */
#ifdef LUNA_ENABLE
#include "users/muellerbernd/luna.c"
#endif
#include "users/muellerbernd/oled.c"
#endif // OLED_ENABLE
#ifdef POINTING_DEVICE_ENABLE
#include "users/muellerbernd/pointing.c"
#endif

#ifdef CUSTOM_SPLIT_TRANSPORT_SYNC
#include "users/muellerbernd/transport_sync.c"
#endif

#include "users/muellerbernd/process_record_user.c"

