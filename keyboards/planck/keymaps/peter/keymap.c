// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "action_layer.h"
//#ifdef AUDIO_ENABLE
  //#include "audio.h"
//#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap
// matrix below.  The underscores don't mean anything - you can have a layer
// called STUFF or any other name.  Layer names don't all need to be of the same
// length, obviously, and you can also skip them entirely and just use numbers.
#define _QWERTY 0
#define _LOWER  1
#define _RAISE  2
#define _NUM    3
//#define _PLOVER 5
#define _ADJUST 16

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  EXT_PLV
};


// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC},
  {MO(_NUM), KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_ENT}
},



[_LOWER] = { 
  { KC_PAUSE , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_PERC , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN   , KC_RPRN , KC_DEL},
  { _______  , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_HOME , KC_NO   , KC_MINS , KC_EQL  , KC_LCBR   , KC_RCBR , KC_BSLS },
  { _______  , KC_F9   , KC_F10  , KC_F11  , KC_F12  , KC_END  , KC_NO   , KC_UNDS , KC_PLUS , KC_LBRC   , KC_RBRC , _______ },
  { _______  , _______ , _______ , _______ , _______ , _______ , _______  , _______ , KC_VOLD, KC_VOLU , KC_VOLD , KC_RIGHT  }
},



[_RAISE] = { 
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    LALT(LCTL(KC_DEL)) },
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLD, KC_VOLU, KC_RGHT}
},


[_NUM] = { 
  { RESET   , KC_F1 , KC_F2  , KC_F3  , KC_F4  , KC_NO  , KC_NO, KC_INSERT, KC_NO   , KC_7  , KC_8 , KC_9  } ,
  { KC_NO   , KC_F5 , KC_F6  , KC_F7  , KC_F8  , KC_NO  , KC_NO, KC_DOWN, KC_UP, KC_4  , KC_5 , KC_6  } ,
  { _______ , KC_F9 , KC_F10 , KC_F11 , KC_F12 , LCTL(KC_MINS)  , S(LCTL(KC_MINS)), KC_LEFT, KC_RIGHT, KC_1  , KC_2 , KC_3  } ,
  { _______ , KC_LCTL , KC_LGUI  , KC_LALT  , KC_NO  , KC_ENT , KC_ENT, KC_INSERT, KC_NO  , KC_0 , KC_DOT , KC_SLSH }
}
};


void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _NUM);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _NUM);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _NUM);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _NUM);
      }
      return false;
      break;
  }
  return true;
}
