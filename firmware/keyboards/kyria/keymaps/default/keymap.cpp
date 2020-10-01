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

#if KEYBOARD_SIDE == SINGLE
std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
   {KEYMAP(
    KC_ESC,  KC_Q,   KC_W,    KC_E,    KC_R,   KC_T,                      
    KC_BSPC, KC_A,   KC_S,    KC_D,    KC_F,   KC_G,                      
    KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,   KC_B,   KC_LSFT, KC_LSFT,  
                              KC_LGUI, KC_DEL, KC_ENT, KC_SPC,  KC_ESC
    )};

void setupKeymap() {

   // no layers for master keymap
   // this is a keymap that's used for testing that each key is responding properly to key presses
   // flash this keymap to both left and right to test whether each half works properly.
   // once tested, you can flash the left and right to their respective halves.

}
#endif

#if KEYBOARD_SIDE == LEFT
std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
   {KEYMAP(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              \ 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              \       
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
                         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO \
    )};

void setupKeymap() {
    uint32_t qwerty[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    KC_ESC,  KC_Q,   KC_W,    KC_E,    KC_R,   KC_T,                      \
    KC_BSPC, KC_A,   KC_S,    KC_D,    KC_F,   KC_G,                      \
    KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,   KC_B,   KC_LSFT, KC_LSFT,  \
                              KC_LGUI, KC_DEL, KC_ENT, KC_SPC,  KC_ESC);
    /*
     * add the other layers
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_QWERTY, Method::PRESS, qwerty[row][col]);
        }
    }
}


#endif

#if KEYBOARD_SIDE == RIGHT
std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
   {KEYMAP(
                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\ 
                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\    
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO \
    )};

void setupKeymap() {
    uint32_t qwerty[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_PIPE,\
                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,\
    KC_LSFT, KC_LSFT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,\
    KC_ENT,  KC_SPC,  KC_TAB,  KC_BSPC, KC_RALT);
    /*
     * add the other layers
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_QWERTY, Method::PRESS, qwerty[row][col]);
        }
    }

}
#endif


