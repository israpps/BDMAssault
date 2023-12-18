
IOP_BIN = bdm_assault.irx


#bdm
BDM_OBJS = main.o bdm.o part_driver.o part_driver_mbr.o part_driver_gpt.o
IOP_LIBS += ../libbdm/lib/libbdm.a
IOP_CFLAGS += -I../libbdm/include/ -Wno-strict-aliasing

#bdmfs_fatfs
BDMFS_FATFS_OBJS = ff.o ffsystem.o ffunicode.o fs_driver.o diskio.o main.o
IOP_LIBS += -static-libgcc -lgcc

IOP_OBJS = $(addprefix bdm_,$(BDM_OBJS)) $(addprefix bdmfs_,$(BDMFS_FATFS_OBJS)) imports.o exports.o

include ../global.make
IOP_SRC_DIR =
vpath %.c src/
vpath %.lst src/
vpath %.tab src/
vpath %.c src/bdm/
vpath %.c src/bdmfs/


$(IOP_OBJS_DIR)%.o: src/bdm/%.c
	$(DIR_GUARD)
	$(IOP_C_COMPILE) -c $< -o $@
$(IOP_OBJS_DIR)%.o: src/bdmfs/%.c
	$(DIR_GUARD)
	$(IOP_C_COMPILE) -c $< -o $@