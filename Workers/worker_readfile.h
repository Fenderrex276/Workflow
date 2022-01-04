#ifndef TASK_2_WORKER_READFILE_H
#define TASK_2_WORKER_READFILE_H
#include "worker.h"
#include <fstream>
#include <iostream>


class WorkerReadFile: public Worker {
    void process(WorkData &in, const std::string &args) override;
};

#endif //TASK_2_WORKER_READFILE_H
