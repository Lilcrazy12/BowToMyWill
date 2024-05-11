#pragma once

#include <cstdint>
#include <vector>
#include <string>

typedef enum {
    PUSH,
    POP,

    CALL,

    MOV,

    JMP,
    JGE,
    JG,
    JLE,
    JL,
    
    ADD,
    SUB,
    MUL,
    DIV
} Instruction;

typedef struct {
    string name;
    Label label;
} Label;

class Stack {
public:
    Stack();

    void push(int64_t num);
    int64_t pop();

private:
    int64_t initial_size = 4096;
    std::vector<int64_t> stk;

    std::vector<Label> labelTable;

    int64_t add(int64_t oprand1, int64_t oprand2);
    int64_t sub(int64_t oprand1, int64_t oprand2);
    int64_t mul(int64_t oprand1, int64_t oprand2);
    int64_t div(int64_t oprand1, int64_t oprand2);
}