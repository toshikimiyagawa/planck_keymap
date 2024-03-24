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
  _LOWER,
  _RAISE,
  _ADJUST,
  _FN
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
#define FN MO(_FN)
#define S_ENT LSFT(KC_ENT)
#define S_SPC LSFT(KC_SPC)
#define CS_UP LCTL(LSFT(KC_UP))
#define CS_DOWN LCTL(LSFT(KC_DOWN))
#define CS_LEFT LCTL(LSFT(KC_LEFT))
#define CS_RGHT LCTL(LSFT(KC_RGHT))


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
      KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, \
      KC_RGUI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQL, \
      KC_LCTL, FN,      KC_F15,  KC_LCTL, LOWER,   KC_SPC,  KC_ENT,  RAISE,   KC_LSFT, KC_F15,  KC_RCTL,  KC_LCTL \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
      KC_CAPS, KC_PGUP, KC_HOME, KC_UP,   KC_END,  XXXXXXX,  KC_SCRL, KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_PSCR, \
      _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_ESC,   XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_TAB, \
      _______, KC_LCTL, KC_BSPC, KC_DEL,  KC_TAB,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, KC_LALT, KC_LSFT, KC_LCTL, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______   \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, \
      _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DQT, \
      _______, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_BSLS, KC_COLN, KC_PIPE, KC_LT,   KC_GT,   KC_QUES, KC_PLUS, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12(
      QK_BOOT, KVM_1,   KVM_2,   KVM_3,   KVM_4,   KVM_5,   KVM_6,   KVM_7,   KVM_8,   KVM_PRV, KVM_NXT, KC_PSCR, \
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F12, \
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),
[_FN] = LAYOUT_ortho_4x12(
      XXXXXXX, XXXXXXX, XXXXXXX, CS_UP,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, CS_LEFT, CS_DOWN, CS_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      _______, KVM_1,   KVM_2,   KVM_3,   KVM_4,   KVM_5,   KVM_6,   KVM_7,   KVM_8,   KVM_PRV, KVM_NXT, XXXXXXX, \
      _______, _______, _______, _______, KC_F13,  S_SPC,   S_ENT,   KC_F14,  _______, _______, _______, _______  \
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
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

// コンボの定義
const uint16_t PROGMEM combo1[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM combo2[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo3[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM combo4[] = {KC_Q, KC_W, COMBO_END};

combo_t key_combos[] = {
  COMBO(combo1, KC_F13),
  COMBO(combo2, KC_F14),
  COMBO(combo3, KC_TAB),
  COMBO(combo4, KC_ESC)
};