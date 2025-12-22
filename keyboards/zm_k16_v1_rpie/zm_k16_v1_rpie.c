/* Copyright 2020 Ungodly Design <hello@ungodly.design>
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
#include "zm_k16_v1_rpie.h"

void keyboard_post_init_kb(void) {
    // Set GP8 as output for LED
    setPinOutput(GP8);

    // Flash LED 3 times on bootup
    for (int i = 0; i < 3; i++) {
        writePinHigh(GP8);
        wait_ms(300);
        writePinLow(GP8);
        wait_ms(300);
    }

    keyboard_post_init_user();
}