
IOP_BIN = ../udp_bd_assault$(HAS_UDP)$(HAS_TTY)$(HAS_DEBUG).irx

#udpbd
UDPBD_OBJS = main.o smap.o xfer.o ministack.o
IOP_CFLAGS += -mno-check-zero-division
HAS_BDM = 1
NO_TTY ?= 0
NO_UDPBD ?= 0

ifeq ($(NO_UDPBD),1)
  IOP_CFLAGS += -DNO_UDPBD
  HAS_UDP = -no_udp
else
  UDPBD_OBJS += udpbd.o
endif

ifeq ($(NO_TTY),1)
  HAS_TTY = -no_tty
  IOP_CFLAGS += -DNO_TTY
else
  UDPBD_OBJS += udptty.o
endif

ifeq ($(HAS_BDM), 0)
  IOP_CFLAGS += -DNO_BDM
endif

#dev9
DEV9_OBJS = ps2dev9.o
DEV9_SKIP_SMAP_INIT ?= 0
DEV9_PSX_SUPPORT ?= 1
DEV9_GAMESTAR_WORKAROUND ?= 1
#IOP_INCS += -I$(PS2SDK)/iop/dev9/poweroff/include

ifeq ($(DEV9_SKIP_SMAP_INIT),1)
IOP_CFLAGS += -DDEV9_SKIP_SMAP_INIT=1
endif

ifeq ($(DEV9_PSX_SUPPORT),1)
IOP_CFLAGS += -DDEV9_PSX_SUPPORT=1
endif

ifeq ($(DEV9_GAMESTAR_WORKAROUND),1)
IOP_CFLAGS += -DDEV9_GAMESTAR_WORKAROUND=1
endif

#----{  }----#
IOP_OBJS = $(UDPBD_OBJS) $(DEV9_OBJS) imports.o exports.o

ifeq ($(DEBUG), 1)
  HAS_DEBUG = -debug
  IOP_CFLAGS += -DDEBUG -DDEBUG_EXTREME
endif

include ../global.make
$(IOP_OBJS_DIR)%.o: src/udpbd/src/%.c
	$(DIR_GUARD)
	$(IOP_C_COMPILE) -c $< -o $@

$(IOP_OBJS_DIR)%.o: src/dev9/src/%.c
	$(DIR_GUARD)
	$(IOP_C_COMPILE) -c $< -o $@

ifeq ($(DEBUG), 1)
ifeq ($(NO_TTY), 1)
$(warning "Enabling debug with TTY disabled is quite a stupid idea (unless you have an alternative method to see printf)")
endif
endif

variants:
	@echo -- normal
	@$(MAKE) --silent clean all
	@echo -- debug
	@$(MAKE) --silent clean all DEBUG=1
	@echo -- no_tty
	@$(MAKE) --silent clean all NO_TTY=1
	@echo -- no_udpbd
	@$(MAKE) --silent clean all NO_UDPBD=1