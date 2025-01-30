traktor keyboard firmware
=========================

This is for the board with a Pro Micro in it!

Makefile is only for compiling. Flashing is done by:

      avrdude -patmega32u4 -cavr109 -b57600 -Uflash:w:traktor_lufa.hex -P/dev/ttyACM1

Controller reset can be triggered via boot magic `LShift + RShift + Pause`
(`Pause` is left layer button + backspace). Reset can also be triggered by
shorting RST to GND.

