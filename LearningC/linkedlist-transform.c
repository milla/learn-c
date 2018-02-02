#include "stdafx.h"
#include "LinkedList.h"

void reverse_linkedlist(LinkList head) {
	if (!head) throw_exception();

	Node *p, *newhead, *r;
	p = newhead = head;
	p = p->next; // 从第一个结点而非头结点开始；
	newhead = NULL;

	while (p != NULL) {
		r = p;
		p = p->next;
		r->next = newhead;
		newhead = r;
	}

	head->next = newhead;
}

void ReversePrint(LinkList head)
{
	// This is a "method-only" submission. 
	// You only need to complete this method. 

	if (!head) exit(1);

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



Node* ReverseList(Node *head) {
	if (!head || !(head->next)) return head;

	Node *newPtr = head->next;
	Node *newHead = ReverseList(newPtr);
	newPtr->next = head;
	head->next = NULL;
	return newHead;
}

Node* ReverseList_mine(Node *head) {
	if (!head || !(head->next)) return head;
	Node *p = head;
	Node *newHead = head->next;
	Node *nPtr = newHead;

	p->next = NULL;
	newHead = ReverseList_mine(newHead);
	nPtr->next = p;
	nPtr = nPtr->next;
	return newHead;
}

Node * switch_node(Node *head, Node * t) {
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
