#include QMK_KEYBOARD_H
#include "version.h"

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
};

enum layers {
	BASE = 0,
	COLEMAK = 1,
	CODING = 2,
	MOVEMENT = 3,
	NETWORK = 4,
};

enum tap_dance {
	TD_A,
	TD_O,
	TD_U,
	TD_S,
	TD_SFT_ESC_CAPS,
	TD_TT1_TL2,
};

#define HOLD(STATE) STATE->pressed && !STATE->interrupted

typedef struct {
	bool on;
} td_multishift_t;

void multitap(qk_tap_dance_state_t* state, uint8_t limit, uint16_t single_code, uint16_t multi_code)
{
	if (state->count == limit) {
		tap_code(multi_code);
	} else {
		for (int i = 0; i < state->count; ++i)
			tap_code(single_code);
	}
}

void td_a_cb(qk_tap_dance_state_t *state, void *user_data) { multitap(state, 3, KC_A, RALT(KC_Q)); }
void td_o_cb(qk_tap_dance_state_t *state, void *user_data) { multitap(state, 3, KC_O, RALT(KC_P)); }
void td_u_cb(qk_tap_dance_state_t *state, void *user_data) { multitap(state, 3, KC_U, RALT(KC_Y)); }
void td_s_cb(qk_tap_dance_state_t *state, void *user_data) { multitap(state, 3, KC_S, RALT(KC_S)); }

void td_sft_esc_caps_cb(qk_tap_dance_state_t *state, void *user_data)
{
	td_multishift_t* multishift = (td_multishift_t*)user_data;
	if (HOLD(state)) {
		register_code(KC_LSHIFT);
		multishift->on = true;
	} else {
		multishift->on = false;
		if (state->count == 1) {
			tap_code(KC_ESC);
		} else {
			tap_code(KC_CAPS);
		}
	}
}
void td_sft_esc_caps_reset_cb(qk_tap_dance_state_t *state, void *user_data)
{
	td_multishift_t* multishift = (td_multishift_t*)user_data;
	if (multishift->on)
		unregister_code(KC_LSHIFT);
	multishift->on = false;
}

void td_tt1_tt2_cb(qk_tap_dance_state_t *state, void *user_data)
{
	if (HOLD(state)) {
		layer_on(CODING);
	} else {
		static uint8_t layer = MOVEMENT;
		static uint8_t on = 0;
		if (on == 0) {
			layer = state->count > 1 ? NETWORK : MOVEMENT;
			on = 1;
			layer_on(layer);
		} else {
			on = 0;
			layer_off(layer);
		}
	}
}
void td_tt1_tt2_reset_cb(qk_tap_dance_state_t *state, void *user_data)
{
	if (state->count == 1)
		layer_off(CODING);
}

