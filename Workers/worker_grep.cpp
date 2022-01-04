#include "worker_grep.h"

void WorkerGrep::process(WorkData &in, const std::string &args) {
    std::vector <std::string> tmp;

    if (!in.getFilled())
        throw WorkerException("Error, got empty list for grep");

    for (auto & i: in.getData()) {
        if (i.find(args) != std::string::npos)
            tmp.push_back(i);
    }

    in.setData(tmp);
}

