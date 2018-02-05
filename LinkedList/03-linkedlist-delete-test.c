#include "stdafx.h"
#include "LinkedList.h"
#include <assert.h>

void TestDelete(){
	testDeleteNth();
	testDelete();
	testRemoveNthFromEnd();
}

void testDeleteNth() {
	int data[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	int len = sizeof(data) / IntSize;
	LinkList head = CreateByHead(data, len);

	head = DeleteNth(head, 0);
	assert(GetNth(head, 0) == 2);
	assert(GetLength(head) == len - 1);

	len--;
	head = DeleteNth(head, 50);
	assert(GetNth(head, len - 1) == 11);
	assert(GetLength(head) == len);

	head = DeleteNth(head, 3);
	assert(GetNth(head, 3) == 6);
	assert(GetLength(head) == len - 1);

	free(head);
}

void testDelete() {
	int data[] = { 3, 2, 3, 4, 5, 3 };
	int len = sizeof(data) / IntSize;
	LinkList head = CreateByHead(data, len);
	
	head = Delete(head, 3);
	Print(head);
	
	assert(GetNth(head,0) == 2);
	assert(GetNth(head,1) == 4);
	assert(GetNth(head,2) == 5);
	assert(GetLength(head) == 3);
	
	int data2[] = { 1, 1 };
	len = sizeof(data2) / IntSize;
	LinkList head2 = CreateByHead(data2, len);
	
	head2 = Delete(head2, 1);
	Print(head2);
	
	assert(GetLength(head2) == 0);
}

void testRemoveNthFromEnd(){
	
	int data[] = { 1, 2, 3, 4 };
	int len = sizeof(data) / IntSize;
	LinkList head = CreateByHead(data, len);
	
	head = RemoveNthFromEnd(head, 1);
	
	assert(GetNth(head, 0) == 1);
	assert(GetNth(head, 1) == 2);
	assert(GetNth(head, 2) == 3);
	assert(GetLength(head) == 3);
	
	Print(head);
	
	head = RemoveNthFromEnd(head, 2);
	Print(head);
	assert(GetNth(head, 0) == 1);
	assert(GetNth(head, 1) == 3);
	assert(GetLength(head) == 2);
}
