#include "worker_dump.h"


void WorkerDump::process(WorkData &in, const std::string &args) {
    std::ofstream output_file;
    output_file.open(args);

    if (!in.getFilled())
        throw WorkerException("Error, bad for dump (got empty list)");

    if (!output_file)
        throw WorkerException("Error, can't create file" + args + " for dump");

    for (auto & i: in.getData())
        output_file << i << "\n";

    output_file.close();
}