#ifndef TASK_2_EXCEPTION_H
#define TASK_2_EXCEPTION_H

#include <exception>
#include <string>

class Exception: public std::exception {
protected:
    std::string message_error;
public:
    virtual const std::string& what() = 0;
};


#endif //TASK_2_EXCEPTION_H
