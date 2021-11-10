CC = gcc

CFlags = -g -Wall

main: main.o Serial_IO/wiringSerial.o Serial_IO/wiringPi.o
	$(CC) $(CFlags) -o main main.o Serial_IO/wiringSerial.o Serial_IO/wiringPi.o

main.o: main.cpp Serial_IO/wiringSerial.h Serial_IO/wiringPi.h
	$(CC) $(CFlags) -c main.cpp

Serial_IO/wiringSerial.o: Serial_IO/wiringSerial.h

Serial_IO/wiringPi.o: Serial_IO/wiringPi.h