################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := /bin/bash
RM := rm -rf
CC := avr-gcc -std=gnu99 -Wall -mmcu=atmega128

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
lcd_2.c \
dag3_5.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
lcd_2.o \
dag3_5.o

OBJS_AS_ARGS +=  \
lcd_2.o \
dag3_5.o

C_DEPS +=  \
lcd_2.d \
dag3_5.d

C_DEPS_AS_ARGS +=  \
lcd_2.d \
dag3_5.d

OUTPUT_FILE_PATH +=dag3_5.elf

OUTPUT_FILE_PATH_AS_ARGS +=dag3_5.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= 

LIB_DEP+= 

# AVR32/GNU C Compiler









%.o: .%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 3.4.2
	avr-gcc  -funsigned-char -funsigned-bitfields -std=gnu99 -DDEBUG  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega128 -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<"
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
	@echo Invoking: AVR/GNU Linker : 3.4.2 lol
	avr-gcc -std=gnu99 -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS)  -Wl,-Map="dag3_5.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mrelax -mmcu=atmega128 
	@echo Finished building target: $@
	"avr-objcopy" -O ihex -R .eeprom -R .fuse -R .lock -R .signature  "dag3_5.elf" "dag3_5.hex"
	"avr-objcopy" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "dag3_5.elf" "dag3_5.eep" || exit 0
	"avr-objdump" -h -S "dag3_5.elf" > "dag3_5.lss"
	"avr-objcopy" -O srec -R .eeprom -R .fuse -R .lock -R .signature  "dag3_5.elf" "dag3_5.srec"
	"avr-size" "dag3_5.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "dag3_5.elf" "dag3_5.a" "dag3_5.hex" "dag3_5.lss" "dag3_5.eep" "dag3_5.map" "dag3_5.srec"
	