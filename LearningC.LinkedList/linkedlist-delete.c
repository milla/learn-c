#include "stdafx.h"
#include "LinkedList.h"

DataType remove_from_linkedlist(LinkList head, int i) {
	Node *p, *r;
	int j = 0;
	p = head;

	// get prev
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}

	r = p->next;
	p->next = r->next;
	DataType data = r->data;
	free(r);
	return data;
}
Node* RemoveDuplicates(Node *head)
{
	if (!head) return NULL;

	// This is a "method-only" submission. 
	// You only need to complete this method. 
	Node *prev, *p, *r;
	prev = r = p = head;
	p = p->next;

	while (p) {
		if (p->data != prev->data)
		{
			// insert 
			prev->next = p;
			prev = prev->next;
		}
		else {
			// remove from head, and add to dummy
			r = p;
			prev->next = p->next;
		}
		p = p->next;
	}

	return head;
}