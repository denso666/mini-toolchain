OUT_DIR=../output/
KERNEL=_$(shell uname -s)_$(shell uname -m)
CC=gcc
CFLAGS=-c -Wall -fpic
CROSS_COMPILE=
COMMANDS = $(basename $(filter %.c, $(wildcard ./*/*)))
OBJS = $(foreach cmd,$(addsuffix .so,$(COMMANDS)),$(addprefix $(addsuffix lib,$(dir $(cmd))),$(notdir $(cmd))))
LIB_FLAGS = $(foreach cmd, $(notdir $(COMMANDS)), $(addsuffix $(cmd),-l))
SO_FLAG = -Llib
LD_CMDS = $(notdir $(COMMANDS))
BIN = $(OUT_DIR)toolchain$(KERNEL)

.PHONY: clean

all: $(BIN)

$(BIN): $(OBJS) main.c
	@export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)/lib/
	@mkdir -p $(OUT_DIR)
	$(CROSS_COMPILE)$(CC) main.c $(LIB_FLAGS) $(SO_FLAG) -Wall -o $@
	@$(foreach cmd, $(LD_CMDS), ln -f -s $(shell pwd)/$(BIN) $(OUT_DIR)$(cmd);)

%.o: %.c
	$(CROSS_COMPILE)$(CC) $(CFLAGS) $< -o $@

lib%.so: %.o
	$(CROSS_COMPILE)$(CC) -shared $< -o $@
	
clean:
	@rm -f ./lib/*.so
	@rm -f -r ${OUT_DIR}
