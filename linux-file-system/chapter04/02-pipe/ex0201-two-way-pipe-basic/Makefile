CC = gcc

OBJDUMP = objdump

BUILD_DIR = buildDir

SRCS = main.c

TARGET = ex0201TwoWayPipeBasic

C_EXTRA :=
C_INC = $(patsubst %,-I%, $(C_EXTRA))

CLIBS :=
CFLAGS = -W -Wall -pedantic-errors

COBJS = $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))

all: clean createdirs pre assemble dump build

createdirs:
	$(shell mkdir ${BUILD_DIR})

pre: $(SRCS)
	$(CC) $(CFLAGS) -E $< -o $(BUILD_DIR)/$(patsubst %.c,%.i,$<)

assemble: $(SRCS)
	$(CC) $(CFLAGS) -S $< -o $(BUILD_DIR)/$(patsubst %.c,%.s,$<)

$(COBJS): $(BUILD_DIR)/%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

dump: $(COBJS)
	$(OBJDUMP) -S $< > $(patsubst %.o,%.dump,$<)

build: $(COBJS)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$(TARGET) $^

clean:
	rm -rf ${BUILD_DIR}

.SUFFIXES: .c .i .s .o .dump
.PHONNY: clean createdirs pre assemble dump build