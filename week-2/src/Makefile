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
# Makefiles have a lot of power, but have not aged well as a development tool
# The coures material does a great job of providing an overview but it is easy
# to get lost in the weeds.  
#
# A useful reference is the course material slides associated discussion 
# and https://devhints.io/makefile
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <file>.i ---> this rule generates the preprocessor output + the dependency
#      	             file (.i and .d respectively) for the input .c file
#      <file>.asm ---> creates the assembly file and stops there
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

# Platform Overrides
PLATFORM = 

# Architectures Specific Flags
LINKER_FILE = 
CPU = 
ARCH = 
SPECS = 

# Compiler Flags and Defines
CC = 
LD = 
LDFLAGS = 
CFLAGS = 
CPPFLAGs = 

