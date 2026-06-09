#include QMK_KEYBOARD_H


// joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
//     JOYSTICK_AXIS_VIRTUAL,
//     JOYSTICK_AXIS_VIRTUAL
// };


enum custom_keycodes {
    DX1 = 0,
    DX2,
    DX3,
    DX4,
    DX5
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
        DX4,
        DX5
    )
};

// RGB Indicator Customization: (100% stolen from Jetpacktuxedo)
void keyboard_post_init_user(void) {
  #ifdef RGBLIGHT_ENABLE
// Set up RGB effects on _only_ the first LED (index 0):
        rgblight_set_effect_range(0, 4);
// Set LED effects to breathing mode in a "terminal-green" type color:
        rgblight_sethsv_noeeprom(50, 255, 20);
        // rgblight_mode_noeeprom(RGBLIGHT_EFFECT_BREATHING + 2);
// Init the second LED to a static color:
        // setrgb(225, 185, 0, (LED_TYPE *)&led[1]);
    rgblight_set();
  #endif // RGBLIGHT_ENABLE
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == DX3 || keycode == DX4 || keycode == DX5) {
        if (record->event.pressed) {
            rgblight_sethsv_noeeprom(60, 255, 50);
            register_joystick_button(keycode - DX1);
        } else {
            unregister_joystick_button(keycode - DX1);
        }
        return false;
    }
    else if (keycode == DX1) {
        if (record->event.pressed) {
            rgblight_sethsv_noeeprom(60, 255, 0);
            register_joystick_button(keycode - DX1);
        } else {
            unregister_joystick_button(keycode - DX1);
        }
        return false;
    }
    else if (keycode == DX2) {
        if (record->event.pressed) {
            // rgblight_increase_val();
            rgblight_decrease_val();
            register_joystick_button(keycode - DX1);
        } else {
            unregister_joystick_button(keycode - DX1);
        }
        return false;
    }
    return true;
}