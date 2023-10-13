// Copyright (c) 2023 @choas
// SPDX-License-Identifier: Apache-2.0

#include QMK_KEYBOARD_H
#include "shared_defines.h"
#include "layout.h"
#include "combos.h"


// left hand

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] =LAYOUT_4x2(
    T4, T3, T2, T1,
    B4, B3, B2, B1
),
[_SYMBOL1] =LAYOUT_4x2(
    KC_LCBR, KC_LPRN, KC_LBRC, KC_NO,
    KC_RCBR, KC_RPRN, KC_RBRC, KC_NO
),
[_NUMBERS] =LAYOUT_4x2(
    KC_NO, KC_3, KC_2, KC_1,
    KC_NO, KC_6, KC_5, KC_4
),
[_SYMBOL2] =LAYOUT_4x2(
    KC_GRV, KC_SCLN, KC_BSLS, KC_EXLM,
    KC_EQL, KC_MINS, KC_QUES, KC_NO
),
[_CUSTOM] =LAYOUT_4x2(
    KC_LCBR, KC_LPRN, KC_LBRC, KC_NO,
    KC_RCBR, KC_RPRN, KC_RBRC, KC_NO
),

};
