#include "math.hpp"

int Runtime::add(int a, int b) {
    return a + b;
}

int Runtime::sub(int a, int b) {
    return a - b;
}

int Runtime::mul(int a, int b) {
    return a * b;
}

int Runtime::div(int a, int b) {
    if (b == 0) {
        return 0;
    }
    return a / b;
}
