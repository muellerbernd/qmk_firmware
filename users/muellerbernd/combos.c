enum combos
{
    C_ESC,
    C_TAB,
    C_NAV1,
    C_NAV2,
};

const uint16_t PROGMEM esc_combo[] = {KC_SPC, KC_BSPC, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {DE_COMM, KC_BSPC, COMBO_END};
// const uint16_t PROGMEM nav1_combo[] = {LT(_RAISE, KC_ENT), KC_BSPC, COMBO_END};
// const uint16_t PROGMEM nav2_combo[] = {LT(_LOWER, KC_DEL), KC_SPC, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [C_ESC] = COMBO(esc_combo, KC_ESC),
    [C_TAB] = COMBO(tab_combo, KC_TAB),
    // [C_NAV1] = COMBO(nav1_combo, MO(_NAV)),
    // [C_NAV2] = COMBO(nav2_combo, MO(_NAV)),
};

