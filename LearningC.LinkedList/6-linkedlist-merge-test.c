#include "stdafx.h"
#include "LinkedList.h"
#include <assert.h>

void TestMergeLists() {
	int m = 0;

	// case 1
	int a1[] = { 1,3,4,6, 9,11 };
	LinkList head1 = CreateByTail(a1, sizeof(a1) / IntSize);
	int a2[] = { 2,3,5,7,8,10,13,14 };
	LinkList head2 = CreateByTail(a2, sizeof(a2) / IntSize);

	m = MergeLists(head1, head2);
	assert(m == 3);

	// case 2
	int b1[] = { 11 };
	head1 = CreateByTail(b1, sizeof(b1) / IntSize);
	int b2[] = { 2,3,5,7,8,10,11,13,14 };
	head2 = CreateByTail(b2, sizeof(b1) / IntSize);

	m = MergeLists(head1, head2);
	assert(m == 11);

	// case 2
	int c1[] = { 2,3,5,7,8};
	head1 = CreateByTail(c1, sizeof(c1) / IntSize);
	int c2[] = { 8,10,11,13,14 };
	head2 = CreateByTail(c2, sizeof(c1) / IntSize);

	m = MergeLists(head1, head2);
	assert(m == 8);

	free(head1);
	free(head2);
}


void TestMergeTwoSorted() {
	int m = 0;

	// case 1
	int a1[] = { 1,3,4 };
	LinkList head1 = CreateByTail(a1, sizeof(a1) / IntSize);
	int a2[] = { 2,3 };
	LinkList head2 = CreateByTail(a2, sizeof(a2) / IntSize);

	m = MergeTwoSorted(head1, head2);
	assert(m == 3);

	// case 2
	int b1[] = { 11 };
	head1 = CreateByTail(b1, sizeof(b1) / IntSize);
	int b2[] = { 2,3,5,7,8,10,11,13,14 };
	head2 = CreateByTail(b2, sizeof(b2) / IntSize);

	m = MergeLists(head1, head2);
	assert(m == 11);

	// case 2
	int c1[] = { 2,3,5,7,8 };
	head1 = CreateByTail(c1, sizeof(c1) / IntSize);
	int c2[] = { 8,10,11,13,14 };
	head2 = CreateByTail(c2, sizeof(c2) / IntSize);

	m = MergeLists(head1, head2);
	assert(m == 8);

	free(head1);
	free(head2);
}