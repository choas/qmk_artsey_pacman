// Copyright (c) 2023 @choas
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "quantum.h"
#include "shared_defines.h"

#define LEFT_HAND

#ifdef LEFT_HAND

#define LAYOUT_4x2( \
	K000, K001, K002, K003, \
    K004, K005, K006, K007 \
) { \
	{ K000,  K001,  K002,  K003}, \
    { K004,  K005,  K006,  K007 } \
}

#else

#define LAYOUT_4x2( \
	K003, K002, K001, K000, \
    K007, K006, K005, K004 \
) { \
	{ K000,  K001,  K002,  K003}, \
    { K004,  K005,  K006,  K007 } \
}

#endif