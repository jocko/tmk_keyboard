traktor keyboard firmware
=========================

This is for the board with a Pro Micro in it!

Enter bootloader mode by shorting RST to GND (double tapping supposedly gives longer reset time).

Makefile is only for compiling. Flashing is done by:

  avrdude -patmega32u4 -cavr109 -b57600 -Uflash:w:traktor_lufa.hex -P/dev/ttyACM1
