

include sources.mk

TARGET = c1m3

CC = arm-none-eabi-gcc
LINKERFILE = msp432p401r.lds

SPECS = nosys.specs
FLOAT = softfp #hard #hard causes vfp errors on current host
DEBUGFLAGS = -g3
# overview of extra flags at 
# https://interrupt.memfault.com/blog/best-and-worst-gcc-clang-compiler-flags
EXTRAFLAGS = -fno-common -Wundef -Wdouble-promotion
CFLAGS = -std=c99 -Wall -Werror
ARMFLAGS = --specs=$(SPECS) -mfloat-abi=$(FLOAT) 
MPFLAGS = -Wl,-Map=$(TARGET).map 
LDFLAGS = $(MPFLAGS) -T $(LINKERFILE)
ASMFLAGS = -fverbose-asm # adds informative comments when compiling with -S
# utils
OBJDUMP = arm-none-eabi-objdump
SIZE = arm-none-eabi-size
NM = arm-none-eabi-nm
# util flags
# -S --size-sort prints the value and size of the symbol
NMF = -S --size-sort --line-numbers
SIZEF = -Atd
OBJDF = -d

OBJS:= $(SOURCES:.c=.o)
ASMS:= $(SOURCES:.c=.s)

FILES = *.o *.map *.s *.size *.nm

*.o:%.c
	$(CC) -c $(CFLAGS) $(ARMFLAGS) $@ $<

%.s:%.c
	$(CC) -S $(ASMFLAGS) $< -o $@

.PHONY: build
build: $(ASMS) $(TARGET).out $(TARGET).s
	@echo "profiling with nm"
	$(NM) $(NMF) $(TARGET).out > $(TARGET).nm

$(TARGET).s : $(TARGET).out
	@echo "disassembling target output"
	$(OBJDUMP) $(OBJDF) $(TARGET).out > $@

$(TARGET).out: $(OBJS)
	@echo "compiling..."
	$(CC) $(OBJS) $(CFLAGS) $(ARMFLAGS) $(LDFLAGS) -o $@
	@echo "profiling with size"
	$(SIZE) $(SIZEF) $(TARGET).out > $(TARGET).size

.PHONY: clean

clean:
	@echo "reseting to starting point"
	rm -rf $(FILES)
