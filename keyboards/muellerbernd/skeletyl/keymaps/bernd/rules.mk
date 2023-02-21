
# File              : rules.mk
# Author            : Bernd Müller <bernd@muellerbernd.de>
# Date              : 29.11.2021
# Last Modified Date: 09.01.2023
# Last Modified By  : Bernd Müller <bernd@muellerbernd.de>
RGBLIGHT_ENABLE = yes       # Enable WS2812 RGB underlight.
OLED_ENABLE = no
OLED_DRIVER = SSD1306
WPM_ENABLE = no
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
CONSOLE_ENABLE = yes
COMMAND_ENABLE = no
VPATH += keyboards/gboards

PIMORONI_TRACKBALL_ENABLE = yes
CUSTOM_POINTING_DEVICE = no

ifeq ($(strip $(PIMORONI_TRACKBALL_ENABLE)), yes)
	POINTING_DEVICE_ENABLE = yes
	POINTING_DEVICE_DRIVER = pimoroni_trackball
	# SRC += pimoroni_trackball.c
	QUANTUM_LIB_SRC += i2c_master.c
endif

CUSTOM_SPLIT_TRANSPORT_SYNC ?= no
ifeq ($(strip $(CUSTOM_SPLIT_TRANSPORT_SYNC)), yes)
	# QUANTUM_LIB_SRC += $(USER_PATH)/split/transport_sync.c
	OPT_DEFS += -DCUSTOM_SPLIT_TRANSPORT_SYNC
endif
