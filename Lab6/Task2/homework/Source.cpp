#define CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include "Stack.h" 

bool isParanthes(char par)
{
	return (par == '(' || par == '[' || par == '{' || par == ')' || par == ']' || par == '}');
}

bool isOpened(char par)
{
	return (par == '(' || par == '[' || par == '{');
}

bool isClosed(char par)
{
	return (par == ')' || par == ']' || par == '}');
}

bool isPair(char parOpened, char parClosed)
{
	return (parOpened == '(' && parClosed == ')') || (parOpened == '[' && parClosed == ']') || (parOpened == '{' && parClosed == '}');
}

bool isBalanced(char* str)
{
	Stack * stack = createStack();
	int index = 0;
	bool result = true;
	while (str[index] != '\0' && result)
	{
		if (isParanthes(str[index]))
		{
			if (isOpened(str[index]))
			{
				push(stack, str[index]);
			}
			if (isClosed(str[index]))
			{
				result &= isPair(pop(stack), str[index]);
			}
		}
		++index;
	}
	result &= isEmpty(stack);

	deleteStack(stack);

	return result;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char str[400] = "()(asdf)sdf(gs)dfg(sdf(gs(dfg{a}{wer}asdf{a[sdf]asdf[qw]er[as]df[asdf]a[sdf[aqwer[zsdf]as{df}asd{qwer[[sdf]asd]f}werasdf]as]dfwer}sdfa)))";
	printf(isBalanced(str) ? "Строка сбалансирована\n" : "Строка не сбалансирована\n");

	system("PAUSE");
	return EXIT_SUCCESS;
}