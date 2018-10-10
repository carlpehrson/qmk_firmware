#include "planck.h"
#include "action_layer.h"
#include "keymap_extras/keymap_swedish.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _WORKMAN,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  WORKMAN = SAFE_RANGE,
  LOWER,
  RAISE
};

#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Workman
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   D  |   R  |   W  |   B  |   J  |   F  |   U  |   P  |   '  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |CtlEsc|   A  |   S  |   H  |   T  |   G  |   Y  |   N  |   E  |   O  |   I  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   M  |   C  |   V  |   K  |   L  |   <  |   ,  |   .  | Ctrl |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   |  | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_WORKMAN] = {
  {KC_TAB,      KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,    KC_J,    KC_F,    KC_U,    KC_P,    NO_APOS, KC_BSPC},
  {CTL_T(KC_ESC),      KC_A,    KC_S,    KC_H,    KC_T,    KC_G,    KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_ENT},
  {KC_LSFT,     KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_K,    KC_L,    NO_LESS, KC_COMM, KC_DOT,  KC_LCTL},
  {NO_PIPE_MAC, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

#define ZM_IN LGUI(NO_PLUS)
#define ZM_OUT LGUI(NO_MINS)
#define COMNT LGUI(LSFT(KC_7))
#define UINDT LALT(LGUI(KC_8))
#define INDNT LALT(LGUI(KC_9))
#define TPREV LALT(LGUI(KC_LEFT))
#define TNEXT LALT(LGUI(KC_RGHT))
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   ?  |   $  |   %  |   &  |   1  |   2  |   3  |   4  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   "  | uind |  ind | ZmIn | ZmOut| Com  | Left |   5  |   6  |   7  |   8  |  9   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |   [  |   ]  |  F11 |  F12 |   0  |   Ö  |   Ä  |   Å  | 1pwd |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   #  |  |   |   ^  |      |      | Tprv | Tnxt |      | ZmOut| Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {NO_TILD, KC_EXLM,    NO_AT,   NO_QUES, NO_DLR,  KC_PERC, NO_AMPR, KC_1,    KC_2,    KC_3,    KC_4,    KC_DEL},
  {NO_QUO2, UINDT,      INDNT,   ZM_IN,   ZM_OUT,  COMNT,   KC_LEFT, KC_5,    KC_6,    KC_7,    KC_8,    KC_9},
  {_______, KC_F7,      KC_F8,   NO_LBRC, NO_RBRC, KC_F11,  KC_F12,  KC_0,    NO_OSLH, NO_AE,   NO_AA,   LGUI(NO_APOS)},
  {KC_HASH, NO_PIPE_MAC,NO_CIRC, _______, _______, TPREV,   TNEXT,   _______, KC_SLCK,  KC_VOLD, KC_VOLU, KC_PAUS}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ´  |   |  |   0  |   ^  |   $  |   5  |   6  |   7     8  |   9  |   0   | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   `  |   /  |   *  |   (  |   )  |   "  |   &  |Right |   =  |  Up  | Down |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   -  |   +  |   {  |   }  |   ^  |  F12 |   _  |   +  |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | Tprv |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {NO_ACUT,       NO_PIPE_MAC,KC_0,    NO_CIRC,     NO_DLR,      KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL},
  {LSFT(NO_ACUT), NO_SLSH,    NO_ASTR, NO_LPRN,     NO_RPRN,     KC_QUOT, NO_AMPR, KC_RGHT, NO_EQL,  KC_UP,   KC_DOWN, NO_BSLS_MAC},
  {_______,       NO_MINS,    NO_PLUS, NO_LCBR_MAC, NO_RCBR_MAC, NO_CIRC, KC_F12,  NO_UNDS, NO_PLUS, KC_PGUP, KC_PGDN, _______},
  {_______,       _______, _______, _______,     _______,     TPREV,   _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Wrkman|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL },
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, WORKMAN,  _______, _______, _______, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case WORKMAN:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_WORKMAN);
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
  }
  return true;
}
