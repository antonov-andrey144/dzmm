#define _CRT_SECURE_NO_WARNINGS
#include "List.h"
#include "ListMergeSort.h"
#include "ConsoleWork.h"

using namespace std;

int main()
{
	List* list;
	startWork(list);

	doWork(list);

	endWork(list);

	int pause = 0;
	scanf("%d", &pause);
	return 0;
}