#pragma once

#include <iostream>

#include "stack.hpp"

class Runtime {
public:
    Runtime();

    void start();
    void stop();

    void exp

private:
    Stack *stack;
    int64_t _rbp;
    int64_t _rsp;
};
