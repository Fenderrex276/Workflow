#include "worker_replace.h"


void WorkerReplace::process(WorkData &in, const std::string &args) {

    if (!in.getFilled())
        throw WorkerException("Warning! can't replace (got empty list)");

    std::vector <std::string> tmp = in.getData();
    std::pair<std::string, std::string> parsed = parseArgs(args);
    std::string word1 = parsed.first, word2 = parsed.second;

    size_t pos = 0;

    for (auto & line: tmp) {
        while (line.find(word1, pos) != std::string::npos) {
            line.replace(line.find(word1, pos), word1.size(), word2);
            pos += word2.size();
        }
    }

    in.setData(tmp);
}

std::pair<std::string, std::string> WorkerReplace::parseArgs(const std::string& args) {
    std::stringstream word(args);
    std::string tmp;
    std::string word1, word2;

    if (word >> tmp)
        word1 = tmp;
    if (word >> tmp)
        word2 = tmp;

    if (word1.empty() || word2.empty())

        throw WorkerException("Error, invalid arguments for replace " + args);

    return {word1, word2};

}