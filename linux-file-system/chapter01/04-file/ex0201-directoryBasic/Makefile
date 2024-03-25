CC = gcc

SRCS = main.c

BUILD_DIR = buildDir

TARGET = ex0201DirectoryBasic

COBJS = $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))

C_EXTRA :=

C_INC = $(patsubst %,-I%, $(C_EXTRA))

CFLAGS = -W -Wall -pedantic-errors

all: clean createdirs pre assemble build

createdirs:
	$(shell mkdir ${BUILD_DIR})

build: $(COBJS)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(TARGET) $^

$(COBJS): $(BUILD_DIR)/%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<



pre: $(SRCS)
	$(CC) $(CFLAGS) -E $^ > $(BUILD_DIR)/$^.pre

assemble: $(SRCS)
	$(CC) $(CFLAGS) -S $< -o $(BUILD_DIR)/$(patsubst %.c,%s, $<)


clean:
	rm -rf ${BUILD_DIR}


.SUFFIXES: .c .s .o .pre
.PHONNY: clean createdirs pre assemble build