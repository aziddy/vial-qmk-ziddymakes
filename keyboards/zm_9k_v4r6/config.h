/* Copyright 2024 Ziddymakes <ziddy@ziddymakes.com>
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

#pragma once

// Flash configuration - 2MB (16Mbit) flash chip: W25Q16JVUXIQ
#define PICO_FLASH_SIZE_BYTES (2 * 1024 * 1024)

// EEPROM emulation configuration - Maximize VIAL macro/keymap storage
// With 2MB flash, we can use the maximum 64KB EEPROM size
// (firmware for a 9-key macropad is well under 1MB, leaving plenty of room)
#define WEAR_LEVELING_LOGICAL_SIZE 65536    // 64KB logical EEPROM (maximum allowed by QMK)
#define WEAR_LEVELING_BACKING_SIZE 131072   // 128KB backing storage (2x logical size for wear leveling)

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.
