// Copyright (c) 2023 @choas
// SPDX-License-Identifier: Apache-2.0

const fs = require('fs');

const artseyio = `
....
XXX. M
....
X..X B
....
XX.. N
....
..XX C
....
XX.X P
.XXX
.... D
XX.X
.... Q
..XX
.... F
....
.XX. U
.XX.
.... G
X.X.
.... V
....
.X.X H
X..X
.... W
XX..
.... J
XXX.
.... X
....
X.X. K
XXXX
.... Z
....
.XXX L
..XX
X... ESC
...X
...X ENTER
.XXX
X... TAB
...X
.XX. QUOT
X...
...X +OSM_CTRL
...X
..X. DOT
X...
..X. +OSM_GUI
...X
.X.. COMMA
X...
.X.. +OSM_ALT
...X
X... SLSH
XXX.
...X +OSM_SHIFT
.X..
.X.. EXLM
..X.
..X. +LCK_SHIFT
....
XXXX SPC
...X
XXX. -CAPS
..X.
...X BSPC
.XX.
.XX. -Clear Bluetooth
..X.
.X.. DEL
.32.
.... 8
..21
.... 7
....
.65. 0
....
..54 9
`.split('\n').slice(1)

let co = "";
let cm = "";

for(let i = 0; i < artseyio.length - 1; i += 2) {
    const l1 = artseyio[i];
    const l2 = artseyio[i + 1].split(' ')[0];
    let keycode = artseyio[i + 1].split(' ')[1];
    let isNumber = false;

    if (keycode.startsWith('-')) {
        continue;
    } else if (keycode.startsWith('+')) {
        keycode = keycode.substring(1);
    } else {
        isNumber = (keycode >= '0' && keycode <= '9');
        keycode = "KC_" + keycode;
    }

    const keys = [];

    if (isNumber) {
        l1.split('').forEach((c, idx) => {
            if (c !== '.') {
                keys.push(c);
            }
        });
        l2.split('').forEach((c, idx) => {
            if (c !== '.') {
                keys.push(c);
            }
        });
    
        co += `CO(num${keys.join('')}, KC_${keys.join(', KC_')})\n`;
        cm += `  CM(num${keys.join('')}, ${keycode})\n`;
    
    } else {
        l1.split('').forEach((c, idx) => {
            if (c !== '.') {
                keys.push(`t${4-idx}`);
            }
        });
        l2.split('').forEach((c, idx) => {
            if (c !== '.') {
                keys.push(`b${4-idx}`);
            }
        });

        const spc = () => {
            return "        ".slice(keys.length*2);
        }
    
        co += `CO(${keys.join('')}, ${spc()} ${keys.map((k) => {return k.toUpperCase();}).join(', ')})\n`;
        cm += `  CM(${keys.join('')}, ${spc()} ${keycode})\n`;

    }

}

fs.writeFileSync('combos.h', `
// Copyright (c) 2023 @choas
// SPDX-License-Identifier: Apache-2.0

// THIS FILE IS GENERATED BY layout2code.js

#include "layout.h"

#define CO(name, ...) const uint16_t PROGMEM combo_##name[] = {__VA_ARGS__, COMBO_END};
#define CM(name, key) COMBO(combo_##name, key),

${co}

combo_t key_combos[] = {
${cm}
};
`)

console.log("done");