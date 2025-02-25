/* Copyright 2025 Ziddy Makes
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

#include "quantum.h"
#include "ws2812.h"
#include "ws2812_custom.h"
#include "rgb_matrix.h"

#ifdef RGBLIGHT_ENABLE
#    include "rgblight.h"
#endif

// This is a custom driver that uses the WS2812 driver for RGB Matrix
// It's designed to work alongside the regular WS2812 driver for RGBlight

#ifndef WS2812_MATRIX_PIN
#    define WS2812_MATRIX_PIN GP10  // Default pin for the RGB Matrix
#endif

// Use RGB_MATRIX_LED_COUNT which is defined by the RGB Matrix system
static rgb_led_t led_state[RGB_MATRIX_LED_COUNT];

static void ws2812_custom_init(void) {
    // Initialize by clearing all LEDs
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        led_state[i].r = 0;
        led_state[i].g = 0;
        led_state[i].b = 0;
#ifdef RGBW
        led_state[i].w = 0;
#endif
    }
}

static void ws2812_custom_flush(void) {
    // Send the data directly to the LEDs
    // The ws2812_setleds function expects rgb_led_t type, which is what we're using
    ws2812_setleds(led_state, RGB_MATRIX_LED_COUNT);
}

static void ws2812_custom_set_color(int index, uint8_t r, uint8_t g, uint8_t b) {
    if (index < 0 || index >= RGB_MATRIX_LED_COUNT) {
        return;
    }

    led_state[index].r = r;
    led_state[index].g = g;
    led_state[index].b = b;
#ifdef RGBW
    led_state[index].w = 0;
#endif
}

static void ws2812_custom_set_color_all(uint8_t r, uint8_t g, uint8_t b) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        ws2812_custom_set_color(i, r, g, b);
    }
}

const rgb_matrix_driver_t rgb_matrix_driver = {
    .init          = ws2812_custom_init,
    .flush         = ws2812_custom_flush,
    .set_color     = ws2812_custom_set_color,
    .set_color_all = ws2812_custom_set_color_all,
}; 