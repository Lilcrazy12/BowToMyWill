#pragma once

#include <iostream>

class Runtime {
public:
    void start();
    void stop();

    int add(int a, int b);
    int sub(int a, int b);
    int mul(int a, int b);
    int div(int a, int b);
};
