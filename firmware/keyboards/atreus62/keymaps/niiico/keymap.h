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
#include <stdint.h>
#include "hid_keycodes.h"
#include "keyboard_config.h"
#include "advanced_keycodes.h"
#include "Key.h"
#include <array>

#ifndef KEYMAP_H
#define KEYMAP_H

#define KC_CAP_D MOD(MOD_LSHIFT, KC_D)

#define _AZERTY_BEPO 0
#define _BEPO  1

void setupKeymap();
extern std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix;

/*
Blocks for each of the four major keyboard layouts
Organized so we can quickly adapt and modify all of them
at once, rather than for each keyboard, one at a time.
And this allows for much cleaner blocks in the keymaps.
For instance Tap/Hold for Control on all of the layouts

NOTE: These are all the same length.  If you do a search/replace
  then you need to add/remove underscores to keep the
  lengths consistent.
*/
#define __________________BEPO_L0__________________        BP_DQOT,    BP_LGIL,    BP_RGIL, BP_LPRN, BP_RPRN
#define __________________BEPO_L1__________________        BP_B,       BP_E_ACUTE, BP_P,    BP_O,    BP_E_GRAVE
#define __________________BEPO_L2__________________        BP_A,       BP_U,       BP_I,    BP_E,    BP_COMMA
#define __________________BEPO_L3__________________        BP_A_GRAVE, BP_Y,       BP_X,    BP_DOT,  BP_K

#define __________________BEPO_R0__________________        BP_AT,   BP_PLUS,  BP_MINUS, BP_SLASH, BP_ASTR
#define __________________BEPO_R1__________________        BP_DCRC, BP_V,     BP_D,     BP_L,     BP_J
#define __________________BEPO_R2__________________        BP_C,    BP_T,     BP_S,     BP_R,     BP_N
#define __________________BEPO_R3__________________        BP_APOS, BP_Q,     BP_G,     BP_H,     BP_F

#define ______________AZERTY_BEPO_L0_______________        FR_QUOT,         FR_LESS, FR_GRTR, FR_LPRN, FR_RPRN
#define ______________AZERTY_BEPO_L1_______________        KC_B,            FR_EACU, KC_P,    KC_O,    FR_EGRV
#define ______________AZERTY_BEPO_L2_______________        FR_A,            KC_U,    KC_I,    KC_E,    FR_COMM
#define ______________AZERTY_BEPO_L3_______________        LALT_T(FR_AGRV), KC_Y,	 KC_X,    FR_DOT,  KC_K

#define ______________AZERTY_BEPO_R0_______________        FR_AT,   FR_PLUS, FR_MINS, FR_SLSH, FR_ASTR
#define ______________AZERTY_BEPO_R1_______________        KC_LBRC,	KC_V,    KC_D,    KC_L,    KC_J
#define ______________AZERTY_BEPO_R2_______________        KC_C,    KC_T,    KC_S,    KC_R,    KC_N
#define ______________AZERTY_BEPO_R3_______________        FR_APOS,	FR_Q,    KC_G,    KC_H,    RALT_T(KC_F)

#define _________________QWERTY_L1_________________        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________        KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH

#define ________________NUMBER_LEFT________________       BP_1,  BP_2,  BP_3,  BP_4,  BP_5
#define ________________NUMBER_RIGHT_______________       BP_6,  BP_7,  BP_8,  BP_9,  BP_0
#define _________________FUNC_ROW1_________________       KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
#define _________________FUNC_ROW2_________________       KC_F6, KC_F7, KC_F8, KC_F9, KC_F10

#define ___________________BLANK___________________        _______, _______, _______, _______, _______


#define _________________SYMBL_L1__________________        BP_DQOT,	BP_LGIL, BP_RGIL, BP_LPRN, BP_RPRN
#define _________________SYMBL_L2__________________        BP_MDSH, BP_LABK, BP_RABK, BP_LBRC, BP_RBRC
#define _________________SYMBL_L3__________________        BP_BSLS, BP_LCBR, BP_RCBR, BP_LCBR, BP_RCBR

#define _________________SYMBL_R1__________________        BP_AT,      BP_PLUS, BP_MINS, BP_SLSH, BP_ASTR
#define _________________SYMBL_R2__________________        BP_PERCENT, BP_AMPR, BP_PIPE, BP_BSLS,   KC_NO
#define _________________SYMBL_R3__________________        BP_GRV,     KC_PSCR, KC_SLCK, KC_PAUS,   KC_NO

#define _________________NUMBR_L1__________________        ________________NUMBER_LEFT________________
#define _________________NUMBR_L2__________________        _________________FUNC_ROW1_________________
#define _________________NUMBR_L3__________________        _________________FUNC_ROW2_________________

#define _________________NUMBR_R1__________________        ________________NUMBER_RIGHT_______________
#define _________________NUMBR_R2__________________        BP_PERCENT, BP_4, BP_5, BP_6, BP_MINS
#define _________________NUMBR_R3__________________        BP_ASTR,    BP_1, BP_2, BP_3, KC_PDOT


#define _________________ADJUST_L1_________________        ___________________BLANK___________________
#define _________________ADJUST_L2_________________        RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD
#define _________________ADJUST_L3_________________        _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD

#define _________________ADJUST_R1_________________        ___________________BLANK___________________
#define _________________ADJUST_R2_________________        KC_NO, KC_NO,            KC_NO,     KC_NO, KC_NO
#define _________________ADJUST_R3_________________        KC_NO, TO(_AZERTY_BEPO), TO(_BEPO), KC_NO, KC_NO

#define ___________________NAV_L1__________________        KC_NO,   KC_INS,  KC_HOME, KC_PGUP, KC_PSCR
#define ___________________NAV_L2__________________        KC_NO,   KC_DEL,  KC_END,  KC_PGDN, KC_SLCK
#define ___________________NAV_L3__________________        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PAUS

#define ___________________NAV_R1__________________        KC_NO,   KC_INS,           KC_HOME,   KC_PGUP, KC_PSCR
#define ___________________NAV_R2__________________        KC_NO,   KC_DEL,           KC_END,    KC_PGDN, KC_SLCK
#define ___________________NAV_R3__________________        KC_NO,   TO(_AZERTY_BEPO), TO(_BEPO), KC_NO,   KC_PAUS


#endif
