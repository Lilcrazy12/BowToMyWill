#include "function.hpp"


class FunctionFrame : public Frame {
private:
    std::shared_ptr<EvaluateFrame> evaluate_frame;
    std::shared_ptr<ReturningFrame> returning_frame;

public:
    FunctionFrame(int instruction, void* return_address) {
        evaluate_frame = std::make_shared<EvaluateFrame>(instruction);
        returning_frame = std::make_shared<ReturningFrame>(return_address);
    }

    void printInfo() const override {
        std::cout << "Function frame:" << std::endl;
        evaluate_frame->printInfo();
        returning_frame->printInfo();
    }
};

class ReturningFrame : public Frame {
public:
    void* return_address;

    ReturningFrame(void* addr) : return_address(addr) {}

    void printInfo() const override {
        std::cout << "Returning frame address: " << return_address << std::endl;
    }
};
