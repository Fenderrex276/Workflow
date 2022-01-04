#include <iostream>
#include "configreader.h"
#include "WorkExecutor/work_executor.h"
using namespace std;

int main() {
    ConfigReader file;
    file.parseConfigFile();
    auto config = file.getConfig();
    auto order = file.getOrder();

    WorkExecutor::executeWork(config, order);

}