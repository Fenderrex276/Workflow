#include "worker_readfile.h"

void WorkerReadFile::process(WorkData &in, const std::string &args) {
    std::vector <std::string> data;
    std::string tmp;

    if (in.getFilled())
        throw WorkerException("Error, invalid order of blocks for read file");

    std::fstream input_file;
    input_file.open(args);

    if (!input_file)
        throw WorkerException("Error, can't open file, bad argument " + args);

    while (!input_file.eof()) {
        std::getline(input_file, tmp);
        data.push_back(tmp);
    }

    in.setFilled(true);
    in.setData(data);
}