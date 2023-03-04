#include QMK_KEYBOARD_H


// joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
//     JOYSTICK_AXIS_VIRTUAL,
//     JOYSTICK_AXIS_VIRTUAL
// };


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
    // [0] = LAYOUT_ortho_4x4(
    //     QK_JOYSTICK_BUTTON_5,
    //     QK_JOYSTICK_BUTTON_6,
    //     QK_JOYSTICK_BUTTON_7,
    //     QK_JOYSTICK_BUTTON_8
    // )
    [0] = LAYOUT_ortho_4x4(
        DX1,
        DX2,
        DX3,
        DX4
    )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == DX1 || keycode == DX2 || keycode == DX3 || keycode == DX4) {
        if (record->event.pressed) {
            register_joystick_button(keycode - DX1);
        } else {
            unregister_joystick_button(keycode - DX1);
        }
        return false;
    }
    return true;
}