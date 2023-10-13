// Copyright (c) 2023 @choas
// SPDX-License-Identifier: Apache-2.0
#pragma once

/*
 *        Left Hand                          Right Hand
 *  ,-------------------.              ,-------------------.
 *  | T4 | T3 | T2 | T1 |   Top row    | T1 | T2 | T3 | T4 |
 *  |----+----+----+----|              |----+----+----+----|
 *  | B4 | B3 | B2 | B1 |  Bottom row  | B1 | B2 | B3 | B4 | 
 *  `-------------------'              `-------------------'
 */

enum custom_keycodes {
    LCK_SHIFT = SAFE_RANGE,
    OSM_CTRL,
    OSM_GUI,
    OSM_ALT,
    OSM_SHIFT
};
