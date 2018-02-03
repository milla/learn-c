#include "stdafx.h"
#include "LinkedList.h"
#include <assert.h>

void TestRemoveDuplicates() {
	// case 1
	int a1[] = { 3,3 };
	LinkList head1 = CreateByTail(a1, sizeof(a1) / IntSize);
	head1 = RemoveDuplicates(head1);

	assert(GetNth(head1, 0) == 3);
	assert(GetNth(head1, 1) < NullInt);

	// case 2
	int b1[] = { 2,3,3,4 };
	head1 = CreateByTail(b1, sizeof(b1) / IntSize);
	head1 = RemoveDuplicates(head1);

	assert(GetNth(head1, 0) == 2);
	assert(GetNth(head1, 1) == 3);
	assert(GetNth(head1, 2) == 4);
	assert(GetNth(head1, 3) < NullInt);
}

void TestRemoveDuplicates2() {
	// case 1
	int a1[] = { 3,3 };
	LinkList head1 = CreateByTail(a1, sizeof(a1) / IntSize);
	head1 = RemoveDuplicates2(head1);

	assert(GetNth(head1, 0) == 3);
	assert(GetNth(head1, 1) < NullInt);

	// case 2
	int b1[] = { 2,3,3,4 };
	head1 = CreateByTail(b1, sizeof(b1) / IntSize);
	head1 = RemoveDuplicates2(head1);

	assert(GetNth(head1, 0) == 2);
	assert(GetNth(head1, 1) == 3);
	assert(GetNth(head1, 2) == 4);
	assert(GetNth(head1, 3) < NullInt);
}