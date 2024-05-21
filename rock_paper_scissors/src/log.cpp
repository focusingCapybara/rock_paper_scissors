// The cpp file of the header file is used to define things

#include "../include/log.h"
#include <iostream>

void Log(std::string message) {
	std::cout << message;
}

void Log(std::string message, std::string secondMessage) {
	std::cout << message << secondMessage;
}

void Log(std::string message, std::string secondMessage, std::string thirdMessage) {
	std::cout << message << secondMessage << thirdMessage;
}

void Log(std::string message, int secondMessage) {
	std::cout << message << secondMessage;
}