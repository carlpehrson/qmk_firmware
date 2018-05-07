#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "keymap_extras/keymap_swedish.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  | Backspc|
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   D  |   R  |   W  |   B  |  L1  |           |  L2  |   J  |   F  |   U  |   P  |   Å  |   Ä    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctrl   |   A  |   S  |   H  |   T  |   G  |------|           |------|   Y  |   N  |   E  |   O  |   I  |   Ö    |
 * |--------+------+------+------+------+------|  '   |           | Meh  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   M  |   C  |   V  |      |           |      |   K  |   L  | </L1 |   ,  |   .  |  ~L1   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  Alt | Left | Right| Cmd  |                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | End  |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Cmd   |Enter |
 *                                 |      |      | Esc  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_LEFT,
        KC_TAB,         KC_Q,         KC_D,   KC_R,   KC_W,   KC_B,   TG(SYMB),
        KC_LCTL,        KC_A,         KC_S,   KC_H,   KC_T,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_M,   KC_C,   KC_V,   NO_APOS,
        LT(SYMB,KC_GRV),KC_LALT,      KC_LEFT,KC_RGHT,KC_LGUI,
                                              ALT_T(KC_APP),  KC_END,
                                                              KC_HOME,
                                               KC_SPC,KC_BSPC,KC_ESC,
        // right hand
             KC_RGHT,     KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_BSPC,
             TG(MDIA),    KC_J,   KC_F,  KC_U,   KC_P,   NO_AA,            NO_AE,
                          KC_Y,   KC_N,  KC_E,   KC_O,   KC_I,             NO_OSLH,
             MEH_T(KC_NO),KC_K,   KC_L,  LT(SYMB,NO_LESS),KC_COMM,KC_DOT,           KC_FN1,
                                  KC_UP, KC_DOWN,NO_LBRC,NO_RBRC,          KC_FN1,
             KC_LALT,        CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,KC_LGUI, KC_ENT
    ),

    #define TPREV LALT(LGUI(KC_LEFT))
    #define TNEXT LALT(LGUI(KC_RGHT))
    /* Keymap 1: Symbol Layer
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |   ?  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |    -   |   _  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |   /  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |   #  |   %  | Prev | Next |                                       |      |    . |   0  |   =  |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 |      |      |------|       |------|      |      |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     */
    // SYMBOLS
    [SYMB] = LAYOUT_ergodox(
           // left hand
           KC_TRNS,KC_F1,  KC_F2, KC_F3,      KC_F4,      KC_F5,       KC_TRNS,
           KC_TRNS,NO_QUES,NO_AT,  NO_LCBR_MAC,NO_RCBR_MAC,NO_PIPE_MAC,KC_TRNS,
           NO_MINS,NO_UNDS,NO_DLR, NO_LPRN,    NO_RPRN,    LSFT(NO_ACUT),
           KC_TRNS,NO_SLSH,NO_CIRC,NO_LBRC,    NO_RBRC,    NO_TILD,    KC_TRNS,
           KC_TRNS,KC_HASH,KC_PERC,TPREV,      TNEXT,
                                           KC_TRNS,KC_TRNS,
                                                   KC_TRNS,
                                   KC_TRNS,KC_TRNS,KC_TRNS,
           // right hand
           KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,     KC_F11,
           KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    NO_ASTR,    KC_F12,
                    KC_DOWN, KC_4,   KC_5,    KC_6,    NO_PLUS,    KC_TRNS,
           KC_TRNS, NO_AMPR, KC_1,   KC_2,    KC_3,    NO_BSLS_MAC,KC_TRNS,
                             KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
           KC_TRNS, KC_TRNS,
           KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS
    ),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Reset |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
      }
      break;
  }
  return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    // TODO: Make this relevant to the ErgoDox EZ.
    case SYMB:
      ergodox_right_led_1_on();
      break;
    case MDIA:
      ergodox_right_led_2_on();
      break;
    default:
      // none
      break;
  }

};
