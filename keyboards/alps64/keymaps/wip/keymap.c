#include "alps64.h"

#define _BASE 0 // Base Layer
#define _FN1 1 // 1st Function Layer

#define _______  KC_TRNS // No key
#define PH(code) KC_TRNS // Placeholder macro

// Describe Layers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = KEYMAP( \
KC_ESC,   KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS, KC_EQL,  _______, KC_BSPC, \
KC_TAB,   KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
MO(_FN1), KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  \
KC_LSFT,  _______, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, _______, \
KC_LCTL,  KC_LALT, KC_LGUI,                 KC_SPC,                                  _______, KC_RGUI, KC_RALT, KC_RCTL  ),

[_FN1] = KEYMAP( \
KC_GRV,      KC_F1,       KC_F2,       KC_F3,      KC_F4,      KC_F5,      KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,      KC_F11,      KC_F12,      _______,     KC_DEL, \
KC_LALT,     PH(KC_Q),    PH(KC_W),    PH(KC_E),   PH(KC_R),   PH(KC_T),   PH(KC_Y), PH(KC_U), KC_UP,    PH(KC_O),  PH(KC_P),    KC_VOLD,     KC_VOLU,     KC_MUTE,     \
_______,     KC_F13,      KC_F16,      KC_F17,     KC_F18,     PH(KC_G),   PH(KC_H), KC_LEFT,  KC_DOWN,  KC_RIGHT,  PH(KC_SCLN), PH(KC_QUOT),              PH(KC_ENT),  \
PH(KC_LSFT), _______,     PH(KC_Z),    PH(KC_X),   PH(KC_C),   PH(KC_V),   PH(KC_B), PH(KC_N), PH(KC_M), KC_MRWD,   KC_MFFD,     KC_MPLY,                  PH(KC_RSFT), _______, \
PH(KC_LCTL), PH(KC_LALT), PH(KC_LGUI),                         PH(KC_SPC),                                          _______,     PH(KC_RGUI), PH(KC_RALT), PH(KC_RCTL)  ),

// Done with layers
};
