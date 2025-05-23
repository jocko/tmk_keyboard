# Target file name (without extension).
TARGET ?= next_usb

# Directory common source filess exist
TMK_DIR ?= ../../tmk_core

# Directory keyboard dependent files exist
TARGET_DIR ?= .

# keyboard dependent files
SRC ?= next_usb.c


CONFIG_H ?= config.h


# MCU name, you MUST set this to match the board you are using
# type "make clean" after changing this, so all files will be rebuilt
# at90usb162       # Teensy 1.0
# atmega32u4       # Teensy 2.0
# at90usb646       # Teensy++ 1.0
# at90usb1286      # Teensy++ 2.0
MCU ?= atmega32u2


# Processor frequency.
#   Normally the first thing your program should do is set the clock prescaler,
#   so your program will run at the correct speed.  You should also set this
#   variable to same clock speed.  The _delay_ms() macro uses this, and many
#   examples use this variable to calculate timings.  Do not add a "UL" here.
F_CPU ?= 16000000


#
# LUFA specific
#
# Target architecture (see library "Board Types" documentation).
ARCH ?= AVR8

# Input clock frequency.
#     This will define a symbol, F_USB, in all source code files equal to the
#     input clock frequency (before any prescaling is performed) in Hz. This value may
#     differ from F_CPU if prescaling is used on the latter, and is required as the
#     raw input clock is fed directly to the PLL sections of the AVR for high speed
#     clock generation for the USB and other AVR subsections. Do NOT tack on a 'UL'
#     at the end, this will be done automatically to create a 32-bit value in your
#     source code.
#
#     If no clock division is performed on the input clock inside the AVR (via the
#     CPU clock adjust registers or the clock division fuses), this will be equal to F_CPU.
F_USB ?= $(F_CPU)


# Build Options
#   *Comment out* to disable the options.
#
MOUSEKEY_ENABLE ?= yes	# Mouse keys
EXTRAKEY_ENABLE ?= yes	# Audio control and System control
NKRO_ENABLE ?= no	# USB Nkey Rollover
UNIMAP_ENABLE ?= yes
KEYMAP_SECTION_ENABLE ?= yes
CONSOLE_ENABLE ?= yes	# Console for debug
COMMAND_ENABLE ?= yes	# Commands for debug and configuration

#NO_KEYBOARD = yes	# disable keyboard


# Boot Section Size in bytes
#   Teensy halfKay   512
#   Atmel DFU loader 4096
#   LUFA bootloader  4096
# Bootloader size can be calculated from fuse bits
#OPT_DEFS += -DBOOTLOADER_SIZE=4096


#
# Keymap file
#
ifeq (yes,$(strip $(UNIMAP_ENABLE)))
    KEYMAP_FILE = unimap
else
    ifeq (yes,$(strip $(ACTIONMAP_ENABLE)))
        KEYMAP_FILE = actionmap
    else
        KEYMAP_FILE = keymap
    endif
endif
ifdef KEYMAP
    SRC := $(KEYMAP_FILE)_$(KEYMAP).c $(SRC)
else
    SRC := $(KEYMAP_FILE).c $(SRC)
endif


# Search Path
VPATH += $(TARGET_DIR)
VPATH += $(TMK_DIR)


include $(TMK_DIR)/protocol/lufa.mk
include $(TMK_DIR)/protocol.mk
include $(TMK_DIR)/common.mk
include $(TMK_DIR)/rules.mk
