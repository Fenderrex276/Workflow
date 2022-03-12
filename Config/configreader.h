#ifndef TASK_2_CONFIGREADER_H
#define TASK_2_CONFIGREADER_H
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <regex>


class ConfigReader {

private:

    std::ifstream file;
    std::map <int, std::pair<std::string, std::string>> config;
    std::vector <int> order;
    void parseBlockTask(std::string &line);
    void parseOrder(std::string &line);

public:
    explicit ConfigReader(std::string file_name);
    ~ConfigReader();
    void parseConfigFile();
    std::vector <int> getOrder();
    std::map <int, std::pair<std::string, std::string>> getConfig();

};


#endif //TASK_2_CONFIGREADER_H
