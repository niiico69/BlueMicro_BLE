/*
Copyright 2018 <Pierre Constantineau>

3-Clause BSD License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#include "keymap.h"
#include "keymap_french.h"
#include "keymap_bepo.h"

std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
   {KEYMAP(
    KC_ESC, FR_QUOT, FR_LESS, FR_GRTR, FR_LPRN, FR_RPRN,                      FR_AT,   FR_PLUS, FR_MINS, FR_SLSH, FR_ASTR, FR_EQL, \
    KC_TAB, KC_B,    FR_EACU, KC_P,    KC_O,    FR_EGRV,                      KC_LBRC, KC_V,    KC_D,    KC_L,    KC_J,    FR_Z,    \
    FR_W,   FR_A,    KC_U,    KC_I,    KC_E,    FR_COMM,                      KC_C,    KC_T,    KC_S,    KC_R,    KC_N,    FR_M,    \
    KC_E,   FR_AGRV, KC_Y,	  KC_X,    FR_DOT,  KC_K,                         FR_APOS, FR_Q,    KC_G,    KC_H,    KC_F,    FR_CCED, \
    FR_DLR, KC_LALT, KC_LGUI, KC_UP,   KC_DOWN, KC_BSPC, KC_DEL,      KC_ENT, KC_SPC,  KC_LEFT, KC_RGHT, KC_RGUI, KC_RALT, KC_NO\
    )};

 
void setupKeymap() {
    uint32_t mod_tap[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,                                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,\ 
    KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,                                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,\    
    KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,                                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,\   
    KC_LSFT, KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,                                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_RSFT,\
    KC_LCTL, KC_LALT, KC_LGUI, KC_UP, KC_DOWN, KC_LSFT, KC_NO,      KC_NO, KC_RSFT, KC_LEFT, KC_RGHT, KC_RGUI, KC_RALT, KC_NO);

    uint32_t bepo[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    KC_ESC, BP_DQOT,    BP_LGIL,    BP_RGIL, BP_LPRN, BP_RPRN,                  BP_AT,   BP_PLUS,  BP_MINUS, BP_SLASH, BP_ASTR, BP_EQL, \
    KC_TAB, BP_B,       BP_E_ACUTE, BP_P,    BP_O,    BP_E_GRAVE,               BP_DCRC, BP_V,     BP_D,     BP_L,     BP_J, BP_Z, \
    BP_W,   BP_A,       BP_U,       BP_I,    BP_E,    BP_COMMA,                 BP_C,    BP_T,     BP_S,     BP_R,     BP_N, BP_M, \
    BP_EGRV,   BP_A_GRAVE, BP_Y,       BP_X,    BP_DOT,  BP_K,                     BP_APOS, BP_Q,     BP_G,     BP_H,     BP_F, BP_CCED, \
    BP_DLR, KC_LALT, KC_LGUI, KC_UP,   KC_DOWN, KC_BSPC, KC_DEL,      KC_ENT, KC_SPC,  KC_LEFT, KC_RGHT, KC_RGUI, KC_RALT, KC_NO);
    /*
     * add the other layers
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_AZERTY_BEPO, Method::MT_HOLD, mod_tap[row][col]);
            matrix[row][col].addActivation(_BEPO, Method::PRESS, mod_tap[row][col]);
        }
    }

}


