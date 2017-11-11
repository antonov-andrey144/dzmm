#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>

int sign(int n)
{
	return n > 0 ? 1 : n < 0 ? -1 : 0;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int dividend = 0;
	int divider = 0;
	printf("������� �������\n");
	scanf("%d", &dividend);
	printf("������� ��������\n");
	scanf("%d", &divider);
	while (divider == 0)
	{
		printf("�������� �� ����� ���� ����� ����, ������� ���-�� ������.\n");
		scanf("%d", &divider);
	}

	int quotient = 0;
	int coef = sign(dividend) * sign(divider);
	while (abs(dividend - divider * quotient) >= abs(divider) || (dividend - divider * quotient < 0))
	{
		quotient += coef;
	}

	printf("�������� ������� = %d\n", quotient);

	system("PAUSE");
	return 0;
}