#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

enum class Status
{
	start,
	readNextSymbol,
	fail
};

bool isRight(char arr)
{
	return(isalpha(arr) || isdigit(arr) || arr == '_');
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	char str[200];
	printf("Введите строку:\n");
	scanf("%s", str);

	int i = 0;
	Status state = Status::start;
	while (str[i] != '\0')
	{
		switch (state)
		{
		case Status::start:
			if (isalpha(str[i]))
			{
				state = Status::readNextSymbol;
				++i;
			}
			else
			{
				state = Status::fail;
			}
			break;

		case Status::readNextSymbol:
		{
			if (!isRight(str[i]))
			{
				state = Status::fail;
				break;
			}
			else
			{
				state = Status::readNextSymbol;
				++i;
			}
			break;
		}

		default:
		{
			state = Status::fail;
			break;
		}
		}
		if (state == Status::fail)
		{
			break;
		}
	}

	if (state != Status::readNextSymbol)
	{
		printf("Неправильная строка\n");
	}
	else
	{
		printf("Правильная строка\n");
	}

	int pause = 0;
	scanf("%d", pause);
	return 0;
}