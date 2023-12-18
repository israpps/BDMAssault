
all: $(IOP_BIN) $(IOP_LIB)
clean:
	rm -rf $(IOP_OBJS_DIR) $(IOP_BIN) $(IOP_LIB)

rebuild: clean all
.PHONY: all clean rebuild

IOP_OBJS_DIR = obj/
IOP_SRC_DIR = src/
IOP_INC_DIR = $(IOP_SRC_DIR)include/
IOP_INCS += -I$(IOP_SRC_DIR)

include $(PS2SDK)/Defs.make
include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.iopglobal