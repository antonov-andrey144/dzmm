#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

bool isSimple(int n)
{
	for (int i = 2; i < n / 2 + 1; ++i)
		if (n%i == 0)
			return false;
	return true;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	printf("Введите натуральное число, до которого будут выводиться все простые числа\n");
	int n = 0;
	scanf("%d", &n);

	for (int i = 2; i <= n; ++i)
		if (isSimple(i))
			printf("%d ", i);
	printf("\n");

	system("PAUSE");
	return 0;
}