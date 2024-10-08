// Copyright 2020 Worldspawn (@worldspawn00)
// Copyright 2022 Hunter Haugen (@hunner)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define LCTL_Z   MT(MOD_LCTL, KC_Z)
#define LALT_X   MT(MOD_LALT, KC_X)
#define ONE_C    LT(1, KC_C)
#define TWO_V    LT(2, KC_V)
#define RGUI_B   MT(MOD_RGUI, KC_B)
#define RALT_N   MT(MOD_RALT, KC_N)
#define RCTL_M   MT(MOD_RCTL, KC_M)
#define LSFT_SPC MT(MOD_LSFT, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   ,
        KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   ,
        LCTL_Z , LALT_X , ONE_C  , TWO_V  , RGUI_B , RALT_N , RCTL_M ,
        LSFT_SPC
    ),
    [1] = LAYOUT(
        KC_ESC , KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_BSPC,
        KC_TAB , UG_TOGG, UG_VALD, UG_VALU, UG_NEXT, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT,
        KC_LCTL, KC_LALT, _______, MO(3)  , KC_RGUI, KC_RALT, KC_RCTL,
        XXXXXXX
    ),
    [2] = LAYOUT(
        KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   ,
        KC_GRV , KC_BSLS, KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, KC_SCLN, KC_QUOT, KC_ENT ,
        KC_LCTL, KC_LALT, MO(3)  , _______, KC_COMM, KC_DOT , KC_SLSH,
        XXXXXXX
    ),
    [3] = LAYOUT(
        KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10  ,
        KC_F11 , KC_F12 , UG_SPDD, UG_SPDU, UG_HUEU, UG_HUED, UG_SATU, UG_SATD, KC_DEL,
        KC_LCTL, KC_LALT, _______, _______, KC_RGUI, KC_RALT, KC_RCTL,
        XXXXXXX
    )
};
