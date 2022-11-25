enum combos { QW_ESC, VOL_DOWN, VOL_UP, RT_BSPC, COMBO_LENGTH };

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM qw_combo[]       = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM rt_combo[]       = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM vol_up_combo[]   = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM vol_down_combo[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[] = {[QW_ESC]   = COMBO(qw_combo, KC_ESC),
                        [RT_BSPC]  = COMBO(rt_combo, KC_BSPC),
                        [VOL_UP]   = COMBO(vol_up_combo, KC_VOLU),
                        [VOL_DOWN] = COMBO(vol_down_combo, KC_VOLD)};
