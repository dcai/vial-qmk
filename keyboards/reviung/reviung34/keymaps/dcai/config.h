#pragma once

#define VIAL_KEYBOARD_UID {0xB8, 0x68, 0xB9, 0x6C, 0x13, 0x2E, 0xA7, 0xDD}
#define VIAL_UNLOCK_COMBO_ROWS {0, 3}
#define VIAL_UNLOCK_COMBO_COLS {0, 5}
#define DYNAMIC_KEYMAP_LAYER_COUNT 8


// home row mods required config
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD

// When the user holds a key after tap, this repeats the tapped key
// rather to hold a modifier key. This allows to use auto repeat
// for the tapped key.
#define TAPPING_FORCE_HOLD

// the non split version
#define WS2812_DI_PIN D3
#ifdef WS2812_DI_PIN
  #define RGBLIGHT_LAYERS

  #define RGBLED_NUM 9
  #define RGBLIGHT_DEFAULT_HUE 85 // green
  #define RGBLIGHT_HUE_STEP 16
  #define RGBLIGHT_SAT_STEP 16
  #define RGBLIGHT_VAL_STEP 16
  #define RGBLIGHT_LIMIT_VAL 255
  #define RGBLIGHT_SLEEP

  #define RGBLIGHT_EFFECT_ALTERNATING
  #define RGBLIGHT_EFFECT_BREATHING
  #define RGBLIGHT_EFFECT_CHRISTMAS
  #define RGBLIGHT_EFFECT_KNIGHT
  #define RGBLIGHT_EFFECT_RAINBOW_MOOD
  #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
  #define RGBLIGHT_EFFECT_RGB_TEST
  #define RGBLIGHT_EFFECT_SNAKE
  #define RGBLIGHT_EFFECT_STATIC_GRADIENT
  #define RGBLIGHT_EFFECT_TWINKLE
#endif
