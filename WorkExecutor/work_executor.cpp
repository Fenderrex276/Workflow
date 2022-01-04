#include "work_executor.h"

void WorkExecutor::executeWork(std::map <int, std::pair<std::string, std::string>>& config, std::vector <int>& order) {

    std::string type, args;

    WorkData data;

    Worker *worker;

    for(auto i: order) {

        if(config.find(i) == config.end())
            throw ExecutorException("Error, can't call block" + std::to_string(i));

        type = config[i].first;
        args = config[i].second;

        if (type == "readfile")
            worker = new WorkerReadFile;
        else if (type == "writefile")
            worker = new WorkerWriteFile;
        else if (type == "grep")
            worker = new WorkerGrep;
        else if (type == "sort")
            worker = new WorkerSort;
        else if (type == "replace")
            worker = new WorkerReplace;
        else if (type == "dump")
            worker = new WorkerDump;
        else
            throw ExecutorException("Error, unknown type of block" + type);

        worker->process(data, args);

    }

}
