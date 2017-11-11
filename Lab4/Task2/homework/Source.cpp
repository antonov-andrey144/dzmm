#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include "ArraysWork.h"

int main()
{
	srand(time(nullptr));

	int len = countElements();
	

	int* arr = initArray(len);
	qsort(arr, 0, len - 1);
	printf("\n Sorted array\n");
	printArray(arr, len);

	printf("Most Frequent Element is %d\n", mostFrequentElement(arr, len));

	delete[] arr;
	system("PAUSE");
	return 0;
}