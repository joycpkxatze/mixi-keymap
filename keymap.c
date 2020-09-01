#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
     * | Knob: Function                                 |
     * .------------------------------------------------.
     * | Encoder     | Yellow           | Yellow        |
     * |-------------|------------------|---------------|
     * | Brown       | Ancient grey     | Ancient Grey  |
     * |-------------|------------------|---------------|
     * | Brown       | Black            | Black         |
     * '------------------------------------------------'
     */
    [0] =
        LAYOUT(
                KC_NO  , KC_NO, TO(1), 
                KC_NO  , KC_NO, KC_NO,  
                KC_NO  , KC_NO, KC_NO
              ),
              
    
    [1] =
        LAYOUT(
                KC_MUTE,  KC_MSTP,   TO(2), 
                KC_MPRV,     KC_MPLY,    KC_MNXT, 
                LWIN(KC_TAB),     LCTL(LWIN(KC_LEFT)), LCTL(LWIN(KC_RGHT))
              ),


    [2] =
        LAYOUT(
                KC_ESC, KC_ENT, TO(3),
                KC_GRV,     KC_1,    KC_2, 
                KC_TAB,     KC_1,    KC_2
              ),


    [3] =
        LAYOUT(
                KC_MUTE  , MO(4), TO(5), 
                LCTL(KC_C)  , KC_BRID,    KC_BRIU,  
                LCTL(KC_V)  , KC_NO, KC_NO
              ),
    

    [4] =
        LAYOUT(
                KC_NO  , KC_TRNS, KC_NO, 
                EEP_RST, RESET, DEBUG,  
                KC_NO  , KC_NO, KC_NO
              ),


    [5] =
        LAYOUT(
                KC_MUTE  , KC_NO, TO(6), 
                KC_NO  , KC_NO, KC_NO,  
                KC_NO  , KC_NO, KC_NO
              ),

    
    [6] =
        LAYOUT(
                KC_MUTE  , KC_NO, TO(7), 
                KC_NO  , KC_NO, KC_NO,  
                KC_NO  , KC_NO, KC_NO
              ),


    [7] =
        LAYOUT(
                KC_MUTE  , KC_NO, TO(0), 
                KC_NO  , KC_NO, KC_NO,  
                KC_NO  , KC_NO, KC_NO
              )
    

};

const rgblight_segment_t PROGMEM _layer_0[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, RGBLED_NUM, HSV_MAGENTA}
        );
const rgblight_segment_t PROGMEM _layer_1[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, RGBLED_NUM, HSV_GREEN}
        );
const rgblight_segment_t PROGMEM _layer_2[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, RGBLED_NUM, HSV_RED}
        );
const rgblight_segment_t PROGMEM _layer_3[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, RGBLED_NUM, HSV_BLUE}
        );
const rgblight_segment_t PROGMEM _layer_4[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, RGBLED_NUM, HSV_WHITE}
        );
const rgblight_segment_t PROGMEM _layer_5[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, RGBLED_NUM, HSV_ORANGE}
        );
const rgblight_segment_t PROGMEM _layer_6[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, RGBLED_NUM, HSV_AZURE}
        );
const rgblight_segment_t PROGMEM _layer_7[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, RGBLED_NUM, HSV_GOLD}
        );


const rgblight_segment_t* const PROGMEM _rgb_layers[] =
RGBLIGHT_LAYERS_LIST(
        _layer_0,
        _layer_1,
        _layer_2,
        _layer_3,
        _layer_4,
        _layer_5,
        _layer_6,
        _layer_7
        );


void keyboard_post_init_user(void) {
    rgblight_layers = _rgb_layers;
}


layer_state_t layer_state_set_user(layer_state_t state) {

    rgblight_set_layer_state(0, layer_state_cmp(state, 0));
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    rgblight_set_layer_state(4, layer_state_cmp(state, 4));
    rgblight_set_layer_state(5, layer_state_cmp(state, 5));
    rgblight_set_layer_state(6, layer_state_cmp(state, 6));
    rgblight_set_layer_state(7, layer_state_cmp(state, 7));
    
    return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}


void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { 
        if (layer_state_is(0)){
            if (clockwise) {
                tap_code(KC_NO);
            } else {
                tap_code(KC_NO);
            }
        }
        else if (layer_state_is(2)){
            if (clockwise) {
                tap_code(KC_RGHT);
            } else {
                tap_code(KC_LEFT);
            }
        }
        else { 
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        } 
  
    } 
    
}

