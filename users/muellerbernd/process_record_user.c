uint8_t mod_state;
uint8_t base_layer;

// static uint16_t key_timer;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
//     if (record->event.pressed)
//     {
#ifdef KEYLOGGER_ENABLE
    process_record_user_oled(keycode, record);
#endif
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
    //     }
    switch (keycode) {
        case QWERTZ:
            if (record->event.pressed) {
                layer_clear();
                set_single_persistent_default_layer(_QWERTZ);
                base_layer = _QWERTZ;
            }
            return false;
            break;
        case COLDH:
            if (record->event.pressed) {
                layer_clear();
                set_single_persistent_default_layer(_COLDH);
                base_layer = _COLDH;
            }
            return false;
            break;
            // case T_ENT:
            //     if (record->event.pressed) { // Key Down, start timer and turn on the held layer
            //         key_timer = timer_read();
            //         layer_on(_RAISE);
            //         update_tri_layer(_LOWER, _RAISE, _ADJUST);
            //     } else {               // this means the key was just released. Was it a tap or hold?
            //         layer_off(_RAISE); // Turn hold layer off, we want this off
            //                            // regardless
            //         update_tri_layer(_LOWER, _RAISE, _ADJUST);
            //         if (timer_elapsed(key_timer) < TAPPING_TERM + 50) { // 150 = Time in milliseconds to consider a tap
            //             // if (IS_LAYER_ON(TAP_LAYER))
            //             // { // It was a tap: Toggle the tap layer
            //             //     layer_off(TAP_LAYER);
            //             // }
            //             // else
            //             // {
            //             //     layer_on(TAP_LAYER);
            //             // }
            //             tap_code(KC_ENT);
            //         } else {
            //             // Hold, do nothing
            //         }
            //     }
            //     return false;
            //     break;
            // case T_DEL:
            //     if (record->event.pressed) { // Key Down, start timer and turn on the held layer
            //         key_timer = timer_read();
            //         layer_on(_LOWER);
            //         update_tri_layer(_LOWER, _RAISE, _ADJUST);
            //     } else {               // this means the key was just released. Was it a tap or hold?
            //         layer_off(_LOWER); // Turn hold layer off, we want this off
            //                            // regardless
            //         update_tri_layer(_LOWER, _RAISE, _ADJUST);
            //         if (timer_elapsed(key_timer) < TAPPING_TERM + 50) { // 150 = Time in milliseconds to consider a tap
            //             // if (IS_LAYER_ON(TAP_LAYER))
            //             // { // It was a tap: Toggle the tap layer
            //             //     layer_off(TAP_LAYER);
            //             // }
            //             // else
            //             // {
            //             //     layer_on(TAP_LAYER);
            //             // }
            //             tap_code(KC_DEL);
            //         } else {
            //             // Hold, do nothing
            //         }
            //     }
            //     return false;
            //     break;
#ifdef OLED_ENABLE
#    ifdef LUNA_ENABLE
        case KC_BSPC:
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
            break;
        case T_SPC:
            if (record->event.pressed) {
                isJumping  = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            break;
#    endif
#endif // OLED_ENABLE
        case RET_BSE:
            if (record->event.pressed) { // Key Down, start timer and turn on the held layer
                layer_move(base_layer);
            } else {
                layer_move(base_layer); // Turn hold layer off, we want this off
            }
            return false;
            break;
#ifdef BACKLIGHT_ENABLE
        case BACKLIT:
            if (record->event.pressed) {
                /** register_code(KC_RSFT); */
                backlight_step();
                // PLAY_SONG(plover_song);
            }
            return false;
            break;
#endif
    }

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
