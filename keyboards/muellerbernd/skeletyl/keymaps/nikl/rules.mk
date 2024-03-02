RGBLIGHT_ENABLE = no       # Enable WS2812 RGB underlight.
OLED_ENABLE = no
OLED_DRIVER = SSD1306
WPM_ENABLE = no
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
ENCODER_ENABLE = yes      # use an encoder
LTO_ENABLE = yes            # significantly reduce the compiled size, but disable the legacy TMK Macros and Functions features
EXTRAFLAGS+=-flto
# EXTRAFLAGS += -ffat-lto-objects
TAP_DANCE_ENABLE = no
LEADER_ENABLE = no
# CONSOLE_ENABLE = yes
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
MUSIC_ENABLE = no
AUTO_SHIFT_ENABLE = no
CONSOLE_ENABLE = yes
COMMAND_ENABLE = no
COMBO_ENABLE = no
ifeq ($(strip $(COMBO_ENABLE)), no)
	# SRC += users/muellerbernd/combo.c
	# INTROSPECTION_KEYMAP_C = users/muellerbernd/combo.c
	VPATH += keyboards/gboards
endif

PIMORONI_TRACKBALL_ENABLE = yes
CUSTOM_POINTING_DEVICE = no

ifeq ($(strip $(PIMORONI_TRACKBALL_ENABLE)), yes)
	POINTING_DEVICE_ENABLE = yes
	POINTING_DEVICE_DRIVER = pimoroni_trackball
	# SRC += pimoroni_trackball.c
	QUANTUM_LIB_SRC += i2c_master.c
endif
