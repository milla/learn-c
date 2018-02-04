#include "stdafx.h"
#include "LinkedList.h"
#include <assert.h>

void TestHasCycle() {
	int data[] = { 1, 2, 3 };
	LinkList head = CreateByHead(data, sizeof(data) / IntSize);
	
	assert(HasCycle(head) == false);
	
	int data2[] = { 1, 2 };
	LinkList head2 = CreateCycleListByTail(data2, sizeof(data2) / IntSize);
	
	head->next = head2;
	
	assert(HasCycle(head) == true);
	assert(HasCycle(head2) == true);
	
	free(head);
}

void TestHasCycle2() {
	int data[] = { 1, 2, 3 };
	LinkList head = CreateByHead(data, sizeof(data) / IntSize);
	
	assert(HasCycle(head) == false);
	
	int data2[] = { 1, 2 };
	LinkList head2 = CreateCycleListByTail(data2, sizeof(data2) / IntSize);
	
	head->next = head2;
	
	assert(HasCycle2(head) == true);
	// the solution broke the list, so we cannot test head2 as HasCycle does.
	// assert(HasCycle2(head2) == true);
	
	free(head);
}
