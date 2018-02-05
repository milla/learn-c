#include "stdafx.h"
#include "LinkedList.h"
#include <assert.h>

void TestSplit() {
	testSplitToEvenOdd();
	testSplitListToParts();
}

void testSplitToEvenOdd()
{
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

void testSplitListToParts()
{	
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,23,24,25,26 };
	LinkList start = CreateByHead(arr, sizeof(arr) / IntSize);
	LinkList head = (Node*)malloc(sizeof(Node));
	head->next = start;
	int *returnSize;
	
	Node** ret = SplitListToParts(head, 8, returnSize);
	int i;
	for (i = 0; i<8;i++){
		printf("- %d\n", ret[i]->data);
	}
	free(head);
	free(ret);
}