qk_tap_dance_action_t tap_dance_actions[] = {
	[TD_A] = ACTION_TAP_DANCE_FN(td_a_cb),
	[TD_O] = ACTION_TAP_DANCE_FN(td_o_cb),
	[TD_U] = ACTION_TAP_DANCE_FN(td_u_cb),
	[TD_S] = ACTION_TAP_DANCE_FN(td_s_cb),
	[TD_SFT_ESC_CAPS] = {
		.fn = { NULL, td_sft_esc_caps_cb, td_sft_esc_caps_reset_cb },
		.user_data = (void*)&((td_multishift_t) { false }),
	},
	[TD_TT1_TL2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_tt1_tt2_cb, td_tt1_tt2_reset_cb),
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
		_______,			KC_Q,						KC_W,					KC_E,			KC_R,			KC_T,			_______,
		KC_LEAD,			TD(TD_A),					TD(TD_S),				KC_D,			KC_F,			KC_G,
		_______,			KC_Z,						KC_X,					KC_C,			KC_V,			KC_B,			OSM(MOD_LGUI),
		_______,			_______,					_______,				OSM(MOD_LCTL),	TD(TD_SFT_ESC_CAPS),

		/* left hand thumbs */
		OSM(MOD_LCTL),		_______,
		OSM(MOD_LALT),
		LCTL_T(KC_SPACE),	KC_ENTER,					KC_LEAD,
		/* right hand */
		_______,			KC_6,						KC_7,					KC_8,			KC_9,			KC_0,			KC_BSPACE,
		_______,			KC_Y,						TD(TD_U),				KC_I,			TD(TD_O),		KC_P,			KC_DELETE,
		KC_H,				KC_J,						KC_K,					KC_L,			KC_SCOLON,		KC_MINUS,
		OSM(MOD_RCTL),		KC_N,						KC_M,					KC_COMMA,		KC_DOT,			KC_SLASH,		_______,
		TD(TD_TT1_TL2),		OSM(MOD_RGUI),				_______,				_______,		_______,

		/* right hand thumbs */
		_______,			OSM(MOD_RCTL),
		OSM(MOD_RALT),
		_______,			RSFT_T(KC_TAB),				KC_BSPACE
	),
	[COLEMAK] = LAYOUT_ergodox(
		/* left hand */
		_______,			_______,					_______,				_______,		_______,		_______,		_______,
		_______,			_______,					_______,				KC_F,			KC_P,			KC_B,			_______,
		_______,			_______,					KC_R,					TD(TD_S),		KC_T,			_______,
		_______,			_______,					_______,				_______,		KC_D,			KC_V,			_______,
		_______,			_______,					_______,				_______,		_______,

		/* left hand thumbs */
		_______,			_______,
		_______,
		_______,			_______,					_______,
		/* right hand */
		_______,			_______,					_______,				_______,		_______,		_______,		_______,
		_______,			KC_J,						KC_L,					TD(TD_U),		KC_Y,			KC_SCOLON,		_______,
		KC_K,				KC_N,						KC_E		,			KC_I,			TD(TD_O),		_______,
		_______,			KC_M,						KC_H,					_______,		_______,		_______,		_______,
		_______,			_______,					_______,				_______,		_______,

		/* right hand thumbs */
		_______,			_______,
		_______,
		_______,			_______,					_______
	),
	[CODING] = LAYOUT_ergodox(
		/* left hand */
		_______,			_______,					_______,				_______,		_______,		_______,		_______,
		_______,			_______,					KC_AT,					KC_LBRACKET,	KC_RBRACKET,	KC_DLR,			_______,
		_______,			KC_EXLM,					KC_ASTR,				KC_UNDS,		KC_MINUS,		KC_PLUS,
		_______,			KC_PIPE,					KC_TILD,				KC_LABK,		KC_RABK,		ST_MACRO_0,		_______,
		_______,			_______,					_______,				_______,		_______,

		/* left hand thumbs */
		_______,			_______,
		_______,
		_______,			_______,					_______,
		/* right hand */
		_______,			_______,					_______,				_______,		_______,		_______,		_______,
		_______,			KC_CIRC,					KC_LPRN,				KC_RPRN,		KC_HASH,		KC_GRAVE,		_______,
		KC_COLON,			KC_EQUAL,					KC_AMPR,				KC_PERC,		KC_QUES,		_______,
		_______,			_______,					KC_DQUO,				KC_QUOTE,		KC_LCBR,		KC_RCBR,		_______,
		_______,			_______,					_______,				_______,		_______,

		/* right hand thumbs */
		_______,			_______,
		_______,
		_______,			_______,					_______
	),
	[MOVEMENT] = LAYOUT_ergodox(
		/* left hand */
		_______,			_______,					_______,				_______,		_______,		_______,		_______,
		_______,			_______,					_______,				_______,		_______,		_______,		_______,
		_______,			_______,					_______,				KC_DELETE,		KC_BSPACE,		_______,
		_______,			_______,					_______,				_______,		_______,		_______,		_______,
		_______,			_______,					_______,				_______,		_______,

		/* left hand thumbs */
		_______,			_______,
		_______,
		_______,			_______,					_______,
		/* right hand */
		_______,			_______,					_______,				_______,		_______,		_______,		_______,
		_______,			_______,					KC_HOME,				LCTL(KC_LEFT),	LCTL(KC_RIGHT),	KC_END,			_______,
		_______,			KC_LEFT,					KC_DOWN,				KC_UP,			KC_RIGHT,		_______,
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
		SEQ_TWO_KEYS(KC_F, KC_L) {
			register_code(KC_LGUI);
			tap_code16(KC_L);
			unregister_code(KC_LGUI);
		}
		SEQ_TWO_KEYS(KC_F, KC_H) {
			register_code(KC_LGUI);
			tap_code16(KC_H);
			unregister_code(KC_LGUI);
		}
		SEQ_TWO_KEYS(KC_M, KC_L) {
			register_code(KC_LGUI);
			register_code(KC_LSHIFT);
			tap_code16(KC_L);
			unregister_code(KC_LGUI);
			unregister_code(KC_LSHIFT);
		}
		SEQ_TWO_KEYS(KC_M, KC_H) {
			register_code(KC_LGUI);
			register_code(KC_LSHIFT);
			tap_code16(KC_H);
			unregister_code(KC_LGUI);
			unregister_code(KC_LSHIFT);
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
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_MINUS) SS_DELAY(100) SS_LSFT(SS_TAP(X_COMMA)));

    }
    break;
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
