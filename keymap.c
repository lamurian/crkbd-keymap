#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
  _QWERTY, // Layer 0: Default
  _NUMBER, // Layer 1
  _SYMBOL, // Layer 2
  _CONFIG, // Layer 3
  _CURSOR, // Layer 4
  _GAME    // Layer 5
};

// Custom keycodes for layer keys
// Dual function escape with left command
#define KC_LGESC LGUI_T(KC_ESC)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NUMBER,
  SYMBOL,
  CONFIG,
  CURSOR,
  GAME
};

// Declare tap dance sequences
enum {
  TD_ACTL,
  TD_CALT,
};

// Tap dance definition
tap_dance_action_t tap_dance_actions[] = {
  [TD_ACTL] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_LCTL),
  [TD_CALT] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_LALT),
};

// Configure home row mods
#define HM_A LT(3, KC_A)
#define HM_S MT(MOD_LCTL, KC_S)
#define HM_D MT(MOD_LALT, KC_D)
#define HM_F LT(2, KC_F)

#define HM_J    LT(2, KC_J)
#define HM_K    MT(MOD_RALT, KC_K)
#define HM_L    MT(MOD_RCTL, KC_L)
#define HM_SCLN LT(3, KC_SCLN)

// Modified keys
#define MO_Z    MT(MOD_LSFT, KC_Z)
#define MO_SLSH MT(MOD_RSFT, KC_SLSH)

// Thumb-key clusters
#define TH_SPC LT(1, KC_SPC)
#define TH_ALT TD(TD_ACTL)
#define TH_CTL TD(TD_CALT)
#define TH_LCA LCTL(KC_LALT)
#define TH_RCA RCTL(KC_RALT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.  Layer 0: Default  ,-----------------------------------------------------.
      XXXXXXX,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    HM_A,    HM_S,    HM_D,    HM_F,    KC_G,                         KC_H,    HM_J,    HM_K,    HM_L, HM_SCLN, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    MO_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, MO_SLSH, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXXXXXX,   TH_ALT, KC_LGUI,     TH_SPC,  TH_CTL, XXXXXXX \
                                      //`--------------------------'  `--------------------------'

  ),

  [_NUMBER] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.       Layer 1      ,-----------------------------------------------------.
      XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_ESC,  KC_GRV, KC_BSPC,  KC_TAB, KC_CAPS,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT,  KC_ENT, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   TG(5),   TG(4),   TG(3),   TG(2), XXXXXXX,                      XXXXXXX, XXXXXXX,  TH_ALT,  TH_CTL, KC_TRNS, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
    ),

  [_SYMBOL] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.       Layer 2      ,-----------------------------------------------------.
      XXXXXXX, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_ESC,  KC_GRV, KC_BSPC,  KC_TAB, KC_CAPS,                      KC_LBRC, KC_MINS, KC_EQL,  KC_RBRC, KC_BSLS, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   TO(0), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_QUOT, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX,KC_LSFT,    KC_RSFT, RCTL(KC_B), XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  ),

  [_CONFIG] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.       Layer 3      ,-----------------------------------------------------.
      XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX,                       XXXXXXX, KC_PGDN, KC_PGUP, KC_F11,  KC_F12,  XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   TO(0), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, KC_LALT,  TH_LCA,     TH_RCA, KC_RALT, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  ),

  [_CURSOR] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.       Layer 4      ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX,                      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   TO(0), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,  TH_CTL, KC_LGUI,    KC_BTN1, KC_BTN2, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  ),

  [_GAME] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.       Layer 5      ,-----------------------------------------------------.
      XXXXXXX,  KC_TAB, KC_ESC,    KC_W,    KC_E,    KC_R,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LSFT,   KC_A,    KC_S,    KC_D,    KC_F,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   TO(0),   KC_Z,    KC_X,    KC_C,    KC_V,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,  KC_SPC,  TH_CTL,     TH_SPC,  TH_ALT, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  )
};
