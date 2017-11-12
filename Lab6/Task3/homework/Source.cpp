#include <iostream>
#include "Stack.h" 

bool isDigit(char chr)
{
	return (chr >= '0' && chr <= '9');
}

bool isOperation(char chr)
{
	return (chr == '+' || chr == '-' || chr == '/' || chr == '*' || chr == '%');
}

bool isOpened(char par)
{
	return par == '(';
}

bool isClosed(char par)
{
	return par == ')';
}

bool isParanthes(char par)
{
	return isOpened(par) || isClosed(par);
}

int char2digit(char chr)
{
	return chr - '0';
}

void addChar2Str(char* str, int &last, char chr)
{
	str[last] = chr;
	++last;
	str[last] = ' ';
	++last;
}

int makeOperation(int operand1, int operand2, char operation)
{
	switch (operation)
	{
	case '+':
		return operand1 + operand2;
	case '-':
		return operand1 - operand2;
	case '*':
		return operand1 * operand2;
	case '/':
		return operand1 / operand2;
	case '%':
		return operand1 % operand2;
	}
	return 0;
}

int operationPriority(char operation)
{
	switch (operation)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
	case '%':
		return 2;
	default:
		return 0;
	}
}

/**
подсчет значения выражения с помощью Обратной Польской Нотации

@param str указатель на строку математического выражения в постфиксной записи
@returns целочисленное значение выражения
*/
int calculateReversePolishNotation(char* str)
{
	Stack * stack = createStack();
	int index = 0;

	while (str[index] != '\0')
	{
		if (str[index] != ' ')
		{
			if (isDigit(str[index]))
			{
				push(stack, char2digit(str[index]));
			}
			else
			{
				push(stack, makeOperation(pop(stack), pop(stack), str[index]));
			}
		}
		++index;
	}
	int result = pop(stack);

	deleteStack(stack);

	return result;
}

/**
преобразовывает инфиксную форму записи выражения в Обратную Польскую Нотацию по алгоритму Дейкстры (алгоритм сортировочной станции)

@param str указатель на строку математического выражения со скобками
@returns строка в формате Обратной Польской Нотации
*/
char* convertToReversePolishNotation(char* str)
{
	Stack * stack = createStack();
	char* result = new char[strlen(str)];
	int last = 0;
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			if (isDigit(str[i]))
			{
				addChar2Str(result, last, str[i]);
			}
			if (isOperation(str[i]))
			{
				while (!isEmpty(stack) && isOperation(peek(stack)) && (operationPriority(peek(stack)) >= operationPriority(str[i])))
				{
					addChar2Str(result, last, pop(stack));
				}
				push(stack, str[i]);
			}
			if (isParanthes(str[i]))
			{
				if (isOpened(str[i]))
				{
					push(stack, str[i]);
				}
				if (isClosed(str[i]))
				{
					while (!isOpened(peek(stack))) {
						addChar2Str(result, last, pop(stack));
					}
					pop(stack); //выкинули открытую скобку
				}
			}
		}
		++i;
	}

	while (!isEmpty(stack)) //перекидываем остатки стека в вывод
	{
		addChar2Str(result, last, pop(stack));
	}
	--last; //последний пробел
	result[last] = '\0'; //закрываем строку

	deleteStack(stack);

	return result;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char str[60] = "((3 - 2) * 4 + 5 * (7 - 4)) * (3 - 4 / (7 - 5) + 4)";
	printf("\"%s\"\n", str);
	char* rpn = convertToReversePolishNotation(str);
	printf("\" %s \"\n", convertToReversePolishNotation(str));
	printf("\" %d \"\n", calculateReversePolishNotation(rpn));
	
	system("PAUSE");
	return EXIT_SUCCESS;
}