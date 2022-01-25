#ifndef TASK_2_WORKER_REPLACE_H
#define TASK_2_WORKER_REPLACE_H

#include "worker.h"
#include <iostream>
#include <sstream>


class WorkerReplace: public Worker{
public:
    void process(WorkData &in, const std::string &args) override;
    // убрать из воркера
    static std::pair<std::string, std::string> parseArgs(const std::string& args);

};

#endif //TASK_2_WORKER_REPLACE_H
