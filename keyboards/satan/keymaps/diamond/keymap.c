#include "satan.h"

// Used for SHIFT_ESC
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1

#define _______  KC_TRNS
#define PH(code) KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,-----------------------------------------------------------.
   * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
   * |-----------------------------------------------------------|
   * | Tab |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
   * |-----------------------------------------------------------|
   * | Fn    |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '| Enter |
   * |-----------------------------------------------------------|
   * | Shift  |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| Shift    |
   * |-----------------------------------------------------------|
   * |XXXXX|Ctrl| Cmd |                      | Alt | Fn |Fn|XXXXX|
   * `-----------------------------------------------------------'
   */
[_BL] = KEYMAP_ANSI(
  F(0),    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS, \
  MO(_FL), KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,         KC_ENT,  \
  KC_LSFT,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,         KC_RSFT, \
  KC_LCTL, KC_LALT,KC_LGUI,                LT(_FL, KC_SPC),                        KC_RGUI,MO(_FL), KC_RALT,KC_RCTL),


[_FL] = KEYMAP_ANSI(
  KC_GRV,      KC_F1,        KC_F2,          KC_F3,      KC_F4,      KC_F5,    KC_F6,    KC_F7,    KC_F8,       KC_F9,      KC_F10,      KC_F11,      KC_F12,     KC_DEL,  \
  KC_LALT,     LGUI(KC_GRV), LGUI(KC_TILDE), PH(KC_E),   PH(KC_R),   PH(KC_T), PH(KC_Y), PH(KC_U), KC_UP,       PH(KC_O),   PH(KC_P),    KC_VOLD,     KC_VOLU,    KC_MUTE, \
  _______,     KC_F13,       KC_F16,         KC_F17,     KC_F18,     PH(KC_G), PH(KC_H), KC_LEFT,  KC_DOWN,     KC_RIGHT,   PH(KC_SCLN), PH(KC_QUOT), PH(KC_ENT), \
  PH(KC_LSFT), BL_DEC,       BL_INC,         BL_TOGG,    PH(KC_V),   PH(KC_B), PH(KC_N), PH(KC_M), KC_MRWD,     KC_MFFD,    KC_MPLY,     PH(KC_RSFT), \
  PH(KC_LCTL), PH(KC_LALT),  PH(KC_LGUI),                PH(KC_SPC),                               PH(KC_RGUI), _______,    PH(KC_RALT), PH(KC_RCTL)),
};

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_FUNCTION(SHIFT_ESC),
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
