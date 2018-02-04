#include "stdafx.h"
#include "LinkedList.h"
#include <assert.h>

void TestCompareLists() {
	// case 2
	int data1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	LinkList head1 = CreateByHead(data1, sizeof(data1) / IntSize);

	int data2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	LinkList head2 = CreateByHead(data2, sizeof(data2) / IntSize);

	//compare
	assert(CompareLists(head1, head2) == 1);

	DeleteNth(head2, 3);
	assert(CompareLists(head1, head2) == 0);

	free(head1);
	free(head2);
}
