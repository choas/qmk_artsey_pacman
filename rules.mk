# Copyright (c) 2023 @choas
# SPDX-License-Identifier: Apache-2.0

COMBO_ENABLE = yes

RAW_ENABLE = yes

ifeq ($(strip $(HAND)), right)
	HAND_RIGHT = yes
	OPT_DEFS += -DHAND_RIGHT
endif


# CONSOLE_ENABLE = yes
