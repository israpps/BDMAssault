
IOP_BIN = usbd_bd_assault.irx

#usbd
USBD_OBJS = hcd.o hub.o interface.o mem.o usbd.o usbio.o driver.o

#usbdmass_bd
IOP_INCS += -Isrc/usbd/include -I../bdm/include
IOP_CFLAGS += -Wno-strict-aliasing
IOP_LDFLAGS += -lgcc
USBMASS_BD_OBJS = main.o usb_mass.o scsi.o

IOP_OBJS = $(addprefix usbd_,$(USBD_OBJS)) $(addprefix usbmass_bd_,$(USBMASS_BD_OBJS)) imports.o exports.o
include ../global.make
$(IOP_OBJS_DIR)%.o: src/usbd/%.c
	$(DIR_GUARD)
	$(IOP_C_COMPILE) -c $< -o $@
$(IOP_OBJS_DIR)%.o: src/usbmass_bd/%.c
	$(DIR_GUARD)
	$(IOP_C_COMPILE) -c $< -o $@