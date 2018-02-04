#include "stdafx.h"
#include "LinkedList.h"

Node * Diff(Node *heada, Node *headb) {
	if (!headb || !heada) return heada;

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
