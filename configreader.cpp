#include "configreader.h"


ConfigReader::ConfigReader() {
    file.open("workflow.txt");
}
ConfigReader::~ConfigReader() {
    file.close();
}

void ConfigReader::parseConfigFile() {
    std::string line;
    bool flag = false;

    while (!file.eof()) {

        std::getline(file, line);

        if (line == "desc")
            continue;
        if (line == "csed") {
            flag = true;
            continue;
        }
        if (!flag) {
            parseBlockTask(line);
        } else {
            parseOrder(line);
            break;
        }
    }
}

void ConfigReader::parseBlockTask(std::string &line) {

    std::regex regex_sentence(R"(([\d]+)[ ]*=[ ]*([\w]+)[ ]*([\w .]*))");
    std::string number, type_block, args;

    auto sentence_begin = std::sregex_iterator(line.begin(), line.end(), regex_sentence);
    std::smatch match = *sentence_begin;

    if (match.begin() + 1 < match.end())
        number = *(match.begin() + 1);
    if (match.begin() + 2 < match.end())
        type_block = *(match.begin() + 2);
    if (match.begin() + 3 < match.end())
        args = *(match.begin() + 3);

    config[std::stoi(number)] = {type_block, args};
}

void ConfigReader::parseOrder(std::string &line) {

    std::string arrow = " -> ";
    size_t start = 0;
    size_t end = line.find(arrow);
    int number;

    while(end != std::string::npos) {
        number = std::stoi(line.substr(start, end - start));
        order.push_back(number);
        start = end + arrow.length();
        end = line.find(arrow, start);
    }

    number = std::stoi(line.substr(start, end - start));
    order.push_back(number);
}

std::vector <int> ConfigReader::getOrder() {
    return order;
}

std::map <int, std::pair<std::string, std::string>> ConfigReader::getConfig() {
    return config;

}