################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := /bin/bash
RM := rm -rf
CC := avr-gcc

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
lcd.c \
dag3_1.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
lcd.o \
dag3_1.o

OBJS_AS_ARGS +=  \
lcd.o \
dag3_1.o

C_DEPS +=  \
lcd.d \
dag3_1.d

C_DEPS_AS_ARGS +=  \
lcd.d \
dag3_1.d

OUTPUT_FILE_PATH +=dag3_1.elf

OUTPUT_FILE_PATH_AS_ARGS +=dag3_1.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

# AVR32/GNU C Compiler









%.o: .%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 3.4.2
	avr-gcc  -funsigned-char -funsigned-bitfields -DDEBUG  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega128 -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<"
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 3.4.2
	avr-gcc -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="dag3_1.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mrelax -mmcu=atmega128 
	@echo Finished building target: $@
	"avr-objcopy" -O ihex -R .eeprom -R .fuse -R .lock -R .signature  "dag3_1.elf" "dag3_1.hex"
	"avr-objcopy" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "dag3_1.elf" "dag3_1.eep" || exit 0
	"avr-objdump" -h -S "dag3_1.elf" > "dag3_1.lss"
	"avr-objcopy" -O srec -R .eeprom -R .fuse -R .lock -R .signature  "dag3_1.elf" "dag3_1.srec"
	"avr-size" "dag3_1.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "dag3_1.elf" "dag3_1.a" "dag3_1.hex" "dag3_1.lss" "dag3_1.eep" "dag3_1.map" "dag3_1.srec"
	