# File              : rules.mk
# Author            : Bernd Müller <bernd@muellerbernd.de>
# Date              : 29.11.2021
# Last Modified Date: 24.05.2023
# Last Modified By  : Bernd Müller <bernd@muellerbernd.de>
RGBLIGHT_ENABLE = no       # Enable WS2812 RGB underlight.
OLED_ENABLE = no
OLED_DRIVER = SSD1306
WPM_ENABLE = no
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
ENCODER_ENABLE = no      # use an encoder
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
# VPATH += keyboards/gboards
ifeq ($(strip $(COMBO_ENABLE)), yes)
	SRC += users/muellerbernd/combo.c
endif
