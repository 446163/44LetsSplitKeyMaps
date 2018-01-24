#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "dynamic_macro.h"

extern keymap_config_t keymap_config;

#define _COLEMAK 0
#define _BTEC 1
#define _NUMPAD 2
#define _SHIFT 3
#define _MOD 4
#define _LAYER 5

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  BTEC,
  NUMPAD,
  SHIFT,
  MOD,
  LAYER,
  DYNAMIC_MACRO_RANGE,
};

#include "dynamic_macro.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
  ┌────┬────┬────┬────┬────┬────┐    ┌────┬────┬────┬────┬────┬────┐
  │ {  │ q  │ w  │ f  │ p  │ g  │    │ j  │ l  │ u  │ y  │ ;  │ -  │
  ├────┼────┼────┼────┼────┼────┤    ├────┼────┼────┼────┼────┼────┤
  │CrTb│ a  │ r  │ s  │ t  │ d  │    │ h  │ n  │ e  │ i  │ o  │ :  │
  ├────┼────┼────┼────┼────┼────┤    ├────┼────┼────┼────┼────┼────┤
  │ (  │ z  │ x  │ c  │ v  │ b  │    │ k  │ m  │ ,  │ .  │ /  │ \  │
  ├────┼────┼────┼────┼────┼────┤    ├────┼────┼────┼────┼────┼────┤
  │ Ly │ [  │ALT │GUI │ESC │Sft │    │SPC │BSP │ENT │ <- │ ^  │ -> │
  └────┴────┴────┴────┴────┴────┘    └────┴────┴────┴────┴────┴────┘
*/
[_COLEMAK] = KEYMAP( \
  KC_LCBR, 	  	KC_Q,    KC_W,    KC_F,    KC_P,   			 KC_G,    		      KC_J,   KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MINS, \
  CTL_T(KC_TAB),KC_A,    KC_R,    KC_S,    KC_T,   			 KC_D,    		      KC_H,   KC_N,    KC_E,    KC_I,    KC_O,    KC_COLN, \
  KC_LPRN,    	KC_Z,    KC_X,    KC_C,    KC_V,   			 KC_B,    		      KC_K,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS, \
  TO(_LAYER), 	KC_LBRC, KC_LALT, KC_LGUI, LT(_MOD, KC_ESC), MO(_SHIFT), KC_SPC, KC_BSPC, KC_ENT,  KC_LEFT, KC_UP,   KC_RGHT \
),

[_BTEC] = KEYMAP( \
  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO, \
  KC_NO,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO, KC_NO, \
  KC_NO, KC_NO,    KC_NO,    LGUI(KC_C),    KC_NO,    KC_NO,    KC_NO,    KC_NO,    LGUI(KC_V), KC_NO,  KC_NO, KC_NO, \
  KC_NO,KC_NO,  KC_NO, KC_NO,  KC_NO,   KC_NO,  KC_NO,  KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO   \
),
/*
  ┌────┬────┬────┬────┬────┬────┐    ┌────┬────┬────┬────┬────┬────┐
  │    │ -  │ +  │ +  │ENT │ENT │    │    │    │    │    │    │    │
  ├────┼────┼────┼────┼────┼────┤    ├────┼────┼────┼────┼────┼────┤
  │    │ /  │ 9  │ 6  │ 3  │ .  │    │    │    │    │    │    │    │
  ├────┼────┼────┼────┼────┼────┤    ├────┼────┼────┼────┼────┼────┤
  │    │ *  │ 8  │ 5  │ 2  │ 0  │    │    │    │    │    │    │    │
  ├────┼────┼────┼────┼────┼────┤    ├────┼────┼────┼────┼────┼────┤
  │ Ly │NMLK│ 7  │ 4  │ 1  │ 0  │    │    │    │    │    │    │    │
  └────┴────┴────┴────┴────┴────┘    └────┴────┴────┴────┴────┴────┘
*/
[_NUMPAD] = KEYMAP( \
  KC_NO,      KC_PMNS, KC_PPLS, KC_PPLS, KC_PENT, KC_PENT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
  KC_NO, 	  KC_PSLS, KC_P9,   KC_P6,   KC_P3,   KC_PDOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
  KC_NO, 	  KC_PAST, KC_P8,   KC_P5,   KC_P2,   KC_P0,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
  TO(_LAYER), KC_NLCK, KC_P7,   KC_P4,   KC_P1,   KC_P0,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO \
),
/*
  ┌────┬────┬────┬────┬────┬────┐    ┌────┬────┬────┬────┬────┬────┐
  │ }  │ Q  │ W  │ F  │ P  │ G  │    │ J  │ L  │ U  │ Y  │ +  │ =  │
  ├────┼────┼────┼────┼────┼────┤    ├────┼────┼────┼────┼────┼────┤
  │CrTb│ A  │ R  │ S  │ T  │ D  │    │ H  │ N  │ E  │ I  │ O  │ *  │
  ├────┼────┼────┼────┼────┼────┤    ├────┼────┼────┼────┼────┼────┤
  │ )  │ Z  │ X  │ C  │ V  │ B  │    │ K  │ M  │ <  │ >  │ ?  │ _  │
  ├────┼────┼────┼────┼────┼────┤    ├────┼────┼────┼────┼────┼────┤
  │    │ ]  │ALT │GUI │Esc │Sft │    │SPC │BSP │ENT │ <- │ V  │ -> │
  └────┴────┴────┴────┴────┴────┘    └────┴────┴────┴────┴────┴────┘
*/
[_SHIFT] = KEYMAP( \
  KC_RCBR,    LSFT(KC_Q), LSFT(KC_W), LSFT(KC_F), LSFT(KC_P), LSFT(KC_G), LSFT(KC_J), LSFT(KC_L), LSFT(KC_U), LSFT(KC_Y), KC_PLUS, KC_EQL, \
  KC_TAB,  	  LSFT(KC_A), LSFT(KC_R), LSFT(KC_S), LSFT(KC_T), LSFT(KC_D), LSFT(KC_H), LSFT(KC_N), LSFT(KC_E), LSFT(KC_I), LSFT(KC_O), KC_ASTR, \
  KC_RPRN, 	  LSFT(KC_Z), LSFT(KC_X), LSFT(KC_C), LSFT(KC_V), LSFT(KC_B), LSFT(KC_K), LSFT(KC_M), KC_LT,   KC_GT,   KC_QUES, KC_UNDS, \
  KC_NO, KC_RBRC, LSFT(KC_LALT), LSFT(KC_LGUI), LSFT(KC_ESC),  KC_TRNS, LSFT(KC_SPC),  KC_BSPC, KC_ENT,  KC_LEFT, KC_DOWN, KC_RGHT \
),
/*
  ┌────┬────┬────┬────┬────┬────┐    ┌────┬────┬────┬────┬────┬────┐
  │HOME│ !  │ "  │ #  │ $  │ %  │    │ &  │ '  │ (  │ )  │ ~  │ ^  │
  ├────┼────┼────┼────┼────┼────┤    ├────┼────┼────┼────┼────┼────┤
  │CrTb│ 1  │ 2  │ 3  │ 4  │ 5  │    │ 6  │ 7  │ 8  │ 9  │ 0  │ |  │
  ├────┼────┼────┼────┼────┼────┤    ├────┼────┼────┼────┼────┼────┤
  │END │ Pt │ Vd │ Pp │ Vu │ Nt │    │SLP │ @  │ `  │ .  │ PU │ PD │
  ├────┼────┼────┼────┼────┼────┤    ├────┼────┼────┼────┼────┼────┤
  │    │SLP │ALT │GUI │Esc │Sft │    │SPC │BSP │ENT │ <- │ V  │ -> │
  └────┴────┴────┴────┴────┴────┘    └────┴────┴────┴────┴────┴────┘
*/
[_MOD] = KEYMAP( \
  KC_HOME,    KC_EXLM, KC_DQT,   KC_HASH, KC_DLR,  KC_PERC, KC_AMPR, 		KC_QUOT, KC_LPRN, KC_RPRN, KC_TILD, KC_CIRC, \
  KC_DEL,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,  			KC_7, 	 KC_8, 	  KC_9,    KC_0, 	KC_PIPE, \
  KC_END,     KC_VOLD, KC_MRWD, KC_MPLY, KC_MFFD, KC_VOLU, KC_SYSTEM_SLEEP, KC_AT, 	 KC_GRV,  KC_DOT,  KC_PGUP, KC_PGDN, \
  KC_NO, KC_SLEP, KC_LALT, KC_LGUI, KC_TRNS,  KC_LSFT, KC_NO,			KC_BSPC, KC_ENT,  KC_LEFT, KC_DOWN, KC_RGHT \
),
/*
  ┌────┬────┬────┬────┬────┬────┐    ┌────┬────┬────┬────┬────┬────┐
  │ N  │    │    │    │    │RST │    │    │ BD │ BD │    │    │    │
  ├────┼────┼────┼────┼────┼────┤    ├────┼────┼────┼────┼────┼────┤
  │ B  │    │    │    │ MS │    │    │    │M1P │M2P │    │    │    │
  ├────┼────┼────┼────┼────┼────┤    ├────┼────┼────┼────┼────┼────┤
  │ C  │    │    │    │    │    │    │    │ M1 │ M2 │    │    │    │
  ├────┼────┼────┼────┼────┼────┤    ├────┼────┼────┼────┼────┼────┤
  │    │    │    │    │    │ B  │    │    │    │    │    │    │    │
  └────┴────┴────┴────┴────┴────┘    └────┴────┴────┴────┴────┴────┘
*/
[_LAYER] = KEYMAP( \
  TO(_NUMPAD), 	KC_NO, KC_NO, KC_NO, KC_NO, RESET, KC_NO, KC_SLCK, KC_PAUS, KC_NO, KC_NO, KC_NO, \
  TO(_BTEC),  KC_NO, KC_NO, KC_NO, DYN_REC_STOP, KC_NO, KC_NO, DYN_MACRO_PLAY1, DYN_MACRO_PLAY2, KC_NO, KC_NO, KC_NO, \
  TO(_COLEMAK), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, DYN_REC_START1, DYN_REC_START2, KC_NO, KC_NO, KC_NO, \
  TO(_LAYER),   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO \
)};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (!process_record_dynamic_macro(keycode, record)) {
		return false;
	}
	return true;
}

