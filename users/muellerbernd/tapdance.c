enum
{
    TD_R = 0,
    TD_AE,
};

void safe_reset(qk_tap_dance_state_t *state, void *user_data)
{
    if (state->count >= 3)
    {
        // Reset the keyboard if you tap the key more than three times
        reset_keyboard();
        reset_tap_dance(state);
    }
    else
    {
        /* register_code(KC_LSFT); */
    }
}

void dance_cln_reset(qk_tap_dance_state_t *state, void *user_data)
{
    /* if (state->count != 3) { */
    /* unregister_code(KC_LSFT); */
    /* } */
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_AE] = ACTION_TAP_DANCE_DOUBLE(LGUI_T(DE_A), DE_ADIA),

};

