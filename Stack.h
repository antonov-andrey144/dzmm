#pragma once 

const  int nullvalue = -1;
typedef int Value;

struct Stack;

Stack* createStack();
void deleteStack(Stack* stack);
void push(Stack* stack, Value value);
Value pop(Stack* stack);
bool isEmpty(Stack* stack);