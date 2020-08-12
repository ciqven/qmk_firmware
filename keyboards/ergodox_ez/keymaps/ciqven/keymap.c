#include QMK_KEYBOARD_H
#include "version.h"

// Layers
// ---------------
enum layers {
    ALPH, // default layer
    SYMB, // symbols
    EXTR,  // media & mouse keys,
    GAME, // Game mode
    GAMX, // Game side swap layer
    TYER, // tyeirem romanized
    TYES  // tyeirem romanized shifted
};

#define RGBLIGHT_COLOR_LAYER_0 27,   255,  255
#define RGBLIGHT_COLOR_LAYER_1 0,    255,  255
#define RGBLIGHT_COLOR_LAYER_2 242,  255,  255
#define RGBLIGHT_COLOR_LAYER_3 187,  255,  255
#define RGBLIGHT_COLOR_LAYER_4 134,  255,  255
#define RGBLIGHT_COLOR_LAYER_5 100,  255,  255 
#define RGBLIGHT_COLOR_LAYER_6 210,  255,  255
#define RGBLIGHT_COLOR_LAYER_7 0,    0,    255 

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  VRSN = EZ_SAFE_RANGE,
#else
  VRSN = SAFE_RANGE,
#endif
  RGB_SLD
};

// Unicode
// -------------
enum unicode_names {
  // romanized vowels
    TY_IH,
    TY_EH,
    TY_AH,
    TY_AO,
    TY_UH,
    TY_OH,
    TY_OO,
    TY_OOH,
  // romanized cons
    TY_G,
    TY_ZH,
    TY_NH,
    TY_SH,
    TY_F,
    TY_FH,
    TY_C,
    TY_CH,
    TY_CC,
    TY_CCH,
    TY_QQ,
    TY_QQH,
  // punctuation & misc
    TY_STOP,
    TY_STRESS,
    TY_REP,
    TY_LONG,
    TY_NUM10,
    TY_NUM11,
    TY_VAR1,
    TY_VAR2,
    TY_VAR3,
    TY_VAR4,
    TY_VAR5,
    TY_VAR6,
    TY_VAR7,
    TY_VAR8,
    TY_VAR9,
    TY_VAR0
};

const uint32_t PROGMEM unicode_map[] = {
  // romanized vowels
    [TY_IH]  = 0x012D,
    [TY_EH]  = 0x0115,
    [TY_AH]  = 0x0103,
    [TY_AO]  = 0x0105,
    [TY_UH]  = 0x016D,
    [TY_OH]  = 0x014F,
    [TY_OO]  = 0x01EB,
    [TY_OOH] = 0x0275,
  // romanized cons
    [TY_G]   = 0x011F,
    [TY_ZH]  = 0x0240,
    [TY_NH]  = 0x0273,
    [TY_SH]  = 0x1D79,
    [TY_F]   = 0x00FE,
    [TY_FH]  = 0x01AA,
    [TY_C]   = 0x00E7,
    [TY_CH]  = 0x2C76,
    [TY_CC]  = 0x023C,
    [TY_CCH] = 0x01E5,
    [TY_QQ]  = 0x01C2,
    [TY_QQH] = 0x0256,
  // punctuation & misc
    [TY_STOP]   = 0x0242,
    [TY_STRESS] = 0x02BC,
    [TY_REP]    = 0x01BA,
    [TY_LONG]   = 0x2013,
    [TY_NUM10]  = 0x218A,
    [TY_NUM11]  = 0x218B,
    [TY_VAR1]   = 0x25B5,
    [TY_VAR2]   = 0x25E6,
    [TY_VAR3]   = 0x25AB,
    [TY_VAR4]   = 0x25CA,
    [TY_VAR5]   = 0x2606,
    [TY_VAR6]   = 0x27E1,
    [TY_VAR7]   = 0x29BE,
    [TY_VAR8]   = 0x2982,
    [TY_VAR9]   = 0x29C8,
    [TY_VAR0]   = 0x2A1D
};

