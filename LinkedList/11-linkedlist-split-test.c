#include "stdafx.h"
#include "LinkedList.h"
#include <assert.h>

void TestSplitToEvenOdd() {
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	LinkList head = CreateByHead(arr, sizeof(arr) / IntSize);
	LinkList head_even = SplitToEvenOdd(head);

	assert(GetLength(head) == 5);
	assert(GetLength(head_even) == 5);
	assert(GetNth(head, 0) == 1);
	assert(GetNth(head_even, 0) == 2);

	free(head);
	free(head_even);
}
