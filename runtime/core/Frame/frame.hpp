#pragma once

#include <iostream>
#include <memory>
#include <vector>

class Frame {
public:
    virtual void printInfo() const = 0;
};

class EvaluateFrame : public Frame {
public:
    int instruction;

    EvaluateFrame(int instr) : instruction(instr) {}

    void printInfo() const override {
        std::cout << "Evaluate frame instruction: " << instruction << std::endl;
    }
};

class ReturningFrame : public Frame {
public:
    void *return_address;

    ReturningFrame(void* addr) : return_address(addr) {}

    void printInfo() const override {
        std::cout << "Returning frame address: " << return_address << std::endl;
    }
};