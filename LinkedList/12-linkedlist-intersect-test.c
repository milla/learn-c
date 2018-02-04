#include "stdafx.h"
#include "LinkedList.h"
#include <assert.h>

void TestIntersect() {

	// case 1
	int a1[] = { 3, 4, 6, 7, 8, 12, 99 };
	LinkList head1 = CreateByTail(a1, sizeof(a1) / IntSize);
	int a2[] = { 3, 5, 7, 8, 20 };
	LinkList head2 = CreateByTail(a2, sizeof(a2) / IntSize);

	Node* ret = Intersect(head1, head2);
	assert(GetNth(ret, 0) == 3);
	assert(GetNth(ret, 1) == 7);
	assert(GetNth(ret, 2) == 8);
	assert(GetLength(ret) == 3);

	// case 2
	int b1[] = { 4, 6, 7 };
	head1 = CreateByTail(b1, sizeof(b1) / IntSize);
	int b2[] = { 3, 5, 7, 8, 20 };
	head2 = CreateByTail(b2, sizeof(b2) / IntSize);

	ret = Intersect(head1, head2);
	assert(GetNth(ret, 0) == 7);
	assert(GetLength(ret) == 1);

	// case 3
	ret = Intersect(head1, NULL);
	assert(ret == NULL);

	// case 4
	ret = Intersect(NULL, head2);
	assert(ret == NULL);

	// case 5
	int c1[] = { 4, 6, 7, 8, 12, 140 };
	head1 = CreateByTail(c1, sizeof(c1) / IntSize);
	int c2[] = { 3, 5, 7, 8, 20, 110, 111, 112, 123, 140 };
	head2 = CreateByTail(c2, sizeof(c2) / IntSize);
	
	ret = Intersect(head1, head2);

	assert(GetNth(ret, 0) == 7);
	assert(GetNth(ret, 1) == 8);
	assert(GetNth(ret, 2) == 140);
	assert(GetLength(ret) == 3);

	free(head1);
	free(head2);
	free(ret);
}
