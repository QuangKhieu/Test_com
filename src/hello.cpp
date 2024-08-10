// src/hello.cpp
#include "hello.h"
#include <iostream>

Hello::Hello(const std::string& name) : name_(name) {}

void Hello::sayHello() const {
    std::cout << "Hello, " << name_ << "!" << std::endl;
}
