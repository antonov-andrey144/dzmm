#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

bool getBit(int num, int bit) {
	return num >> bit & 1;
}

bool* toBitArray(int num) {
	bool* res = new bool[32];
	for (int i = 0; i < 32; ++i)
	{
		res[i] = getBit(num, i);
	}
	return res;
}

int toInt(bool* bitNum)
{
	int res = 0;
	for (int i = 0; i < 32; ++i)
	{
		res += (bitNum[i] << i);
	}
	return res;
}

void printNum(bool* num)
{
	for (int i = 31; i >= 0; --i) {
		printf("%d", num[i]);
	}
	printf("\n");
}

bool* sumNumbers(bool* bitNum1, bool* bitNum2)
{
	bool* res = new bool[32];
	bool mem = 0;

	for (int i = 0; i < 32; ++i) {
		res[i] = mem ^ bitNum1[i] ^ bitNum2[i];
		mem = (mem & bitNum1[i]) | (mem & bitNum2[i]) | (bitNum2[i] & bitNum1[i]);
	}

	return res;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	printf("¬ведите первое число \n");
	int num1 = 0;
	scanf("%d", &num1);

	printf("¬ведите второе число \n");
	int num2 = 0;
	scanf("%d", &num2);

	bool* bitNum1 = toBitArray(num1);
	bool* bitNum2 = toBitArray(num2);
	bool* bitNum3 = sumNumbers(bitNum1, bitNum2);

	printNum(bitNum1);
	printNum(bitNum2);
	printNum(bitNum3);

	printf("%d\n", toInt(bitNum1));
	printf("%d\n", toInt(bitNum2));
	printf("%d\n", toInt(bitNum3));

	delete[] bitNum1;
	delete[] bitNum2;
	delete[] bitNum3;

	system("PAUSE");
	return 0;
}