#include <assert.h>
#include "stdafx.h"
#include "LinkedList.h"

void TestSplitToEvenOdd() {
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	LinkList head = CreateByHead(arr, sizeof(arr) / IntSize);
	printf("whole list\n");
	Print(head);

	LinkList head_even = SplitToEvenOdd(head);
	printf("head odd list\n");
	Print(head);

	printf("head even list\n");
	Print(head_even);
}