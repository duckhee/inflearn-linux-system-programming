CC = gcc

SRCS = main.c

BUILD_DIR = buildDir

TARGET = ex0105LsUtilityGetFileTime

CFLAGS = -W -Wall -pedantic-errors



COBJS = $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))
ASSEMBLER = $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.s))
all: clean createdirs pre asemble build

createdirs:
	$(shell mkdir ${BUILD_DIR})

build: $(COBJS)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(TARGET) $^

$(COBJS): $(BUILD_DIR)/%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

pre: $(SRCS)
	$(CC) $(CFLAGS) -E $^ > ${BUILD_DIR}/$^.pre

asemble: $(SRCS)
	$(CC) $(CFLAGS) -S $< -o $(BUILD_DIR)/$(patsubst %.c,%.s, $<)

clean:
	rm -rf ${BUILD_DIR}

.SUFFIXES: .c .o .pre .s
.PHONNY: clean createdirs pre asemble build