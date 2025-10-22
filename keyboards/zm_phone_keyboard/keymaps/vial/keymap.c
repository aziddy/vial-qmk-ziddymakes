/* Copyright 2025 - Ziddy Makes™ - Alex Zidros
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap _BL: (Base Layer) Phone Keyboard Layout
     * ,---------------------------------.
     * |  1  |  2  |  3  |  4  |  5     |
     * |---------------------------------|
     * |  Q  |  W  |  E  |  R  |  T     |
     * |---------------------------------|
     * |  A  |  S  |  D  |  F  |  G     |
     * |---------------------------------|
     * |  Z  |  X  |  C  |  V  |  B     |
     * |---------------------------------|
     * | ESC | TAB | SPC | ENT | BSPC   |
     * |---------------------------------|
     * |  6  |  7  |  8  |  9  |  0     |
     * |---------------------------------|
     * |  Y  |  U  |  I  |  O  |  P     |
     * `---------------------------------'
     */
    [0] = LAYOUT_zm_phone_keyboard(
        KC_Q,     KC_E,     KC_R,     KC_U,     KC_O,
        KC_W,     KC_S,     KC_G,     KC_H,     KC_L,
        KC_SLSH,  KC_D,     KC_T,     KC_Y,     KC_I,
        KC_A,     KC_P,     KC_RBRC,  KC_1,     KC_BSPC,
        KC_DOT,   KC_X,     KC_V,     KC_B,     KC_VOLU,
        KC_SPACE, KC_Z,     KC_C,     KC_N,     KC_M,
        KC_BSLS,  KC_LBRC,  KC_F,     KC_J,     KC_K
    )