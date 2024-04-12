CC = gcc

OBJDUMP = objdump

SRCS = main.c

BUILD_DIR = buildDir

TARGET = ex0101MutexConcept

C_EXTRA :=  customerror.h
C_INC = $(patsubst %,-I%, $(C_EXTRA))

COBJS = $(addprefix $(BUILD_DIR)/, $(SRCS:.c=.o))

CILBS = -pthread

CFLAGS = -W -Wall -pedantic-errors $(CILBS)

all: clean createdirs pre assemble dump build

createdirs:
	$(shell mkdir ${BUILD_DIR})

pre: $(SRCS)
	$(CC) $(CFLAGS) $(C_INC) -E $< -o $(BUILD_DIR)/$(patsubst %.c,%.i,$<)

assemble: $(SRCS)
	$(CC) $(CFLAGS) $(C_INC) -S $< -o $(BUILD_DIR)/$(patsubst %.c,%.s,$<)

$(COBJS): $(BUILD_DIR)/%.o : %.c
	$(CC) $(CFLAGS) $(C_INC) -o $@ -c $<

dump: $(COBJS)
	$(OBJDUMP) -S $< > $(patsubst %.o,%.dump,$<)

build: $(COBJS)
	$(CC) $(CFLAGS) $(C_INC) -o $(BUILD_DIR)/$(TARGET) $^

clean:
	rm -rf ${BUILD_DIR}

.SUFFIXES: .c .i .s .o .dump
.PHONNY: clean createdirs pre assemble dump build