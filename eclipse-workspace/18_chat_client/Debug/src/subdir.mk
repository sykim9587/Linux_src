################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/18_chat_client.c 

OBJS += \
./src/18_chat_client.o 

C_DEPS += \
./src/18_chat_client.d 


# Each subdirectory must supply rules for building sources it contributes
src/18_chat_client.o: ../src/18_chat_client.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -D_REENTRANT -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/18_chat_client.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


