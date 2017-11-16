#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>

void swap(int &a, int &b) { 
	int c = a;
	a = b;
	b = c;
}

void printMenu() // печать меню
{
	printf("\tМеню\n");
	printf("\t0 - Выйти\n");
	printf("\t1 - Заполнить массив чисел случайными значениями\n");
	printf("\t2 - Отсортировать массив\n");
	printf("\t3 - Развернуть массив\n");
	printf("\t4 - Посчитать среднее арифметическое элементов массива\n");	
}

void initArray(int *arr, int len) // заполнение массива случайными элементами
{
	for (int i = 0; i < len; ++i)
	{
		arr[i] = rand() % 90 + 10;
	}
}

void printArray(int* arr, int len) // печать массива
{
	for (int i = 0; i < len; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void bubbleSort(int* arr, int len) // сортировка пузырьком
{
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void makeChoice(int choice, int *arr, int len)//Пользователь выбирает что ему делать с массивом
{												//свичи соответствуют пунктам меню из printMenu
	switch (choice) {
	case 1:
		initArray(arr, len);
		printArray(arr, len);
		break;

	case 2:
		bubbleSort(arr, len);
		printArray(arr, len);
		break;

	case 3:
		for (int i = 0; i < len / 2; ++i)
		{
			swap(arr[i], arr[len - 1 - i]);
		}
		printArray(arr, len);
		break;

	case 4:
		int arithmeticАverage = 0; // поскольку элементы в массиве не более 100, то в это число влезает 2^31/100 = 21474836 сложений элементов массива.
		for (int i = 0; i < len; ++i)
		{
			arithmeticАverage += arr[i];
		}
		arithmeticАverage /= len;
		printf("Среднее арифметическое = %d\n", arithmeticАverage);
		break;
	}
}

int main(){
	setlocale(LC_ALL, "Russian");
	srand(time(nullptr));

	printf("Программа работает с массивом. Введите длинну массива\n");
	int n = 0;
	scanf("%d", &n);
	int *arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		arr[i] = 0;
	}
	printArray(arr, n);

	int choice = 0;
	do {
		printMenu();
		printf("Ваш выбор: ");
		scanf("%d", &choice);
		makeChoice(choice, arr, n);
	} while (choice != 0);

	delete[] arr;
	system("PAUSE");
	return 0;
}