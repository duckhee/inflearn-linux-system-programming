CC = gcc

SRCS = main.c

BUILD_DIR = buildDir

TARGET = ex0104FileUID-GID

CFLAGS = -W -Wall -pedantic-errors

COBJS = $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))

all: clean createdirs pre build

createdirs:
	$(shell mkdir ${BUILD_DIR})

$(COBJS): $(BUILD_DIR)/%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

pre: $(SRCS)
	$(CC) $(CFLAGS) -E $^ > $(BUILD_DIR)/$^.pre

build: $(COBJS)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(TARGET) $^

clean:
	rm -rf ${BUILD_DIR}


.SUFFIXES: .c .o .pre
.PHONNY: clean createdirs pre build clean