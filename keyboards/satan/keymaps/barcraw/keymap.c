#include "satan.h"

// Used for SHIFT_ESC
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1
#define _RL 2
#define _EL 3
#define _GM 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,-----------------------------------------------------------.
   * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
   * |-----------------------------------------------------------|
   * |FN _FL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space      |Alt |FN _RL |FN _EL |Ctrl |
   * `-----------------------------------------------------------'
   */
[_BL] = KEYMAP_ANSI(
  F(0),    KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,    KC_7,     KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,     KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
  MO(_FL), KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,     KC_K,    KC_L,   KC_SCLN, KC_QUOT,          KC_ENT,  \
  KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,    KC_N,    KC_M,     KC_COMM, KC_DOT, KC_SLSH,                   KC_RSFT, \
  KC_LCTL, KC_LGUI, KC_LALT,                           KC_SPC,                             KC_RALT, MO(_RL), MO(_EL), KC_RCTL),

/* Keymap _FL: Vim Function Layer
   * ,-----------------------------------------------------------.
   * | ~ | F1|F2 |F3 |END|F5 |F6 |F7 |F8 |F9 |HM |F11|F12|  DEL  |
   * |-----------------------------------------------------------|
   * |    |  |  |  |  |  |  |  |  |  |Print|Scroll|Pause|        |
   * |-----------------------------------------------------------|
   * |      |  | | |PGDN| | LF | DW | UP | RT | INS |  |         |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |PGUP|   |   |   |   |  |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */
[_FL] = KEYMAP_ANSI(
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_END,  KC_F5,   KC_F6,   KC_F7,    KC_F8,   KC_F9,    KC_HOME, KC_F11,  KC_F12,  KC_DEL,  \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_PSCR, KC_SLCK, KC_PAUS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDN, KC_TRNS, KC_LEFT, KC_DOWN,  KC_UP ,  KC_RIGHT, KC_INS, KC_TRNS,           KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,                   KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

/* Keymap _EL: Layer Select Function Layer
   * ,-----------------------------------------------------------.
   * | ~ |Fn0|Fn1|F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|  DEL  |
   * |-----------------------------------------------------------|
   * |     |  |  |  |  |  |  |   |  |   |  |  |  |      |
   * |-----------------------------------------------------------|
   * |      |Left|Down|Rig|  |  |  |  |   |   |Home|PgUp|        |
   * |-----------------------------------------------------------|
   * |        |   |App|  |  |   |Vdn|Vup|Mute|End|PgDn|          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */

[_EL] = KEYMAP_ANSI(
  KC_GRV,  KC_TRNS, TG(_GM), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_CALC, KC_TRNS,  KC_INS,  KC_TRNS,  KC_PSCR, KC_SLCK, KC_PAUS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDN, KC_TRNS, KC_LEFT, KC_DOWN,  KC_UP ,  KC_RIGHT, KC_INS, KC_TRNS,           KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,                   KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  /* Keymap _RL: Media Keys Function Layer
   * ,-----------------------------------------------------------.
   * |   |   |   |   |   |   |   |   |   |   |   |   |   |       |
   * |-----------------------------------------------------------|
   * |     |   |PLAY|MUTE|   |   |   |   |   |   |   |BL-|BL+|BL |
   * |-----------------------------------------------------------|
   * |      |PRV|STP|NXT|   |   |   |       |   |   |   |        |
   * |-----------------------------------------------------------|
   * |        |RGB|RGB|RGB|RGB|RGB|RGB|RGB|RGB|   |   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */
[_RL] = KEYMAP_ANSI(
  #ifdef RGBLIGHT_ENABLE
  KC_GRV,  KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   \
  KC_TRNS, KC_TRNS, KC_MPLY, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, BL_DEC,  BL_INC,  BL_TOGG, \
  KC_TRNS, KC_MPRV, KC_STOP, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, \
  KC_TRNS, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_TRNS,                   KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
  #else
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  RESET,  \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, BL_DEC,  BL_INC,  BL_TOGG, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, \
  KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                    KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
  #endif

  /* Keymap _GM: Game Layer
   * ,-----------------------------------------------------------.
   * | ~ |Fn0|Fn1|F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|  DEL  |
   * |-----------------------------------------------------------|
   * |     |  |  |  |  |  |  |   |  |   |  |  |  |      |
   * |-----------------------------------------------------------|
   * |      |Left|Down|Rig|  |  |  |  |   |   |Home|PgUp|        |
   * |-----------------------------------------------------------|
   * |        |   |App|  |  |   |Vdn|Vup|Mute|End|PgDn|          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */

  [_GM] = KEYMAP_ANSI(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_UP  , KC_TRNS , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN,  KC_UP ,  KC_RIGHT, KC_TRNS, KC_TRNS,          KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS , KC_TRNS, KC_PGUP, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,                   KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch(id) {
    case 0: // this would trigger when you hit a key mapped as M(0)
      if (record->event.pressed) {
        return MACRO( I(1), T(H), T(E), T(L), T(L), W(255), T(O), END  ); // this sends the string 'hello' when the macro executes
      }
      break;

    case 1:
      if (record->event.pressed) {
        return MACRO( T(H), T(E), T(L), T(L), T(O), END  ); // this sends the string 'hello' when the macro executes
      }
      break;
  }
  return MACRO_NONE;
};
