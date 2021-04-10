#include <stdint.h>
#include "annepro2.h"
#include "qmk_ap2_led.h"
#include "config.h"

enum anne_pro_layers {
  _BASE_LAYER,
  _FN1_LAYER,
  _FN2_LAYER,
  _FN3_LAYER,
};

// Key symbols are based on QMK. Use them to remap your keyboard
/*
* Layer _BASE_LAYER
* ,-----------------------------------------------------------------------------------------.
* | `   |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
* |-----------------------------------------------------------------------------------------+
* | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
* |-----------------------------------------------------------------------------------------+
* | Esc/FN1 |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  L1   |  Alt  |               space             |  FN3  |  FN1  |  FN2  | Ctrl  |
* \-----------------------------------------------------------------------------------------/
* Layer TAP in _BASE_LAYER
* ,-----------------------------------------------------------------------------------------.
* |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
* |-----------------------------------------------------------------------------------------+
* |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
* |-----------------------------------------------------------------------------------------+
* |         |     |     |     |     |     |     |     |     |     |     |     |             |
* |-----------------------------------------------------------------------------------------+
* |            |     |     |     |     |     |     |     |     |     |     |       UP       |
* |-----------------------------------------------------------------------------------------+
* |       |       |       |                                 |       |  LEFT | DOWN  | RIGHT |
* \-----------------------------------------------------------------------------------------/
*/
 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_BASE_LAYER] = KEYMAP( /* Base */
    KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
    LT(_FN1_LAYER,KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
    LSFT_T(KC_CAPS), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_UP),
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, MO(_FN3_LAYER), LT(_FN1_LAYER,KC_LEFT), LT(_FN2_LAYER,KC_DOWN), RCTL_T(KC_RGHT)
),
  /*
  * Layer _FN1_LAYER navigation via mouse keys and vim arrows navigation via mouse keys and vim arrows
  * ,-----------------------------------------------------------------------------------------.
  * |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  DELETE   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  q  | MSUP  |  e  |  r  |  t  |  y  |  u  |  i  |  o  | PS | HOME | END |  \   |
  * |-----------------------------------------------------------------------------------------+
  * | Esc | MLEFT |MDOWN | MRIGHT |  f  |  g  | LEFT |  DN | UP | RIGHT | PGUP | PGDN | Enter |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |V-UP |V-DWN| MUTE |  v  |  b  |  n  |  m  |  ,  |INSRT| DEL |    Shift      |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  MBTN3   |  MBTN2  |           MSBTN1           |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_FN1_LAYER] = KEYMAP( /* Base */
    KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
    KC_TRNS, KC_TRNS, KC_MS_UP, KC_TRNS, KC_ACL0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_HOME, KC_END, KC_TRNS,
    KC_TRNS, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_ACL1, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_PGUP, KC_PGDN, KC_TRNS,
    KC_TRNS, KC_VOLU, KC_VOLD, KC_MUTE, KC_ACL2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, KC_DEL, KC_TRNS,
    KC_TRNS, KC_BTN3, KC_MS_BTN2, KC_MS_BTN1, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
  /*
  * Layer _FN2_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |  ~  | BT1 | BT2 | BT3 | BT4 |  F5 |  F6 |  F7 |LEDOF|LEDON| F10 | F11 | F12 |    Bksp   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  q  | UP  |  e  |  r  |  t  |  y  |  u  |  i  |  o  | PS | HOME | END |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | Esc     |LEFT |DOWN |RIGHT|  f  |  g  |  h  |  j  |  k  |  l  | PGUP|PGDN |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |INSRT| DEL |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_FN2_LAYER] = KEYMAP( /* Base */
    KC_TRNS, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, KC_TRNS, KC_TRNS, KC_TRNS, KC_AP_LED_OFF, KC_AP_LED_ON, KC_AP_LED_NEXT_INTENSITY, KC_AP_LED_SPEED, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_HOME, KC_END, KC_TRNS,
    KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_PGDN, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, KC_DEL, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
 ),

  /*
  * Layer _FN3_LAYER for coding (easier access to symbols) and numpad
  * ,-----------------------------------------------------------------------------------------.
  * | `   |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  &  |  w  |  !  |  r  |  t  |  y  |  u  |  i  |  7  |  8  |  9  |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | Esc/FN1 |  {  |  (  |  )  |  }  | [ | ] |  h  |  j  |  k  |  4  |  5  |  6  |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |  [  |  <  |  >  |  ]  |  b  |  n  |  m  |  1  |  2  |  3  |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  FN3  |  0  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_FN3_LAYER] = KEYMAP(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_AMPR,KC_TRANSPARENT,KC_TRANSPARENT,KC_EXCLAIM,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_7,KC_8,KC_9,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_LCBR,KC_LPRN,KC_RPRN,KC_RCBR,KC_PIPE,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_4,KC_5,KC_6,KC_TRANSPARENT,KC_LSHIFT,KC_LBRACKET,KC_LEFT_ANGLE_BRACKET,KC_RIGHT_ANGLE_BRACKET,KC_RBRACKET,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_1,KC_2,KC_3,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_0,KC_TRANSPARENT,KC_TRANSPARENT),
};
const uint16_t keymaps_size = sizeof(keymaps);


void matrix_init_user(void) {

}

void matrix_scan_user(void) {
}

// Code to run after initializing the keyboard
void keyboard_post_init_user(void) {
    // Here are two common functions that you can use. For more LED functions, refer to the file "qmk_ap2_led.h"

    // annepro2-shine disables LEDs by default. Uncomment this function to enable them at startup.
    // annepro2LedEnable();

    // Additionally, it also chooses the first LED profile by default. Refer to the "profiles" array in main.c in
    // annepro2-shine to see the order. Replace "i" with the index of your preferred profile. (i.e the RED profile is index 0)
    // annepro2LedSetProfile(i);
}

layer_state_t layer_state_set_user(layer_state_t layer) {
    return layer;
}
