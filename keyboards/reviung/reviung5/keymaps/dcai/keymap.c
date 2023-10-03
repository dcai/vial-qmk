/* Copyright 2021 gtips
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names { _BASE, _LOWER, _RAISE };

#define L1_RIGHT LT(_LOWER, KC_RIGHT)
#define L2_UP LT(_RAISE, KC_UP)

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE]  = {ENCODER_CCW_CW(KC_RIGHT, KC_LEFT)},
    [_LOWER] = {ENCODER_CCW_CW(RGB_HUD, RGB_HUI)},
    [_RAISE] = {ENCODER_CCW_CW(RGB_HUD, RGB_HUI)},
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT_reviung5(KC_MUTE, KC_LEFT, KC_DOWN, L2_UP, L1_RIGHT),
    /* Lower */
    [_LOWER] = LAYOUT_reviung5(_______, _______, _______, _______, _______),
    /* Higher */
    [_RAISE] = LAYOUT_reviung5(_______, _______, _______, _______, _______)

};
