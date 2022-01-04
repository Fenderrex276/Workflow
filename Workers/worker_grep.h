#ifndef TASK_2_WORKER_GREP_H
#define TASK_2_WORKER_GREP_H

#include "worker.h"
#include <iostream>


class WorkerGrep: public Worker {
    void process(WorkData &in, const std::string &args) override;
};


#endif //TASK_2_WORKER_GREP_H
