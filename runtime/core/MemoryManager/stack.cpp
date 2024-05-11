#include "stack.h"

Stack::Stack() {
    stk.resize(initial_size);
}

void Stack::push(int64_t num) {
    stk.push_back(num);
}

int64_t Stack::pop() {
    if (stk.empty()) throw std::out_of_range("Stack is empty");
    int64_t top = stk.back();
    stk.pop_back();
    return top;
}


int64_t Stack::add(int64_t oprand1, int64_t oprand2) {
    return a + b;
}

int64_t Stack::sub(int64_t oprand1, int64_t oprand2) {
    return a - b;
}

int64_t Stack::mul(int64_t oprand1, int64_t oprand2) {
    return a * b;
}

int64_t Stack::div(int64_t oprand1, int64_t oprand2) {
    if (b == 0) {
        return 0;
    }
    return a / b;
}