#include "stdafx.h"
#include "LinkedList.h"

Node * get_sorted_diff(Node *heada, Node *headb) {
	Node *pa, *dummy, *p, *pb;
	pa = heada; pb = headb;
	dummy = (Node*)malloc(sizeof(Node));
	p = dummy;

	while (pa && pb) {
		if (pa->data == pb->data) {
			p->next = NULL;
			pa = pa->next;
			pb = pb->next;
		}
		else if (pa->data > pb->data) {
			pb = pb->next;
		}
		else /* pa->data < pb->data */ {
			p->next = pa;
			p = p->next;
			pa = pa->next;
		}
	}

	Node *f = dummy->next;
	dummy->next = NULL;
	free(dummy);
	return f;
}

Node * get_sorted_join(Node *heada, Node *headb) {
	Node *pa, *dummy, *p, *pb;
	pa = heada; pb = headb;
	dummy = (Node*)malloc(sizeof(Node));
	p = dummy;

	while (pa && pb && pa->next) {
		if (pa->data == pb->data) {
			p->next = pa;
			p = p->next;

			pa = pa->next;
			pb = pb->next;
		}
		else if (pa->data > pb->data) {
			pb = pb->next;
			pa = pa->next;
		}
		else {
			p = p->next;
			pa = pa->next;
		}
	}

	Node *f = dummy->next;
	dummy->next = NULL;
	free(dummy);
	return f;
}