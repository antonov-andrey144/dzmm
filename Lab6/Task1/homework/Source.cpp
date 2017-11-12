#include <iostream>
#include "Stack.h" 


bool isDigit(char chr)
{
	return (chr >= '0' && chr <= '9');
}

int c2d(char chr)
{
	return chr - '0';
}

int makeop(int num1, int num2, char op)
{
	switch (op)
	{
	case '+':
		return num1 + num2;
	case '-':
		return num1 - num2;
	case '*':
		return num1 * num2;
	case '/':
		return num1 / num2;
	case '%':
		return num1 % num2;
	}
	return 0;
}

int countReversePolishNotation(char* str)
{
	Stack * stack = createStack();
	int index = 0;

	while (str[index] != '\0')
	{
		if (str[index] != ' ')
		{
			if (isDigit(str[index]))
			{
				push(stack, c2d(str[index]));
			}
			else
			{
				push(stack, makeop(pop(stack), pop(stack), str[index]));
			}
		}
		++index;
	}
	int result = pop(stack);

	deleteStack(stack);

	return result;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char str[40] = "6 9 + 2 3 - *";
	printf("%d\n", countReversePolishNotation(str));
	char str1[40] = "2 3 + 4 +";
	printf("%d\n", countReversePolishNotation(str1));
	system("PAUSE");
	return EXIT_SUCCESS;
}