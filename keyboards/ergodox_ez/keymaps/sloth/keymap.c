#include QMK_KEYBOARD_H
#include "version.h"

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  ST_MACRO_1,
};

enum layers {
	BASE = 0,
	COLEMAK = 1,
	CODING = 2,
	MOVEMENT = 3,
	NETWORK = 4,
	NONE = 255,
};

#if 0
		/* left hand */
		_______,			_______,					_______,				_______,		_______,		_______,		_______,
		_______,			_______,					_______,				_______,		_______,		_______,		_______,
		_______,			_______,					_______,				_______,		_______,		_______,
		_______,			_______,					_______,				_______,		_______,		_______,		_______,
		_______,			_______,					_______,				_______,		_______,

		/* left hand thumbs */
		_______,			_______,
		_______,
		_______,			_______,					_______,
		/* right hand */
		_______,			_______,					_______,				_______,		_______,		_______,		_______,
		_______,			_______,					_______,				_______,		_______,		_______,		_______,
		_______,			_______,					_______,				_______,		_______,		_______,
		_______,			_______,					_______,				_______,		_______,		_______,		_______,
		_______,			_______,					_______,				_______,		_______,

		/* right hand thumbs */
		_______,			_______,
		_______,
		_______,			_______,					_______
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT_ergodox(
		/* left hand */
		TG(COLEMAK),		KC_1,						KC_2,					KC_3,			KC_4,			KC_5,			_______,
		LALT_T(KC_ESC),		KC_Q,						KC_W,					KC_E,			KC_R,			KC_T,			_______,
		LCTL_T(KC_TAB),		KC_A,						KC_S,					KC_D,			KC_F,			KC_G,
		KC_LSPO,			KC_Z,						KC_X,					KC_C,			KC_V,			KC_B,			KC_LEAD,
		_______,			_______,					_______,				TT(MOVEMENT),	OSM(MOD_LGUI),

		/* left hand thumbs */
		OSM(MOD_LCTL),		OSM(MOD_LALT),
		OSM(MOD_LSFT),
		KC_SPACE,			KC_TAB,						_______,
		/* right hand */
		_______,			KC_6,						KC_7,					KC_8,			KC_9,			KC_0,			_______,
		_______,			KC_Y,						KC_U,					KC_I,			KC_O,			KC_P,			KC_LEAD,
		KC_H,				KC_J,						KC_K,					KC_L,			KC_SCOLON,		KC_MINUS,
		KC_ESC,				KC_N,						KC_M,					KC_COMMA,		KC_DOT,			KC_SLASH,		KC_RSPC,
		OSL(CODING),		KC_LEFT,					KC_DOWN,				KC_UP,			KC_RIGHT,

		/* right hand thumbs */
		OSM(MOD_RALT),		OSM(MOD_RCTL),
		OSM(MOD_RSFT),
		KC_LEAD,			KC_ENTER,					KC_BSPACE
	),
	[COLEMAK] = LAYOUT_ergodox(
		/* left hand */
		_______,			_______,					_______,				_______,		_______,		_______,		_______,
		_______,			_______,					_______,				KC_F,			KC_P,			KC_B,			_______,
		_______,			_______,					KC_R,					KC_S,			KC_T,			_______,
		_______,			_______,					_______,				_______,		KC_D,			KC_V,			_______,
		_______,			_______,					_______,				_______,		_______,

		/* left hand thumbs */
		_______,			_______,
		_______,
		_______,			_______,					_______,
		/* right hand */
		_______,			_______,					_______,				_______,		_______,		_______,		_______,
		_______,			KC_J,						KC_L,					KC_U,			KC_Y,			KC_SCOLON,		_______,
		KC_K,				KC_N,						KC_E		,			KC_I,			KC_O,			_______,
		_______,			KC_M,						KC_H,					_______,		_______,		_______,		_______,
		_______,			_______,					_______,				_______,		_______,

		/* right hand thumbs */
		_______,			_______,
		_______,
		_______,			_______,					_______
	),
	[CODING] = LAYOUT_ergodox(
		/* left hand */
		_______,			KC_F1,						KC_F2,					KC_F3,			KC_F4,			KC_F5,			_______,
		_______,			KC_EXLM,					KC_AT,					KC_LCBR,		KC_RCBR,		KC_DLR,			_______,
		_______,			KC_UNDS,					KC_ASTR,				KC_LBRACKET,	KC_RBRACKET,	KC_PLUS,
		_______,			KC_PIPE,					KC_TILD,				KC_LABK,		KC_RABK,		_______,		_______,
		_______,			_______,					_______,				_______,		_______,

		/* left hand thumbs */
		_______,			_______,
		_______,
		_______,			_______,					_______,
		/* right hand */
		_______,			KC_F6,						KC_F7,					KC_F8,			KC_F9,			KC_F10,			_______,
		_______,			KC_CIRC,					KC_EQUAL,				KC_AMPR,		KC_HASH,		KC_QUES,		_______,
		KC_GRAVE,			KC_LPRN,					KC_RPRN,				KC_PERC,		KC_COLON,		KC_MINUS,
		_______,			_______,					KC_DQUO,				KC_QUOTE,		_______,		_______,		_______,
		_______,			_______,					_______,				_______,		_______,

		/* right hand thumbs */
		_______,			_______,
		_______,
		_______,			_______,					_______
	),
	[MOVEMENT] = LAYOUT_ergodox(
		/* left hand */
		_______,			_______,					_______,				_______,		_______,		_______,		_______,
		_______,			_______,					KC_HOME,				KC_UP,			KC_END,			KC_PGUP,		_______,
		_______,			_______,					KC_LEFT,				KC_DOWN,		KC_RIGHT,		KC_PGDOWN,
		_______,			_______,					_______,				_______,		_______,		_______,		_______,
		_______,			_______,					_______,				_______,		_______,

		/* left hand thumbs */
		_______,			_______,
		_______,
		_______,			_______,					_______,
		/* right hand */
		_______,			_______,					_______,				_______,		_______,		_______,		_______,
		_______,			KC_PGUP,					KC_HOME,				LCTL(KC_LEFT),	LCTL(KC_RIGHT),	KC_END,			_______,
		KC_PGDOWN,			KC_LEFT,					KC_DOWN,				KC_UP,			KC_RIGHT,		_______,
		_______,			_______,					_______,				_______,		_______,		_______,		_______,
		_______,			_______,					_______,				_______,		_______,

		/* right hand thumbs */
		_______,			_______,
		_______,
		_______,			_______,					_______
	),
	[NETWORK] = LAYOUT_ergodox(
		/* left hand */
		_______,			_______,					_______,				_______,		_______,		_______,		_______,
		_______,			_______,					_______,				KC_COLN,		ST_MACRO_1,		_______,		_______,
		_______,			KC_1,						KC_2,					KC_3,			KC_4,			KC_5,
		_______,			_______,					_______,				_______,		_______,		_______,		_______,
		_______,			_______,					_______,				_______,		_______,

		/* left hand thumbs */
		_______,			_______,
		_______,
		_______,			_______,					_______,
		/* right hand */
		_______,			_______,					_______,				_______,		_______,		_______,		_______,
		_______,			_______,					KC_AT,					_______,		_______,		_______,		_______,
		KC_6,				KC_7,						KC_8,					KC_9,			KC_0,			_______,
		_______,			_______,					_______,				_______,		_______,		_______,		_______,
		_______,			_______,					_______,				_______,		_______,

		/* right hand thumbs */
		_______,			_______,
		_______,
		_______,			_______,					_______
	),

};

