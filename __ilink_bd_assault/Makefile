
IOP_BIN = ../ilink_bd_assault.irx


#IEEE1394_bd
IEEE1394_BD_OBJS = sbp2_driver.o main.o scsi.o
IOP_CFLAGS += -mno-check-zero-division -Wno-strict-aliasing # -DSIF_CALLBACKS_12_13
IOP_INCS += -I../bdm/include
IOP_LDFLAGS = -lgcc

#ilinkman
ILINKMAN_OBJS = iLink.o iLink_PHY.o iLink_internal.o iLink_crom.o iLink_intr.o iLink_TxRx.o iLink_DMA.o
IOP_INCS += -IiLinkman/include/

IOP_OBJS = $(IEEE1394_BD_OBJS) $(ILINKMAN_OBJS) imports.o exports.o
IOP_CFLAGS += -DREQ_CHECK_CONSOLE_VERSION
ifeq ($(DEBUG), 1)
  IOP_CFLAGS += -DDEBUG -DDEBUG_EXTREME
endif
include ../global.make
IOP_SRC_DIR =


$(IOP_OBJS_DIR)%.o: src/IEEE1394_bd/src/%.c
	$(DIR_GUARD)
	$(IOP_C_COMPILE) -c $< -o $@
$(IOP_OBJS_DIR)%.o: src/ilinkman/src/%.c
	$(DIR_GUARD)
	$(IOP_C_COMPILE) -c $< -o $@