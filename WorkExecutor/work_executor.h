#ifndef TASK_2_WORK_EXECUTOR_H
#define TASK_2_WORK_EXECUTOR_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include "../Exceptions/executor_exceptions.h"

#include "work_data.h"
#include "../Workers/worker.h"
#include "../Workers/worker_dump.h"
#include "../Workers/worker_grep.h"
#include "../Workers/worker_readfile.h"
#include "../Workers/worker_replace.h"
#include "../Workers/worker_writefile.h"
#include "../Workers/worker_sort.h"


class WorkExecutor {
public:
    static void execute(std::map <int, std::pair<std::string, std::string>>& config, std::vector <int>& order);
};

#endif //TASK_2_WORK_EXECUTOR_H
