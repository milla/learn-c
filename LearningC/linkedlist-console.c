#include "stdafx.h"
#include "LinkedList.h"

void print_linkedlist(LinkList head) {
	Node *p;
	if (head == NULL) {
		printf("wrong input, or error");
		exit(1);
	}

	p = head;
	while ((p = p->next) != NULL) {
		printf("%c\n", p->data);
	}
}


void print_linkedlist_d(LinkList head) {
	Node *p;
	if (head == NULL) {
		printf("wrong input, or error");
		exit(1);
	}

	p = head->next;
	while (p != NULL) {
		printf("%d\n", p->data);
		p = p->next;
	}
}


void print_linkedlist_d_nohaed(LinkList head) {
	Node *p;
	if (head == NULL) {
		printf("wrong input, or error");
		exit(1);
	}

	p = head;
	while (p != NULL) {
		if (p->data)
		{
			printf("%d\n", p->data);
			p = p->next;
		}
	}
}
