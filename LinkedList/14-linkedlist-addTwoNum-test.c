#include "stdafx.h"
#include "LinkedList.h"
#include <assert.h>

void TestAddTwoNumbers() {
	testAddTwoNumbers();
	//todo: failed testIntersect2();
}

void testAddTwoNumbers(){	
	// case 1
	int a1[] = { 2, 4 };
	LinkList head1 = CreateByTail(a1, sizeof(a1) / IntSize);
	int a2[] = { 8, 6, 2};
	LinkList head2 = CreateByTail(a2, sizeof(a2) / IntSize);

	Node* ret = AddTwoNumbers(head1, head2);
	assert(GetNth(ret, 0) == 0);
	assert(GetNth(ret, 1) == 1);
	assert(GetNth(ret, 2) == 3);
	
	free(head1);
	free(head2);
	free(ret);
}

