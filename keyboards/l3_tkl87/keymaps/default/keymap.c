#include QMK_KEYBOARD_H

enum layers {
  _BASE = 0,
  _LONE,
};

#define ______ KC_TRNS
#define LT_L1SP LT(_LONE, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = KEYMAP(
       KC_ESC,   KC_F1,   KC_F2, KC_F3, KC_F4, KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,     KC_F10,  KC_F11,  KC_F12,                   KC_PSCR, KC_SLCK, KC_PAUS,
       KC_GRV,    KC_1,    KC_2,  KC_3,  KC_4,  KC_5,   KC_6,   KC_7,   KC_8,   KC_9,       KC_0, KC_MINS,  KC_EQL,   KC_NO, KC_BSPC,  KC_INS, KC_HOME, KC_PGUP,
       KC_TAB,    KC_Q,    KC_W,  KC_E,  KC_R,  KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,       KC_P, KC_LBRC, KC_RBRC, KC_BSLS,           KC_DEL,  KC_END, KC_PGDN,
      KC_LGUI,    KC_A,    KC_S,  KC_D,  KC_F,  KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,   KC_NO,  KC_ENT,
      KC_LSFT,   KC_NO,    KC_Z,  KC_X,  KC_C,  KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,                              KC_UP,
      KC_LCTL, KC_LGUI, KC_LALT,                      KC_SPC,                   KC_RALT, KC_RGUI, KC_RCTL,                            KC_LEFT, KC_DOWN, KC_RGHT),

  [_LONE] = KEYMAP(
        ______, KC_FN0, KC_FN1, KC_FN2, KC_FN3, KC_FN4, KC_FN5, KC_FN6, KC_FN7, KC_FN8, KC_FN9, ______, ______,                 ______, ______, ______,
        ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,
        ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______, ______, ______,
        ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,
        ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,                         ______,
        ______, ______, ______,                         ______,                 ______, ______, ______,                         ______, ______, ______),
};

enum function_id {
  ACTION_LED_CHANGE_MODE,
  ACTION_RGB_CHANGE_MODE,
  ACTION_LED_ON,
  ACTION_LED_OFF,
  ACTION_RGB_ON,
  ACTION_RGB_OFF,
  ACTION_LED_RGB_PRESET,
  ACTION_LED_SPEED
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch (id) {
    case ACTION_LED_CHANGE_MODE:
    if (record->event.pressed)
        {
          led_change_mode();
        }
      break;
    case ACTION_RGB_CHANGE_MODE:
    if (record->event.pressed)
        {
          rgb_change_mode();
        }
      break;
    case ACTION_LED_ON:
    if (record->event.pressed)
        {
          led_on();
        }
      break;
    case ACTION_LED_OFF:
    if (record->event.pressed)
        {
          led_off();
        }
      break;
    case ACTION_RGB_ON:
    if (record->event.pressed)
        {
          rgb_on();
        }
      break;
    case ACTION_RGB_OFF:
    if (record->event.pressed)
        {
          rgb_off();
        }
      break;
    case ACTION_LED_RGB_PRESET:
    if (record->event.pressed)
        {
          rgb_on();
        }
      break;
    case ACTION_LED_SPEED:
    if (record->event.pressed)
        {
          rgb_off();
        }
      break;
    default:
      break;
  }
}

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_BACKLIGHT_TOGGLE(),
    [1] = ACTION_BACKLIGHT_INCREASE(),
    [2] = ACTION_FUNCTION_TAP(ACTION_LED_CHANGE_MODE),
    [3] = ACTION_FUNCTION_TAP(ACTION_RGB_CHANGE_MODE),
    [4] = ACTION_FUNCTION_TAP(ACTION_LED_ON),
    [5] = ACTION_FUNCTION_TAP(ACTION_LED_OFF),
    [6] = ACTION_FUNCTION_TAP(ACTION_RGB_ON),
    [7] = ACTION_FUNCTION_TAP(ACTION_RGB_OFF),
    [8] = ACTION_FUNCTION_TAP(ACTION_LED_RGB_PRESET),
    [9] = ACTION_FUNCTION_TAP(ACTION_LED_SPEED),
};