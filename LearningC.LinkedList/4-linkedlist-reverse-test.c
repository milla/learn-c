#include "stdafx.h"
#include "LinkedList.h"
#include <assert.h>

void TestReversePrint() {
	int data[] = { 1,2,3 };
	LinkList head = CreateByHead(data, sizeof(data) / IntSize);
	Print(head);

	printf("ReversePrint:\n");
	ReversePrint(head);

	printf("ReversePrint NULL list:\n");
	ReversePrint(NULL);

	free(head);
}

void TestReverse() {
	// case 1
	int data[] = { 1,2,3 };
	LinkList head = CreateByHead(data, sizeof(data) / IntSize);
	Print(head);

	printf("Reverse:\n");
	head = Reverse(head);
	Print(head);

	// case 2
	int data2[] = { 1,2,3,4,5,6,7,8,9,10 };
	head = CreateByHead(data2, sizeof(data2) / IntSize);
	Print(head);
	printf("Reverse:\n");
	head = Reverse(head);
	Print(head);

	// case 3
	printf("Reverse NULL list:\n");
	head = Reverse(NULL);
	Print(head);

	free(head);
}

void TestReverseList() {
	// case 1
	int data[] = { 1,2,3};
	LinkList head = CreateByHead(data, sizeof(data) / IntSize);
	Print(head);

	printf("Reverse:\n");
	head = ReverseList(head);
	Print(head);

	// case 2
	int data2[] = { 1,2,3,4,5,6,7,8,9,10 };
	head = CreateByHead(data2, sizeof(data2) / IntSize);
	Print(head);
	printf("Reverse:\n");
	head = ReverseList(head);
	Print(head);

	// case 3
	printf("Reverse NULL list:\n");
	head = ReverseList(NULL);
	Print(head);

	free(head);
}

void TestSwitchNode() {
	// case 1
	int data[] = { 1,2,3,4,5 };
	LinkList head = CreateByHead(data, sizeof(data) / IntSize);
	Print(head);

	printf("\nSwitch the 1st node:\n");
	head = SwitchNode(head, head);
	Print(head);

	printf("\nSwitch the 4th node:\n");
	head = SwitchNode(head, head->next->next->next);
	Print(head);

	free(head);
}
