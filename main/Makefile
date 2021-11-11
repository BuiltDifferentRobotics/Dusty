CC = g++

CFlags = -g -Wall

main: main.o Serial_IO/wiringSerial.o Serial_IO/wiringPi.o Serial_IO/softPwm.o Serial_IO/softTone.o
	$(CC) $(CFlags) -o main main.o Serial_IO/wiringSerial.o Serial_IO/wiringPi.o Serial_IO/softPwm.o Serial_IO/softTone.o

main.o: main.cpp Serial_IO/wiringSerial.h Serial_IO/wiringPi.h Serial_IO/softPwm.h Serial_IO/softTone.h
	$(CC) $(CFlags) -c main.cpp

Serial_IO/softPwm.o: Serial_IO/softPwm.h

Serial_IO/softTone.o: Serial_IO/softTone.h

Serial_IO/wiringSerial.o: Serial_IO/wiringSerial.h

Serial_IO/wiringPi.o: Serial_IO/wiringPi.h