CC = gcc

SRCS = main.c

BUILD_DIR = buildDir

TARGET = ex0106LsUtilConditionalCharBlockAndBlock

C_EXTRA =

C_INC = $(patsubst %,-I%, $(C_EXTRA))

CFLAGS = -W -Wall -pedantic-errors

COBJS = $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))

all: clean createdirs pre assemble build

createdirs:
	$(shell mkdir ${BUILD_DIR})

build: $(COBJS)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(TARGET) $^

pre: $(SRCS)
	$(CC) $(CFLAGS) -E $^ > $(BUILD_DIR)/$(patsubst %.c,%.pre, $^)

assemble: $(SRCS)
	$(CC) $(CFLAGS) -S $< -o $(BUILD_DIR)/$(patsubst %.c,%.s, $<)

clean:
	rm -rf ${BUILD_DIR}

.SUFFIXES: .c .o .pre .s
.PHONNY: clean createdirs pre assemble build