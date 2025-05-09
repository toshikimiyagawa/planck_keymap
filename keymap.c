/* Copyright 2015-2017 Jack Humbert
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

enum planck_layers {
  _QWERTY,
  _JIS,
  _LOWER,
  _RAISE,
  _JISR,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  KVM_NXT,
  KVM_PRV,
  KVM_1,
  KVM_2,
  KVM_3,
  KVM_4,
  KVM_5,
  KVM_6,
  KVM_7,
  KVM_8
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define JIS TG(_JIS)
#define JISR MO(_JISR)
#define C_SPC LCTL(KC_SPC)
#define S_ENT LSFT(KC_ENT)
#define CS_LEFT LCTL(LSFT(KC_LEFT))
#define CS_RGHT LCTL(LSFT(KC_RGHT))


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ortho_4x12(
  KC_BSPC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, \
  KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_TAB,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQL, \
  KC_LCTL,  KC_RCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_ENT,  RAISE,   KC_RALT, KC_LGUI, KC_RCTL, KC_LCTL \
),

[_JIS] = LAYOUT_ortho_4x12(
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, \
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_AMPR, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UNDS, \
  KC_LCTL, KC_LGUI, KC_LALT, KC_LCTL, LOWER,   KC_SPC,  KC_ENT,  RAISE,   KC_LSFT, KC_F18,  KC_F19,  KC_F20 \
),

[_LOWER] = LAYOUT_ortho_4x12(
  KC_DEL, KC_PGUP, KC_HOME, KC_UP,   KC_END,  CS_LEFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, \
  KC_SCRL, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, CS_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F12, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
  _______, _______, _______, _______, _______, _______, S_ENT,   _______, _______, _______, _______, _______\
),

[_RAISE] = LAYOUT_ortho_4x12(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DQT, \
  _______, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_BSLS, KC_COLN, KC_PIPE, KC_LT,   KC_GT,   KC_QUES, KC_PLUS, \
  _______, _______, _______, _______, _______, C_SPC,   _______, _______, _______, _______, _______, _______\
),

[_JISR] = LAYOUT_ortho_4x12(
  KC_LCBR, KC_EXLM, KC_LBRC, KC_HASH, KC_DLR,  KC_PERC, KC_EQL,  KC_CIRC, KC_DQT,  KC_ASTR, KC_LPRN, S(KC_INT1), \
  KC_PLUS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_AT, \
  _______, S(KC_INT3), KC_INT1, KC_SCLN, KC_RCBR, KC_PIPE, KC_RBRC, KC_BSLS,  KC_LT,   KC_GT,   KC_QUES, KC_COLN, \
  _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, JIS \
),

[_ADJUST] = LAYOUT_ortho_4x12(
  QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, XXXXXXX, XXXXXXX,\
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  _______, KVM_1,   KVM_2,   KVM_3,   KVM_4,   KVM_5,   KVM_6,   KVM_7,   KVM_8,   KVM_PRV, KVM_NXT, XXXXXXX, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, JIS  \
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case JISR:
      if (record->event.pressed) {
        layer_on(_JISR);
        update_tri_layer(_LOWER, _JISR, _ADJUST);
      } else {
        layer_off(_JISR);
        update_tri_layer(_LOWER, _JISR, _ADJUST);
      }
      return false;
    case KVM_PRV:
      if (record->event.pressed) {
        register_code(KC_SCRL);
        unregister_code(KC_SCRL);
        register_code(KC_SCRL);
        unregister_code(KC_SCRL);
        register_code(KC_PGDN);
        unregister_code(KC_PGDN);
      }
      return false;
      break;
    case KVM_NXT:
      if (record->event.pressed) {
        register_code(KC_SCRL);
        unregister_code(KC_SCRL);
        register_code(KC_SCRL);
        unregister_code(KC_SCRL);
        register_code(KC_PGUP);
        unregister_code(KC_PGUP);
      }
      return false;
      break;
    case KVM_1:
      if (record->event.pressed) {
        register_code(KC_SCRL);
        unregister_code(KC_SCRL);
        register_code(KC_SCRL);
        unregister_code(KC_SCRL);
        register_code(KC_1);
        unregister_code(KC_1);
      }
      return false;
      break;
    case KVM_2:
      if (record->event.pressed) {
        register_code(KC_SCRL);
        unregister_code(KC_SCRL);
        register_code(KC_SCRL);
        unregister_code(KC_SCRL);
        register_code(KC_2);
        unregister_code(KC_2);
      }
      return false;
      break;
    case KVM_3:
      if (record->event.pressed) {
        register_code(KC_SCRL);
        unregister_code(KC_SCRL);
        register_code(KC_SCRL);
        unregister_code(KC_SCRL);
        register_code(KC_3);
        unregister_code(KC_3);
      }
      return false;
      break;
    case KVM_4:
      if (record->event.pressed) {
        register_code(KC_SCRL);
        unregister_code(KC_SCRL);
        register_code(KC_SCRL);
        unregister_code(KC_SCRL);
        register_code(KC_4);
        unregister_code(KC_4);
      }
      return false;
      break;
    case KVM_5:
      if (record->event.pressed) {
        register_code(KC_SCRL);
        unregister_code(KC_SCRL);
        register_code(KC_SCRL);
        unregister_code(KC_SCRL);
        register_code(KC_5);
        unregister_code(KC_5);
      }
      return false;
      break;
    case KVM_6:
      if (record->event.pressed) {
        register_code(KC_SCRL);
        unregister_code(KC_SCRL);
        register_code(KC_SCRL);
        unregister_code(KC_SCRL);
        register_code(KC_6);
        unregister_code(KC_6);
      }
      return false;
      break;
    case KVM_7:
      if (record->event.pressed) {
        register_code(KC_SCRL);
        unregister_code(KC_SCRL);
        register_code(KC_SCRL);
        unregister_code(KC_SCRL);
        register_code(KC_7);
        unregister_code(KC_7);
      }
      return false;
      break;
    case KVM_8:
      if (record->event.pressed) {
        register_code(KC_SCRL);
        unregister_code(KC_SCRL);
        register_code(KC_SCRL);
        unregister_code(KC_SCRL);
        register_code(KC_8);
        unregister_code(KC_8);
      }
      return false;
      break;
  }
  return true;
}

