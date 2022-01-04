#include "executor_exceptions.h"

const std::string & ExecutorException::what() {
    return message_error;
}

ExecutorException::ExecutorException(const std::string &message) {
    message_error = message;
}

