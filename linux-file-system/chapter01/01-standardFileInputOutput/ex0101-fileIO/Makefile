CC = gcc

OBJDUMP = objdump

SRCS = main.c

BUILD_DIR = buildDir

TARGET = ex0101FileIO

COBJS = $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))

CFLAGS = -W -Wall -pedantic-errors

all: clean createdirs pre assemble dump build

createdirs:
	$(shell mkdir ${BUILD_DIR})

pre: $(SRCS)
	$(CC) $(CFLAGS) -E $< -o $(BUILD_DIR)/$(patsubst %.c,%.i,$<)

assemble: $(SRCS)
	$(CC) $(CFLAGS) -S $< -o $(BUILD_DIR)/$(patsubst %.c,%.s,$<)

build: $(COBJS)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(TARGET) $^

$(COBJS): $(BUILD_DIR)/%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

dump: $(COBJS)
	$(OBJDUMP) -S $< > $(patsubst %.o,%.dump,$<)

clean:
	rm -rf ${BUILD_DIR}

.SUFFIXES: .c .i .s  .o .dump
.PHONNY: clean createdirs pre assemble dump build