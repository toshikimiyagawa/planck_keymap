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
#include "muse.h"


enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _CAPS,
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
#define CAPS MO(_CAPS)
#define CTL_Z LCTL(KC_Z)
#define CTL_X LCTL(KC_X)
#define CTL_C LCTL(KC_C)
#define CTL_V LCTL(KC_V)
#define CTL_S_Z LCTL(LSFT(KC_Z))
#define WIN_V LGUI(KC_V)
#define L_DESK LGUI(LCTL(KC_LEFT))
#define R_DESK LGUI(LCTL(KC_RGHT))
#define AD_DESK LGUI(LCTL(KC_D))
#define P_TOYS LGUI(LALT(KC_SPC))
#define M_TASK LGUI(KC_TAB)
#define W_UP LGUI(KC_UP)
#define W_DOWN LGUI(KC_DOWN)
#define W_LEFT LGUI(KC_LEFT)
#define W_RGHT LGUI(KC_RGHT)
#define LO_F13 LT(_LOWER, KC_F13)
#define RA_F14 LT(_RAISE, KC_F14)
#define CTL_F9 CTL_T(KC_F9)
#define SFT_F7 SFT_T(KC_F7)
#define SFT_ENT LSFT(KC_ENT)
#define SFT_INS LSFT(KC_INS)
#define CTL_INS LCTL(KC_INS)
#define CTL_SPC LCTL(KC_SPC)
#define TO_QW TO(_QWERTY)
#define TO_LO TO(_LOWER)
#define TX_UP LCTL(LALT(LSFT(KC_UP)))
#define TX_DOWN LCTL(LALT(LSFT(KC_DOWN)))
#define TX_RGHT LCTL(LALT(LSFT(KC_RIGHT)))
#define TX_LEFT LCTL(LALT(LSFT(KC_LEFT)))
#define TX_SPLV LCTL(LALT(LSFT(KC_PGUP)))
#define TX_SPLH LCTL(LALT(LSFT(KC_PGDN)))
#define TX_NWIN LCTL(LALT(LSFT(KC_HOME)))
#define TX_PRFX LCTL(KC_RBRC)

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
[_QWERTY] = LAYOUT_planck_grid(
      KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, \
      CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_EQL, \
      KC_LCTL, KC_LGUI, KC_LALT, KC_LCTL, LOWER,   KC_SPC,  KC_ENT,  RAISE,   KC_LSFT, KC_LALT, KC_APP,  KC_LCTL \
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
[_LOWER] = LAYOUT_planck_grid(
      KC_PSCR, KC_ENT,  KC_PGUP, KC_UP,   KC_PGDN, XXXXXXX, XXXXXXX, KC_PGUP, KC_UP,   KC_PGDN, XXXXXXX, KC_ESC, \
      KC_F13,  KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_TAB, \
      _______, KC_ESC,  KC_BSPC, KC_DEL,  KC_TAB,  KC_ESC,  KC_ESC,  KC_TAB,  KC_DEL,  KC_BSPC, KC_ESC, KC_LSFT, \
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
[_RAISE] = LAYOUT_planck_grid(
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, \
      KC_F14,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DQT, \
      _______, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_BSLS, KC_PIPE, KC_COLN, KC_LT,   KC_GT,   KC_QUES, KC_PLUS, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

[_CAPS] = LAYOUT_planck_grid(
      XXXXXXX, P_TOYS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, L_DESK,  W_UP,    R_DESK,  AD_DESK, KVM_1,  \
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, W_LEFT,  W_DOWN,  W_RGHT,  M_TASK,  KVM_2,  \
      XXXXXXX, XXXXXXX, XXXXXXX, CTL_INS, SFT_INS, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KVM_3,  \
      RGB_TOG, RGB_MOD, XXXXXXX, XXXXXXX, KC_F13,  CTL_SPC,  XXXXXXX, KC_F14,  KVM_1,   KVM_2,   KVM_3,   KVM_4  \
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
[_ADJUST] = LAYOUT_planck_grid(
      KC_CAPS, KVM_1,   KVM_2,   KVM_3,   KVM_4,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, \
      KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12, \
      KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
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
