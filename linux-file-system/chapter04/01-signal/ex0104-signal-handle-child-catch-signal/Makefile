CC = gcc

OBJDUMP = objdump

SRCS = main.c

BUILD_DIR = buildDir

TARGET = ex0104SignalHandleChildProcess

C_EXTRA :=
C_INC = $(patsubst %,-I%,$(C_EXTRA))

CLIBS = -pthread
CFLAGS = -W -Wall -pedantic-errors $(CLIBS)

COBJS = $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))

all: clean createdirs pre assemble dump build