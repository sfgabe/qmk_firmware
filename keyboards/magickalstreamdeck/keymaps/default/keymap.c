/* Copyright 2022 Gabe Galaxy
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
      HYPR(KC_F13), HYPR(KC_F14), HYPR(KC_F15), HYPR(KC_F16), KC_AUDIO_MUTE,
      HYPR(KC_F17), HYPR(KC_F18), HYPR(KC_F19), HYPR(KC_F20),
      MEH(KC_F17), MEH(KC_F18), MEH(KC_F19), MEH(KC_F20), RGB_TOG
    ),
    [_FN] = LAYOUT(
      HYPR(KC_F13), HYPR(KC_F14), HYPR(KC_F15), HYPR(KC_F16), KC_AUDIO_MUTE,
      HYPR(KC_F17), HYPR(KC_F18), HYPR(KC_F19), HYPR(KC_F20),
      MEH(KC_F17), MEH(KC_F18), MEH(KC_F19), MEH(KC_F20), RGB_TOG
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_AUDIO_VOL_UP);
        } else {
            tap_code(KC_AUDIO_VOL_DOWN);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_LEFT);
        } else {
            tap_code(KC_RIGHT);
        }
    }
    return false;
}

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
  rgblight_sethsv_noeeprom(255, 74, 250);
}
#endif
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//
// //    rgblight_get_val();
// //    rgblight_setrgb(RGB_PINK);
//
//     switch (keycode) {
//         case QMKBEST:
//             if (record->event.pressed) {
//                 // when keycode QMKBEST is pressed
//                 SEND_STRING("QMK is the best thing ever!");
//             } else {
//                 // when keycode QMKBEST is released
//             }
//             break;
//         case QMKURL:
//             if (record->event.pressed) {
//                 // when keycode QMKURL is pressed
//                 SEND_STRING("https://qmk.fm/\n");
//             } else {
//                 // when keycode QMKURL is released
//             }
//             break;
//     }
//     return true;
// }
