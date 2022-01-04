#ifndef TASK_2_WORKER_SORT_H
#define TASK_2_WORKER_SORT_H

#include "worker.h"
#include <algorithm>
#include <iostream>

class WorkerSort: public Worker{
    void process(WorkData &in, const std::string &args) override;


};


#endif //TASK_2_WORKER_SORT_H
