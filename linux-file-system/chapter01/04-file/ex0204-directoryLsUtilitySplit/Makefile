CC = gcc

SRCS = main.c

BUILD_DIR = buildDir

TARGET = ex0204DirectoryLsUtilitySplit

CFLAGS = -W -Wall -pedantic-errors

C_EXTRA :=
C_INC = $(patsubst %,-I%, $(C_EXTRA))

COBJS = $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))

all: clean createdirs pre assemble build

createdirs:
	$(shell mkdir ${BUILD_DIR})

pre: $(SRCS)
	$(CC) $(CFLAGS) -E $^ > $(BUILD_DIR)/$^.pre

assemble: $(SRCS)
	$(CC) $(CFLAGS) -S $< -o $(BUILD_DIR)/$(patsubst %., %.s, $<)

$(COBJS):$(BUILD_DIR)/%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

build: $(COBJS)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(TARGET) $^

clean:
	rm -rf ${BUILD_DIR}

.SUFFIXES: .c .pre .s .o
.PHONNY: clean createdirs pre assemble build