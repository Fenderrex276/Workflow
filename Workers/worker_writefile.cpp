#include "worker_writefile.h"

void WorkerWriteFile::process(WorkData &in, const std::string &args) {
    std::ofstream output_file;
    output_file.open(args);

    if (!in.getFilled())
        throw WorkerException("Error, invalid order of blocks for write file");

    if (!output_file)
        throw WorkerException("Error, can't open this file");

    for (auto & i: in.getData())
        output_file << i << "\n";

    output_file.close();
    in.setFilled(false);

}