################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Test1.cpp \
../Test10.cpp \
../Test11.cpp \
../Test12.cpp \
../Test13.cpp \
../Test14.cpp \
../Test15.cpp \
../Test2.cpp \
../Test3.cpp \
../Test4.cpp \
../Test5.cpp \
../Test6.cpp \
../Test7.cpp \
../Test8.cpp \
../Test9.cpp 

OBJS += \
./Test1.o \
./Test10.o \
./Test11.o \
./Test12.o \
./Test13.o \
./Test14.o \
./Test15.o \
./Test2.o \
./Test3.o \
./Test4.o \
./Test5.o \
./Test6.o \
./Test7.o \
./Test8.o \
./Test9.o 

CPP_DEPS += \
./Test1.d \
./Test10.d \
./Test11.d \
./Test12.d \
./Test13.d \
./Test14.d \
./Test15.d \
./Test2.d \
./Test3.d \
./Test4.d \
./Test5.d \
./Test6.d \
./Test7.d \
./Test8.d \
./Test9.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


