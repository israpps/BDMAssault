# _____     ___ ____     ___ ____
#  ____|   |    ____|   |        | |____|
# |     ___|   |____ ___|    ____| |    \    PS2DEV Open Source Project.
#-----------------------------------------------------------------------
# Copyright 2001-2004, ps2dev - http://www.ps2dev.org
# Licenced under Academic Free License version 2.0
# Review ps2sdk README & LICENSE files for further details.

# IOP_CFLAGS += -DDEBUG

IOP_BIN = usbmass_bd.irx

IOP_INCS += -I../usbd/include
IOP_INCS += -I../bdm/include

IOP_CFLAGS += -Wno-strict-aliasing

IOP_LDFLAGS = -lgcc

IOP_OBJS = main.o usb_mass.o scsi.o imports.o

include ../global.make
