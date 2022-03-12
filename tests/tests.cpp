#include <gtest/gtest.h>
#include "../configreader.h"
#include "../WorkExecutor/work_executor.h"


TEST(FirstTest, CorrectWorkflow) {

    ConfigReader reader(R"(..\tests\FirstTest\workflow.txt)");
    reader.parseConfigFile();
    auto config = reader.getConfig();
    auto order = reader.getOrder();
    WorkExecutor::execute(config, order);


    std::ifstream t(R"(..\tests\FirstTest\out_file.txt)");
    std::string out_file((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
    std::ifstream s(R"(..\tests\FirstTest\answer.txt)");
    std::string answer_file((std::istreambuf_iterator<char>(s)), std::istreambuf_iterator<char>());

    ASSERT_EQ(out_file, answer_file);
}

TEST(SecondTest, CorrectWorkflow2) {

    ConfigReader reader(R"(..\tests\SecondTest\workflow.txt)");
    reader.parseConfigFile();
    auto config = reader.getConfig();
    auto order = reader.getOrder();
    WorkExecutor::execute(config, order);


    std::ifstream t(R"(..\tests\SecondTest\out_file.txt)");
    std::string out_file((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
    std::ifstream s(R"(..\tests\SecondTest\answer.txt)");
    std::string answer_file((std::istreambuf_iterator<char>(s)), std::istreambuf_iterator<char>());

    ASSERT_EQ(out_file, answer_file);

}

TEST(ThirdTest, Incorrectworkflow) {

    std::string message = "Error, incorrect order, can't replace (got empty list)";
    try {
        ConfigReader reader(R"(..\tests\ThirdTest\workflow.txt)");
        reader.parseConfigFile();
        auto config = reader.getConfig();
        auto order = reader.getOrder();
        WorkExecutor::execute(config, order);
    }
    catch (OrderException &error) {
        ASSERT_EQ(error.what(), message);

    }
    catch (ExecutorException &error) {
        error.what();
    }

}

TEST(FourthTest, Incorrectworkflow2) {

    std::string message = "Error, unknown type of block replace12";
    try {
        ConfigReader reader(R"(..\tests\FourthTest\workflow.txt)");
        reader.parseConfigFile();
        auto config = reader.getConfig();
        auto order = reader.getOrder();
        WorkExecutor::execute(config, order);
    }
    catch (WorkerException &error) {
        error.what();
    }
    catch (ExecutorException &error) {
        ASSERT_EQ(error.what(), message);
    }

}

TEST(FifthTest, Incorrectworkflow2) {

    std::string message = "Error, incorrect order of blocks, couldn't sort this text (got empty list) ";
    try {
        ConfigReader reader(R"(..\tests\FifthTest\workflow.txt)");
        reader.parseConfigFile();
        auto config = reader.getConfig();
        auto order = reader.getOrder();
        WorkExecutor::execute(config, order);
    }
    catch (OrderException &error) {
        ASSERT_EQ(error.what(), message);
    }
    catch (ExecutorException &error) {
        error.what();
    }
}

TEST(SixthTest, Incorrectworkflow2) {

    std::string message = "Error, 0 arguments were expected, but here is something argument dasdasdasdasd" ;
    try {
        ConfigReader reader(R"(..\tests\FourthTest\workflow.txt)");
        reader.parseConfigFile();
        auto config = reader.getConfig();
        auto order = reader.getOrder();
        WorkExecutor::execute(config, order);
    }
    catch (WorkerException &error) {
        ASSERT_EQ(error.what(), message);
    }
    catch (ExecutorException &error) {
        error.what();
    }

}
