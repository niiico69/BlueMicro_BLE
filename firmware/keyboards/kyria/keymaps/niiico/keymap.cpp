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

#if KEYBOARD_SIDE == SINGLE
std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
   {KEYMAP(
    KC_TAB, BP_B,    BP_E_ACUTE, BP_P,  BP_O,    BP_EGRV,             
    BP_W,   BP_A,    BP_U,       BP_I,  BP_E,    BP_COMMA,            
    BP_DLR, BP_AGRV, BP_Y,       BP_X,  BP_DOT,  BP_K,  BP_1,  BP_2,
                                 KC_UP, KC_DOWN, BP_Q,  BP_3,   BP_4
    )};

void setupKeymap() {

   // no layers for master keymap
   // this is a keymap that's used for testing that each key is responding properly to key presses
   // flash this keymap to both left and right to test whether each half works properly.
   // once tested, you can flash the left and right to their respective halves.

}
void setupKeymapBepo() {}
void setupKeymapAzertyBepo() {}
#endif

#if KEYBOARD_SIDE == LEFT
std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
   {KEYMAP(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              \ 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              \       
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
                         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO\
    )};

void setupKeymap() {
    setupKeymapBepo();
}
 
void setupKeymapBepo() {
    uint32_t bepo[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    KC_TAB, BP_B,  BP_E_ACUTE, BP_P,  BP_O,    BP_EGRV,             \
    BP_W,   BP_A,  BP_U,       BP_I,  BP_E,    BP_COMMA,            \
    BP_DLR, KC_NO, BP_Y,       BP_X,  BP_DOT,  BP_K,   KC_NO, KC_NO,\
                               KC_UP, KC_DOWN, KC_NO,  KC_NO, KC_NO);

    uint32_t mod_hold[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,                  \    
    KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,                  \   
    KC_NO, KC_LALT, KC_NO, KC_NO, KC_NO, KC_NO, KC_LCTL, KC_LALT,\
                           KC_NO, KC_NO, NUMBR, KC_LSFT, SYMBL);

    uint32_t mod_tap[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,                  \
    KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,                  \
    KC_NO, BP_AGRV, KC_NO, KC_NO, KC_NO, KC_NO,  KC_ENT,  KC_TAB,\
                           KC_NO, KC_NO, KC_SPC, KC_BSPC, KC_DEL);
    
    uint32_t numbr[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    _______, BP_1,  BP_2,  BP_3,   BP_4,   BP_5,                \
    XXXXXXX, KC_F1, KC_F2, KC_F3,  KC_F4,  KC_F5,               \
    XXXXXXX, KC_F6, KC_F7, KC_F8,  KC_F9,  KC_F10, KC_NO, KC_NO,\
                           KC_F11, KC_F12, NUMBR,  KC_NO, SYMBL);

    uint32_t symbl[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                    \
    KC_NO, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                  \
    KC_NO, KC_NO,   RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, KC_NO, KC_LALT, \
                             KC_PGUP, KC_PGDN, NUMBR,    KC_NO, SYMBL);

    uint32_t adjust[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    _______, BP_DQOT, BP_LGIL, BP_RGIL, BP_LPRN, BP_RPRN,             \
    RESET,   BP_MDSH, BP_LABK, BP_RABK, BP_LBRC, BP_RBRC,             \
    KC_NO,   KC_LALT, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, \
                               KC_NO,   KC_NO,   NUMBR, KC_NO, SYMBL);
    /*
     * add the other layers
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_BEPO, Method::PRESS, bepo[row][col]);
            matrix[row][col].addActivation(_BEPO, Method::MT_HOLD, mod_hold[row][col]); 
            matrix[row][col].addActivation(_BEPO, Method::MT_TAP, mod_tap[row][col]); 
            matrix[row][col].addActivation(_NUMBR, Method::PRESS, numbr[row][col]);
            matrix[row][col].addActivation(_SYMBL, Method::PRESS, symbl[row][col]);
            matrix[row][col].addActivation(_ADJUST, Method::PRESS, adjust[row][col]);

        }
    }
}

void setupKeymapAzertyBepo() {
    uint32_t bepo[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    KC_TAB, KC_B,    FR_EACU, KC_P,  KC_O,    FR_EGRV,             \
    FR_W,   FR_A,    KC_U,    KC_I,  KC_E,    FR_COMM,             \
    FR_DLR, KC_NO,   KC_Y,	  KC_X,  FR_DOT,  KC_K,   KC_NO, KC_NO,\
                              KC_UP, KC_DOWN, KC_NO,  KC_NO, KC_NO);

    uint32_t mod_hold[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,                   \    
    KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,                   \   
    KC_NO, KC_LALT, KC_NO, KC_NO, KC_NO, KC_NO, KC_LCTL, KC_LALT, \
                           KC_NO, KC_NO, NUMBR, KC_LSFT, SYMBL);

    uint32_t mod_tap[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,                   \
    KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,                   \
    KC_NO, FR_AGRV, KC_NO, KC_NO, KC_NO, KC_NO,  KC_ENT,  KC_TAB, \
                           KC_NO, KC_NO, KC_SPC, KC_BSPC, KC_DEL);
    
    uint32_t numbr[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    _______, FR_1,  FR_2,  FR_3,   FR_4,   FR_5,                 \
    XXXXXXX, KC_F1, KC_F2, KC_F3,  KC_F4,  KC_F5,                \
    XXXXXXX, KC_F6, KC_F7, KC_F8,  KC_F9,  KC_F10, KC_NO, KC_NO, \
                           KC_F11, KC_F12, NUMBR,  KC_NO, SYMBL);

    uint32_t symbl[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                    \
    KC_NO, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                  \
    KC_NO, KC_NO,   RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, KC_NO, KC_LALT, \
                             KC_PGUP, KC_PGDN, NUMBR,    KC_NO, SYMBL);

    uint32_t adjust[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    _______, FR_DQUO, FR_DQUO, FR_DQUO, FR_LPRN, FR_RPRN,             \
    RESET,   FR_MINS, FR_LABK, FR_RABK, FR_LBRC, FR_RBRC,             \
    KC_NO,   KC_LALT, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, \
                               KC_NO,   KC_NO,   NUMBR, KC_NO, SYMBL);
    /*
     * add the other layers
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_BEPO, Method::PRESS, bepo[row][col]);
            matrix[row][col].addActivation(_BEPO, Method::MT_HOLD, mod_hold[row][col]); 
            matrix[row][col].addActivation(_BEPO, Method::MT_TAP, mod_tap[row][col]); 
            matrix[row][col].addActivation(_NUMBR, Method::PRESS, numbr[row][col]);
            matrix[row][col].addActivation(_SYMBL, Method::PRESS, symbl[row][col]);
            matrix[row][col].addActivation(_ADJUST, Method::PRESS, adjust[row][col]);

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
    setupKeymapBepo();
}
 
void setupKeymapBepo() {
    uint32_t bepo[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
                    BP_DCRC, BP_V,    BP_D,   BP_L, BP_J, BP_Z,    \
                    BP_C,    BP_T,    BP_S,   BP_R, BP_N, BP_M,    \
    KC_LGUI, KC_NO, BP_APOS, BP_Q,    BP_G,   BP_H, KC_NO, BP_CCED,\
    KC_NO,   KC_NO, KC_NO,   KC_LEFT, KC_RGHT);

    uint32_t mod_hold[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,\    
                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,\   
    KC_NO, KC_RCTL, KC_NO, KC_NO, KC_NO, KC_NO, KC_RALT, KC_NO,\
    SYMBL, KC_RSFT, NUMBR, KC_NO, KC_NO);

    uint32_t mod_tap[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
                    KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
                    KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
    KC_NO,  KC_ENT, KC_NO,   KC_NO, KC_NO, KC_NO, BP_F,  BP_CCED,\
    KC_ESC, KC_SPC, KC_BSPC, KC_NO, KC_NO);
    
    uint32_t numbr[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
                   BP_6,    BP_7, BP_8,   BP_9, BP_0,    BP_EQL,\
                   BP_PERC, BP_4, BP_5,   BP_6, BP_MINS, BP_PLUS,\
    KC_NO, KC_NO,  BP_ASTR, BP_1, BP_2,   BP_3, KC_PDOT, BP_SLSH,\
    SYMBL, KC_NO,  NUMBR,   BP_0, KM_00);

    uint32_t symbl[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
                  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, \
                  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, \
    KC_NO, KC_NO, KC_NO, KC_PSCR,  KC_SLCK, KC_PAUS, KC_NO, KC_NO,\
    SYMBL, KC_NO, NUMBR,  KC_HOME, KC_END);

    uint32_t adjust[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
                  KC_NO, KC_INS,     KC_HOME, KC_PGUP, KC_PSCR, PRINT_BATTERY, \
                  KC_NO, KC_DEL,     KC_END,  KC_PGDN, KC_SLCK, PRINT_INFO, \
    KC_NO, KC_NO, KC_NO, KM_AZ_BEPO, KC_NO,   KC_NO,   KC_NO,   KC_NO,\
    SYMBL, KC_NO, NUMBR, KC_NO,      KC_NO);
    /*
     * add the other layers
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_BEPO, Method::PRESS, bepo[row][col]);
            matrix[row][col].addActivation(_BEPO, Method::MT_HOLD, mod_hold[row][col]); 
            matrix[row][col].addActivation(_BEPO, Method::MT_TAP, mod_tap[row][col]); 
            matrix[row][col].addActivation(_NUMBR, Method::PRESS, numbr[row][col]);
            matrix[row][col].addActivation(_SYMBL, Method::PRESS, symbl[row][col]);
            matrix[row][col].addActivation(_ADJUST, Method::PRESS, adjust[row][col]);

        }
    }

}


void setupKeymapAzertyBepo() {
    uint32_t bepo[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
                    KC_LBRC, KC_V,    KC_D,    KC_L,    KC_J,    FR_Z,    \
                    KC_C,    KC_T,    KC_S,    KC_R,    KC_N,    FR_M,    \
    KC_LGUI, KC_NO, FR_APOS, FR_Q,    KC_G,    KC_H,    KC_NO,   FR_CCED, \
    KC_NO,   KC_NO, KC_NO,   KC_LEFT, KC_RGHT);

    uint32_t mod_hold[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,\    
                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,\   
    KC_NO, KC_RCTL, KC_NO, KC_NO, KC_NO, KC_NO, KC_RALT, KC_NO,\
    SYMBL, KC_RSFT, NUMBR, KC_NO, KC_NO);

    uint32_t mod_tap[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
                    KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
                    KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
    KC_NO,  KC_ENT, KC_NO,   KC_NO, KC_NO, KC_NO, KC_F,  FR_CCED,\
    KC_ESC, KC_SPC, KC_BSPC, KC_NO, KC_NO);
    
    uint32_t numbr[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
                   FR_6,    FR_7, FR_8,   FR_9, FR_0,    FR_EQL,\
                   FR_PERC, FR_4, FR_5,   FR_6, FR_MINS, FR_PLUS,\
    KC_NO, KC_NO,  FR_ASTR, FR_1, FR_2,   FR_3, KC_PDOT, FR_SLSH,\
    SYMBL, KC_NO,  NUMBR,   FR_0, KMZ_00);

    uint32_t symbl[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
                  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, \
                  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, \
    KC_NO, KC_NO, KC_NO, KC_PSCR, KC_SLCK, KC_PAUS, KC_NO, KC_NO,\
    SYMBL, KC_NO, NUMBR,  KC_HOME, KC_END);

    uint32_t adjust[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
                  KC_NO, KC_INS, KC_HOME, KC_PGUP, KC_PSCR, PRINT_BATTERY, \
                  KC_NO, KC_DEL, KC_END,  KC_PGDN, KC_SLCK, PRINT_INFO, \
    KC_NO, KC_NO, KC_NO, KC_NO,  KM_BEPO, KC_NO,   KC_NO,   KC_NO,\
    SYMBL, KC_NO, NUMBR, KC_NO,  KC_NO);
    /*
     * add the other layers
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_BEPO, Method::PRESS, bepo[row][col]);
            matrix[row][col].addActivation(_BEPO, Method::MT_HOLD, mod_hold[row][col]); 
            matrix[row][col].addActivation(_BEPO, Method::MT_TAP, mod_tap[row][col]); 
            matrix[row][col].addActivation(_NUMBR, Method::PRESS, numbr[row][col]);
            matrix[row][col].addActivation(_SYMBL, Method::PRESS, symbl[row][col]);
            matrix[row][col].addActivation(_ADJUST, Method::PRESS, adjust[row][col]);

        }
    }

}
#endif

void process_user_macros(uint16_t macroid)
{
    switch ((macroid))
    {
        case KM_AZ_BEPO:
            setupKeymapAzertyBepo();
        break;
        case KM_BEPO:
            setupKeymapBepo();
        break;
        case KM_00:
            addKeycodeToQueue(BP_0);
            addKeycodeToQueue(BP_0);
        break;
        case KMZ_00:
            addKeycodeToQueue(FR_0);
            addKeycodeToQueue(FR_0);
        break;
    }
}


