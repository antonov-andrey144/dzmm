#include "List.h"
#include "ListMergeSort.h"
#include "ConsoleWork.h"

int main()
{
	List* list = startWork();

	doWork(list);

	endWork(list);

	system("pause");
	return 0;
}