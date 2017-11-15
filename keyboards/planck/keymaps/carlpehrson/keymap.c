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

#include "planck.h"
#include "action_layer.h"
#include "keymap_extras/keymap_swedish.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _WORKMAN,
  _DEAD,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  WORKMAN,
  DEAD,
  LOWER,
  RAISE,
  BACKLIT
};

#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Ö  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   Ä  |  Å   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    NO_OSLH, KC_ENT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  NO_AE,   NO_AA},
  {BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Workman
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   D  |   R  |   W  |   B  |   J  |   F  |   U  |   P  |   '  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   H  |   T  |   G  |   Y  |   N  |   E  |   O  |   I  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   M  |   C  |   V  |   K  |   L  | Dead |   ,  |   .  |  Å   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_WORKMAN] = {
  {KC_TAB,  KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,    KC_J,    KC_F,    KC_U,    KC_P,    NO_APOS, KC_BSPC},
  {KC_ESC,  KC_A,    KC_S,    KC_H,    KC_T,    KC_G,    KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_ENT},
  {KC_LSFT, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_K,    KC_L,    DEAD, KC_COMM,    KC_DOT,  NO_AA},
  {BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Workman Dead Layer
 * ,-----------------------------------------------------------------------------------.
 * |      |   !  |   &  |   ?  |   +  |   @  |   $  |   _  |   [  |   ]  |   "  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   /  |   (  |   =  |   0  |   {  |   }  |   1  |   *  |   )  |   Ö  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   6  |   7  |   8  |   9  |   |  |   \  |   2  |   3  |   4  |   5  |  Ä   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |   %  |   ~  |   `  |   <  |   >  |   #  |   ^  |   >  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_DEAD] = {
  {XXXXXXX,  KC_EXLM, NO_AMPR, NO_QUES, NO_PLUS,       NO_AT,       NO_DLR,      NO_UNDS, NO_LBRC, NO_RBRC, NO_QUO2, XXXXXXX},
  {XXXXXXX,  NO_SLSH, NO_LPRN, NO_EQL,  KC_0,          NO_LCBR_MAC, NO_RCBR_MAC, KC_1,    NO_ASTR, NO_RPRN, NO_OSLH, XXXXXXX},
  {XXXXXXX,  KC_6,    KC_7,    KC_8,    KC_9,          NO_PIPE_MAC, NO_BSLS_MAC, KC_2,    KC_3,    KC_4,    KC_5,    NO_AE},
  {XXXXXXX,  XXXXXXX, KC_PERC, NO_TILD, LSFT(NO_ACUT), NO_LESS,     NO_GRTR,     KC_HASH, NO_CIRC, NO_GRTR, XXXXXXX, XXXXXXX}
},
#define ZM_IN LGUI(NO_PLUS)
#define ZM_OUT LGUI(NO_MINS)
#define COMNT LGUI(LSFT(KC_7))
#define UINDT LALT(LGUI(KC_8))
#define INDNT LALT(LGUI(KC_9))
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   ?  |   $  |   %  |   &  |   1  |   2  |   3  |   4  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  | uind |  ind |   <  |   >  | Com  |  F6  |   5  |   6  |   7  |   8  |  9   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   0  |   Ö  |   Ä  |   Å  | 1pwd |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   #  |  |   |   ^  |      |      |   [  |   ]  |      | ZmOut| Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {NO_TILD, KC_EXLM,    NO_AT,   NO_QUES, NO_DLR,  KC_PERC, NO_AMPR, KC_1,    KC_2,    KC_3,    KC_4,    KC_DEL},
  {KC_DEL,  UINDT,      INDNT,   NO_LESS, NO_GRTR, COMNT,   KC_F6,   KC_5,    KC_6,    KC_7,    KC_8,    KC_9},
  {_______, KC_F7,      KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_0,    NO_OSLH, NO_AE,   NO_AA,   LGUI(NO_APOS)},
  {KC_HASH, NO_PIPE_MAC,NO_CIRC, _______, _______, NO_LBRC, NO_RBRC, _______, ZM_OUT,  KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ´  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |   /  |   *  |   (  |   )  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   `  |   -  |   +  |   {  |   }  |  F11 |  F12 |   _  |   +  |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {NO_ACUT,       KC_1,    KC_2,    KC_3,        KC_4,        KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_DEL,        NO_SLSH, NO_ASTR, NO_LPRN,     NO_RPRN,     KC_F5,   KC_F6,   NO_MINS, NO_EQL,  NO_LBRC, NO_RBRC, NO_BSLS_MAC},
  {LSFT(NO_ACUT), NO_MINS, NO_PLUS, NO_LCBR_MAC, NO_RCBR_MAC, KC_F11,  KC_F12,  NO_UNDS, NO_PLUS, KC_PGUP, KC_PGDN, _______},
  {_______,       _______, _______, _______,     _______,     _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Wrkman|      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL },
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  WORKMAN, _______, _______, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}


};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
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
    case WORKMAN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_WORKMAN);
      }
      return false;
      break;
    case DEAD:
      if (record->event.pressed) {
        layer_on(_DEAD);
        set_oneshot_layer(_DEAD, ONESHOT_START);
        clear_oneshot_layer_state(ONESHOT_PRESSED);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
  }
  return true;
}