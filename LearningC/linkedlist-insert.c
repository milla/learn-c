#include "stdafx.h"
#include "LinkedList.h"

void insert_into_linkedlist(LinkList head, int i, DataType data) {
	Node *p, *q, *cur_next;
	int j = 0;
	p = head;

	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}

	if (p == NULL) {
		printf("error");exit(0);
	}

	q = (Node *)malloc(sizeof(Node));
	cur_next = p->next;
	p->next = q;
	q->next = cur_next;
	q->data = data;
}


Node* Insert(Node *head, int data)
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
		Node *h; h = (Node*)malloc(sizeof(Node));
		head = h;
		head->next = q;
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
	if (!head && position > 0) { exit(1); }

	Node *p, *r, *newHead, *q;
	newHead = head;
	q = (Node*)malloc(sizeof(Node));
	q->data = data;
	if (!head) {
		head = q;
		q->next = NULL;
	}
	else {
		p = head;
		if (position == 0) {
			q->next = head;
			newHead = q;
		}
		else {
			int i = 0;
			while (p && i < position - 1) {
				p = p->next;
				i++;
			}
			r = p;
			p->next = q;
			q->next = r;
		}
	}

	newHead = newHead ? newHead : head;

	return newHead;
}