LEADER_EXTERNS();
void matrix_scan_user(void)
{
	LEADER_DICTIONARY() {
		leading = false;
		leader_end();

		SEQ_ONE_KEY(KC_T) {
			tap_code16(LGUI(KC_ENTER));
		}
		SEQ_ONE_KEY(KC_C) {
			tap_code16(LGUI(LSFT(KC_C)));
		}
		SEQ_ONE_KEY(KC_A) {
			tap_code16(RALT(KC_Q));
		}
		SEQ_ONE_KEY(KC_O) {
			tap_code16(RALT(KC_P));
		}
		SEQ_ONE_KEY(KC_U) {
			tap_code16(RALT(KC_Y));
		}
		SEQ_ONE_KEY(KC_S) {
			tap_code16(RALT(KC_S));
		}
		SEQ_TWO_KEYS(KC_F, KC_L) {
			tap_code16(LGUI(KC_L));
		}
		SEQ_TWO_KEYS(KC_F, KC_H) {
			tap_code16(LGUI(KC_H));
		}
		SEQ_TWO_KEYS(KC_M, KC_L) {
			tap_code16(LGUI(LSFT(KC_L)));
		}
		SEQ_TWO_KEYS(KC_M, KC_H) {
			tap_code16(LGUI(LSFT(KC_H)));
		}
		SEQ_TWO_KEYS(KC_W, KC_L) {
			tap_code16(LGUI(LCTL(KC_L)));
		}
		SEQ_TWO_KEYS(KC_W, KC_H) {
			tap_code16(LGUI(LCTL(KC_H)));
		}
	}
}

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [BASE] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },
    [COLEMAK] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {141,255,233}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [CODING] = { {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233} },

    [MOVEMENT] = { {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {33,255,255}, {33,255,255}, {33,255,255}, {33,255,255}, {0,0,255}, {141,255,233}, {141,255,233}, {141,255,233}, {141,255,233}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255} },

    [NETWORK] = { {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {33,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_R) SS_DELAY(100) SS_TAP(X_O) SS_DELAY(100) SS_TAP(X_O) SS_DELAY(100) SS_TAP(X_T));

    }
    break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

  uint8_t layer = biton32(state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};
