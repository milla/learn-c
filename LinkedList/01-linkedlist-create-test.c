#include "stdafx.h"
#include "LinkedList.h"
#include <assert.h>

void TestCreate(){
	//TestCreateByTailConsole();
	testCreateByHead();
	testCreateByTailWithHead();
	testCreateByTail();
	testCreateCycleListByTail();
	testCreateDoublyList();
}

void testCreateByTailConsole() {
	LinkList list1 = CreateByTailConsole();
}

void testCreateByHead() {
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

void testCreateByTailWithHead() {
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

void testCreateByTail() {
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

void testCreateCycleListByTail(){
	int data[] = { 1 };
	LinkList head = CreateCycleListByTail(data, sizeof(data) / IntSize);

	assert(GetNth(head, 0) == 1);
	assert(GetNth(head, 1) == 1);

	// case2

	int data2[] = { 1, 2 };
	head = CreateCycleListByTail(data2, sizeof(data2) / IntSize);

	assert(GetNth(head, 0) == 1);
	assert(GetNth(head, 1) == 2);
	assert(GetNth(head, 2) == 1);
	assert(GetNth(head, 3) == 2);

	free(head);
}

void testCreateDoublyList(){
	
	int data[] = { 1 };
	Dnode* head = CreateDoublyList(data, sizeof(data) / IntSize);

	Dnode* n = GetNthDnode(head, 0);
	
	assert(n);
	assert(n->prev == NULL);
	assert(n->next == NULL);
	assert(n->data == 1);	
	
	// case2

	int data2[] = { 1, 2, 3 };
	head = CreateDoublyList(data2, sizeof(data2) / IntSize);
	n = GetNthDnode(head,1);
	
	assert(n);
	assert(n->prev->data == 1);
	assert(n->next->data == 3);
	assert(n->data == 2);

	free(head);
}
