// https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list/problem
#include "stdafx.h"
#include "LinkedList.h"
/*
Print elements of a linked list on console
head pointer input could be NULL as well for empty list
Node is defined as
struct Node
{
int data;
struct Node *next;
}
*/
#include <stdio.h>

void Print(LinkList head) {
	Node *p;
	if (head == NULL) {
		printf("wrong input, or error");
		return;
	}

	// check whether contains head node
	if (head->data) {
		p = head;
	}
	else {
		p = head->next;
	}

	while (p != NULL) {
		printf("%d\n", p->data);
		p = p->next;
	}
}
