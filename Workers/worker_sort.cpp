#include "worker_sort.h"


void WorkerSort::process(WorkData &in, const std::string &args) {

    if (!in.getFilled())
        throw WorkerException("Error, couldn't sort this text (got empty list) " + args);

    std::vector<std::string> tmp = in.getData();
    std::sort(tmp.begin(), tmp.end());
    in.setData(tmp);

}
