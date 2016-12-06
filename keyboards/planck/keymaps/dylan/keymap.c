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
//#define _ADJUST 16

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  LOWER,
  RAISE,
  BACKLIT,
  EXT_PLV
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | NUMS | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */

[_QWERTY] = {
  { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC },
  { KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT },
  { KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT  },
  { MO(_NUM),KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT }
},


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Pause |      |      |      |      |      |      |   -  |   =  |   {  |   }  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   _  |   +  |   [  |   ]  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Enter    |      | Home | PgDn | PgUp | End  |
 * `-----------------------------------------------------------------------------------'
 */

[_LOWER] = { 
  { KC_TILD  , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN   , KC_RPRN , KC_DELT },
  { KC_PAUSE , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_MINS , KC_EQL  , KC_LCBR   , KC_RCBR , KC_BSLS },
  { _______  , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_UNDS , KC_PLUS , KC_LBRC   , KC_RBRC , _______ },
  { _______  , _______ , _______ , _______ , _______ , _______ , _______  , _______ , KC_HOME , KC_PGDOWN , KC_PGUP , KC_END  }
},


/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |      |      |      |      |      | Home | PagUp| PagDn| End  |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Pause |      |      |      |      |      |      |ShTab |CtShTb|      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      | Left |  Up  | Down | Right|      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Home | PgDw | PgUp | End  |
 * `-----------------------------------------------------------------------------------'
 */

[_RAISE] = { 
  { KC_GRV   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_HOME , KC_PGDOWN       , KC_PGUP      , KC_END    , KC_NO   , KC_DELT },
  { KC_PAUSE , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , LCTL(S(KC_TAB)) , LCTL(KC_TAB) , KC_NO     , KC_NO   , KC_NO   },
  { _______  , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_LEFT , KC_DOWN         , KC_UP        , KC_RGHT   , KC_NO   , _______ },
  { _______  , _______ , _______ , _______ , _______ , _______ , _______ , _______         , KC_HOME      , KC_PGDOWN , KC_PGUP , KC_END  }
},


[_NUM] = { 
  { KC_NO   , KC_F1 , KC_F2  , KC_F3  , KC_F4  , KC_NO  , KC_NO  , KC_7  , KC_8 , KC_9  , KC_NO , KC_INSERT } ,
  { KC_NO   , KC_F5 , KC_F6  , KC_F7  , KC_F8  , KC_NO  , KC_NO  , KC_4  , KC_5 , KC_6  , KC_NO , _______ } ,
  { _______ , KC_F9 , KC_F10 , KC_F11 , KC_F12 , KC_NO  , KC_NO  , KC_1  , KC_2 , KC_3  , KC_NO , _______ } ,
  { _______ , KC_NO , KC_NO  , KC_NO  , KC_NO  , KC_ENT , KC_ENT , KC_NO , KC_0 , KC_NO , KC_NO , _______ }
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
