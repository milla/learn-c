#include "stdafx.h"
#include "LinkedList.h"
#include <assert.h>

void TestInsertAtTail() {
	int data[] = { 1,2,3,4,5,6,7,8,9,10 };
	int len = sizeof(data) / IntSize;
	LinkList head = CreateByTail(data, len);

	head = InsertAtTail(head, 30);

	assert(GetNth(head, 0) == 1);
	assert(GetLength(head) == len + 1);
	assert(GetNth(head, len) == 30);

	free(head);
}

void TestInsertAtHead() {
	int data[] = { 1,2,3,4,5,6,7,8,9,10 };
	int len = sizeof(data) / IntSize;
	LinkList head = CreateByTail(data, len);

	head = InsertAtHead(head, 30);

	assert(GetNth(head, 0) == 30);
	assert(GetLength(head) == len + 1);
	assert(GetNth(head, len) == 10);

	free(head);
}

void TestInsertNth() {
	int data[] = { 1,2,3,4,5,6,7,8,9,10 };
	int len = sizeof(data) / IntSize;
	LinkList head = CreateByTail(data, len);
	head = InsertNth(head, 30, 0);

	assert(GetNth(head, 0) == 30);
	assert(GetLength(head) == len + 1);
	assert(GetNth(head, len) == 10);

	len++;

	head = InsertNth(head, 50, len);
	assert(GetNth(head, 0) == 30);
	assert(GetLength(head) == len + 1);
	assert(GetNth(head, len) == 50);

	free(head);
}