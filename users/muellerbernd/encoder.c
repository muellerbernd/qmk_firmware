#ifdef ENCODER_ENABLE
#   ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_DEFAULT_LAYER_1] = { { KC_DOWN, KC_UP   } },
    [_DEFAULT_LAYER_2] = { { _______, _______ } },
    [_DEFAULT_LAYER_3] = { { _______, _______ } },
    [_DEFAULT_LAYER_4] = { { _______, _______ } },
    [_GAMEPAD]         = { { _______, _______ } },
    [_DIABLO]          = { { _______, _______ } },
    [_MOUSE]           = { { KC_WH_D, KC_WH_U } },
    [_MEDIA]           = { { _______, _______ } },
    [_RAISE]           = { { KC_VOLD, KC_VOLU } },
    [_LOWER]           = { { RGB_MOD, RGB_RMOD} },
    [_ADJUST]          = { { CK_DOWN, CK_UP   } },
};
// clang-format on
#    else
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state)) {
        case _RAISE:
            clockwise ? rgblight_step() : rgblight_step_reverse();
            break;
        case _LOWER:
            clockwise ? rgb_matrix_step() : rgb_matrix_step_reverse();
            break;
        default:
            clockwise ? tap_code(KC_VOLD) : tap_code(KC_VOLU);
            break;
    }
    return false;
}
#    endif  // ENCODER_ENABLE

#endif
