#include QMK_KEYBOARD_H
#include "version.h"

enum custom_keycodes {
  RGB_SOLID = EZ_SAFE_RANGE,
  RGB_HEATMAP,
};

enum layers {
	BASE = 0,
	COLEMAK = 1,
	CODING = 2,
	MOVEMENT = 3,
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
		OSM(MOD_LSFT),		KC_Z,						KC_X,					KC_C,			KC_V,			KC_B,			_______,
		_______,			_______,					_______,				TT(MOVEMENT),	OSM(MOD_LGUI),

		/* left hand thumbs */
		OSM(MOD_LCTL),		OSM(MOD_LALT),
		OSM(MOD_LSFT),
		KC_SPACE,			OSM(MOD_LCTL),				_______,
		/* right hand */
		_______,			KC_6,						KC_7,					KC_8,			KC_9,			KC_0,			RGB_HEATMAP,
		_______,			KC_Y,						KC_U,					KC_I,			KC_O,			KC_P,			RGB_SOLID,
		KC_H,				KC_J,						KC_K,					KC_L,			KC_SCOLON,		KC_ENTER,
		_______,			KC_N,						KC_M,					KC_COMMA,		KC_DOT,			KC_SLASH,		OSM(MOD_RSFT),
		OSL(CODING),		KC_LEFT,					KC_DOWN,				KC_UP,			KC_RIGHT,

		/* right hand thumbs */
		OSM(MOD_RALT),		OSM(MOD_RCTL),
		OSM(MOD_RSFT),
		KC_LEAD,			KC_LEAD,					KC_BSPACE
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
		_______,			KC_UNDS,					KC_ASTR,				KC_LBRACKET,	KC_RBRACKET,	KC_MINUS,
		_______,			KC_PIPE,					KC_TILD,				KC_LABK,		KC_RABK,		KC_PLUS,		_______,
		_______,			_______,					_______,				_______,		_______,

		/* left hand thumbs */
		_______,			_______,
		_______,
		KC_ESC,				_______,					_______,

		/* right hand */
		_______,			KC_F6,						KC_F7,					KC_F8,			KC_F9,			KC_F10,			_______,
		_______,			KC_CIRC,					KC_EQUAL,				KC_AMPR,		KC_HASH,		KC_QUES,		_______,
		KC_GRAVE,			KC_LPRN,					KC_RPRN,				KC_PERC,		KC_COLON,		_______,
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
	)
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

void keyboard_post_init_user(void)
{
	rgb_matrix_enable();
	rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
}

struct colordef_t {
	bool on;
	int8_t idx[11];
	uint8_t rgb[3];
};

uint8_t colidx(uint16_t mask) {
	switch (mask) {
		case MOD_MASK_SHIFT: return 0;
		case MOD_MASK_CTRL: return 1;
		case MOD_MASK_ALT: return 2;
		case MOD_MASK_GUI: return 3;
		default: return -1;
	}
	return -1;
}
struct colordef_t modifier_colors[] = {
	[0] = {
		.on = false, .idx = { 4, 9, 14, 19, 28, 33, 38, 43, -1 }, .rgb = { RGB_GOLD },
	},
	[1] = {
		.on = false, .idx = { 3, 8, 13, 18, 27, 32, 37, 42, -1 }, .rgb = { RGB_TEAL },
	},
	[2] = {
		.on = false, .idx = { 2, 7, 12, 17, 26, 31, 36, 41, -1 }, .rgb = { RGB_CORAL },
	},
	[3] = {
		.on = false, .idx = { 1, 6, 11, 16, 25, 30, 35, 40, -1 }, .rgb = { RGB_SPRINGGREEN },
	},
};

struct colordef_t layer_color = {
	.on = false, .idx = { 28, 27, 26, 25, 24, 0, 1, 2, 3, 4, -1 },
};

void set_layer_color(void)
{
	if (layer_color.on == false) return;
	for (uint8_t i = 0; layer_color.idx[i] != -1; ++i)
		rgb_matrix_set_color(layer_color.idx[i], layer_color.rgb[0], layer_color.rgb[1], layer_color.rgb[2]);
}

void set_color(uint16_t mask)
{
	uint8_t idx = colidx(mask);
	if (idx < 0) return;
	struct colordef_t* coldef = &modifier_colors[idx];

	if (get_mods() & mask || coldef->on) {
		for (uint8_t i = 0; coldef->idx[i] != -1; ++i)
			rgb_matrix_set_color(coldef->idx[i], coldef->rgb[0], coldef->rgb[1], coldef->rgb[2]);
	}
}

void rgb_matrix_indicators_user(void)
{
	if (g_suspend_state || keyboard_config.disable_layer_led) return;

	if (rgb_matrix_get_mode() == RGB_MATRIX_SOLID_COLOR)
		rgb_matrix_set_color_all(0, 0, 0);

	set_layer_color();

	set_color(MOD_MASK_SHIFT);
	set_color(MOD_MASK_CTRL);
	set_color(MOD_MASK_ALT);
	set_color(MOD_MASK_GUI);
}

void oneshot_mods_changed_user(uint8_t mods)
{
	modifier_colors[colidx(MOD_MASK_SHIFT)].on = mods & MOD_MASK_SHIFT;
	modifier_colors[colidx(MOD_MASK_CTRL)].on = mods & MOD_MASK_CTRL;
	modifier_colors[colidx(MOD_MASK_ALT)].on = mods & MOD_MASK_ALT;
	modifier_colors[colidx(MOD_MASK_GUI)].on = mods & MOD_MASK_GUI;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case RGB_SOLID:
			if (record->event.pressed)
				rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
			return false;
		case RGB_HEATMAP:
			if (record->event.pressed)
				rgb_matrix_mode(RGB_MATRIX_TYPING_HEATMAP);
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

	struct colordef_t* col = &layer_color;

	col->on = false;
	uint8_t coding[] = { RGB_TEAL };
	uint8_t movement[] = { RGB_ORANGE };
	uint8_t colemak[] = { RGB_RED };
	switch (layer) {
		case BASE:
			break;
		case COLEMAK:
			ergodox_right_led_1_on();
			memcpy(col->rgb, colemak, 3);
			col->on = true;
			break;
		case CODING:
			memcpy(col->rgb, coding, 3);
			col->on = true;
			ergodox_right_led_2_on();
			break;
		case MOVEMENT:
			memcpy(col->rgb, movement, 3);
			col->on = true;
			ergodox_right_led_3_on();
			break;
		default:
			break;
	}
	return state;
};
