################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Operations/Push-Pop-MinValue_In_Stack_O1.cpp 

OBJS += \
./Operations/Push-Pop-MinValue_In_Stack_O1.o 

CPP_DEPS += \
./Operations/Push-Pop-MinValue_In_Stack_O1.d 


# Each subdirectory must supply rules for building sources it contributes
Operations/%.o: ../Operations/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


