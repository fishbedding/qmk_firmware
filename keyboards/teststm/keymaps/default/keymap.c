#include QMK_KEYBOARD_H

// enum custom_keycodes {
//     SYM_UP = SAFE_RANGE,
//     SYM_DOWN,
//     BRT_UP,
//     BRT_DOWN,
//     DEPR_RET_UP,
//     DEPR_RET_DOWN,
//     CONT_UP,
//     CONT_DOWN
// }

enum custom_keycodes {
    TOGGLE_UP = SAFE_RANGE,
    TOGGLE_DW
};

enum toggle_states {
    OFF,
    ON
};

int toggle_up_state = OFF;
int toggle_dw_state = OFF;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_ortho_6x4(
        KC_A, KC_B, KC_C, KC_D, KC_E, KC_F,
        KC_G, KC_H, KC_I, KC_J, KC_L, TOGGLE_UP,
        KC_N, KC_O, KC_P, KC_Q, KC_R, TOGGLE_DW,
        KC_T, KC_U, KC_V, KC_W, KC_X, KC_Y
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TOGGLE_UP:
            if (record->event.pressed)
            {
                if (toggle_up_state == OFF) {
                    toggle_up_state = ON;
                    tap_code16(KC_M);
                }
            }
            else {
                toggle_up_state = OFF;
                tap_code16(KC_K);
            }
            return false;
        case TOGGLE_DW:
            if (record->event.pressed)
            {
                if (toggle_dw_state == OFF) {
                    toggle_dw_state = ON;
                    tap_code16(KC_S);
                }
            }
            else {
                toggle_dw_state = OFF;
                tap_code16(KC_K);
            }
            return false;
        default:
            return true;
    }
}


// #if defined(ENCODER_MAP_ENABLE)
// const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
//     [0] = { ENCODER_CCW_CW(KC_1, KC_2) }
// };
// #endif