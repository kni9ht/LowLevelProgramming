CC = gcc
CFLAGS = -Wall -Ilib
LDFLAGS = -Lbuild/lib -lipc
BUILD_DIR = build
LIB_DIR = $(BUILD_DIR)/lib

all: pipe $(LIB_DIR)/libipc.a build/procA build/procB

$(LIB_DIR)/libipc.a: lib/IPC.c lib/ipc.h
	@mkdir -p $(LIB_DIR)
	$(CC) $(CFLAGS) -c lib/IPC.c -o $(LIB_DIR)/ipc.o
	ar rcs $(LIB_DIR)/libipc.a $(LIB_DIR)/ipc.o
	@rm $(LIB_DIR)/ipc.o

build/procA: procA.c
	$(CC) $(CFLAGS) procA.c -o build/procA $(LDFLAGS)

build/procB: procB.c
	$(CC) $(CFLAGS) procB.c -o build/procB $(LDFLAGS)

pipe:
	@mkdir -p $(BUILD_DIR)
	@if [ ! -p /tmp/SeGMsg ]; then mkfifo /tmp/SeGMsg; fi

clean:
	rm -rf build
	rm -f /tmp/SeGMsg
