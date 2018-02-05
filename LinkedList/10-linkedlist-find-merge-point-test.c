#include "stdafx.h"
#include "LinkedList.h"
#include <assert.h>

void TestFindMergeNode() {
	testFindMergeNode1();
	testFindMergeNode2();
	testFindMergeNode3();
	testFindMergeNode4();
}

void testFindMergeNode1() {

	int m = 0;

	// case 1
	int a1[] = { 1, 3, 5, 7, 8, 10, 13, 14 };
	LinkList head1 = CreateByTail(a1, sizeof(a1) / IntSize);
	int a2[] = { 2, 3, 5, 7, 8, 10, 13, 14 };
	LinkList head2 = CreateByTail(a2, sizeof(a2) / IntSize);

	m = FindMergeNode1(head1, head2);
	assert(m == 3);

	// case 2
	int b1[] = { 11, 13, 14 };
	head1 = CreateByTail(b1, sizeof(b1) / IntSize);
	int b2[] = { 2, 3, 5, 7, 8, 10, 11, 13, 14 };
	head2 = CreateByTail(b2, sizeof(b2) / IntSize);

	m = FindMergeNode1(head1, head2);
	assert(m == 11);

	// case 3
	int c1[] = { 2, 3, 5, 7, 8, 10, 11, 13, 14 };
	head1 = CreateByTail(c1, sizeof(c1) / IntSize);
	int c2[] = { 8, 10, 11, 13, 14 };
	head2 = CreateByTail(c2, sizeof(c2) / IntSize);

	m = FindMergeNode1(head1, head2);
	assert(m == 8);

	// case 4
	int d1[] = { 2, 3, 5, 7, 8, 10, 11, 13, 14 };
	head1 = CreateByTail(d1, sizeof(d1) / IntSize);
	int d2[] = { 2, 3, 5, 7, 8, 10, 11, 13, 14  };
	head2 = CreateByTail(d2, sizeof(d2) / IntSize);

	m = FindMergeNode1(head1, head2);
	assert(m == 2);


	free(head1);
	free(head2);
}
void testFindMergeNode2() {
	int m = 0;

	// case 1
	int a1[] = { 1, 3, 5, 7, 8, 10, 13, 14 };
	LinkList head1 = CreateByTail(a1, sizeof(a1) / IntSize);
	int a2[] = { 2, 3, 5, 7, 8, 10, 13, 14 };
	LinkList head2 = CreateByTail(a2, sizeof(a2) / IntSize);

	m = FindMergeNode2(head1, head2);
	assert(m == 3);

	// case 2
	int b1[] = { 11, 13, 14 };
	head1 = CreateByTail(b1, sizeof(b1) / IntSize);
	int b2[] = { 2, 3, 5, 7, 8, 10, 11, 13, 14 };
	head2 = CreateByTail(b2, sizeof(b2) / IntSize);

	m = FindMergeNode2(head1, head2);
	assert(m == 11);

	// case 3
	int c1[] = { 2, 3, 5, 7, 8, 10, 11, 13, 14 };
	head1 = CreateByTail(c1, sizeof(c1) / IntSize);
	int c2[] = { 8, 10, 11, 13, 14 };
	head2 = CreateByTail(c2, sizeof(c2) / IntSize);

	m = FindMergeNode2(head1, head2);
	assert(m == 8);

	// case 4
	int d1[] = { 2, 3, 5, 7, 8, 10, 11, 13, 14 };
	head1 = CreateByTail(d1, sizeof(d1) / IntSize);
	int d2[] = { 2, 3, 5, 7, 8, 10, 11, 13, 14  };
	head2 = CreateByTail(d2, sizeof(d2) / IntSize);

	m = FindMergeNode2(head1, head2);
	assert(m == 2);

	free(head1);
	free(head2);
}

void testFindMergeNode3() {
	int m = 0;

	// case 1
	int a1[] = { 1, 3, 5, 7, 8, 10, 13, 14 };
	LinkList head1 = CreateByTail(a1, sizeof(a1) / IntSize);
	int a2[] = { 2, 3, 5, 7, 8, 10, 13, 14 };
	LinkList head2 = CreateByTail(a2, sizeof(a2) / IntSize);

	m = FindMergeNode3(head1, head2);
	assert(m == 3);

	// case 2
	int b1[] = { 11, 13, 14 };
	head1 = CreateByTail(b1, sizeof(b1) / IntSize);
	int b2[] = { 2, 3, 5, 7, 8, 10, 11, 13, 14 };
	head2 = CreateByTail(b2, sizeof(b2) / IntSize);

	m = FindMergeNode3(head1, head2);
	assert(m == 11);

	// case 3
	int c1[] = { 2, 3, 5, 7, 8, 10, 11, 13, 14 };
	head1 = CreateByTail(c1, sizeof(c1) / IntSize);
	int c2[] = { 8, 10, 11, 13, 14 };
	head2 = CreateByTail(c2, sizeof(c2) / IntSize);

	m = FindMergeNode3(head1, head2);
	assert(m == 8);

	// case 4
	int d1[] = { 2, 3, 5, 7, 8, 10, 11, 13, 14 };
	head1 = CreateByTail(d1, sizeof(d1) / IntSize);
	int d2[] = { 2, 3, 5, 7, 8, 10, 11, 13, 14  };
	head2 = CreateByTail(d2, sizeof(d2) / IntSize);

	m = FindMergeNode3(head1, head2);
	assert(m == 2);


	free(head1);
	free(head2);
}

void testFindMergeNode4() {	

	int m = 0;

	// case 1
	int a1[] = { 1, 3, 5, 7, 8, 10, 13, 14 };
	LinkList head1 = CreateByTail(a1, sizeof(a1) / IntSize);
	int a2[] = { 2  };
	
	/*
	solution #4 equires the merging point should be same object reference, but not value. 
	*/

	LinkList head2 = CreateByTail(a2, sizeof(a2) / IntSize);
	head2->next = head1->next;

	m = FindMergeNode4(head1, head2);
	assert(m == 3);

	// case 2
	int b1[] = { 11, 13, 14 };
	head1 = CreateByTail(b1, sizeof(b1) / IntSize);
	int b2[] = { 2, 3, 5, 7, 8, 10 };
	head2 = CreateByTail(b2, sizeof(b2) / IntSize);
	head2->next = head1;

	m = FindMergeNode4(head1, head2);
	assert(m == 11);

	// case 3
	int c1[] = { 2, 3, 5, 7, 8, 10, 11, 13, 14 };
	head1 = CreateByTail(c1, sizeof(c1) / IntSize);
	head2 = head1->next->next->next->next; // 8

	m = FindMergeNode4(head1, head2);
	assert(m == 8);

	// case 4
	int d1[] = { 2, 3, 5, 7, 8, 10, 11, 13, 14 };
	head1 = CreateByTail(d1, sizeof(d1) / IntSize);
	head2 = head1;

	m = FindMergeNode4(head1, head2);
	assert(m == 2);

	free(head1);
}
