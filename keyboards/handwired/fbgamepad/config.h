// Copyright 2023 fishbedding (@fishbedding)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define EXPANDED_JOYSTICK_BUTTON_COUNT 40
#define JOYSTICK_AXIS_COUNT 0

#define ENCODERS_PAD_A { A1, A2, A3, A4 }
#define ENCODERS_PAD_B { A2, A3, A4, A5 }

#define RGBLIGHT_HUE_STEP 10            // The number of steps to cycle through the hue by
#define RGBLIGHT_SAT_STEP 10            // The number of steps to increment the saturation by
#define RGBLIGHT_VAL_STEP 10            // The number of steps to increment the brightness by
#define RGBLIGHT_LIMIT_VAL 100          // Max brightness level
// #define RGBLIGHT_SLEEP                  // RGB will switch off when host goes to sleep

#define RGBLIGHT_EFFECT_BREATHING       // Enable all additional RGB animation modes
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_TWINKLE



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
