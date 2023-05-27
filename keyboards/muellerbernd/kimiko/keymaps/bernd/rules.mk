RGBLIGHT_ENABLE = yes       # Enable WS2812 RGB underlight.
RGB_MATRIX_ENABLE = no
RGB_MATRIX_DRIVER = WS2812
RGB_MATRIX_CUSTOM_USER = no #only need this if using custom effects
OLED_ENABLE = yes
OLED_DRIVER = SSD1306
WPM_ENABLE = yes
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
ENCODER_ENABLE = yes      # use an encoder
LTO_ENABLE = yes            # significantly reduce the compiled size, but disable the legacy TMK Macros and Functions features
EXTRAFLAGS+=-flto
# EXTRAFLAGS += -ffat-lto-objects
COMBO_ENABLE = yes
TAP_DANCE_ENABLE = no
LEADER_ENABLE = no
# CONSOLE_ENABLE = yes
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
MUSIC_ENABLE = no
AUTO_SHIFT_ENABLE = no
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c
AVR_USE_MINIMAL_PRINTF = yes

# VPATH += keyboards/gboards
ifeq ($(strip $(COMBO_ENABLE)), yes)
	SRC += users/muellerbernd/combo.c
endif

CUSTOM_SPLIT_TRANSPORT_SYNC = no
ifeq ($(strip $(CUSTOM_SPLIT_TRANSPORT_SYNC)), yes)
	# QUANTUM_LIB_SRC += $(USER_PATH)/split/transport_sync.c
	OPT_DEFS += -DCUSTOM_SPLIT_TRANSPORT_SYNC
endif
