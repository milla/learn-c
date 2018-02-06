#include "stdafx.h"
#include "LinkedList.h"
#include <assert.h>

void TestMerge() {
	testMergeLists();
	testMergeLists2();
	testMergeTwoSorted();
	testMergeKLists();
}

void testMergeLists() {
	// case 1
	int a1[] = { 1, 3, 4, 6, 9, 11 };
	int a1L = sizeof(a1) / IntSize;
	LinkList head1 = CreateByTail(a1, a1L);
	int a2[] = { 2, 3, 5, 7, 8, 10, 13, 14 };
	int a2L = sizeof(a2) / IntSize;
	LinkList head2 = CreateByTail(a2, a2L);

	head1 = MergeLists(head1, head2);

	assert(GetNth(head1, 0) == 1);
	assert(GetNth(head1, 1) == 2);
	assert(GetNth(head1, 2) == 3);
	assert(GetNth(head1, 3) == 3);
	assert(GetNth(head1, 4) == 4);
	assert(GetLength(head1) == a1L + a2L);

	// case 2
	int b1[] = { 4 };
	int b1L = sizeof(b1) / IntSize;
	head1 = CreateByTail(b1, b1L);

	int b2[] = { 2, 3, 5, 7, 8, 10, 11, 13, 14 };
	int b2L = sizeof(b2) / IntSize;
	head2 = CreateByTail(b2, b2L);

	head1 = MergeLists(head1, head2);

	assert(GetNth(head1, 0) == 2);
	assert(GetNth(head1, 1) == 3);
	assert(GetNth(head1, 2) == 4);
	assert(GetNth(head1, 3) == 5);
	assert(GetLength(head1) == b1L + b2L);
}


void testMergeTwoSorted() {
	// case 1
	int a1[] = { 1, 3, 4, 6, 9, 11 };
	int a1L = sizeof(a1) / IntSize;
	LinkList head1 = CreateByTail(a1, a1L);
	int a2[] = { 2, 3, 5, 7, 8, 10, 13, 14 };
	int a2L = sizeof(a2) / IntSize;
	LinkList head2 = CreateByTail(a2, a2L);

	head1 = MergeTwoSorted(head1, head2);

	assert(GetNth(head1, 0) == 1);
	assert(GetNth(head1, 1) == 2);
	assert(GetNth(head1, 2) == 3);
	assert(GetNth(head1, 3) == 3);
	assert(GetNth(head1, 4) == 4);
	assert(GetLength(head1) == a1L + a2L);

	// case 2
	int b1[] = { 4 };
	int b1L = sizeof(b1) / IntSize;
	head1 = CreateByTail(b1, b1L);

	int b2[] = { 2, 3, 5, 7, 8, 10, 11, 13, 14 };
	int b2L = sizeof(b2) / IntSize;
	head2 = CreateByTail(b2, b2L);

	head1 = MergeTwoSorted(head1, head2);

	assert(GetNth(head1, 0) == 2);
	assert(GetNth(head1, 1) == 3);
	assert(GetNth(head1, 2) == 4);
	assert(GetNth(head1, 3) == 5);
	assert(GetLength(head1) == b1L + b2L);
}
void testMergeLists2() {
	// case 1
	int a1[] = { 1, 3, 4, 6, 9, 11 };
	int a1L = sizeof(a1) / IntSize;
	LinkList head1 = CreateByTail(a1, a1L);
	int a2[] = { 2, 3, 5, 7, 8, 10, 13, 14 };
	int a2L = sizeof(a2) / IntSize;
	LinkList head2 = CreateByTail(a2, a2L);

	head1 = MergeLists2(head1, head2);

	assert(GetNth(head1, 0) == 1);
	assert(GetNth(head1, 1) == 2);
	assert(GetNth(head1, 2) == 3);
	assert(GetNth(head1, 3) == 3);
	assert(GetNth(head1, 4) == 4);
	assert(GetLength(head1) == a1L + a2L);

	// case 2
	int b1[] = { 4 };
	int b1L = sizeof(b1) / IntSize;
	head1 = CreateByTail(b1, b1L);

	int b2[] = { 2, 3, 5, 7, 8, 10, 11, 13, 14 };
	int b2L = sizeof(b2) / IntSize;
	head2 = CreateByTail(b2, b2L);

	head1 = MergeLists2(head1, head2);

	assert(GetNth(head1, 0) == 2);
	assert(GetNth(head1, 1) == 3);
	assert(GetNth(head1, 2) == 4);
	assert(GetNth(head1, 3) == 5);
	assert(GetLength(head1) == b1L + b2L);
}

void testMergeKLists(){
	// case 1
	int a1[] = { 1, 3, 5 };  			LinkList head1 = CreateByTail(a1, sizeof(a1) / IntSize);
	int a2[] = { 2, 4, 6}; 				LinkList head2 = CreateByTail(a2, sizeof(a2) / IntSize);
	int a3[] = { 1, 2, 4, 5, 10 };		LinkList head3 = CreateByTail(a3, sizeof(a3) / IntSize);
	int a4[] = { 12 };					LinkList head4 = CreateByTail(a4, sizeof(a4) / IntSize);
	
	Node** list[4];
	list[0] = head1; list[1] = head2; list[2] = head3; list[3] = head4; 
	
	Node * merged = MergeKLists(list, 4);
	assert(GetLength(merged) == 12);
	assert(GetNth(merged,11) == 12);
	assert(GetNth(merged,10) == 10);
}
