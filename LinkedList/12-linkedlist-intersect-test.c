#include "stdafx.h"
#include "LinkedList.h"
#include <assert.h>

void TestIntersect() {

	// case 1
	int a1[] = { 3, 4, 6, 7, 8, 12, 99 };
	LinkList head1 = CreateByTail(a1, sizeof(a1) / IntSize);
	Print(head1);

	int a2[] = { 3, 5, 7, 8, 20 };
	LinkList head2 = CreateByTail(a2, sizeof(a2) / IntSize);
	Print(head2);

	Node* ret = Intersect(head1, head2);
	Print(ret);

	assert(GetNth(ret, 0) == 4);
	assert(GetNth(ret, 1) == 6);
	assert(GetNth(ret, 2) == 12);
	assert(GetNth(ret, 3) == 99);

	// case 2
	int b1[] = { 4, 6, 7 };
	head1 = CreateByTail(b1, sizeof(b1) / IntSize);
	Print(head1);

	int b2[] = { 3, 5, 7, 8, 20 };
	head2 = CreateByTail(b2, sizeof(b2) / IntSize);
	Print(head2);

	ret = Intersect(head1, head2);
	Print(ret);
	assert(GetNth(ret, 0) == 4);
	assert(GetNth(ret, 1) == 6);

	// case 3
	ret = Intersect(head1, NULL);
	Print(ret);
	assert(GetNth(ret, 0) == 4);
	assert(GetNth(ret, 1) == 6);
	assert(GetNth(ret, 2) == 7);

	// case 4
	ret = Intersect(NULL, head2);
	Print(ret);
	assert(GetNth(ret, 0) < NullInt);

	// case 5
	int c1[] = { 4, 6, 7, 8, 12, 140 };
	head1 = CreateByTail(c1, sizeof(c1) / IntSize);
	Print(head1);

	int c2[] = { 3, 5, 7, 8, 20, 110, 111, 112, 123, 140 };
	head2 = CreateByTail(c2, sizeof(c2) / IntSize);
	Print(head2);

	ret = Intersect(head1, head2);
	Print(ret);

	assert(GetNth(ret, 0) == 4);
	assert(GetNth(ret, 1) == 6);
	assert(GetNth(ret, 2) == 12);

	free(head1);
	free(head2);
	free(ret);
}
