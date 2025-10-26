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

// Define GPIO pin for backlight MOSFET control
#define BACKLIGHT_PIN GP18
// Track backlight state
static bool backlight_state = false;

void keyboard_pre_init_user(void) {
    // Set LED IO as outputs
    // setPinOutput(BACKLIGHT_PIN);
    // writePinLow(BACKLIGHT_PIN);  // Start with MOSFET ON (HIGH overcomes the 10k pull-down)
    // Custom mode: Output with explicitly no pulls, standard drive strength
    palSetLineMode(BACKLIGHT_PIN, 
        PAL_RP_IOCTRL_FUNCSEL_SIO |  // Use SIO function (standard I/O)
        PAL_RP_GPIO_OE |              // Output enable
        PAL_RP_PAD_DRIVE12             // 4mA drive strength (adequate for MOSFET gate)
        // Note: NOT including PAL_RP_PAD_PUE or PAL_RP_PAD_PDE
    );
    
    // Initialize to LOW immediately after configuration
    writePinLow(BACKLIGHT_PIN);
    writePinLow(BACKLIGHT_PIN);
}
// // Initialize the backlight pin
void keyboard_post_init_user(void) {

}

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
        KC_A,     KC_P,     KC_RBRC,  KC_ENTER, KC_BSPC,
        MO(1),    KC_X,     KC_V,     KC_B,     KC_VOLU,
        KC_SPACE, KC_Z,     KC_C,     KC_N,     KC_M,
        KC_LGUI,  KC_LSFT,  KC_F,     KC_J,     KC_K
    ),
    [1] = LAYOUT_zm_phone_keyboard(
        BL_TOGG,        KC_2,            KC_3,             LSFT(KC_MINUS),  LSFT(KC_EQUAL),
        KC_1,           KC_4,            KC_SLASH,         LSFT(KC_SCLN),   LSFT(KC_QUOTE),
        KC_SLSH,        KC_5,            LSFT(KC_9),       LSFT(KC_0),      KC_MINUS,
        LSFT(KC_8),     LSFT(KC_2),      KC_RBRC,          QK_BOOT,         KC_BSPC,
        KC_TRNS,        KC_8,            LSFT(KC_SLASH),   LSFT(KC_1),      KC_VOLU,
        KC_SPACE,       KC_7,            KC_9,             KC_COMM,         KC_DOT,
        KC_0,           KC_LBRC,         KC_6,             KC_SCLN,         KC_K
    )
};

// Intercept BL_TOGG keycode to control GPIO18
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BL_TOGG:
            if (record->event.pressed) {
                // Toggle the state and write it to the pin
                backlight_state = !backlight_state;
                if (backlight_state) {
                    writePinHigh(BACKLIGHT_PIN);  // Turn MOSFET ON
                } else {
                    writePinLow(BACKLIGHT_PIN);   // Turn MOSFET OFF
                    writePinLow(BACKLIGHT_PIN);
                }// Tap the Q key to toggle the backlight
            }
            return false;  // Skip further processing
        default:
            return true;   // Process all other keycodes normally
    }
}