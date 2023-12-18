# _____     ___ ____     ___ ____
#  ____|   |    ____|   |        | |____|
# |     ___|   |____ ___|    ____| |    \    PS2DEV Open Source Project.
#-----------------------------------------------------------------------
# Copyright 2001-2004, ps2dev - http://www.ps2dev.org
# Licenced under Academic Free License version 2.0
# Review ps2sdk README & LICENSE files for further details.

# IOP_CFLAGS += -DDEBUG

IOP_BIN = bdm.irx

IOP_OBJS = main.o bdm.o part_driver.o part_driver_mbr.o part_driver_gpt.o imports.o exports.o
IOP_LIBS = ../libbdm/lib/libbdm.a
IOP_CFLAGS += -I../libbdm/include/ -Wno-strict-aliasing

include ../global.make

../libbdm/lib/libbdm.a:
	$(MAKE) ../libbdm