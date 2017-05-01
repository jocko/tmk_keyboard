#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: qwerty */
    KEYMAP_ANSI(
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS, \
        ESC, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,  \
        LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,          RSFT, \
        LCTL,LALT,LGUI,          SPC,                     NO,  FN0, NO,  RCTL),
    KEYMAP_ANSI(
         ESC,  F1,  F2,  F3,  F4,  F5,  F6,   F7,  F8,  F9, F10, F11, F12,TRNS, \
        TRNS,TRNS,  UP,TRNS,TRNS,TRNS,TRNS, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,LEFT,DOWN,RGHT,TRNS,TRNS,TRNS, TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS,TRNS,TRNS,TRNS,          TRNS, \
        TRNS,TRNS,TRNS,          TRNS,                     TRNS,TRNS,TRNS,TRNS),
};
const action_t PROGMEM fn_actions[] = {
    /* Poker Layout */
    [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
};
