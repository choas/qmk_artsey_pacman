// Copyright (c) 2023 @choas
// SPDX-License-Identifier: Apache-2.0

#pragma once

enum {
    _BASE,   // default
    _SYMBOL1, // special characters
    _NUMBERS,  // numbers/function/motion
    _SYMBOL2, // special characters
    _CUSTOM
};


#define KEY_T1 KC_A
#define KEY_T2 KC_R
#define KEY_T3 KC_T
#define KEY_T4 KC_S
#define KEY_B1 KC_E
#define KEY_B2 KC_Y
#define KEY_B3 KC_I
#define KEY_B4 KC_O

#define NUM_T4 LT(_NUMBERS, KEY_T4)
#define SYM1_T1 LT(_SYMBOL1, KEY_T1)
#define SYM2_B1 LT(_SYMBOL2, KEY_B1)
#define CUST_B4 LT(_CUSTOM, KEY_B4)

#define T1 SYM1_T1
#define T2 KEY_T2
#define T3 KEY_T3
#define T4 NUM_T4
#undef B1
#undef B2
#undef B3
#undef B4
#define B1 SYM2_B1
#define B2 KEY_B2
#define B3 KEY_B3
#define B4 CUST_B4
