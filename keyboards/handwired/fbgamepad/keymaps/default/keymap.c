#include QMK_KEYBOARD_H

enum custom_keycodes {
    DX1 = SAFE_RANGE,
    DX2,
    DX3,
    DX4
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ * │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * ├───┼───┼───┼───┤
     * │ 0 │ . │Ent│ + │
     * └───┴───┴───┴───┘
     */
    [0] = LAYOUT_ortho_4x4(
        KC_P7
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            register_joystick_button(DX1 - DX1);
            wait_ms(50);
            unregister_joystick_button(DX1 - DX1);
        } else {
            register_joystick_button(DX2 - DX1);
            wait_ms(50);
            unregister_joystick_button(DX2 - DX1);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code_delay(KC_C, 10);
        } else {
            tap_code_delay(KC_D, 10);
        }
    } else if (index == 2) { /* Second encoder */
        if (clockwise) {
            tap_code_delay(KC_E, 10);
        } else {
            tap_code_delay(KC_F, 10);
        }
    }
    return false;
}
