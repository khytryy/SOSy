SOSY_VER	:= v1.0.0-pre-alpha

CC 			:= i686-elf-gcc
ASM 		:= nasm

C_SRC 		:= $(shell find src -name "*.c")
ASM_SRC 	:= $(shell find src -name "*.asm")

INC     	:= $(shell find include -name "*.h")
TARGET		:= sosykrnl

C_OBJS    	:= $(patsubst src/%.c,   obj/%.o, $(C_SRC))
ASM_OBJS   	:= $(patsubst src/%.asm, obj/%.o, $(ASM_SRC))

OBJS		:= $(C_OBJS) $(ASM_OBJS)
DEPS    	:= $(C_OBJS:.o=.d)

C_FLAGS		:= -ffreestanding -O2 -Wall -Wextra -MMD -MP -Iinclude -g
LD_FLAGS	:= -ffreestanding -lgcc -nostdlib

ASM_FLAGS   := -felf32

all: $(TARGET) iso

# Link object files
$(TARGET): $(OBJS)
	@echo "  LD      $@"
	@$(CC) $(LD_FLAGS) -T linker.ld -o $@ $^

# Compile C code
obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	@echo "  CC      $<"
	@$(CC) $(C_FLAGS) -c $< -o $@

# Assembly asm code
obj/%.o: src/%.asm
	@mkdir -p $(dir $@)
	@echo "  ASM     $<"
	@$(ASM) $(ASM_FLAGS) $< -o $@

-include $(DEPS)

clean:
	@echo "Cleaning up..."
	@rm -rf $(OBJ_DIR) $(TARGET)
	@rm -rf obj $(TARGET) iso sosy-*.iso

iso: $(TARGET)
	@echo "Building an ISO..."
	@mkdir -p iso/boot/grub

	@cp $(TARGET) iso/boot/$(TARGET)
	@cp grub.cfg  iso/boot/grub/grub.cfg

	@grub-mkrescue -o sosy-$(SOSY_VER).iso iso

.PHONY: all clean iso