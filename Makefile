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
dag5_7a.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
lcd_2.o \
dag5_7a.o

OBJS_AS_ARGS +=  \
lcd_2.o \
dag5_7a.o

C_DEPS +=  \
lcd_2.d \
dag5_7a.d

C_DEPS_AS_ARGS +=  \
lcd_2.d \
dag5_7a.d

OUTPUT_FILE_PATH +=dag5_7a.elf

OUTPUT_FILE_PATH_AS_ARGS +=dag5_7a.elf

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
	avr-gcc -std=gnu99 -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS)  -Wl,-Map="dag5_7a.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mrelax -mmcu=atmega128 
	@echo Finished building target: $@
	"avr-objcopy" -O ihex -R .eeprom -R .fuse -R .lock -R .signature  "dag5_7a.elf" "dag5_7a.hex"
	"avr-objcopy" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "dag5_7a.elf" "dag5_7a.eep" || exit 0
	"avr-objdump" -h -S "dag5_7a.elf" > "dag5_7a.lss"
	"avr-objcopy" -O srec -R .eeprom -R .fuse -R .lock -R .signature  "dag5_7a.elf" "dag5_7a.srec"
	"avr-size" "dag5_7a.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "dag5_7a.elf" "dag5_7a.a" "dag5_7a.hex" "dag5_7a.lss" "dag5_7a.eep" "dag5_7a.map" "dag5_7a.srec"
	