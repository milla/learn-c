#include "stdafx.h"
#include "LinkedList.h"
#include <assert.h>

void TestGetNthFromTail() {
	// case 1
	int a1[] = { 1, 3, 4, 6, 9, 11 };
	int a1L = sizeof(a1) / IntSize;
	LinkList head = CreateByTail(a1, a1L);

	assert(GetNthFromTail(head, 0) == 11);
}

void TestGetLength() {
	// case 1
	int a1[] = { 1, 3, 4, 6, 9, 11 };
	int a1L = sizeof(a1) / IntSize;
	LinkList head = CreateByTail(a1, a1L);

	assert(GetLength(head) == a1L);
}
