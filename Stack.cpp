#include "Stack.h" 

struct Element
{
	Value data;
	Element* next;
};

struct Stack
{
	Element* head;
};

Stack* createStack()
{
	return new Stack();
}

void deleteStack(Stack* stack)
{
	while (!isEmpty(stack))
	{
		pop(stack);
	}
	delete stack;
}

void push(Stack* stack, Value value)
{
	stack->head = new Element{ value, stack->head };
}

Value pop(Stack* stack)
{
	if (isEmpty(stack))
	{
		return nullvalue;
	}

	Element* element = stack->head;
	Value data = element->data;
	stack->head = element->next;
	delete element;
	return data;
}

bool isEmpty(Stack* stack)
{
	return (stack->head == nullptr);
}