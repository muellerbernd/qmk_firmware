#pragma once
#include "quantum.h"
#include "keymap_german.h"

// enum for combos.
enum combos {
    ss2,
    ss3,
    COMBO_LENGTH,
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM ss2_combo[] = {DE_COMM, LALT_T(DE_S), COMBO_END};
const uint16_t PROGMEM ss3_combo[] = {DE_COMM, LCTL_T(DE_S), COMBO_END};

combo_t key_combos[] = {
    [ss2] = COMBO(ss2_combo, DE_SS),
    [ss3] = COMBO(ss3_combo, DE_SS),
};
