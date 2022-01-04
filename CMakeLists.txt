cmake_minimum_required(VERSION 3.17)
project(task_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(task_2 main.cpp configreader.cpp configreader.h Workers/worker.h Workers/worker_dump.cpp
        Workers/worker_dump.h Workers/worker_grep.cpp Workers/worker_grep.h Workers/worker_readfile.cpp
        Workers/worker_readfile.h Workers/worker_replace.cpp Workers/worker_replace.h Workers/worker_sort.cpp
        Workers/worker_sort.h Workers/worker_writefile.cpp Workers/worker_writefile.h
        WorkExecutor/work_data.h WorkExecutor/work_data.cpp WorkExecutor/work_executor.cpp WorkExecutor/work_executor.h
        Exceptions/exception.h Exceptions/executor_exceptions.cpp Exceptions/executor_exceptions.h Exceptions/worker_exceptions.cpp
        Exceptions/worker_exceptions.h)
