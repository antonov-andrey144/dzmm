#pragma once

typedef int Value;

struct Set;

/**
�������� ������ ���������
@return ��������� �� ����� ���������
*/
Set* createSet();

/**
�������� ���������
@param set ��������� ��� ��������
*/
void deleteSet(Set* set);

/**
���������� �������� �� ���������
@param set ��������� ��� ����������
@param value ������� ��� ����������
*/
void addToSet(Set* set, Value value);

/**
�������� �������� �� ���������
@param set ���������, �� �������� ��������� �������
@param value �������, ������� ���������
*/
void removeFromSet(Set* set, Value value);

/**
������ ��������� � ������� ����������� ���������
����� � �������
@param set ��������� ��� ������
*/
void printSetAscend(Set* set);

/**
������ ��������� � ������� �������� ���������
����� � �������
@param set ��������� ��� ������
*/
void printSetDescend(Set* set);

/**
������ ��������� � ������� ����������� ���������
����� � ���� ������
@param set ��������� ��� ������
*/
void printLPR(Set* set);

/**
������ ��������� � ������� �������� ���������
����� � ���� ������
@param set ��������� ��� ������
*/
void printRPL(Set* set);

/**
�������� ������� �������� �� ���������
@param set ��������� ��� ������ ��������
@param value ������� ��� ������
*/
bool containsInSet(Set* set, Value value);