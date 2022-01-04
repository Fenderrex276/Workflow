#include "worker_exceptions.h"

WorkerException::WorkerException(const std::string &message) {
    message_error = message;
}

const std::string & WorkerException::what() {
    return message_error;
}