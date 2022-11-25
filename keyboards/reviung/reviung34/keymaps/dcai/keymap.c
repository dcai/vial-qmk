#include <stdio.h>
#include QMK_KEYBOARD_H

enum layer_names { _BASE, _SYM, _NUM, _CFG, _QAZ };

/* #include "combo.c" */

/* enum custom_keycodes { */
/*     MY_SWIT = SAFE_RANGE, */
/*     MY_CPY, */
/* }; */

// Left-hand home row mods
#define MOD_A LCTL_T(KC_A)
#define LT2_S LT(_NUM, KC_S)
#define MOD_D LGUI_T(KC_D)
#define MOD_F LSFT_T(KC_F)
#define MOD_G LALT_T(KC_G)

// Right-hand home row mods
#define MOD_H LALT_T(KC_H)
#define MOD_J RSFT_T(KC_J)
#define MOD_K LGUI_T(KC_K)
#define LT2_L LT(_NUM, KC_L)
#define MOD_SCL LCTL_T(KC_SCLN)

#define MOD_ENT LGUI_T(KC_ENT)
#define MOD_TAB RGUI_T(KC_TAB)

// Layers
#define LT1_BSPC LT(_SYM, KC_BSPC)
#define LT2_SPC LT(_NUM, KC_SPC)
#define LT3_ESC LT(_CFG, KC_ESC)
#define LT3_Q LT(_CFG, KC_Q)
#define LT3_P LT(_CFG, KC_P)
#define LT3_Z LT(_CFG, KC_Z)
#define LT3_SLS LT(_CFG, KC_SLSH)


#define GDOWN LGUI(KC_DOWN)
#define GUP   LGUI(KC_UP)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung34(
  //+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+
         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        MOD_A,   LT2_S,   MOD_D,   MOD_F,   MOD_G,                        MOD_H,   MOD_J,   MOD_K,   LT2_L, MOD_SCL,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        LT3_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, LT3_SLS,
  //+--------+--------+--------+--------+--------+--------+  +--------+--------+--------+--------+--------+--------+
                                          MOD_ENT, LT2_SPC,   LT1_BSPC, MOD_TAB
                                      //+--------+--------+  +--------+--------+
  ),
  [_SYM] = LAYOUT_reviung34(
  //+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+
      KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_MINS, KC_UNDS,  KC_GRV, KC_QUOT,  KC_DQT,                      KC_COLN, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_BSLS, KC_PIPE, KC_TILD,  KC_EQL, KC_PLUS,                      KC_LCBR, KC_RCBR,   KC_LT,   KC_GT, KC_QUES,
  //+--------+--------+--------+--------+--------+--------+  +--------+--------+--------+--------+--------+--------+
                                          _______, _______,    _______, _______
                                      //+--------+--------+  +--------+--------+
  ),
  [_NUM] = LAYOUT_reviung34(
  //+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+
         KC_1,    KC_2,    KC_3, KC_MINS, KC_ASTR,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_4,    KC_5,    KC_6, KC_PLUS, KC_SLSH,                      KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_7,    KC_8,    KC_9,    KC_0,  KC_DOT,                      XXXXXXX, GDOWN,   GUP    , XXXXXXX, XXXXXXX,
  //+--------+--------+--------+--------+--------+--------+  +--------+--------+--------+--------+--------+--------+
                                            TO(3), _______,    _______, _______
                                      //+--------+--------+  +--------+--------+
  ),
  [_CFG] = LAYOUT_reviung34(
  //+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+
      XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //+--------+--------+--------+--------+--------+--------+  +--------+--------+--------+--------+--------+--------+
                                           TO(0), _______,    _______, _______
                                      //+--------+--------+  +--------+--------+
  ),
  [_QAZ] = LAYOUT_reviung34(
  //+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+
         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  //+--------+--------+--------+--------+--------+--------+  +--------+--------+--------+--------+--------+--------+
                                          _______, _______,    _______, _______
                                      //+--------+--------+  +--------+--------+
  ),
};

/*

// clang-format on
const uint16_t PROGMEM vol_down[]   = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM vol_up[]     = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM qw_esc[]     = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM gb_lt3[]     = {KC_G, KC_B, COMBO_END};
const uint16_t PROGMEM qwe_osm_sc[] = {KC_Q, KC_W, KC_E, COMBO_END};
// clang-format off
enum combos {
    ESC,
    LT3,
    VOL_DOWN,
    VOL_UP,
    OSM_SC
};
combo_t key_combos[] = {
    [ESC] = COMBO(qw_esc, KC_ESC),
    [LT3] = COMBO(gb_lt3, TO(3)),
    [VOL_DOWN] = COMBO(vol_down, KC_KB_VOLUME_DOWN),
    [VOL_UP] = COMBO(vol_up, KC_KB_VOLUME_UP),
    [OSM_SC] = COMBO(qwe_osm_sc, OSM(MOD_LCTL | MOD_LSFT)),
};
// clang-format on
*/
