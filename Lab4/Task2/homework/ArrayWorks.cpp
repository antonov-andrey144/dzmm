#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include "ArraysWork.h"
#include <iostream>
#include <time.h>

void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

int countElements() {
	FILE * pFile = fopen("arr.txt", "r");
	int len = 0;
	int p = 0;
	while (!feof(pFile)) {
		fscanf(pFile, "%d", &p);
		++len;
	}
	fclose(pFile);
	return len;
}

int* initArray(int len)
{
	int* result = new int[len];
	FILE * pFile = fopen("arr.txt", "r");
	for (int i = 0; i < len; ++i)
	{
		fscanf(pFile, "%d", &result[i]);
	}
	fclose(pFile);
	return result;
}

void qsort(int* arr, int startIndex, int endIndex)
{
	if (startIndex >= endIndex) {
		return;
	}
	int iteratorIndex = startIndex;
	int element = arr[startIndex];
	for (int i = startIndex; i <= endIndex; ++i)
	{
		if (arr[i] < element)
		{
			swap(arr[i], arr[iteratorIndex]);
			++iteratorIndex;
		}
	}
	if (iteratorIndex == startIndex)
	{
		++iteratorIndex;
	}
	qsort(arr, startIndex, iteratorIndex - 1);
	qsort(arr, iteratorIndex, endIndex);
}

void printArray(int* arr, int len)
{
	for (int i = 0; i < len; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int mostFrequentElement(int* arr, int len)
{
	int frequency = 0;
	int frequentElement = 0;
	int tempFrequency = 1;
	int tempFrequentElement = arr[0];
	for (int i = 1; i < len; ++i) {
		if (tempFrequentElement == arr[i]) {
			++tempFrequency;
		}
		else
		{
			if (tempFrequency > frequency)
			{
				frequentElement = tempFrequentElement;
				frequency = tempFrequency;
			}
			tempFrequency = 1;
			tempFrequentElement = arr[i];
		}
	}
	if (tempFrequency > frequency) {
		return tempFrequentElement;
	}
	else {
		return frequentElement;
	}
}