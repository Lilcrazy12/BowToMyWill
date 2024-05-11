#include "runtime.hpp"

Runtime::Runtime() {
    stack = new Stack();
}

void Runtime::start() {
    std::cout << "Runtime started." << std::endl;
}

void Runtime::stop() {
    std::cout << "Runtime stopped." << std::endl;
}