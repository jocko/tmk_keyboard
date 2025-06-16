traktor keyboard firmware
=========================

This is for the board with a Pro Micro in it!

Add udev rule:

    echo 'SUBSYSTEM=="tty", ATTRS{idVendor}=="2341", SYMLINK+="traktor-mkii"' \
        | sudo tee /etc/udev/rules.d/10-tmk-arduino-micro.rules

Use must belong to correct group. For example, `dialout` on Ubuntu:

    sudo usermod -aG dialout $USER

Or, `uucp` on Arch:

    sudo usermod -aG uucp $USER

Build firmware:

    make

Then upload:

    sleep 5; make program

Controller reset can be triggered via boot magic `LShift + RShift + Pause`
(`Pause` is left layer button + enter). Reset can also be triggered by
shorting RST to GND.

