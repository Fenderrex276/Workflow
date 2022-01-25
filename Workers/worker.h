#ifndef TASK_2_WORKER_H
#define TASK_2_WORKER_H
#include "../WorkExecutor/work_data.h"
#include "../Exceptions/worker_exceptions.h"

// CR: добавить метод validate , которые проверяет достаточность параметров
class Worker {
public:
    virtual void process (WorkData& in, const std::string& args) = 0;
};

#endif //TASK_2_WORKER_H
