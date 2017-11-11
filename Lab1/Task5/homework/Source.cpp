#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


bool isOpenedParanthesis(char parenthesis)
{
	return (parenthesis == '(' || parenthesis == '{' || parenthesis == '[');
}

bool isClosedParanthesis(char parenthesis)
{
	return (parenthesis == ')' || parenthesis == '}' || parenthesis == ']');
}

bool isPair(char parenthesis1, char parenthesis2) {
	return (parenthesis1 == '(' && parenthesis2 == ')') || (parenthesis1 == '{' && parenthesis2 == '}') || (parenthesis1 == '[' && parenthesis2 == ']');
}

bool isCorrect(char* str) {
	bool correct = true;
	int current = 0;
	int i = 0;
	char* openedPartheses = new char[strlen(str)];

	while (str[i] != '\0')
	{
		if (isOpenedParanthesis(str[i])) {
			openedPartheses[current] = str[i];
			++current;
		}
		else
		{
			if (isClosedParanthesis(str[i])) {
				if (current > 0 && isPair(openedPartheses[current - 1], str[i])) {
					--current;
				}
				else
				{
					correct = false;
					break;
				}
			}
		}
		i++;
	}

	if (current != 0) {
		correct = false;
	}

	delete[] openedPartheses;

	return correct;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	char str[100] = "";

	printf("Введите текст для проверки на баланса скобок\n");
	gets_s(str);

	printf(isCorrect(str) ? "Баланс скобок соблюден" : "Баланс скобок не соблюден");

	system("PAUSE");
	return 0;
}