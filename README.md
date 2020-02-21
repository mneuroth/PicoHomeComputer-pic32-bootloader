## Bootloader for the PicoHomeComputer

This is the source code for the bootloader of the PIC32 of the PicoHomeComputer.
This source code is cloned from a [mercurical repository of kewl.org](http://hg.kewl.org/pub/chipKITPi)
on the [kewl.org homepage](https://wiki.kewl.org/dokuwiki/projects:chipkit32) and modified
for the PicoHomeComputer.

The main processor of the PicoHomeComputer is a PIC32MX270B256 with 64kByte RAM and 256kByte Flash running with 48 MHz.

The bootloader activated LED is assigned to PIC32 pin 0 (A0).
The program button is assigned to PIC32 pin 4 (B0)
