#include "main.hpp"

int main() {
    Runtime Runtime;
    Runtime.start();

    int a = 10;
    int b = 5;

    std::cout << "Addition: " << Runtime.add(a, b) << std::endl;
    std::cout << "Subtraction: " << Runtime.sub(a, b) << std::endl;
    std::cout << "Multiplication: " << Runtime.mul(a, b) << std::endl;
    std::cout << "Division: " << Runtime.div(a, b) << std::endl;

    Runtime.stop();
    return 0;
}
