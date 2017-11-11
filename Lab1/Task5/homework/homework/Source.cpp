#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");

	printf("Введите значение x для вычисления формулы x^4 + x^3 + x^2 + x + 1\nx = ");
	int x = 0;
	scanf("%d", &x);
	int squareX = x * x;
	int expressionValue = (squareX + 1) * (squareX + x) + 1;
	printf("Значение формулы = %d\n", expressionValue);
	
	scanf("%d", &x);
	return 0;
}