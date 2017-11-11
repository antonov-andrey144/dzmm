#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int pow(int a, int n)
{
	int result = 1;
	for (int i = 0; i < n; i++)
	{
		result *= a;
	}
	return result;
}

int powLog(int a, int n)
{
	if (n == 0) return 1;
	if (n == 1) return a;
	if (n == 2) return a * a;
	int semiPow = powLog(a, n / 2);
	return semiPow * semiPow * powLog(a, n % 2);
}

int main() {

	setlocale(LC_ALL, "Russian");

	int n = 0;
	int a = 0;
	int result = 0;
	printf("Введите число, которое будет возведено в степень\n");
	scanf("%d", &a);
	printf("Введите степень\n");
	scanf("%d", &n);
	result = powLog(a, n);

	printf("Рекурсивное вычисление : %d\n", result);
	result = pow(a, n);
	printf("Нерекурсивное вычисление: %d\n", result);
	system("PAUSE");
	return 0;
}