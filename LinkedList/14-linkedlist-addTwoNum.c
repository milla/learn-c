#include "stdafx.h"
#include "LinkedList.h"

Node * AddTwoNumbers(Node *l1, Node *l2)
{
	Node* p1 = l1; Node* p2 = l2;
	Node* head = (Node*)malloc(sizeof(Node));
	Node* p = head; 
	Node* q;

	int extra = 0; int sum = 0;

	while (p1 || p2 || (extra > 0)) {
		q = (Node*)malloc(sizeof(Node));

		sum = (p1 ? p1->data: 0) + (p2? p2->data: 0) + extra;

		p1 = p1 ? p1->next : p1;
		p2 = p2 ? p2->next : p2;

		extra = sum/10;

		q->data = sum%10;
		p->next = q;

		p = q;
	}

	p->next = NULL;

	return head->next;
}
