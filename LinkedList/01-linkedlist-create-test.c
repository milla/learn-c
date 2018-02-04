#include "stdafx.h"
#include "LinkedList.h"
#include <assert.h>

void TestCreateByTailConsole() {
	LinkList list1 = CreateByTailConsole();
}

void TestCreateByHead() {
	int data[] = { 1 };
	LinkList head = CreateByHead(data, sizeof(data) / IntSize);
	assert(GetNth(head, 0) == 1);
	assert(GetLength(head) == 1);

	// case2
	int data2[] = { 1, 2 };
	head = CreateByHead(data2, sizeof(data2) / IntSize);

	assert(GetNth(head, 0) == 1);
	assert(GetNth(head, 1) == 2);
	assert(GetLength(head) == 2);

	free(head);
}

void TestCreateByTailWithHead() {
	int data[] = { 1 };
	LinkList head = CreateByTailWithHead(data, sizeof(data) / IntSize);

	assert(GetNth(head, 1) == 1);
	assert(GetLength(head) == 2);

	// case2
	int data2[] = { 1, 2 };
	head = CreateByTailWithHead(data2, sizeof(data2) / IntSize);

	assert(GetNth(head, 1) == 1);
	assert(GetNth(head, 2) == 2);
	assert(GetLength(head) == 3);

	free(head);
}

void TestCreateByTail() {
	int data[] = { 1 };
	LinkList head = CreateByTail(data, sizeof(data) / IntSize);

	assert(GetNth(head, 0) == 1);
	assert(GetLength(head) == 1);

	// case2

	int data2[] = { 1, 2 };
	head = CreateByTail(data2, sizeof(data2) / IntSize);

	assert(GetNth(head, 0) == 1);
	assert(GetNth(head, 1) == 2);
	assert(GetLength(head) == 2);

	free(head);
}
