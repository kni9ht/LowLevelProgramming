PWD := $(shell pwd)
SRC := $(PWD)/src
BUILD := $(PWD)/build
LIB := extrLib
MOD := program


%:
	@:

asmTOc:
	@mkdir -p $(PWD)/build
	@nasm -f elf64 -o $(BUILD)/$(LIB).o $(SRC)/$(LIB).asm
	@echo "[+] Done building Library"
	@gcc -c $(SRC)/$(MOD).c -o $(BUILD)/$(MOD).o	
	@echo "[+] Done building Binary"
	@gcc $(BUILD)/$(LIB).o $(BUILD)/$(MOD).o -o $(BUILD)/program
	@echo "[+] Done Linking Binary"


asm:
	@mkdir -p $(PWD)/build
	@nasm -f elf64 -o $(BUILD)/$(filter-out $@,$(MAKECMDGOALS)).o $(SRC)/$(filter-out $@,$(MAKECMDGOALS)).asm
	@ld -o $(BUILD)/$(filter-out $@,$(MAKECMDGOALS)) $(BUILD)/$(filter-out $@,$(MAKECMDGOALS)).o
	@echo "🔧 Done building $(filter-out $@,$(MAKECMDGOALS)).asm"

gcc:
	@mkdir -p $(PWD)/build
	@gcc -c $(SRC)/$(filter-out $@,$(MAKECMDGOALS)).c -o $(BUILD)/$(filter-out $@,$(MAKECMDGOALS)).o
	@gcc -o $(BUILD)/$(filter-out $@,$(MAKECMDGOALS)) $(SRC)/$(filter-out $@,$(MAKECMDGOALS)).c
	@echo "🔧 Done building $(filter-out $@,$(MAKECMDGOALS)).c"

g++:
	@mkdir -p $(PWD)/build
	@g++ -o $(BUILD)/$(filter-out $@,$(MAKECMDGOALS)) $(SRC)/$(filter-out $@,$(MAKECMDGOALS)).cpp
	@echo "🔧 Done building $(filter-out $@,$(MAKECMDGOALS)).cpp"

clean:
	@rm -rf $(BUILD)/*
	@echo "🧹 Done cleaning"

run:
	@$(BUILD)/$(filter-out $@,$(MAKECMDGOALS))

dump:
	@objdump -d -M intel $(BUILD)/$(filter-out $@,$(MAKECMDGOALS))
