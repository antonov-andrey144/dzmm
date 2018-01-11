#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>

enum class Status
{
	start,
	readNextSymbolStart,
	digitWas,
	alphaWas,
	digit2Was,
	groop,
	groopWas,
	dWas,
	mWas,
	fail
};

bool isRightAlpha(char alpha)
{
	if (alpha == 'B' || alpha == 'M' || alpha == 'S' || alpha == 'm')

	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	char str[100];
	printf("Enter the string you want to check: ");
	scanf("%s", &str);
	int i = 0;
	Status state = Status::start;
	while (str[i] != '\0')
	{
		switch (state)
		{
		case Status::start:
		{
			if (isdigit(str[i]))
			{
				state = Status::readNextSymbolStart;
				++i;
			}
			else
			{
				state = Status::fail;
			}
			break;
		}

		case Status::digitWas:
		{
			if (isalpha(str[i]) && isRightAlpha(str[i]))
			{
				state = Status::alphaWas;
				++i;
			}
			else
			{
				state = Status::fail;
			}
			break;
		}

		case Status::alphaWas:
		{
			if (isdigit(str[i]))
			{
				if (str[i] >='1')
				{
					state = Status::groop;
					i++;
				}
				else 
				{
					state = Status::groopWas;
				}
			}

			else
			{
				state = Status::fail;
				i++;
			}
			break;
		}

		case Status::groop:
		{
			if (str[i] == '0')
			{
				state = Status::groopWas;
				++i;
			}
			else if (str[i] == '-')
			{
				state = Status::groopWas;
			}
			else
			{
				state = Status::fail;
			}
			break;
		}

		case Status::groopWas:
		{
			if (str[i] == '-')
			{
				state = Status::dWas;
			}
			else
			{
				state = Status::fail;
				i++;
			}
			break;
		}

		case Status::dWas:
		{
			if (str[i] == 'm')
			{
				state = Status::mWas;
				++i;
			}
			else
			{
				state = Status::fail;
				i++;
			}
			break;
		}

		case Status::mWas:
		{
			if (str[i] == 'm')
			{
				state = Status::mWas;
				break;
			}
			else
			{
				state = Status::fail;
			}
			break;
		}

		case Status::readNextSymbolStart:
		{

			if (isdigit(str[i]))
			{
				state = Status::digitWas;
				++i;
			}

			else 
			{
				state = Status::fail;
			}
			break;
		}

		case Status::fail:
		{
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

	if (state == Status::mWas)
	{
		printf("String is right");
	}
	else
	{
		printf("String is not right");
	}

	int pause = 0;
	scanf("%d", &pause);
	return 0;
}