RGBLIGHT_ENABLE = yes       # Enable WS2812 RGB underlight.
RGB_MATRIX_ENABLE = no
RGB_MATRIX_DRIVER = WS2812
OLED_ENABLE = yes
OLED_DRIVER = SSD1306
WPM_ENABLE = yes
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
ENCODER_ENABLE = yes      # use an encoder
COMBO_ENABLE = yes
TAP_DANCE_ENABLE = no
LEADER_ENABLE = no
CONSOLE_ENABLE = yes
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
MUSIC_ENABLE = no
AUTO_SHIFT_ENABLE = no
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
VPATH += keyboards/gboards

# POINTING_DEVICE_ENABLE = yes
PIMORONI_TRACKBALL_ENABLE = yes

ifeq ($(strip $(PIMORONI_TRACKBALL_ENABLE)), yes)
	POINTING_DEVICE_ENABLE = yes
	POINTING_DEVICE_DRIVER = pimoroni_trackball
	# SRC += pimoroni_trackball.c
	# QUANTUM_LIB_SRC += i2c_master.c
endif

RP2040_ENABLE = yes
ifeq ($(strip $(RP2040_ENABLE)), yes)
	# MCU name
	MCU = RP2040
	# Bootloader selection
	BOOTLOADER = rp2040
	# Ignore some warnings during the build, likely to be fixed before RP2040 PR is merged
	ALLOW_WARNINGS = yes
	# LTO must be disabled for RP2040 builds
	LTO_ENABLE = no
	# # PIO serial/WS2812 drivers must be used on RP2040
	# SERIAL_DRIVER = vendor
	# WS2812_DRIVER = vendor
	# Audio currently doesn't work with the RP2040
	AUDIO_ENABLE = no
	# convert to rp2040 pinout. if you use the kb2040 comment this line and uncomment the second line
	# CONVERT_TO = promicro_rp2040
	CONVERT_TO = kb2040
	BOOTMAGIC_ENABLE = no
endif

CUSTOM_SPLIT_TRANSPORT_SYNC ?= yes
ifeq ($(strip $(CUSTOM_SPLIT_TRANSPORT_SYNC)), yes)
	# QUANTUM_LIB_SRC += $(USER_PATH)/split/transport_sync.c
	OPT_DEFS += -DCUSTOM_SPLIT_TRANSPORT_SYNC
endif
