// https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list-in-reverse/problem
// https://www.hackerrank.com/challenges/reverse-a-linked-list

#include "stdafx.h"
#include "LinkedList.h"

/*
Print elements of a linked list in reverse order as standard output
head pointer could be NULL as well for empty list
Node is defined as
struct Node
{
int data;
struct Node *next;
}
*/
void ReversePrint(Node *head)
{
	// This is a "method-only" submission. 
	// You only need to complete this method. 

	if (!head) {}

	Node *p, *r, *newHead;
	p = r = newHead = head;
	r = NULL;

	while (p) {
		newHead = p;
		p = p->next;
		newHead->next = r;
		r = newHead;
	}

	p = newHead;
	while (p) {
		printf("%d\n", p->data);
		p = p->next;
	}
}

/*
Reverse a linked list and return pointer to the head
The input list will have at least one element
Node is defined as
struct Node
{
int data;
struct Node *next;
}
*/
Node* Reverse(Node *head)
{
	// Complete this method
	if (!head) { return NULL; }

	Node *p, *r, *newHead;
	p = r = newHead = head;
	r = NULL;

	while (p) {
		newHead = p;
		p = p->next;
		newHead->next = r;
		r = newHead;
	}

	return newHead;
}

/*
recursion
*/
Node* ReverseList(Node *head) {
	if (!head || !(head->next)) return head;

	Node *newPtr = head->next;

	Node *newHead = ReverseList(newPtr);

	newPtr->next = head;
	head->next = NULL;
	return newHead;
}

// 自考数据结构书习题
// switch a node with its succeeder
Node * SwitchNode(Node *head, Node * t) {
	Node *p, *q, *c, *r;
	Node *d, *dummy;

	dummy = (Node*)malloc(sizeof(Node));
	dummy->next = head;
	p = dummy;

	while (t && p && p->next && p->next->next)
	{
		r = p->next->next;
		c = p->next;

		if (c == t) {

			// switch t and r
			// p -> c -> r -> 
			// p -> r -> c ->
			q = r->next;

			p->next = r;
			r->next = c;
			c->next = q;
			break;
		}
		else {
			p = p->next;
		}
	}

	return dummy->next;
}