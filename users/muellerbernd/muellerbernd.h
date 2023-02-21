#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

#include "keymap_german.h"
// Each layer gets a name for readability, which is then used in the keymap
// matrix below. The underscores don't mean anything - you can have a layer
// called STUFF or any other name. Layer names don't all need to be of the same
// length, obviously, and you can also skip them entirely and just use numbers.
enum custom_layers
{
    _COLDH,
    _QWERTZ,
    _LOWER,
    _RAISE,
    _NAV,
    _ADJUST,
    _POINTER
    // _SPECIAL,
};

enum custom_keycodes
{
    QWERTZ = SAFE_RANGE,
    COLDH,
    TABD,
    TABU,
    T_ENT,
    T_DEL,
    T_NAV,
    T_ADAP,
    T_SPC,
    L_SFT,
    R_SFT,
    RET_BSE,
    BACKLIT,
};

// aliases for clarity in layering
#define CTAB LCTL_T(KC_TAB)
#define STAB LSFT(KC_TAB)
#define I3_L LGUI(KC_LEFT)
#define I3_R LGUI(KC_RIGHT)
#define I3_U LGUI(KC_UP)
#define I3_D LGUI(KC_DOWN)
#define ATPI LALT_T(DE_ADIA)
// #define L_SFT LSFT_T(DE_SS)
// #define R_SFT OSM(MOD_LSFT)
#define TABD C(KC_PGUP)
#define TABU C(KC_PGDN)

#define T_ADAP LT(_ADJUST, KC_APP)
// #define T_DEL LT(_LOWER, KC_DEL)
// #define T_ENT LT(_RAISE, KC_ENT)

#define T_BSPC KC_BSPC
#define T_NAV MO(_NAV)
#define T_ADJ MO(_ADJUST)

// clang-format off

// readability
#define ___ KC_NO

#define LAYOUT_kimiko( \
    L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
    L30, L31, L32, L33, L34, L35, L40, R40, R30, R31, R32, R33, R34, R35, \
              L41, L42, L43, L44, L45, R41, R42, R43, R44, R45  \
    ) \
    { \
        { L00, L01, L02, L03, L04, L05 }, \
        { L10, L11, L12, L13, L14, L15 }, \
        { L20, L21, L22, L23, L24, L25 }, \
        { L30, L31, L32, L33, L34, L35 }, \
        { L41, L42, L43, L44, L45, L40 }, \
        { R05, R04, R03, R02, R01, R00 }, \
        { R15, R14, R13, R12, R11, R10 }, \
        { R25, R24, R23, R22, R21, R20 }, \
        { R35, R34, R33, R32, R31, R30 }, \
        { R45, R44, R43, R42, R41, R40 } \
    }
#define LAYOUT_kimiko_wrapper(...)      LAYOUT_kimiko(__VA_ARGS__)

#define LAYOUT_kimiko_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_kimiko_wrapper( \
 KC_ESC ,       KC_1,       KC_2,       KC_3,       KC_4, KC_5,               KC_6,        KC_7,       KC_8,       KC_9,       KC_0, DE_SS,\
  KC_ESC,        K01,        K02,        K03,        K04,  K05,                K06,         K07,        K08,        K09,        K0A, DE_UDIA, \
  CTAB  ,LGUI_T(K11),LALT_T(K12),LCTL_T(K13),LSFT_T(K14),  K15,                K16, LSFT_T(K17),LCTL_T(K18),LALT_T(K19),LGUI_T(K1A), ATPI,\
 KC_LSFT,        K21,        K22,        K23,        K24,  K25, TABD,   TABU,  K26,         K27,        K28,        K29,        K2A, KC_RSFT,\
                              KC_LALT,T_NAV, KC_LGUI,   T_DEL, T_SPC, T_BSPC,  T_ENT,  T_ADAP,   T_NAV, KC_LCTL \
  )
#define LAYOUT_kimiko_base_wrapper(...)       LAYOUT_kimiko_base(__VA_ARGS__)

