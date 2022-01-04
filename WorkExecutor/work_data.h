#ifndef TASK_2_WORK_DATA_H
#define TASK_2_WORK_DATA_H
#include <vector>
#include <string>

class WorkData {
private:
    std::vector <std::string> data;
    bool filled = false;
public:
    void setData(std::vector <std::string> &new_data);
    void setFilled(bool is_filled);
    std::vector <std::string> getData();
    bool getFilled() const;

};


#endif //TASK_2_WORK_DATA_H
