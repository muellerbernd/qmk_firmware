/*
Copyright 2021 Bernd Müller

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

#pragma once

/* USB Device descriptor parameter */
// #define VENDOR_ID 0xFEED
// #define PRODUCT_ID 0x0000
// #define DEVICE_VER 0x0001
// #define MANUFACTURER muellerbernd
// #define PRODUCT sweep

/* key matrix size */
// Rows are doubled-up
// #define MATRIX_ROWS 8
// #define MATRIX_COLS 5
/* Keyboard Matrix Assignments

D3  TXO ┌─■─┐ RAW RAW
D2  RX1 │o o│ GND GND
GND GND │o o│ RST RESET
GND GND │o o│ VCC VCC
D1    2 │o o│ A3   F4
D0    3 │o o│ A2   F5
D4    4 │o o│ A1   F6
C6    5 │o o│ A0   F7
D7    6 │o o│ 15   B1
E6    7 │o o│ 14   B3
B4    8 │o o│ 16   B2
B5    9 │o o│ 10   B6
        └───┘
*/

#define SPLIT_USB_TIMEOUT_POLL 10
#define SPLIT_WATCHDOG_ENABLE
#define SPLIT_WATCHDOG_TIMEOUT 3000