#define LAYOUT_helidox( \
    L00, L01, L02, L03, L04, L05,           R05, R04, R03, R02, R01, R00, \
    L10, L11, L12, L13, L14, L15,           R15, R14, R13, R12, R11, R10, \
    L20, L21, L22, L23, L24, L25, LT5, RT5, R25, R24, R23, R22, R21, R20, \
                   LT1, LT2, LT3, LT4, RT4, RT3, RT2, RT1 \
    ) \
    { \
        { L00, L01, L02, L03, L04, L05 }, \
        { L10, L11, L12, L13, L14, L15 }, \
        { L20, L21, L22, L23, L24, L25 }, \
        { ___, LT1, LT2, LT3, LT4, LT5 }, \
        { R00, R01, R02, R03, R04, R05 }, \
        { R10, R11, R12, R13, R14, R15 }, \
        { R20, R21, R22, R23, R24, R25 }, \
        { ___, RT1, RT2, RT3, RT4, RT5 }, \
    }

#define LAYOUT_helidox_wrapper(...)      LAYOUT_helidox(__VA_ARGS__)

#define LAYOUT_helidox_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_helidox_wrapper( \
  KC_ESC,        K01,        K02,        K03,        K04,  K05,                K06,         K07,        K08,        K09,        K0A, DE_UDIA, \
  CTAB  ,LGUI_T(K11),LALT_T(K12),LCTL_T(K13),LSFT_T(K14),  K15,                K16, LSFT_T(K17),LCTL_T(K18),LALT_T(K19),LGUI_T(K1A), ATPI,\
 KC_LSFT,        K21,        K22,        K23,        K24,  K25, TABD,   TABU,  K26,         K27,        K28,        K29,        K2A, KC_RSFT,\
                                       T_NAV,    KC_LGUI,T_DEL,T_SPC, T_BSPC,T_ENT,      T_ADAP,T_NAV \
  )
#define LAYOUT_helidox_base_wrapper(...)       LAYOUT_helidox_base(__VA_ARGS__)

#define LAYOUT_split_3x5_2( \
        K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
        K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
        K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
                       K34, K35, K36, K37       \
    ) \
    { \
        { K01, K02, K03, K04, K05 }, \
        { K11, K12, K13, K14, K15 }, \
        { K21, K22, K23, K24, K25 }, \
        { ___, ___, ___, K34, K35}, \
        { K06, K07, K08, K09, K0A }, \
        { K16, K17, K18, K19, K1A }, \
        { K26, K27, K28, K29, K2A }, \
        { K36, K37, ___, ___, ___ }  \
    }
#define LAYOUT_split_3x5_2_wrapper(...)      LAYOUT_split_3x5_2(__VA_ARGS__)
#define LAYOUT_split_3x5_2_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_split_3x5_2_wrapper( \
    K01,    K02,     K03,      K04,     K05,                        K06,     K07,     K08,     K09,     K0A, \
    LGUI_T(K11),  LALT_T(K12), LCTL_T(K13),LSFT_T(K14), K15,K16, LSFT_T(K17),LCTL_T(K18),LALT_T(K19),LGUI_T(K1A), \
    K21, K22, K23,      K24,     K25,                        K26,     K27,     K28,     K29, K2A, \
                                        T_DEL,  T_SPC,        T_BSPC,  T_ENT \
  )
#define LAYOUT_3x5_2_base_wrapper(...)       LAYOUT_split_3x5_2_base(__VA_ARGS__)


#define LAYOUT_PLANCK_grid( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b \
) \
{ \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b }, \
    { k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b } \
}

#define LAYOUT_PLANCK_grid_wrapper(...)      LAYOUT_PLANCK_grid(__VA_ARGS__)
#define LAYOUT_PLANCK_grid_hr_base( \
    k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, \
    k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, \
    k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a \
) \
LAYOUT_PLANCK_grid_wrapper( \
     KC_ESC , k01        , k02        , k03        , k04        , k05  , k06   , k07        , k08        , k09        , k0a        , DE_UDIA , \
     CTAB   , LGUI_T(k11), LALT_T(k12), LCTL_T(k13), LSFT_T(k14), k15  , k16   , LSFT_T(k17), LCTL_T(k18), LALT_T(k19), LGUI_T(k1a), ATPI , \
     KC_LSFT, k21        , k22        , k23        , k24        , k25  , k26   , k27        , k28        , k29        , k2a        , KC_RSFT , \
     BACKLIT, KC_LCTL    , T_ADAP     , KC_LGUI    , T_DEL      , T_SPC, T_BSPC, T_ENT      , KC_LEFT    , KC_DOWN    , KC_UP      , KC_RIGHT \
)
#define LAYOUT_PLANCK_grid_hr_base_wrapper(...)       LAYOUT_PLANCK_grid_hr_base(__VA_ARGS__)
// clang-format on

