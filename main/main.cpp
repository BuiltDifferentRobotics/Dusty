#include "Serial_IO/wiringSerial.h"
#include "Serial_IO/wiringPi.h"
#include "nlohmann/json.hpp"
#include<unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sstream>
#include <iostream>

using json = nlohmann::json;

struct Data {
    int left;
    int right;
    Data(int l, int r) : left(l), right(r) {}
};

void to_json(json& j, const Data& p) {
    j = json{{"left", p.left}, {"right", p.right}};
}

int main() {
    
    std::string serialDev = "/dev/ttyACM0";
    int baud = 19200;
    int fd;

    json j;
    Data d(-3, 17);
    to_json(j, d);
    std::stringstream message;
    message << j;


    if ((fd = serialOpen(serialDev.c_str(), baud)) < 0) {
        fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
        return 1 ;
    }
/*
    if (wiringPiSetup() == -1) {
        fprintf (stdout, "Unable to start wiringPi: %s\n", strerror (errno)) ;
        return 1 ;
    }
*/
    serialFlush(fd);

    while(true) {
        serialPuts(fd, message.str().c_str());
        std::cout << message.str() << std::endl;
        usleep(10000);
    }
    
    return 0;
}