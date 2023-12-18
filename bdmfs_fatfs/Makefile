# _____     ___ ____     ___ ____
#  ____|   |    ____|   |        | |____|
# |     ___|   |____ ___|    ____| |    \    PS2DEV Open Source Project.
#-----------------------------------------------------------------------
# Copyright 2001-2004, ps2dev - http://www.ps2dev.org
# Licenced under Academic Free License version 2.0
# Review ps2sdk README & LICENSE files for further details.

# IOP_CFLAGS += -DDEBUG -DDEBUG_EXTREME

IOP_BIN = bdmfs_fatfs.irx

IOP_INCS += -I../bdm/include
IOP_CFLAGS += -Wno-error -Wno-strict-aliasing

IOP_OBJS = ff.o ffsystem.o ffunicode.o fs_driver.o diskio.o main.o imports.o
IOP_LIBS = -static-libgcc -lgcc

include ../global.make