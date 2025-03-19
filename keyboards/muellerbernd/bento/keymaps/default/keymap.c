#include QMK_KEYBOARD_H

enum encoder_names {
  _ENCODER
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        |                   |      | Knob 1: Vol Dn/Up  |
        | Hold: Layer 2     | Up   | Press: Mute        |
        | Left              | Down | Right              |
     */
    [0] = LAYOUT(
        KC_1, KC_2, KC_3,
        KC_4, KC_5, KC_6
    ),
    /*
        | Held: Layer 2  | Home | QK_BOOT      |
        | Media Previous | End  | Media Next |
     */
    [1] = LAYOUT(
        _______, KC_HOME, QK_BOOT,
        KC_MPRV, KC_END , KC_MNXT
    ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == _ENCODER) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}
