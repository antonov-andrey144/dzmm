#include "List.h"

List* mergeSortedLists(List* list1, List* list2, int sortBy, bool asc)
{
	List* result = listCreate();

	Node* temp1 = listExtractFirst(list1);
	Node* temp2 = listExtractFirst(list2);

	while (temp1 != nullptr && temp2 != nullptr) {
		int cmp = (sortBy == 0 ? nodeCompareByName(temp1, temp2) : nodeCompareByPhone(temp1, temp2));

		if (cmp < 0 == asc) {
			listAppend(result, temp1);
			temp1 = listExtractFirst(list1);
		}
		else if (cmp > 0 == asc)
		{
			listAppend(result, temp2);
			temp2 = listExtractFirst(list2);
		}
		else if (cmp == 0)
		{
			listAppend(result, temp1);
			listAppend(result, temp2);
			temp1 = listExtractFirst(list1);
			temp2 = listExtractFirst(list2);
		}
	}

	listAppend(result, temp1);
	listAppend(result, list1);
	listAppend(result, temp2);
	listAppend(result, list2);
	listDelete(list1);
	listDelete(list2);
	return result;
}

void listMergeSort(List* &list, int sortBy, bool asc) 
{
	int length = list->length;
	List** merging = new List*[length];
	for (int i = 0; i < length; ++i) 
	{
		merging[i] = listCreate(listExtractFirst(list));
	}
	listDelete(list);

	while (length != 1) 
	{
		for (int i = 0; i < length; i += 2)
		{
			List* list1 = merging[i];
			merging[i] = nullptr;
			List* list2 = nullptr;
			if (i + 1 < length) 
			{
				list2 = merging[i + 1];
				merging[i + 1] = nullptr;
			}
			merging[i / 2] = mergeSortedLists(list1, list2, sortBy, asc);
		}
		length = length / 2 + length % 2;
	}

	List* result = merging[0];
	merging[0] = nullptr;
	for (int i = 0; i < length; ++i) 
	{
		listDelete(merging[i]);
	}
	delete[] merging;
	list = result;
}
