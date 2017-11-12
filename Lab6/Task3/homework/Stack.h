#pragma once

const int nullvalue = -1;
typedef int Value;

struct Stack;

/**
�������� ������ �����

@return ��������� �� ����� ����
*/
Stack* createStack();

/**
�������� �����

@param stack ���� ��� ��������
*/
void deleteStack(Stack* stack);

/**
���������� �������� � ����

@param stack ���� ��� ����������
@param value �������� ��� ����������
*/
void push(Stack* stack, Value value);

/**
���������� �������� �� �����

@param stack ����
@return ������� ������� �����
*/
Value pop(Stack* stack);

/**
�������� ����� �� �������

@param stack ����
@return true - ���� � ����� ���� ���� �� ���� ������� false - ���� ���� ������
*/
bool isEmpty(Stack* stack);

/**
�������� ������� �� ������� ����� ��� ��� ��������

@param stack ����
*/
Value peek(Stack* stack);