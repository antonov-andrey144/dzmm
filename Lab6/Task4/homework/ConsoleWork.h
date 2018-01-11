#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "List.h"
#include "ListMergeSort.h"

//инициализация переменных
List* startWork();

//выполнение алгоритма
void doWork(List* &list);

//освобождение памяти из под переменных
void endWork(List* &list);


