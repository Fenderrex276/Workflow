#include "work_data.h"

std::vector<std::string> WorkData::getData() {
    return data;
}

bool WorkData::getFilled() const {
    return filled;
}

void WorkData::setData(std::vector<std::string> &new_data) {
    data = new_data;
}

void WorkData::setFilled(bool is_filled) {
    filled = is_filled;
}