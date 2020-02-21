## Bootloader for the PicoHomeComputer

This is the source code for the bootloader of the PIC32 of the PicoHomeComputer.
This source code is cloned from a [mercurical repository of kewl.org](http://hg.kewl.org/pub/chipKITPi)
on the [kewl.org homepage](https://wiki.kewl.org/dokuwiki/projects:chipkit32) and modified
for the PicoHomeComputer.

The main processor of the PicoHomeComputer is a PIC32MX270B256 with 64kByte RAM and 256kByte Flash running with 48 MHz.
To build the bootloader for the PicoHomeComputer the configuration [CHIPKIT_DP32_MX270_48.mk](firmware/mk/CHIPKIT_DP32_MX270_48.mk)
will be used.

To build the bootloader the gcc compiler from the [chipKIT plugin](https://chipkit.net/wiki/index.php?title=ChipKIT_core) 
for the [ArduinoIDE](https://www.arduino.cc/en/Main/Software) will be used from the directory

    C:\Users\{username}\AppData\Local\Arduino15\packages\chipKIT\tools\pic32-tools\1.43-pic32gcc
    
To compile under windows (in a bash) the [CHIPKIT_DP32_MX270_48.mk](firmware/mk/CHIPKIT_DP32_MX270_48.mk) was patchted to use
the absolute path for the gcc compiler tools.

    > bash
    > cd {project-root}/firmware
    > make clean
    > make
    > mv CHIPKIT_DP32_MX270_48.hex CHIPKIT_PicoHomeComputer_MX270_48.hex

Pinouts:
* The bootloader activated LED is assigned to PIC32 pin 0 (A0).
* The program button is assigned to PIC32 pin 4 (B0)

A binary hex file to flash the PIC32 with a Pickit3 programme is available [here](firmware/bootloaders-hex/CHIPKIT_PicoHomeComputer_MX270_48.hex).
