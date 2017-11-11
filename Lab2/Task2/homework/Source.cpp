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
	printf("������� �����, ������� ����� ��������� � �������\n");
	scanf("%d", &a);
	printf("������� �������\n");
	scanf("%d", &n);
	result = powLog(a, n);

	printf("����������� ���������� : %d\n", result);
	result = pow(a, n);
	printf("������������� ����������: %d\n", result);
	system("PAUSE");
	return 0;
}