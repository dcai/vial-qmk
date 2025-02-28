/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include QMK_KEYBOARD_H

enum layer_names { _BASE, _SYM, _NUM, _CFG };

#include "combo.c"

enum custom_keycodes {
    MY_SWIT = SAFE_RANGE,
    MY_CPY,
};

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
#define MOD_TAB LALT_T(KC_TAB)

// Layers
#define LT1_BSPC LT(_SYM, KC_BSPC)
#define LT2_SPC LT(_NUM, KC_SPC)
#define LT3_ESC LT(_CFG, KC_ESC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
  //+--------+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+--------+
      LT3_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, LT3_ESC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LT3_ESC,   MOD_A,   LT2_S,   MOD_D,   MOD_F,   MOD_G,                        MOD_H,   MOD_J,   MOD_K,   LT2_L, MOD_SCL, LT3_ESC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LT3_ESC,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, LT3_ESC,
  //+--------+--------+--------+--------+--------+--------+--------+  +--------+--------+--------+--------+--------+--------+--------+
                                          KC_LGUI, MOD_ENT, LT2_SPC,   LT1_BSPC, MOD_TAB,MO(_CFG)
                                      //+--------+--------+--------+  +--------+--------+--------+

  ),

  [_SYM] = LAYOUT_split_3x6_3(
  //+--------+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+--------+
      XXXXXXX, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_MINS, KC_UNDS,  KC_GRV, KC_QUOT,  KC_DQT,                      KC_COLN, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_BSLS, KC_PIPE, KC_TILD,  KC_EQL, KC_PLUS,                      KC_LCBR, KC_RCBR,   KC_LT,   KC_GT, KC_QUES, XXXXXXX,
  //+--------+--------+--------+--------+--------+--------+--------+  +--------+--------+--------+--------+--------+--------+--------+
                                          XXXXXXX,  KC_ENT,  KC_SPC,    KC_BSPC,  KC_TAB, XXXXXXX
                                      //+--------+--------+--------+  +--------+--------+--------+
  ),

  [_NUM] = LAYOUT_split_3x6_3(
  //+--------+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+--------+
      XXXXXXX,    KC_1,    KC_2,    KC_3, KC_MINS, KC_ASTR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_4,    KC_5,    KC_6, KC_PLUS, KC_SLSH,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DOT,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, XXXXXXX,
  //+--------+--------+--------+--------+--------+--------+--------+  +--------+--------+--------+--------+--------+--------+--------+
                                          XXXXXXX,  KC_ENT,  KC_SPC,    KC_BSPC,  KC_TAB, XXXXXXX
                                      //+--------+--------+--------+  +--------+--------+--------+
  ),

  [_CFG] = LAYOUT_split_3x6_3(
  //+--------+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+--------+
      XXXXXXX, XXXXXXX, RGB_TOG, RGB_VAI, RGB_HUI,  MY_CPY,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_CAPS, RGB_MOD, RGB_VAD, RGB_SAI, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //+--------+--------+--------+--------+--------+--------+--------+  +--------+--------+--------+--------+--------+--------+--------+
                                          XXXXXXX,  KC_ENT,  KC_SPC,    KC_BSPC,  KC_TAB, XXXXXXX
                                      //+--------+--------+--------+  +--------+--------+--------+
  )
};
// clang-format on

char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ',  ' ', ' ', 'a',  'b', 'c', 'd', 'e', 'f', 'g', 'h',
    'i', 'j',  'k', 'l', 'm',  'n', 'o', 'p', 'q', 'r', 's', 't',
    'u', 'v',  'w', 'x', 'y',  'z', '1', '2', '3', '4', '5', '6',
    '7', '8',  '9', '0', 'R',  'E', 'B', 'T', '_', '-', '=', '[',
    ']', '\\', '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
    char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }
    if (keycode < 60) {
        name = code_to_name[keycode];
    }

    // update keylog
    snprintf(keylog_str, sizeof(keylog_str), "%dx%d\n\n=>%c",
             record->event.key.row, record->event.key.col, name);
}

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180; // flips the display 180 degrees if offhand
    }
    return rotation;
}

void oled_render_layer_state(void) {
    bool isnum     = layer_state_is(_NUM) & !layer_state_is(_CFG);
    bool issymbols = layer_state_is(_SYM) & !layer_state_is(_CFG);
    bool iscfg     = layer_state_is(_CFG);

    if (isnum) {
        oled_write_P(PSTR("NUM "), false);
    } else if (issymbols) {
        oled_write_P(PSTR("SYM "), false);
    } else if (iscfg) {
        oled_write_P(PSTR("CFG "), false);
    } else {
        oled_write_P(PSTR("BASE"), false);
    }
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a,
        0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0,
        0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab,
        0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xc0, 0xc1,
        0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc,
        0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_write_ln_P(PSTR("\n\n"), false);
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

#endif // OLED_ENABLE
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }
    switch (keycode) {
        case MY_SWIT:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("`"));
            } else {
            }
            break;

        case MY_CPY:
            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_BTN1) SS_TAP(X_BTN1)
                                SS_UP(X_LALT) SS_LGUI("c"));
            }
            break;
    }
    return true;
};
