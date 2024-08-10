// include/hello.h
#ifndef HELLO_H
#define HELLO_H

#include <string>

class Hello {
public:
    Hello(const std::string& name);
    void sayHello() const;

private:
    std::string name_;
};

#endif // HELLO_H
