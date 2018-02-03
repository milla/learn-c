// 1. https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list/problem
// 2. https://www.hackerrank.com/challenges/insert-a-node-at-the-head-of-a-linked-list/problem
// 3. https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/problem

#include "stdafx.h"
#include "LinkedList.h"
/*
Insert Node at the end of a linked list
head pointer input could be NULL as well for empty list
Node is defined as
struct Node
{
int data;
struct Node *next;
}
*/

#include<stdio.h>
Node* InsertAtTail(Node *head, int data)
{
	Node *q;
	q = (Node*)malloc(sizeof(Node));
	q->data = data;
	q->next = NULL;
	if (head) {
		Node *p, *r;
		p = r = head;
		while (p) {
			r = p;
			p = p->next;
		}

		r->next = q;
	}
	else {
		head = q;
	}
	return head;
}

/*
Insert Node at the begining of a linked list
Initially head pointer argument could be NULL for empty list
Node is defined as
struct Node
{
int data;
struct Node *next;
}
return back the pointer to the head of the linked list in the below method.
*/
Node* InsertAtHead(Node *head, int data)
{
	Node *q, *p;
	q = (Node*)malloc(sizeof(Node));
	q->data = data;
	// Complete this method
	if (head) {
		p = head;
		head = q;
		q->next = p;
	}
	else {
		head = q;
		q->next = NULL;
	}
	return head;
}

/*
Insert Node at a given position in a linked list
head can be NULL
First element in the linked list is at position 0
Node is defined as
struct Node
{
int data;
struct Node *next;
}
*/
Node* InsertNth(Node *head, int data, int position)
{
	// Complete this method only
	// Do not write main function. 
	if (!head && position > 0 || position < 0) { exit(1); }

	Node *p, *r, *newHead, *q;
	newHead = head;

	q = (Node*)malloc(sizeof(Node));
	q->data = data;
	q->next = NULL;

	if (position == 0) {
		q->next = head;
		newHead = q;
	}
	else if (!head) {
		head = q;
	}
	else {
		p = head;
		int i = 0;
		while (p && i < position - 1) {
			p = p->next;
			i++;
		}
		if (p == NULL && i != position - 1) {
			free(q);
			exit(1);
		}

		r = p->next;
		p->next = q;
		q->next = r;
	}

	newHead = newHead ? newHead : head;

	return newHead;
}