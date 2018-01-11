#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

enum class Status
{
	start,
	intPart,
	dot,
	fractPart,
	exp,
	sign,
	pow,
	success,
	fail
};

bool isSign(char chr)
{
	return chr == '+' || chr == '-';
}

bool isEndOfLine(char chr)
{
	return chr == '\0';
}


int main()
{
	Status status = Status::start;
	char str[200];
	printf("digit+ (. digit+)? (E(+ | -)? digit+)?\n");
	scanf("%s", str);

	int i = 0;
	while (status != Status::fail && status != Status::success)
	{
		switch (status)
		{
		case Status::start: //начало
		{
			if (!isdigit(str[i]))
			{
				status = Status::fail;
			}
			else
			{
				status = Status::intPart;
			}
		}
		break;
		case Status::intPart: //до запятой
		{
			if (!isdigit(str[i]))
			{
				switch (str[i])
				{
				case '.':
					status = Status::dot;
					break;
				case 'e':
				case 'E':
					status = Status::exp;
					break;
				case '\0':
					status = Status::success;
					break;
				default:
					status = Status::fail;
					break;
				}
			}
		}
		break;
		case Status::dot: //символ после запятой
		{
			if (isdigit(str[i]))
			{
				status = Status::fractPart;
			}
			else
			{
				status = Status::fail;
			}
		}
		break;
		case Status::fractPart: //после запятой
		{
			if (!isdigit(str[i]))
			{
				switch (str[i])
				{
				case 'e':
				case 'E':
					status = Status::exp;
					break;
				case '\0':
					status = Status::success;
					break;
				default:
					status = Status::fail;
					break;
				}
			}
		}
		break;
		case Status::exp: //знак после E
		{
			if (isSign(str[i]) || isdigit(str[i]))
			{
				status = isSign(str[i]) ? Status::sign : Status::pow;
			}
			else
			{
				status = Status::fail;
			}
		}
		break;
		case Status::sign:
		{
			if (isdigit(str[i]))
			{
				status = Status::pow;
			}
			else
			{
				status = Status::fail;
			}
		}
		break;
		case Status::pow: //степень
		{
			if (!isdigit(str[i]))
			{
				if (isEndOfLine(str[i]))
				{
					status = Status::success;
				}
				else
				{
					status = Status::fail;
				}
			}
		}
		break;
		}

		++i;
	}

	if (status == Status::success)
	{
		printf("Correct\n");
	}
	else if (status == Status::fail)
	{
		printf("Not correct\n");
	}

	int pause = 0;
	scanf("%d", &pause);
	return 0;
}