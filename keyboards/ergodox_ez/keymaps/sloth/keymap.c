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
	UMLAUTS = 4,
	NUMPAD = 5,
	NONE = 255,
};

/* Thoughts
 * - symmetry: put -/_, brackets etc. on different hands, but same position?
 *
 *
 */

#if 0
		/* left hand */
		_______,			_______,					_______,				_______,			_______,			_______,		_______,
		_______,			_______,					_______,				_______,			_______,			_______,		_______,
		_______,			_______,					_______,				_______,			_______,			_______,
		_______,			_______,					_______,				_______,			_______,			_______,		_______,
		_______,			_______,					_______,				_______,			_______,

		/* left hand thumbs */
		_______,			_______,
		_______,
		_______,			_______,					_______,
		/* right hand */
		_______,			_______,					_______,				_______,			_______,			_______,		_______,
		_______,			_______,					_______,				_______,			_______,			_______,		_______,
		_______,			_______,					_______,				_______,			_______,			_______,
		_______,			_______,					_______,				_______,			_______,			_______,		_______,
		_______,			_______,					_______,				_______,			_______,

		/* right hand thumbs */
		_______,			_______,
		_______,
		_______,			_______,					_______
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT_ergodox(
		/* left hand */
		TG(COLEMAK),		KC_1,						KC_2,					KC_3,				KC_4,				KC_5,			_______,
		_______,			KC_Q,						KC_W,					KC_E,				KC_R,				KC_T,			_______,
		KC_TAB,				KC_A,						KC_S,					KC_D,				KC_F,				KC_G,
		OSM(MOD_LSFT),		KC_Z,						KC_X,					KC_C,				KC_V,				KC_B,			KC_ESC,
		RGB_SOLID,			RGB_HEATMAP,				_______,				TT(NUMPAD),			MO(MOVEMENT),

		/* left hand thumbs */
		OSM(MOD_LGUI),		KC_HOME,
		OSM(MOD_LALT),
		KC_SPACE,			OSM(MOD_LSFT),				OSM(MOD_LCTL),
		/* right hand */
		_______,			KC_6,						KC_7,					KC_8,				KC_9,				KC_0,			KC_PGUP,
		_______,			KC_Y,						KC_U,					KC_I,				KC_O,				KC_P,			KC_PGDOWN,
		KC_H,				KC_J,						KC_K,					KC_L,				KC_SCOLON,			KC_ENTER,
		MO(UMLAUTS),		KC_N,						KC_M,					KC_COMMA,			KC_DOT,				KC_SLASH,		OSM(MOD_RSFT),
		MO(CODING),			KC_LEFT,					KC_DOWN,				KC_UP,				KC_RIGHT,

		/* right hand thumbs */
		KC_END,				OSM(MOD_RGUI),
		OSM(MOD_RALT),
		OSM(MOD_LCTL),		OSM(MOD_RSFT),				KC_BSPACE
	),
	[COLEMAK] = LAYOUT_ergodox(
		/* left hand */
		_______,			_______,					_______,				_______,			_______,			_______,		_______,
		_______,			_______,					_______,				KC_F,				KC_P,				KC_B,			_______,
		_______,			_______,					KC_R,					KC_S,				KC_T,				_______,
		_______,			_______,					_______,				_______,			KC_D,				KC_V,			_______,
		_______,			_______,					_______,				_______,			_______,

		/* left hand thumbs */
		_______,			_______,
		_______,
		_______,			_______,					_______,
		/* right hand */
		_______,			_______,					_______,				_______,			_______,			_______,		_______,
		_______,			KC_J,						KC_L,					KC_U,				KC_Y,				KC_SCOLON,		_______,
		KC_K,				KC_N,						KC_E,					KC_I,				KC_O,				_______,
		_______,			KC_M,						KC_H,					_______,			_______,			_______,		_______,
		_______,			_______,					_______,				_______,			_______,

		/* right hand thumbs */
		_______,			_______,
		_______,
		_______,			_______,					_______
	),
	[CODING] = LAYOUT_ergodox(
		/* left hand */
		_______,			KC_F1,						KC_F2,					KC_F3,				KC_F4,				KC_F5,			_______,
		_______,			KC_EXLM,					KC_AT,					KC_LCBR,			KC_RCBR,			KC_DLR,			_______,
		_______,			KC_ASTR,					KC_MINUS,				KC_LBRACKET,		KC_RBRACKET,		KC_UNDS,
		_______,			KC_PIPE,					KC_TILD,				KC_LABK,			KC_RABK,			KC_PLUS,		_______,
		_______,			_______,					_______,				_______,			_______,

		/* left hand thumbs */
		_______,			_______,
		_______,
		KC_ESC,				_______,					_______,

		/* right hand */
		_______,			KC_F6,						KC_F7,					KC_F8,				KC_F9,				KC_F10,			_______,
		_______,			KC_CIRC,					KC_EQUAL,				KC_PERC,			KC_HASH,			KC_QUES,		_______,
		KC_GRAVE,			KC_LPRN,					KC_RPRN,				KC_AMPR,			KC_COLON,			_______,
		_______,			_______,					KC_DQUO,				KC_QUOTE,			_______,			_______,		_______,
		_______,			_______,					_______,				_______,			_______,

		/* right hand thumbs */
		_______,			_______,
		_______,
		_______,			_______,					KC_DEL
	),
	[MOVEMENT] = LAYOUT_ergodox(
		/* left hand */
		_______,			_______,					_______,				_______,			_______,			_______,		_______,
		_______,			_______,					_______,				_______,			_______,			_______,		_______,
		_______,			_______,					_______,				_______,			_______,			_______,
		_______,			_______,					_______,				_______,			_______,			_______,		_______,
		_______,			_______,					_______,				_______,			_______,

		/* left hand thumbs */
		_______,			_______,
		_______,
		_______,			_______,					_______,
		/* right hand */
		_______,			_______,					_______,				_______,			_______,			_______,		_______,
		_______,			KC_PGUP,					KC_HOME,				KC_UP,				KC_END,				KC_PGUP,		_______,
		KC_PGDOWN,			KC_LEFT,					KC_DOWN,				KC_RIGHT,			KC_PGDOWN,			_______,
		_______,			_______,					_______,				_______,			_______,			_______,		_______,
		_______,			_______,					_______,				_______,			_______,

		/* right hand thumbs */
		_______,			_______,
		_______,
		_______,			_______,					TG(MOVEMENT)
	),
	[UMLAUTS] = LAYOUT_ergodox(
		/* left hand */
		_______,			_______,					_______,				_______,			_______,			_______,		_______,
		_______,			_______,					_______,				_______,			_______,			_______,		_______,
		_______,			RALT(KC_Q),					RALT(KC_P),				RALT(KC_Y),			RALT(KC_S),			RALT(KC_5),
		_______,			_______,					_______,				_______,			_______,			_______,		_______,
		_______,			_______,					_______,				_______,			_______,

		/* left hand thumbs */
		_______,			_______,
		_______,
		_______,			_______,					_______,
		/* right hand */
		_______,			_______,					_______,				_______,			_______,			_______,		_______,
		_______,			_______,					_______,				_______,			_______,			_______,		_______,
		_______,			_______,					_______,				_______,			_______,			_______,
		_______,			_______,					_______,				_______,			_______,			_______,		_______,
		_______,			_______,					_______,				_______,			_______,

		/* right hand thumbs */
		_______,			_______,
		_______,
		_______,			_______,					_______
	),
	[NUMPAD] = LAYOUT_ergodox(
		/* left hand */
		_______,			_______,					_______,				_______,			_______,			_______,		_______,
		_______,			_______,					_______,				_______,			_______,			_______,		_______,
		_______,			_______,					_______,				_______,			KC_AT,				KC_COLON,
		_______,			_______,					_______,				_______,			_______,			_______,		_______,
		_______,			_______,					_______,				_______,			_______,

		/* left hand thumbs */
		_______,			_______,
		_______,
		_______,			_______,					_______,
		/* right hand */
		_______,			_______,					_______,				KC_SLASH,			KC_ASTR,			KC_MINUS,		_______,
		_______,			_______,					KC_7,					KC_8,				KC_9,				KC_PLUS,		_______,
		_______,			KC_4,						KC_5,					KC_6,				KC_DOT,				_______,
		_______,			_______,					KC_1,					KC_2,				KC_3,				_______,		_______,
		KC_0,				KC_BSPACE,					KC_DEL,					_______,			_______,

		/* right hand thumbs */
		_______,			_______,
		_______,
		_______,			_______,					_______
	),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void)
{
	rgb_matrix_enable();
	rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
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
		.on = false, .idx = { 2, 7, 12, 17, 26, 31, 36, 41, -1 }, .rgb = { RGB_ORANGE },
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

void light_up_layers(void)
{
	if (layer_state_is(MOVEMENT)) {
		uint8_t arrows[] = { 11, 12, 13, 7 };
		uint8_t other_movement[] = { 10, 5, 9, 14 };
		uint8_t home_end[] = { 6, 8 };
		for (int i = 0; i < sizeof(arrows); ++i)
			rgb_matrix_set_color(arrows[i], RGB_WHITE);
		for (int i = 0; i < sizeof(other_movement); ++i)
			rgb_matrix_set_color(other_movement[i], RGB_ORANGE);
		for (int i = 0; i < sizeof(home_end); ++i)
			rgb_matrix_set_color(home_end[i], RGB_PINK);
	}
	if (layer_state_is(UMLAUTS)) {
		uint8_t umlauts[] = { 38, 37, 36, 35, 34 };
		for (int i = 0; i < sizeof(umlauts); ++i)
			rgb_matrix_set_color(umlauts[i], RGB_CORAL);
	}
	if (layer_state_is(NUMPAD)) {
		uint8_t numpad[] = { 6, 7, 8, 11, 12, 13, 16, 17, 18 };
		for (int i = 0; i < sizeof(numpad); ++i)
			rgb_matrix_set_color(numpad[i], RGB_WHITE);
	}
}

void rgb_matrix_indicators_user(void)
{
	if (g_suspend_state || keyboard_config.disable_layer_led) return;

	if (rgb_matrix_get_mode() == RGB_MATRIX_SOLID_COLOR)
		rgb_matrix_set_color_all(0, 0, 0);

	set_layer_color();

	rgb_matrix_set_color(11, RGB_ORANGE);
	rgb_matrix_set_color(35, RGB_ORANGE);

	set_color(MOD_MASK_SHIFT);
	set_color(MOD_MASK_CTRL);
	set_color(MOD_MASK_ALT);
	set_color(MOD_MASK_GUI);

	light_up_layers();
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
				rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
			return false;
		case RGB_HEATMAP:
			if (record->event.pressed)
				rgb_matrix_mode_noeeprom(RGB_MATRIX_TYPING_HEATMAP);
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
	uint8_t colemak[] = { RGB_GREEN };
	uint8_t umlauts[] = { RGB_CORAL };
	uint8_t numpad[] = { RGB_WHITE };
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
		case UMLAUTS:
			memcpy(col->rgb, umlauts, 3);
			col->on = true;
			ergodox_right_led_1_on();
			ergodox_right_led_2_on();
		case NUMPAD:
			memcpy(col->rgb, numpad, 3);
			col->on = true;
			ergodox_right_led_1_on();
			ergodox_right_led_3_on();
		default:
			break;
	}
	return state;
};
