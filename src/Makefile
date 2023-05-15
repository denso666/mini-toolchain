LIB=./lib
INC=./include
OUT=../output
KREL=$(shell uname -r)
PWD=$(shell pwd)
CC=gcc
CFLAGS=-Wall -g
CROSSC=
CMDS=sleep uname ls cat lsmod uptime mkdir chown chmod touch

.PHONY: clean folders

all: folders commands
	${CROSSC}${CC} ${CFLAGS} main.c ${OUT}/commands_${KREL}.o -o ${OUT}/bin_${KREL}.o
	@$(foreach cmd, $(CMDS), ln -f -s ${PWD}/${OUT}/bin_${KREL}.o ${OUT}/$(cmd);)

commands: ${LIB}/commands.c ${INC}/commands.h
	${CROSSC}${CC} ${CFLAGS} -c ${LIB}/commands.c -o ${OUT}/commands_${KREL}.o

folders:
	mkdir -p ${OUT}

clean:
	@rm -f -r ${OUT}
