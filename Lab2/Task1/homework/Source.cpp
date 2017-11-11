#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int fibRec(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	if (n > 2)
	{
		return fibRec(n - 1) + fibRec(n - 2);
	}
	return 0;
}

int fibNonRec(int n)
{
	int first = 1;
	int second = 1;
	int next = 1;
	for (int i = 2; i < n; ++i)
	{
		next = first + second;
		first = second;
		second = next;
	}
	return second;
}

int main(){
	setlocale(LC_ALL, "Russian");
	int n = 0;
	printf("Введите номер числа фибоначчи\n");
	scanf("%d", &n);
	int nonRecResult = 0;
	nonRecResult  = fibNonRec(n);
	printf("Нерекурсивное вычисление: %d\n", nonRecResult);
	
	int recResult = 0;
	recResult = fibRec(n);
	printf("Рекурсивное вычисление: %d\n", recResult);
	
	system("PAUSE");
	return 0;
}