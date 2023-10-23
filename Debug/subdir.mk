################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Funciones.c \
../HoppityParaCambios.c 

C_DEPS += \
./Funciones.d \
./HoppityParaCambios.d 

OBJS += \
./Funciones.o \
./HoppityParaCambios.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./Funciones.d ./Funciones.o ./HoppityParaCambios.d ./HoppityParaCambios.o

.PHONY: clean--2e-

