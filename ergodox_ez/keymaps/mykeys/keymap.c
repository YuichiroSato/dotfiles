#include QMK_KEYBOARD_H
#include "version.h"

#define PERMISSIVE_HOLD

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMB 2 // numbers
#define MDIA 3 // media keys

/* Japanese Keybord Alias */
#define JP_AT   KC_LBRC
#define JP_BSLS KC_SLSH
#define JP_COLN KC_QUOT
#define JP_CRET KC_EQL
#define JP_LBRC KC_RBRC
#define JP_RBRC KC_BSLS

enum custom_keycodes {
  EPRM = SAFE_RANGE,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | SftIns |  L1  |  L2  |  L3  |      |      |      |           |      |      |      |      |      |      | Delete |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Gui    |  :   |   ,  |   .  |   P  |   Y  |      |           |      |   F  |   G  |   C  |   R  |   L  | Esc    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Alt    |A/Ctrl| O/L1 |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  | N/L1 |S/Ctrl| Alt    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | ZKHK   |;/Shft| Q/L2 |   J  |   Z  |   X  |      |           |      |   B  |   M  |   W  | V/L2 |Z/Shft| MHEN   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      | END  | PgUp |PgDown| HOME |                                       | Left | Down |  Up  | Right|      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | PtrSc|      |       |      | Insert |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | Space| Tab  |------|       |------| Enter  |Back  |
 *                                 |      |      |      |       |      |        |space |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox(
  // left hand
  LSFT(KC_INS), TG(SYMB),       TG(NUMB),       TG(MDIA),KC_NO,   KC_NO,   KC_NO,
  KC_LGUI,      JP_COLN,        KC_COMM,        KC_DOT,  KC_P,    KC_Y,    KC_NO,
  KC_LALT,      CTL_T(KC_A),    LT(SYMB, KC_O), KC_E,    KC_U,    KC_I,
  KC_ZKHK,      SFT_T(KC_SCLN), LT(NUMB, KC_Q), KC_J,    KC_K,    KC_X,    KC_NO,
  KC_NO,        KC_END,         KC_PGUP,        KC_PGDN, KC_HOME,
                                                                  KC_PSCR, KC_NO,
                                                                           KC_NO,
                                                         KC_SPC,  KC_TAB,  KC_NO,
  // right hand
  KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,          KC_NO,          KC_DEL,
  KC_NO,        KC_F,    KC_G,    KC_C,    KC_R,           KC_L,           KC_ESC,
                KC_D,    KC_H,    KC_T,    LT(SYMB, KC_N), CTL_T(KC_S),    KC_RALT,
  KC_NO,        KC_B,    KC_M,    KC_W,    LT(NUMB, KC_V), SFT_T(KC_Z),    KC_MHEN,
  KC_LEFT,      KC_DOWN, KC_UP,   KC_RGHT, KC_NO,
  KC_NO,        KC_INS,
  KC_NO,
  KC_NO,        KC_ENT,  KC_BSPC
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |  ~   |   '  |   {  |   }  |      |           |      |   <  |   >  |   $  |   _  |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |  !   |  ?   |   "  |   (  |   )  |------|           |------|   -  |   =  |   *  |   +  |   /  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |  \   |  `   |   ^  |   [  |   ]  |      |           |      |   |  |   &  |   #  |   %  |   @  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
  KC_TRNS, KC_NO,          LSFT(JP_CRET),  LSFT(KC_7),     LSFT(JP_LBRC),  LSFT(JP_RBRC),  KC_TRNS,
  KC_TRNS, LSFT(KC_1),     LSFT(KC_SLSH),  LSFT(KC_2),     LSFT(KC_8),     LSFT(KC_9),
  KC_TRNS, KC_JYEN,        LSFT(JP_AT),    JP_CRET,        JP_LBRC,        JP_RBRC,        KC_TRNS,
  KC_TRNS, KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                           KC_TRNS,        KC_TRNS,
                                                                                           KC_TRNS,
                                                           KC_TRNS,        KC_TRNS,        KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
  KC_TRNS, LSFT(KC_COMM),  LSFT(KC_DOT),   LSFT(KC_4),     LSFT(KC_RO),    KC_NO,          KC_TRNS,
           KC_MINS,        LSFT(KC_MINS),  LSFT(JP_COLN),  LSFT(KC_SCLN),  KC_SLSH,        KC_TRNS,
  KC_TRNS, LSFT(KC_JYEN),  LSFT(KC_6),     LSFT(KC_3),     LSFT(KC_5),     JP_AT,          KC_TRNS,
  KC_TRNS, KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS,        KC_TRNS
),
/* Keymap 2: Number Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |   F12  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |  1   |  2   |   3  |   4  |   5  |------|           |------|   6  |   7  |   8  |   9  |   0  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |   (  |   )  |      |           |      |   -  |   =  |   *  |   +  |   /  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NUMB] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
  KC_TRNS, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRNS,
  KC_TRNS, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,
  KC_TRNS, KC_NO,          KC_NO,          KC_NO,          LSFT(KC_8),     LSFT(KC_9),     KC_TRNS,
  KC_TRNS, KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                                           KC_TRNS,        KC_TRNS,
                                                                                           KC_TRNS,
                                                           KC_TRNS,        KC_TRNS,        KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_F12,
  KC_TRNS, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRNS,
  KC_TRNS, KC_MINS,        LSFT(KC_MINS),  LSFT(JP_COLN),  LSFT(KC_SCLN),  KC_SLSH,        KC_TRNS,
  KC_TRNS, KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS,        KC_TRNS
),
/* Keymap 3: Media and mouse keyS
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |LCLICK|RCLICK|      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      | ACL2 | ACL1 | ACL0 |------|           |------|MsLeft|MsDown| MsUp |MsRght|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |WhLeft|WhDown| WhUp |WhRght|      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      | 
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
  KC_TRNS, KC_NO,   KC_NO,   KC_ACL2, KC_ACL1, KC_ACL0,
  KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_NO,   KC_BTN1, KC_BTN2, KC_NO,   KC_NO,   KC_TRNS,
           KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,   KC_TRNS,
  KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO,   KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
