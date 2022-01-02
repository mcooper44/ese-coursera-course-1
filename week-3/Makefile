

include sources.mk

TARGET = c1m3

CC = arm-none-eabi-gcc
LINKERFILE = msp432p401r.lds

SPECS = nosys.specs
FLOAT = softfp #hard #hard causes vfp errors on current host
CFLAGS = -std=c99 -Wall -Werror
ARMFLAGS = --specs=$(SPECS) -mfloat-abi=$(FLOAT) 
MPFLAGS = -Wl,-MAP=$(TARGET).map,-Wl,$(ARMFLAGS)
LDFLAGS = -T $(LINKERFILE)
ASMFLAGS = -fverbose-asm # adds informative comments when compiling with -S
# utils
OBJDUMP = arm-none-eabi-objdump
SIZE = arm-none-eabi-size
NM = arm-none-eabi-nm
# util flags
NMF = -S --size-sort -s
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
