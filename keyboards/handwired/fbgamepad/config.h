// Copyright 2023 fishbedding (@fishbedding)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define EXPANDED_JOYSTICK_BUTTON_COUNT 40
#define JOYSTICK_AXIS_COUNT 0

#define ENCODERS_PAD_A { A1, A2, A3 }
#define ENCODERS_PAD_B { A2, A3, A4 }

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
