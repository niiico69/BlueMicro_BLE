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
#define KEYBOARD_SIDE SINGLE

#define DEVICE_NAME_M                       "Atreus62"                          /**< Name of device. Will be included in the advertising data. */
#define DEVICE_MODEL                        "Atreus62_v1"                          /**< Name of device. Will be included in the advertising data. */
#define MANUFACTURER_NAME                   "Profet"                      /**< Manufacturer. Will be passed to Device Information Service. */


#define KEYMAP( \
    k00, k01, k02, k03, k04, k05,           k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15,           k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25,           k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34, k35,           k36, k37, k38, k39, k3a, k3b, \
    k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b, k4c, k4d \
) \
{ \
    { k00, k01, k02, k03, k04, k05, KC_NO, k06, k07, k08, k09, k0a, k0b }, \
    { k10, k11, k12, k13, k14, k15, KC_NO, k16, k17, k18, k19, k1a, k1b }, \
    { k20, k21, k22, k23, k24, k25, KC_NO, k26, k27, k28, k29, k2a, k2b }, \
    { k30, k31, k32, k33, k34, k35, k46,   k36, k37, k38, k39, k3a, k3b }, \
    { k40, k41, k42, k43, k44, k45, k47,   k48, k49, k4a, k4b, k4c, k4d } \
}


#endif /* KEYBOARD_CONFIG_H */
