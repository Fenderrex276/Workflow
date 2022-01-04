#ifndef TASK_2_WORKER_DUMP_H
#define TASK_2_WORKER_DUMP_H

#include "worker.h"
#include <fstream>
#include <iostream>

class WorkerDump: public Worker {
public:
    void process(WorkData &in, const std::string &args) override;

};


#endif //TASK_2_WORKER_DUMP_H
