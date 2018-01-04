#include "List.h"
#include "ListMergeSort.h"
#include "ConsoleWork.h"

int main()
{
	List* list = startWork();

	doWork(list);

	endWork(list);

	int pause = 0;
	scanf("%d", &pause);
	return 0;
}