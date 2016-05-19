#include "keymap_common.h"

/*
 * dvarg
 */
const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = {
    {KC_FN10, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,    KC_NO},
    {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,    KC_LBRC, KC_BSPC,  KC_NO},
    {KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN, KC_QUOT, KC_ENT,   KC_NO},
    {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH, KC_RSFT, KC_NO,    KC_NO},
    {KC_NO,   KC_NO,   KC_LALT, KC_FN0,  KC_LCTL, KC_SPC,  KC_FN1,  KC_FN8,  KC_NO,   KC_LEFT,  KC_DOWN, KC_UP,   KC_RIGHT, KC_NO},
  },
  [1] = {
    {KC_BTLD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS},
    {KC_FN5,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_TRNS, KC_TRNS,  KC_TRNS},
    {KC_TRNS, KC_FN11, KC_QUOT, KC_LBRC, KC_FN12, KC_FN13, KC_FN14, KC_FN15, KC_RBRC, KC_MINS,  KC_FN16, KC_TRNS, KC_TRNS,  KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_LALT, KC_FN0,  KC_LCTL, KC_SPC,  KC_FN1,  KC_RGUI, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS},
  },
  [2] = {
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS},
    {KC_GRV,  KC_FN20, KC_FN21, KC_FN22, KC_FN23, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_BSLS, KC_TRNS, KC_TRNS,  KC_TRNS},
    {KC_TRNS, KC_FN24, KC_FN25, KC_FN26, KC_FN27, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_EQL,  KC_TRNS, KC_TRNS,   KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_LALT, KC_FN0,  KC_LCTL, KC_SPC,  KC_FN1,  KC_RGUI, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS},
  },
};

enum macro_id {
  CMD_TAB,
  CTL_TAB,
};

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
    [1] = ACTION_LAYER_MOMENTARY(2),

    [5] = ACTION_MACRO(CMD_TAB),
    [6] = ACTION_MACRO(CTL_TAB),
    [7] = ACTION_MODS_TAP_KEY(MOD_RGUI, KC_SCLN),
    [8] = ACTION_MODS_ONESHOT(MOD_RGUI),

    [10] = ACTION_MODS_KEY(MOD_LSFT, KC_GRV),
    [11] = ACTION_MODS_KEY(MOD_LSFT, KC_QUOT),
    [12] = ACTION_MODS_KEY(MOD_LSFT, KC_9),
    [13] = ACTION_MODS_KEY(MOD_LSFT, KC_LBRC),
    [14] = ACTION_MODS_KEY(MOD_LSFT, KC_RBRC),
    [15] = ACTION_MODS_KEY(MOD_LSFT, KC_0),
    [16] = ACTION_MODS_KEY(MOD_LSFT, KC_MINS),
    [17] = ACTION_MODS_KEY(MOD_LSFT, KC_QUOT),
    [18] = ACTION_MODS_KEY(MOD_LSFT, KC_QUOT),
    [19] = ACTION_MODS_KEY(MOD_LSFT, KC_QUOT),

    [20] = ACTION_MODS_KEY(MOD_LSFT, KC_1),
    [21] = ACTION_MODS_KEY(MOD_LSFT, KC_2),
    [22] = ACTION_MODS_KEY(MOD_LSFT, KC_3),
    [23] = ACTION_MODS_KEY(MOD_LSFT, KC_4),
    [24] = ACTION_MODS_KEY(MOD_LSFT, KC_5),
    [25] = ACTION_MODS_KEY(MOD_LSFT, KC_6),
    [26] = ACTION_MODS_KEY(MOD_LSFT, KC_7),
    [27] = ACTION_MODS_KEY(MOD_LSFT, KC_8),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) 
{
  switch(id) {
    case CMD_TAB:
      return (record->event.pressed ?
          MACRO( D(LGUI), D(TAB), END ) :
          MACRO( U(TAB), END ));
    case CTL_TAB:
      return (record->event.pressed ?
          MACRO( D(LCTL), D(TAB), END ) :
          MACRO( U(TAB), END ));
  } 
  return MACRO_NONE;
};
