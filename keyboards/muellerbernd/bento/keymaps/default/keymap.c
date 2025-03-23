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
        KC_BRID, KC_BRIU, KC_MUTE,
        KC_MPRV, KC_MNXT, LT(1, KC_MPLY)
    ),
    /*
        | Held: Layer 2  | Home | QK_BOOT      |
        | Media Previous | End  | Media Next |
     */
    [1] = LAYOUT(
        RGB_TOG, RGB_VAI, QK_BOOT,
        RGB_MOD, RGB_VAD, _______
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
