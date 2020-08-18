/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#define DISABLE_RGB_MATRIX_DIGITAL_RAIN
#define DISABLE_RGB_MATRIX_ALPHAS_MODS
#define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#define DISABLE_RGB_MATRIX_RAINDROPS
#define LEADER_TIMEOUT 300
#define LEADER_PER_KEY_TIMING
#define ONESHOT_TAP_TOGGLE 2

#define RGB_MATRIX_STARTUP_SPD 100
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR

#define IGNORE_MOD_TAP_INTERRUPT
