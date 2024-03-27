/* Copyright 2021 Bernd Müller
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

#include "sweep.h"

#ifdef RGB_MATRIX_ENABLE

// Logical Layout
// Columns
// Left
// 0  1  2  3  4  5
//                   ROWS
// 25 24 19 18 11 10   0
//    03    02    01
// 26 23 20 17 12 09   1
//    04    05    06
// 27 22 21 16 13 08   2
//
//          15 14 07   3
//
// Right
// 0  1  2  3  4  5
//                    ROWS
// 25 24 19 18 11 10   4
//    03    02    01
// 26 23 20 17 12 09   5
//    04    05    06
// 27 22 21 16 13 08   6
//
//          15 14 07   7
//
// Physical Layout
// Columns
// 0  1  2  3  4     5  6  7  8  9
//                                           ROWS
// 24 19 18 11 10    10 11 18 19 24     0
// 23 20 17 12 09    09 12 17 20 23     1
// 22 21 16 13 08    08 13 16 21 22     2
//          14 07    07 14                3

led_config_t g_led_config = {
    {// Key Matrix to LED Index
     {4, 3, 2, 1, 0},
     {5, 6, 7, 8, 9},
     {14, 13, 12, 11, 10},
     {NO_LED, NO_LED, NO_LED, 15, 16},
     {17, 18, 19, 20, 21},
     {26, 25, 24, 23, 22},
     {27, 28, 29, 30, 31},
     {33, 32, NO_LED, NO_LED,NO_LED}},
    {// LED Index to Physical Position
     {224, 0},   {168, 0},   {112, 0},   {56, 0},  {  0,  0},
     {0, 9},    {56, 9},  {112, 9}, {168, 9},  {224, 9},
     {224, 18}, {168, 18},  {112, 18},  {56, 18},  {0, 18},
                                       {168, 27},  {224, 27},
     {224,36},   {168,36},   {112,36},   {56,36},  {  0,36},
     {0, 45},    {56, 45},  {112, 45}, {168, 45},  {224, 45},
     {224, 54}, {168, 54},  {112, 54},  {56, 54},  {0, 54},
                                       {168, 64},  {224, 64}
     // {208, 42}, {208, 24}, {208, 7},  {224, 7},  {224, 24}, {224, 41}
    },
    {// LED Index to Flag
     1,2,3,2,1,
     1,2,3,2,1,
     1,2,3,2,1,
     2,1,
     1,2,3,2,1,
     1,2,3,2,1,
     1,2,3,2,1,
     2,1
    }};
#endif
