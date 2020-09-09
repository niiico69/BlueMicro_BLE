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
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\ 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\    
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\   
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO \
    )};

void setupKeymap() {
    setupKeymapBepo();
}
 
void setupKeymapBepo() {
    uint32_t bepo[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    KC_ESC,  BP_DQOT,    BP_LGIL,    BP_RGIL, BP_LPRN, BP_RPRN,                  BP_AT,   BP_PLUS,  BP_MINUS, BP_SLASH, BP_ASTR, BP_EQL,\
    KC_TAB,  BP_B,       BP_E_ACUTE, BP_P,    BP_O,    BP_E_GRAVE,               BP_DCRC, BP_V,     BP_D,     BP_L,     BP_J,    BP_Z,\
    BP_W,    BP_A,       BP_U,       BP_I,    BP_E,    BP_COMMA,                 BP_C,    BP_T,     BP_S,     BP_R,     BP_N,    BP_M,\
    BP_EGRV, BP_A_GRAVE, BP_Y,       BP_X,    BP_DOT,  BP_K,                     BP_APOS, BP_Q,     BP_G,     BP_H,     BP_F,    BP_CCED,\
    BP_DLR,  KC_LALT,    KC_LGUI,    KC_UP,   KC_DOWN, KC_NO, KC_NO,      KC_NO, KC_NO,  KC_LEFT,  KC_RGHT,  KC_RGUI,  KC_RALT, KC_NO);

    uint32_t mod_hold[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,\ 
    KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,\    
    KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,\   
    KC_LSFT, KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RSFT,\
    KC_LCTL, KC_LALT, KC_LGUI, KC_UP, KC_DOWN, KC_LSFT, NUMBR,      NAV, KC_RSFT, KC_LEFT, KC_RGHT, KC_RGUI, KC_RALT, KC_NO);

    uint32_t mod_tap[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BSPC, KC_DEL,    KC_ENT, KC_SPC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO );
    
    uint32_t numbr[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,  KC_F8,  KC_F9,   KC_F10,  KC_F11,\
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    BP_6,    BP_7,   BP_8,   BP_9,    BP_0,    KC_F12,\
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    BP_PERC, BP_4,   BP_5,   BP_6,    BP_MINS, BP_PLUS,\
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    BP_ASTR, BP_1,   BP_2,   BP_3,    KC_PDOT, BP_SLSH,\
    _______, _______, _______, KC_PGUP, KC_PGDN, _______, NUMBR,        NAV, _______, BP_0,   KM_00,  KC_HOME, KC_END,  BP_EQL);

    uint32_t nav[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    _______, _______, _______,  _______, _______, _______,                     _______, _______,    _______, _______, _______, _______, \
    _______, KC_NO,   KC_INS,   KC_HOME, KC_PGUP, KC_PSCR,                     KC_NO,   KC_INS,     KC_HOME, KC_PGUP, KC_PSCR, PRINT_BATTERY, \
    RESET,   KC_NO,   KC_DEL,   KC_END,  KC_PGDN, KC_SLCK,                     KC_NO,   KC_DEL,     KC_END,  KC_PGDN, KC_SLCK, PRINT_INFO, \
    _______, KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_PAUS,                     KC_NO,   KM_AZ_BEPO, KM_BEPO, KC_NO,   KC_PAUS, PRINT_BLE, \
    _______, _______, _______,  _______, _______, _______, NUMBR,         NAV, _______, _______,    _______, _______, _______, _______);
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
            matrix[row][col].addActivation(_NAV, Method::PRESS, nav[row][col]);

        }
    }

}

void setupKeymapAzertyBepo() {
        uint32_t azerty_bepo[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    KC_ESC,  FR_QUOT, FR_LESS, FR_GRTR, FR_LPRN, FR_RPRN,                      FR_AT,   FR_PLUS, FR_MINS, FR_SLSH, FR_ASTR, FR_EQL, \
    KC_TAB,  KC_B,    FR_EACU, KC_P,    KC_O,    FR_EGRV,                      KC_LBRC, KC_V,    KC_D,    KC_L,    KC_J,    FR_Z,    \
    FR_W,    FR_A,    KC_U,    KC_I,    KC_E,    FR_COMM,                      KC_C,    KC_T,    KC_S,    KC_R,    KC_N,    FR_M,    \
    FR_EGRV, FR_AGRV, KC_Y,	   KC_X,    FR_DOT,  KC_K,                         FR_APOS, FR_Q,    KC_G,    KC_H,    KC_F,    FR_CCED, \
    FR_DLR, KC_LALT, KC_LGUI,  KC_UP,   KC_DOWN, KC_BSPC, KC_NO,        KC_NO, KC_SPC,  KC_LEFT, KC_RGHT, KC_RGUI, KC_RALT, KC_NO);

    uint32_t mod_hold[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,\ 
    KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,\    
    KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,\   
    KC_LSFT, KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RSFT,\
    KC_LCTL, KC_LALT, KC_LGUI, KC_UP, KC_DOWN, KC_LSFT, NUMBR,      NAV, KC_RSFT, KC_LEFT, KC_RGHT, KC_RGUI, KC_RALT, KC_NO);

    uint32_t mod_tap[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_DEL,      KC_ENT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO );

    uint32_t numbr[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,  KC_F8,  KC_F9,   KC_F10,  KC_F11,\
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    FR_6,    FR_7,   FR_8,   FR_9,    FR_0,    KC_F12,\
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    FR_PERC, FR_4,   FR_5,   FR_6,    FR_MINS, FR_PLUS,\
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    FR_ASTR, FR_1,   FR_2,   FR_3,    KC_PDOT, FR_SLSH,\
    _______, _______, _______, KC_PGUP, KC_PGDN, _______, NUMBR,        NAV, _______, FR_0,   KM_00,  KC_HOME, KC_END,  FR_EQL);

    uint32_t nav[MATRIX_ROWS][MATRIX_COLS] =
    KEYMAP(
    _______, _______, _______,  _______, _______, _______,                     _______, _______,    _______, _______, _______, _______, \
    _______, KC_NO,   KC_INS,   KC_HOME, KC_PGUP, KC_PSCR,                     KC_NO,   KC_INS,     KC_HOME, KC_PGUP, KC_PSCR, XXXXXXX, \
    UF2_DFU, KC_NO,   KC_DEL,   KC_END,  KC_PGDN, KC_SLCK,                     KC_NO,   KC_DEL,     KC_END,  KC_PGDN, KC_SLCK, XXXXXXX, \
    _______, KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_PAUS,                     KC_NO,   KM_AZ_BEPO, KM_BEPO, KC_NO,   KC_PAUS, XXXXXXX, \
    _______, _______, _______,  _______, _______, _______, NUMBR,         NAV, _______, _______,    _______, _______, _______, _______);
    /*
     * add the other layers
     */
    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            matrix[row][col].addActivation(_AZERTY_BEPO, Method::PRESS, azerty_bepo[row][col]);
            matrix[row][col].addActivation(_AZERTY_BEPO, Method::MT_HOLD, mod_hold[row][col]);
            matrix[row][col].addActivation(_AZERTY_BEPO, Method::MT_TAP, mod_tap[row][col]); 
            matrix[row][col].addActivation(_NUMBR, Method::PRESS, numbr[row][col]);
            matrix[row][col].addActivation(_NAV, Method::PRESS, nav[row][col]);

        }
    }

}

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
    }
}


