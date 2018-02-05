#include "stdafx.h"
#include "LinkedList.h"
#include <assert.h>

void TestReverse() {
	testReversePrint();
	testReverse();
	testReverseList();
	testSwitchNode();
	testReverseDoublyList();
}

void testReversePrint() {
	int data[] = { 1, 2, 3 };
	LinkList head = CreateByHead(data, sizeof(data) / IntSize);
	Print(head);

	printf("ReversePrint:\n");
	ReversePrint(head);

	printf("ReversePrint NULL list:\n");
	ReversePrint(NULL);

	free(head);
}

void testReverse() {
	// case 1
	int data[] = { 1, 2, 3 };
	LinkList head = CreateByHead(data, sizeof(data) / IntSize);
	head = Reverse(head);
	assert(GetNth(head, 0) 	== 3);
	assert(GetNth(head, 1) 	== 2);
	assert(GetNth(head, 2)	== 1);
	assert(GetLength(head)	== 3);

	// case 2
	int data2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	head = CreateByHead(data2, sizeof(data2) / IntSize);
	head = Reverse(head);
	assert(GetNth(head, 0) == 10);
	assert(GetNth(head, 1) == 9);
	assert(GetNth(head, 2) == 8);
	assert(GetLength(head) == sizeof(data2) / IntSize);

	// case 3
	printf("Reverse NULL list:\n");
	head = Reverse(NULL);
	assert(head == NULL);

	free(head);
}

void testReverseList() {
	// case 1
	int data[] = { 1, 2, 3 };
	LinkList head = CreateByHead(data, sizeof(data) / IntSize);
	head = ReverseList(head);
	assert(GetNth(head, 0) == 3);
	assert(GetNth(head, 1) == 2);
	assert(GetNth(head, 2) == 1);
	assert(GetLength(head) == 3);

	// case 2
	int data2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	head = CreateByHead(data2, sizeof(data2) / IntSize);
	head = ReverseList(head);
	assert(GetNth(head, 0) == 10);
	assert(GetNth(head, 1) == 9);
	assert(GetNth(head, 2) == 8);
	assert(GetLength(head) == sizeof(data2) / IntSize);

	// case 3
	printf("Reverse NULL list:\n");
	head = ReverseList(NULL);
	assert(head == NULL);

	free(head);
}

void testSwitchNode() {
	// case 1
	int data[] = { 1, 2, 3, 4, 5 };
	int len = sizeof(data) / IntSize;
	LinkList head = CreateByHead(data, len);
	head = SwitchNode(head, head);
	assert(GetNth(head, 0) == 2);
	assert(GetNth(head, 1) == 1);
	assert(GetNth(head, 2) == 3);
	assert(GetLength(head) == len);

	head = SwitchNode(head, head->next->next->next);
	assert(GetNth(head, 0) == 2);
	assert(GetNth(head, 1) == 1);
	assert(GetNth(head, 2) == 3);
	assert(GetNth(head, 3) == 5);
	assert(GetNth(head, 4) == 4);
	assert(GetLength(head) == len);

	free(head);
}

void testReverseDoublyList(){
	int data[] = { 1, 2, 3 };
	Dnode *head = CreateDoublyList(data, sizeof(data) / IntSize);
	
	head = ReverseDoublyList(head);
	
	Dnode *n = GetNthDnode(head,0);
	
	assert(n->data == 3);
	assert(n->prev == NULL);
	assert(n->next->data == 2);
	assert(n->next->prev->data == 3);
	assert(n->next->next->data == 1);
	assert(GetNthDnode(head,1)->data == 2);
	assert(GetNthDnode(head,2)->data == 1);
	
	int data2[] = { 1, 2 };
	head = CreateDoublyList(data2, sizeof(data2) / IntSize);
	
	head = ReverseDoublyList(head);
	
	assert(GetNthDnode(head,0)->data == 2);
	assert(GetNthDnode(head,1)->data == 1);
	
	int data3[] = { 1 };
	head = CreateDoublyList(data3, sizeof(data3) / IntSize);
	
	head = ReverseDoublyList(head);
	
	assert(GetNthDnode(head,0)->data == 1);
	
	free(head);
}

