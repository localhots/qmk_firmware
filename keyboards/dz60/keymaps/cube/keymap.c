#include "dz60.h"

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define MT_SLSH         MT(MOD_RSFT,KC_SLSH)
#define LAYOUT_2S       LAYOUT_2_shifts

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_2S( // Base layer
KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   XXXXXXX,  KC_BSPC,
KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
MO(1),    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,
KC_LSFT,  XXXXXXX,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   XXXXXXX,  MT_SLSH,  KC_UP,    XXXXXXX,
KC_LCTL,  KC_LALT,  KC_LGUI,                      KC_SPC,   KC_SPC,   KC_SPC,                       MO(2),    MO(2),    KC_LEFT,  KC_DOWN,  KC_RIGHT),

[1] = LAYOUT_2S( // Function layer
KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   XXXXXXX,  KC_DEL,
_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_UP,    _______,  _______,  KC_VOLD,  KC_VOLU,  KC_MUTE,
_______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT, _______,  _______,  _______,
_______,  XXXXXXX,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MRWD,  KC_MFFD,  XXXXXXX,  KC_MPLY,  _______,  XXXXXXX,
_______,  _______,  _______,                      _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______),

[2] = LAYOUT_2S( // Backlight control and extras
_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  XXXXXXX,  _______,
_______,  RGB_TOG,  RGB_MOD,  BL_TOGG,  BL_INC,   BL_STEP,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RESET,
_______,  RGB_HUI,  RGB_HUD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
_______,  XXXXXXX,  RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD,  _______,  _______,  _______,  _______,  _______,  XXXXXXX,  _______,  _______,  XXXXXXX,
_______,  _______,  _______,                      _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______),
};
