TARGET_NAME := thread

BUILD_DIR := build

all: build run

build:
	@if not exist $(BUILD_DIR) (mkdir $(BUILD_DIR))
	@gcc -c  main.c -o $(BUILD_DIR)/main.o
	@gcc $(BUILD_DIR)/main.o  -o $(BUILD_DIR)/$(TARGET_NAME).exe

run:
	@./$(BUILD_DIR)/$(TARGET_NAME).exe

clean:
	@rmdir /s /q build