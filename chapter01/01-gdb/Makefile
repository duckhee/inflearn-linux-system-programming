CC = gcc

SRCS = main.c

BUILD_DIR = buildDir

TARGET = ex01GDB

C_FLAGS = -g

COBJS = $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))

all: clean createdirs build

createdirs:
	$(shell mkdir ${BUILD_DIR})

