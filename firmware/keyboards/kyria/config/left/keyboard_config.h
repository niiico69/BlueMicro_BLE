/*
Copyright 2018 <Pierre Constantineau>

3-Clause BSD License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#ifndef KEYBOARD_CONFIG_H
#define KEYBOARD_CONFIG_H
#include "hardware_config.h"
/*
#define COL2ROW       1
#define ROW2COL       0

#define LEFT 0
#define RIGHT 1
#define MASTER 2
*/
#define KEYBOARD_SIDE LEFT


#define DEVICE_NAME_R                       "Kyria_R"                      /**< Name of device. Will be included in the advertising data. */
#define DEVICE_NAME_L                       "Kyria_L"                      /**< Name of device. Will be included in the advertising data. */
#define DEVICE_NAME_M                       "KyriaBLE"                     /**< Name of device. Will be included in the advertising data. */
#define DEVICE_MODEL                        "Kyria"                        /**< Name of device. Will be included in the advertising data. */
#define MANUFACTURER_NAME                   "splitkb"                      /**< Manufacturer. Will be passed to Device Information Service. */

#if KEYBOARD_SIDE == RIGHT
#define KEYMAP( \
              R06, R07, R08, R09, R10, R11, \
              R18, R19, R20, R21, R22, R23, \
    R32, R33, R34, R35, R36, R37, R38, R39, \
    R45, R46, R47, R48, R49 \
  ) \
  { \
    { KC_NO, KC_NO, R06,   R07,   R08,   R09,   R10,   R11   }, \
    { KC_NO, KC_NO, R18,   R19,   R20,   R21,   R22,   R23   }, \
    { R32,   R33,   R34,   R35,   R36,   R37,   R38,   R39   }, \
    { R45,   R46,   R47,   R48,   R49,   KC_NO, KC_NO, KC_NO } \
  }
#else
#define KEYMAP( \
    L00, L01, L02, L03, L04, L05, \          
    L12, L13, L14, L15, L16, L17, \         
    L24, L25, L26, L27, L28, L29, L30, L31, \
                   L40, L41, L42, L43, L44) \
  { \
    { KC_NO, KC_NO, L05,   L04,   L03,   L02,   L01,   L00   }, \
    { KC_NO, KC_NO, L17,   L16,   L15,   L14,   L13,   L12   }, \
    { L31,   L30,   L29,   L28,   L27,   L26,   L25,   L24   }, \
    { L44,   L43,   L42,   L41,   L40,   KC_NO, KC_NO, KC_NO } \
  } 

#endif

#endif /* KEYBOARD_CONFIG_H */
