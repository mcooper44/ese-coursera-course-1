

include sources.mk

TARGET = c1m3

CC = arm-none-eabi-gcc
LINKERFILE = msp432p401r.lds

SPECS = nosys.specs
FLOAT = softfp #hard #hard causes vfp errors on current host
CFLAGS = -std=c99
ARMFLAGS = --specs=$(SPECS) -mfloat-abi=$(FLOAT) 
MPFLAGS = -Wl,-MAP=$(TARGET).map,-Wl,$(ARMFLAGS)
LDFLAGS = -T $(LINKERFILE)

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

FILES = *.o *.map *.s

*.o:%.c
	$(CC) -c $(CFLAGS) $(ARMFLAGS) $@ $<

%.s:%.c
	$(CC) -S $< -o $@

.PHONY: build
build: $(ASMS) $(TARGET).out $(TARGET).s
	$(NM) $(NMF) $(TARGET).out > $(TARGET).nm

$(TARGET).s : $(TARGET).out
	$(OBJDUMP) $(OBJDF) $(TARGET).out > $@

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(ARMFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $(SIZEF) $(TARGET).out > $(TARGET).size
.PHONY: clean

clean:
	rm -rf $(FILES) *.nm *.size *.out
