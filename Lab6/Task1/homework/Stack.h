#pragma once

const int nullvalue = -1;
typedef int Value;

struct Stack;

/**
создание нового стека

@return указатель на новый стек
*/
Stack* createStack();

/**
удаление стека

@param stack стек для удаления
*/
void deleteStack(Stack* stack);

/**
добавление элемента в стек

@param stack стек для добавления
@param value значение для добавления
*/
void push(Stack* stack, Value value);

/**
извлечение элемента из стека

@param stack стек
@return верхний элемент стека
*/
Value pop(Stack* stack);

/**
проверка стека на пустоту

@param stack стек
@return true - если в стеке есть хотя бы один элемент false - если стек пустой
*/
bool isEmpty(Stack* stack);

/**
получить элемент на вершине стека без его удаления

@param stack стек
*/
Value peek(Stack* stack);