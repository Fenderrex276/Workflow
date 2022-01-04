#ifndef TASK_2_WORKER_WRITEFILE_H
#define TASK_2_WORKER_WRITEFILE_H
#include "worker.h"
#include <fstream>
#include <iostream>


class WorkerWriteFile: public Worker {
    void process(WorkData &in, const std::string &args) override;
};


#endif //TASK_2_WORKER_WRITEFILE_H
