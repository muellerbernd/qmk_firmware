#include QMK_KEYBOARD_H

enum layers { _BASE, _RGB, _ADJ, _TEAMS };

#define T_MUTE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_BASE] = LAYOUT(
        TT(_RGB),TT(_TEAMS), KC_MUTE,
        KC_MPRV, KC_MNXT, LT(_ADJ, KC_MPLY)
    ),
    [_RGB] = LAYOUT(
        _______, _______ , _______,
        _______, _______ , TT(_RGB)
    ),
    [_TEAMS] = LAYOUT(
        _______, _______ , _______ ,
        _______, _______ , TT(_TEAMS)
    ),
    [_ADJ] = LAYOUT(
        _______, _______, QK_BOOT,
        _______, _______, _______
    ),
    // clang-format on
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state)) {
        case 1:
            // Default encoder behavior of Page Up and Down
            clockwise ? tap_code(KC_PGDN) : tap_code(KC_PGUP);
            break;
        default:
            // Change volume when on nav layer
            clockwise ? tap_code(KC_AUDIO_VOL_UP) : tap_code(KC_AUDIO_VOL_DOWN);
            break;
    }
    return true;
}
#ifdef RGBLIGHT_ENABLE

/*Light 4 LEDs, starting with LED 0*/
const rgblight_segment_t PROGMEM my_teams_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 4, HSV_PURPLE});

const rgblight_segment_t PROGMEM my_rgb_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 2, HSV_RED});

/*define layers*/
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(my_teams_layer, my_rgb_layer);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers; // Load layer definitions from memory
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _TEAMS));
    rgblight_set_layer_state(1, layer_state_cmp(state, _RGB));
    /*rgblight_set_layer_state(1, layer_state_cmp(state, _W));*/
    /*rgblight_set_layer_state(2, layer_state_cmp(state, _F));*/
    /*rgblight_set_layer_state(3, layer_state_cmp(state, _M));*/
    return state;
}

#endif
