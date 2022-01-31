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

HOST_SOURCES = main.c memory.c course1.c stats.c

MSP432_SOURCES = main.c \
		 memory.c \
		 course1.c \
		 stats.c \
		 startup_msp432p401r_gcc.c \
		 system_msp432p401r.c \
		 interrupts_msp432p401r_gcc.c

HOST_INCLUDES = -I../include/common

MSP432_INCLUDES = -I../include/common \
		  -I../include/msp432 \
		  -I../include/CMSIS