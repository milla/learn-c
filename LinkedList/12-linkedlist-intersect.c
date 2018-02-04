#include "stdafx.h"
#include "LinkedList.h"
#include <assert.h>

Node * Intersect(Node *heada, Node *headb) {
	Node *pa, *dummy, *p, *pb;
	pa = heada; pb = headb;
	dummy = (Node*)malloc(sizeof(Node));
	p = dummy;

	while (pa && pb) {
		if (pa->data == pb->data) {
			p->next = pa;
			p = p->next;

			pa = pa->next;
			pb = pb->next;
		}
		else if (pa->data > pb->data) {
			pb = pb->next;
		}
		else {
			pa = pa->next;
		}
	}

	p->next	= NULL;
	Node *f = dummy->next;
	dummy->next = NULL;
	free(dummy);
	return f;
}
