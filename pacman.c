// Copyright (c) 2023 @choas
// SPDX-License-Identifier: Apache-2.0

#include "pacman.h"
#include "raw_hid.h"

// #include "print.h"


// see qmk-artsey

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
        case LCK_SHIFT:
            if (record->event.pressed) {
                if (get_mods() & MOD_BIT(KC_LSFT)) {
                    unregister_mods(MOD_BIT(KC_LSFT));
                }
                else {
                    register_mods(MOD_BIT(KC_LSFT));
                }
            }
            break;
        case OSM_CTRL:
            if (record->event.pressed) {
                add_oneshot_mods(MOD_BIT(KC_LCTL));
            }
            break;
        case OSM_GUI:
            if (record->event.pressed) {
                add_oneshot_mods(MOD_BIT(KC_LGUI));
            }
            break;
        case OSM_ALT:
            if (record->event.pressed) {
                add_oneshot_mods(MOD_BIT(KC_LALT));
            }
            break;
        case OSM_SHIFT:
        print("OS\n");
            if (record->event.pressed) {
                add_oneshot_mods(MOD_BIT(KC_LSFT));
            }
            break;
        default:
            break;
    }
    return true;
}


// HID
void raw_hid_receive(uint8_t *data, uint8_t length) {
    uint8_t response[length];
    memset(response, 0, length);
    response[0] = 'B';

    if(data[0] == 'R') {
        print("reset\n");
        raw_hid_send(response, length);
        reset_keyboard();

    } else if(data[0] == 'A') {
        print("A\n");
        raw_hid_send(response, length);
    }
}