/* Qwerty Layer */
#define QWERTZ_L1 DE_Q, DE_W, DE_E, DE_R, DE_T
#define QWERTZ_L2 DE_A, DE_S, DE_D, DE_F, DE_G
#define QWERTZ_L3 DE_Y, DE_X, DE_C, DE_V, DE_B
#define QWERTZ_R1 DE_Z, DE_U, DE_I, DE_O, DE_P
#define QWERTZ_R2 DE_H, DE_J, DE_K, DE_L, DE_PLUS
#define QWERTZ_R3 DE_N, DE_M, DE_COMM, DE_DOT, DE_MINS

#define COLDH_L1 DE_Q, DE_W, DE_F, DE_P, DE_B
#define COLDH_L2 DE_A, DE_R, DE_S, DE_T, DE_G
#define COLDH_L3 DE_Z, DE_X, DE_C, DE_D, DE_V
#define COLDH_R1 DE_J, DE_L, DE_U, DE_Y, DE_PLUS
#define COLDH_R2 DE_M, DE_N, DE_E, KC_I, DE_O
#define COLDH_R3 DE_K, DE_H, DE_COMM, DE_DOT, DE_MINS

#define LOWER_L1 KC_F9, KC_F10, KC_F11, KC_F12, DE_ADIA
#define LOWER_L2 KC_F5, KC_F6, KC_F7, KC_F8, DE_UDIA
#define LOWER_L3 KC_F1, KC_F2, KC_F3, KC_F4, DE_ODIA
#define LOWER_R1 DE_COLN, KC_7, KC_8, KC_9, DE_DOT
#define LOWER_R2 DE_SCLN, KC_4, KC_5, KC_6, DE_COMM
#define LOWER_R3 KC_0, KC_1, KC_2, KC_3, DE_PLUS

#define RAISE_L1 DE_AT, DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC
#define RAISE_L2 DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR
#define RAISE_L3 DE_HASH, DE_TILD, DE_PIPE, DE_DLR, DE_EURO
#define RAISE_R1 DE_EXLM, DE_LABK, DE_RABK, DE_EQL, DE_AMPR
#define RAISE_R2 DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_ACUT
#define RAISE_R3 DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_GRV

#define NAV_L1 KC_ESC, KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_U
#define NAV_L2 KC_TAB, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D
#define NAV_L3 STAB,   KC_BTN2, KC_BTN3, KC_BTN1, _______
#define NAV_R1 TABD,   KC_PGUP,   KC_UP, KC_PGDN, TABU
#define NAV_R2 KC_HOME,KC_LEFT, KC_DOWN,KC_RIGHT, KC_END
#define NAV_R3 _______,I3_L   , I3_U   , I3_D   , I3_R

#define ADJUST_L1 RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI
#define ADJUST_L2 XXXXXXX,RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD
#define ADJUST_L3 KC_CAPS, XXXXXXX, XXXXXXX, RGB_SPI, RGB_SPD
#define ADJUST_R1 KC_APP , KC_MPRV, KC_VOLU, KC_MNXT, KC_MPLY
#define ADJUST_R2 XXXXXXX, KC_BRID, KC_VOLD, KC_BRIU, KC_MUTE
#define ADJUST_R3 QWERTZ , COLDH  , _______, _______, KC_CAPS

#define POINTER_L1 XXXXXXX, KC_BTN2, KC_BTN3, KC_BTN1, XXXXXXX
#define POINTER_L2 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define POINTER_L3 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define POINTER_R1 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define POINTER_R2 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define POINTER_R3 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#endif // USERSPACE