// Keymaps
// -------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Alpha layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |   1  |   2  |   3  |   4  |   5  |   [  |           |  ]   |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   F  |   P  |   B  |      |           |      |   J  |   L  |   U  |   Y  |   ;  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   R  |   S  |   T  |   G  |------|           |------|   M  |   N  |   E  |   I  |   O  |        |
 * |--------+------+------+------+------+------|      |           |SUPER |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   V  |      |           |      |   K  |   H  |   ,  |   .  |   /  |  LAlt  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCtl |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |TGGAME|       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |TGTYER|       |      |      |      |
 *                                 | Space|Enter |------|       |------|LTEXTR|LTSYMB|
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[ALPH] = LAYOUT_ergodox_pretty(
  // left hand
  KC_ESC,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_LBRC,             KC_RBRC, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
  KC_TAB,          KC_Q,        KC_W,          KC_F,    KC_P,    KC_B,    XXXXXXX,             XXXXXXX, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, XXXXXXX,
  KC_BSPC,         KC_A,        KC_R,          KC_S,    KC_T,    KC_G,                                  KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    XXXXXXX,
  KC_LSFT,         KC_Z,        KC_X,          KC_C,    KC_D,    KC_V,    XXXXXXX,             KC_LWIN, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_LALT,
  KC_LCTRL,        XXXXXXX,     XXXXXXX,       XXXXXXX, XXXXXXX,                                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                                XXXXXXX,  TG(GAME),            XXXXXXX, XXXXXXX,
                                                                          TG(TYER),            XXXXXXX,
                                                         KC_SPC, KC_ENT,  XXXXXXX,             XXXXXXX, LT(EXTR, XXXXXXX), LT(SYMB, XXXXXXX)
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      | Home |  Up  | End  |      |      |           | PrScr|      |   (  |   )  |      |   \  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   Del   |      | Left | Down | Right|      |------|           |------|      |   [  |   ]  |      |   `  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift  |      | PgUp |      | PgDn |      |      |           |      |      |   -  |   =  |  "   |   '  |  LAlt  |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCtl  |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox_pretty(
  // left hand
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
  _______, _______, KC_HOME, KC_UP,   KC_END,  _______, _______,     _______, _______, KC_LPRN, KC_RPRN, _______, KC_BSLS, _______,
  KC_DEL,  _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,                        _______, KC_LBRC, KC_RBRC, _______, KC_GRV,  _______,
  KC_LSFT, _______, KC_PGUP, _______, KC_PGDN, _______, _______,     _______, _______, KC_MINS, KC_EQL,  KC_DQUO, KC_QUOT, KC_LALT,
  KC_LCTL, _______, _______, _______, _______,                                         _______, _______,  _______,    _______,  _______,
                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, _______
),
/* Keymap 2: Media and mouse keys, extra
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      | MACC0| RESET  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      | MACC1|        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Insert |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      | MB4  |      | MACC2|        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CapsLc |      |      |      |      |      |      |           |      |      | MLft | MMdl | MRgt | MWU  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      | MB5  | MW<  | MWD  | MW>  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |  |<  |  >|  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       | Vol+ |      |      |
 *                                 |      |      |------|       |------|      | Play |
 *                                 |      |      |      |       | Vol- |      |      |
 *                                 `--------------------'       `--------------------'
 */
[EXTR] = LAYOUT_ergodox_pretty(
  // left hand
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, KC_ACL0, RESET,
  _______, _______, _______, KC_MS_U, _______, _______, _______,     _______, _______, _______, _______, _______, KC_ACL1, _______,
  KC_INS,  _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,                       _______, _______, KC_BTN4, _______, KC_ACL2, _______,
  KC_CAPS, _______, _______, _______, _______, _______, _______,     _______, _______, KC_BTN1, KC_BTN2, KC_BTN3, KC_WH_U, _______,
  _______, _______, _______, _______, _______,                                         _______, KC_BTN5, KC_WH_L, KC_WH_D, KC_WH_R,

                                               _______, _______,     KC_MPRV, KC_MNXT,
                                                        _______,     KC_VOLU,
                                      _______, _______, _______,     KC_VOLD, _______, KC_MPLY
),
/* Keymap 3: Game
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |   1  |   2  |   3  |   4  |   5  |   [  |           |  ]   |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   F  |   P  |   B  | NUM0 |           | NUM2 |   J  |   L  |   U  |   Y  |   ;  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   R  |   S  |   T  |   G  |------|           |------|   M  |   N  |   E  |   I  |   O  |        |
 * |--------+------+------+------+------+------| NUM1 |           | NUM3 |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   V  |      |           |      |   K  |   H  |   ,  |   .  |   /  |  LAlt  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCtl | LAlt | PgUp | PgDn |LTGAMX|                                       |      |      |      |   \  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  F15 |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |  F13 |       |      |      |      |
 *                                 | Space|Enter |------|       |------|      |      |
 *                                 |      |      |  F14 |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[GAME] = LAYOUT_ergodox_pretty(
  // left hand
  KC_ESC,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_LBRC,             KC_RBRC,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
  KC_TAB,          KC_Q,        KC_W,          KC_F,    KC_P,    KC_B,    KC_P0,               KC_P2,        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, XXXXXXX,
  KC_BSPC,         KC_A,        KC_R,          KC_S,    KC_T,    KC_G,                                       KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    XXXXXXX,
  KC_LSFT,         KC_Z,        KC_X,          KC_C,    KC_D,    KC_V,    KC_P1,               KC_P3,        KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_LALT,
  KC_LCTRL,        KC_LALT,     KC_PGUP,       KC_PGDN, LT(GAMX, XXXXXXX),                                                     XXXXXXX, XXXXXXX, XXXXXXX, KC_BSLS, XXXXXXX,
                                                                 KC_F15,  _______,                XXXXXXX, XXXXXXX,
                                                                          KC_F13,                 XXXXXXX,
                                                         KC_SPC, KC_ENT,  KC_F14,                 XXXXXXX, XXXXXXX, XXXXXXX
),
/* Keymap 4: GameX
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   [    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |        |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |   ]    |   J  |   L  |   U  |   Y  |   ;  | NUM0 |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   M  |   N  |   E  |   I  |   O  |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------| NUM1 |           |      |------+------+------+------+------+--------|
 * |        |   K  |   H  |   ,  |   .  |   /  |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | NUM4 | NUM5 | NUM6 | NUM7 |LTGAMX|                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Vol+ |       |      |      |      |
 *                                 | Play |      |------|       |------|      |      |
 *                                 |      |      | Vol- |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[GAMX] = LAYOUT_ergodox_pretty(
  // left hand
  KC_LBRC,  KC_1,        KC_2,  KC_3,    KC_4,    KC_5,    KC_LBRC,             _______, _______, _______, _______, _______, _______, _______,
  KC_RBRC,  KC_J,        KC_L,  KC_U,    KC_Y,    KC_SCLN, KC_P8,               _______, _______, _______, _______, _______, _______, _______,
  _______,  KC_M,        KC_N,  KC_E,    KC_I,    KC_O,                                  _______, _______, _______, _______, _______, _______,
  _______,  KC_K,        KC_H,  KC_COMM, KC_DOT,  KC_SLSH, KC_P9,               _______, _______, _______, _______, _______, _______, _______,
  KC_P4,    KC_P5,       KC_P6, KC_P7,   _______,                                                 _______, _______, _______, _______, _______,
                                         _______, _______,             _______, _______,
                                                  KC_VOLU,             _______,
                                KC_MPLY, _______, KC_VOLD,             _______, _______, _______
),
/* Keymap 5 & 6: tyĕɂirĕm romanized (& shifted)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |  1   |  2   |  3   |  4   |  5   |  6   |           |   7  |  8   |  9   |  ↊   |  ↋   |  0   |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  TAB   |  ǂ ɖ |  ą   |  þ ƪ |  p   |  b d |      |           |      |  y j |  l   |  u ŭ |  ǫ ɵ |  ; : |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |BCK DEL |  a ă |  r   |  s ᵹ |  t ɂ |  ƺ – |------|           |------|  m ʼ |  n ɳ |  e ĕ |  i ĭ |  o ŏ |         |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LTTYES |  z ɀ |  x   |  ç ⱶ |  ȼ ǥ |  v w |      |           |      |  k q |  ğ h |  ,   |  .   |  / ? | LALT   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | CTL  |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Space| Enter|------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[TYER] = LAYOUT_ergodox_pretty(
  // left hand
  KC_ESC,            KC_1,        KC_2,        KC_3,       KC_4,       KC_5,        KC_6,             KC_7,       KC_8,         KC_9,       X(TY_NUM10), X(TY_NUM11),  KC_0,     XXXXXXX,
  KC_TAB,            X(TY_QQ),    X(TY_AO),    X(TY_F),    KC_P,       KC_B,        XXXXXXX,          XXXXXXX,    KC_Y,         KC_L,       KC_U,        X(TY_OO),     KC_SCLN,  XXXXXXX,
  KC_BSPC,           KC_A,        KC_R,        KC_S,       KC_T,       X(TY_REP),                                 KC_M,         KC_N,       KC_E,        KC_I,         KC_O,     XXXXXXX,
  LT(TYES, XXXXXXX), KC_Z,        KC_X,        X(TY_C),    X(TY_CC),   KC_V,        XXXXXXX,          XXXXXXX,    KC_K,         X(TY_G),    KC_COMM,     KC_DOT,       KC_SLSH,  XXXXXXX,
  KC_LCTRL,          XXXXXXX,     XXXXXXX,     XXXXXXX,    XXXXXXX,                                                             XXXXXXX,    XXXXXXX,     XXXXXXX,      XXXXXXX,  KC_LALT,

                                                                       XXXXXXX,     XXXXXXX,          XXXXXXX,    XXXXXXX,
                                                                                    XXXXXXX,          XXXXXXX,
                                                           KC_SPC,     KC_ENT,      XXXXXXX,          XXXXXXX,    XXXXXXX,      XXXXXXX
),
[TYES] = LAYOUT_ergodox_pretty(
  // left hand
  XXXXXXX,           X(TY_VAR0),  X(TY_VAR1),  X(TY_VAR2), X(TY_VAR3), X(TY_VAR4), X(TY_VAR5),        X(TY_VAR6), X(TY_VAR7),   X(TY_VAR8), X(TY_VAR9),  XXXXXXX,      XXXXXXX,  XXXXXXX,
  XXXXXXX,           X(TY_QQH),   XXXXXXX,     X(TY_FH),   XXXXXXX,    KC_D,       XXXXXXX,           XXXXXXX,    KC_J,         XXXXXXX,    X(TY_UH),    X(TY_OOH),    XXXXXXX,  XXXXXXX,
  KC_DEL,            X(TY_AH),    XXXXXXX,     X(TY_SH),   X(TY_STOP), X(TY_LONG),                                X(TY_STRESS), X(TY_NH),   X(TY_EH),    X(TY_IH),     X(TY_OH), XXXXXXX,
  _______,           X(TY_ZH),    XXXXXXX,     X(TY_CH),   X(TY_CCH),  KC_W,       XXXXXXX,           XXXXXXX,    KC_Q,         KC_H,       XXXXXXX,     XXXXXXX,      XXXXXXX,  XXXXXXX,
  KC_LCTRL,          XXXXXXX,     XXXXXXX,     XXXXXXX,    XXXXXXX,                                                             XXXXXXX,    XXXXXXX,     XXXXXXX,      XXXXXXX,  KC_LALT,

                                                                       XXXXXXX,    XXXXXXX,           XXXXXXX,    XXXXXXX,
                                                                                   XXXXXXX,           XXXXXXX,
                                                           KC_SPC,     KC_ENT,     XXXXXXX,           XXXXXXX,    XXXXXXX,      XXXXXXX
),
};

/*

[EXTR] = LAYOUT_ergodox_pretty(
  // left hand
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,                                         _______, _______, _______, _______, _______,

                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, _______
),


*/
/* Keymap 2: Media and mouse keys, extra
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
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

void set_rgb(uint8_t r, uint8_t g, uint8_t b);


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
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
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  set_rgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          set_rgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          set_rgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          set_rgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          set_rgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          set_rgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          set_rgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          set_rgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          set_rgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};

void set_rgb(uint8_t r, uint8_t g, uint8_t b) {
  rgblight_enable_noeeprom();
  rgblight_mode_noeeprom(1);
  rgblight_sethsv_noeeprom(r,g,b);
}