#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

enum class Status
{
	start,
	state1,
	state2,
	state3,
	state4,
	state5,
	success,
	fail
};

bool isDigit(char chr)
{
	return (chr >= '0' && chr <= '9');
}

bool isExp(char chr)
{
	return (chr == 'e' || chr == 'E');
}

bool isSign(char chr)
{
	return (chr == '+' || chr == '-');
}

bool isEndOfLine(char chr)
{
	return (chr == '\0');
}


int main()
{
	Status status = Status::start;
	char str[200];
	scanf("%s", str);

	int i = 0;
	while (status != Status::fail && status != Status::success)
	{
		switch (status)
		{
		case Status::start: //начало
		{
			if (!isDigit(str[i]))
			{
				status = Status::fail;
			}
			else
			{
				status = Status::state1;
			}
		}
			break;
		case Status::state1: //до запятой
		{
			if (!isDigit(str[i]))
			{
				switch (str[i])
				{
				case '.':
					status = Status::state2;
					break;
				case 'e':
				case 'E':
					status = Status::state4;
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
		case Status::state2: //символ после запятой
		{
			if (isDigit(str[i]))
			{
				status = Status::state3;
			}
			else
			{
				status = Status::fail;
			}
		}
			break;
		case Status::state3: //после запятой
		{
			if (!isDigit(str[i]))
			{
				switch (str[i])
				{
				case 'e':
				case 'E':
					status = Status::state4;
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
		case Status::state4: //знак после E
		{
			if (isSign(str[i]) || isDigit(str[i]))
			{
				status = Status::state5;
			}
			else
			{
				status = Status::fail;
			}
		}
			break;
		case Status::state5: //степень
		{
			if (!isDigit(str[i]))
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