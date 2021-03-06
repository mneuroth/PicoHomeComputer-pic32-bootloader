#
# Copyright (C) 2014-2015 Darron Broad
# All rights reserved.
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# 3. Neither the name `Darron Broad' nor the names of any contributors
#    may be used to endorse or promote products derived from this
#    software without specific prior written permission.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#

CPU     = 32MX250F128B
BOARD	= BREADBOARD_9600
OBJ	= obj/$(BOARD)
LKR	= lib/MX1-2-boot-linkerscript.ld

HEAP    =
STACK   =

PIC32   = /mnt/c/Users/micha/AppData/Local/Arduino15/packages/chipKIT/tools/pic32-tools/1.43-pic32gcc
ifeq (,$(wildcard $(PIC32)))
$(error $(PIC32) unavailable)
endif

COMPILE = $(PIC32)/bin/pic32-

AS      = $(COMPILE)as.exe
LD      = $(COMPILE)ld.exe
CC      = $(COMPILE)gcc.exe
AR      = $(COMPILE)ar.exe
NM      = $(COMPILE)nm.exe
HX      = $(COMPILE)bin2hex.exe
STRIP   = $(COMPILE)strip.exe
OBJCOPY = $(COMPILE)objcopy.exe
OBJDUMP = $(COMPILE)objdump.exe

RM      = /bin/rm

TARGET  = $(BOARD).hex

CSOURCE = main.c
CHEADER = main.h BoardConfig.h serial.h util.h configs/not_element14.h
COBJECT = $(OBJ)/main.o

ASOURCE = crt0.S
AOBJECT = $(OBJ)/crt0.o

ELF     = $(OBJ)/$(TARGET:.hex=.elf)
MAP     = $(OBJ)/$(TARGET:.hex=.map)

CFLAGS  = -mprocessor=$(CPU) -D_BOARD_$(BOARD)_ -mips16 -Os -fverbose-asm -save-temps=obj -mdebugger
CLINK   = -nostdlib -nostartfiles -mno-peripheral-libs -Wl,-T$(LKR),-Map=$(MAP)

build:init $(TARGET)

init:
	@mkdir -p $(OBJ)

$(TARGET):$(ELF)
	@echo -n "[HX] "
	$(HX) $(ELF)
	@echo -n "[MV] "
	mv $(OBJ)/$(TARGET) $(TARGET)

$(ELF):$(AOBJECT) $(COBJECT)
	@echo -n "[LINK] "
	$(CC) $(CFLAGS) $(CPPFLAGS) $(AOBJECT) $(COBJECT) -o $(ELF) $(CLINK)

$(COBJECT):$(CHEADER) mk/BREADBOARD_9600.mk $(LKR)

program:build
	p32 program $(TARGET)

verify:
	p32 verify $(TARGET)

$(OBJ)/%.o:%.c
	@echo -n "[CC] "
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ)/%.o:%.S
	@echo -n "[CC] "
	$(CC) $(CFLAGS) $(AFLAGS) $(CPPFLAGS) -c $< -o $@

install:build

uninstall:clean

clean:
	@echo -n "[RM] "
	$(RM) -Rf obj *.elf *.map *.hex *~
