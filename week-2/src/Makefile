#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# This is the second assignment for the Coursera Course Introduction to Embedded 
# Systems Software and Development Environments 
#
# The goal is to produce a makefile that can compile for host and target hardware
# and produce a variety of intermediary files and outputs for analysis
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <file>.i ---> this rule generates the preprocessor output + the dependency
#      	             file (.i and .d respectively) for the input .c file
#      <file>.asm ---> creates the assembly file with the help of objdump and stops there
#      <file>.o ---> creates the object and source files
#      compile-all ---> compiles all source files and creates object files but does not link
#      build ---> creates an executable named c1m2.out by linking the object files
#                 it also generates the memory map and outputs the size with the size tool
#      clean ---> purges .i .o .d .map .s .out files
#
# Platform Overrides:
#      This makefile support two platforms the native HOST and the MSP432. 
#      The host embedded system will use the native compiler, gcc. The target embedded system 
#      will use the cross compiler, arm-none-eabi-gcc. 
#      The PLATFORM keyword provided in the Makefile should be used to conditionally assign the 
#      appropriate compiler flags, linker flags, and architecture flags. The target 
#      platform must be provided at the command line with the make command to set the 
#      platform you are compiling for. 
#
#	eg. 
#	make build PLATFORM=MSP432
#	make build PLATFORM=HOST
#
#------------------------------------------------------------------------------
include sources.mk
# base file name for output specified in assignment
OUTPUTNAME = c1m2

# Platform Overrides - default platform
PLATFORM = MSP432
# generate dependency files
CPPFLAGS = -MMD -MP

# Architectures Specific Flags
# MSP432
ifeq ($(PLATFORM), MSP432)
	LINKER_FILE = ../msp432p401r.lds
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
	CC = arm-none-eabi-gcc 
	LD = arm-none-eabi-ld 
	# Wl can pass an option to the linker chained with commas.
	# the following passed c1m2.map to the linker
	LDFLAGS = -Wl,-Map=$(OUTPUTNAME).map -T $(LINKER_FILE)
	PLATFORM = MSP432
	# as per the assignment the following flags need to be passed in for the target
	CFLAGS = -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS) -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mthumb -Wall -Werror -g -O0 -std=c99 -D$(PLATFORM)
	SOURCES = $(MSP432_SOURCES)
	INCLUDES = $(MSP432_INCLUDES)
	OBJDUMP = arm-none-eabi-objdump
	SIZEF = arm-none-eabi-size
	

else
	# as per the assignment instructions for the host system these flags must be used
	CC = gcc
	LD = ld
	LDFLAGS = -Wl,-Map=$(OUTPUTNAME).map
	CPPFLAGS = -MMD 
	PLATFORM = HOST
	SOURCES = $(HOST_SOURCES)
	INCLUDES = $(HOST_INCLUDES)
	OBJDUMP = objdump
	SIZEF = size
	# for RPI3
	CPU = armv7l 
	# for regular desktop environment
	#CPU = x86_64
	ARCH:=$(shell arch)
	CFLAGS = -Wall -Werror -g -O0 -std=c99 -D$(PLATFORM)
endif

OBJS:= $(SOURCES:.c=.o)
ASMS:= $(SOURCES:.c=.asm)
PPS:= $(SOURCES:.c=.i)
MAPS:= $(SOURCES:.c=.map)
DEPS:= $(SOURCES:.c=.d)

########################################
# Target: <file>.i                     #
# Must have: .c file                   #
# Output: .d + .i files                #
#                                      #
# -E end at preprocessing step         #
#                                      #
########################################

%.i : %.c
	@echo "creating preprocessor output and dependency files"
	$(CC) -E $(INCLUDES) $(CPPFLAGS) $< $(CFLAGS) -o $@

%.d : %.c
	$(CC) $(INCLUDES) -M $< $(CFLAGS) -o $@

########################################
# Target: <file>.asm                   #
# Must have: .c file                   #
# Output: .asm                         #
#                                      #
# -S stops before assembling           #
#                                      #
# objdump is the command-line tool for #
# displaying information about object  #
# files on unix-like OS'               #
########################################

%.asm : %.c
	@echo "creating assembly file"
	$(CC) $(INCLUDES) -S $< $(CFLAGS) -o $@

$(OUTPUTNAME).asm : $(OUTPUTNAME).out
	$(OBJDUMP) -d $(OUTPUTNAME).out >> $@

########################################
# Target: <file>.o                     #
# Must have: .c file                   #
# Output: .o file from .c file and     #
# dependency files                     #
########################################

%.o : %.c
	@echo "creating object files as output"
	$(CC) $(INCLUDES) -c $< $(CFLAGS) -o $@

########################################
# Target: compile-all                  #
# Must have: source                    #
# Output: compiles source but halts at #
# linking                              #
#                                      #
########################################

.PHONY: compile-all
compile-all: $(OBJS)
	@echo "compiling source files but not linking!"
	$(CC) $(OBJS) $(INCLUDES) -c $(CFLAGS) $(CPPFLAGS) -o $(OUTPUTNAME).o

########################################
# Target: build                        #
# Must have: main.out                  #
# Output: and executable and the size  #
# output                               #
#                                      #
########################################

.PHONY: build
build: $(OUTPUTNAME).out  $(OUTPUTNAME).asm

$(OUTPUTNAME).out: $(OBJS) $(DEPS)
	@echo "building..."
	$(CC) $(CFLAGS) $(INCLUDES) $(CPPFLAGS) $(LDFLAGS) -o $@ $(OBJS)
	$(SIZEF) $(OUTPUTNAME).out

# purge the output files so we can start again
.PHONY: clean
clean:
	@echo "purging..."
	rm -f *.o *.out *.s *.i *.d *.map *.asm
