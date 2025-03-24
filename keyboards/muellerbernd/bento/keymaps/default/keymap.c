#include QMK_KEYBOARD_H

enum encoder_names { _ENCODER };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        |                   |      | Knob 1: Vol Dn/Up  |
        | Hold: Layer 2     | Up   | Press: Mute        |
        | Left              | Down | Right              |
     */
    // clang-format off
    [0] = LAYOUT(
        LT(2, KC_F20), KC_BRIU, KC_MUTE,
        KC_MPRV, KC_MNXT, LT(1, KC_MPLY)
    ),
    /*
        | Held: Layer 2  | Home | QK_BOOT      |
        | Media Previous | End  | Media Next |
     */
    [1] = LAYOUT(
        RGB_TOG, KC_1 , QK_BOOT,
        RGB_MOD, KC_1 , _______
    ),
    [2] = LAYOUT(
        _______, RGB_SAI, QK_BOOT,
        RGB_HUD, RGB_SAD, _______
    ),
    // clang-format on
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == _ENCODER) {
        if (layer_state_is(0)) {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        };
        /*if (layer_state_is(1)) {*/
        /*    if (clockwise) {*/
        /*        tap_code(RGB_VAI);*/
        /*    } else {*/
        /*        tap_code(RGB_VAD);*/
        /*    }*/
        /*};*/
        /*if (layer_state_is(2)) {*/
        /*    if (clockwise) {*/
        /*        tap_code(RGB_SAI);*/
        /*    } else {*/
        /*        tap_code(RGB_SAD);*/
        /*    }*/
        /*};*/
    }
    return true;
}
