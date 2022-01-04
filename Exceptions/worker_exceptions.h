#ifndef TASK_2_WORKER_EXCEPTIONS_H
#define TASK_2_WORKER_EXCEPTIONS_H

#include "exception.h"

class WorkerException: public Exception {
public:
    explicit WorkerException(const std::string& message);
    const std::string& what() override;

};


#endif //TASK_2_WORKER_EXCEPTIONS_H
