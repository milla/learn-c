// https://www.hackerrank.com/challenges/delete-duplicate-value-nodes-from-a-sorted-linked-list/problem

#include "stdafx.h"
#include "LinkedList.h"

/*
Remove all duplicate elements from a sorted linked list
Node is defined as
struct Node
{
int data;
struct Node *next;
}
*/
Node* RemoveDuplicates(Node *head)
{
	if (!head) return NULL;

	// This is a "method-only" submission. 
	// You only need to complete this method. 
	Node *prev, *p;
	prev = p = head;
	p = p->next;

	while (p) {
		if (p->data != prev->data)
		{
			prev->next = p;
			prev = prev->next;
		}
		else {
			prev->next = p->next;
		}
		p = p->next;
	}

	return head;
}


/*
Remove all duplicate elements from a sorted linked list
Node is defined as
struct Node
{
int data;
struct Node *next;
}
*/
Node* RemoveDuplicates2(Node *head)
{
	if (!head) return NULL;

	// This is a "method-only" submission. 
	// You only need to complete this method. 
	Node *p, *tmp;
	p = head;

	while (p->next) {
		if (p->data == p->next->data)
		{
			tmp = p->next;
			p->next = p->next->next;
			free(tmp);
		}
		else {
			p = p->next;
		}
	}

	return head;
}
