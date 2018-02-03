#include "stdafx.h"
#include "LinkedList.h"

/*
create from console input
*/
LinkList CreateByTailConsole() {
	LinkList head = (Node *)malloc(sizeof(Node));
	Node *p;
	Node *rear; // rear pointer 
	char ch;
	rear = head;

	while ((ch = getchar()) != '\n') {
		p = (Node *)malloc(sizeof(Node));
		p->data = ch;
		rear->next = p; // point prev to p;
		rear = p; // poin rear to p;
	}
	rear->next = NULL;

	return head;
}


LinkList CreateByHead(int data[], int len) {
	LinkList head = (Node *)malloc(sizeof(Node));
	Node *p, *r;
	p = head;
	r = head;

	for (int i = 0;i < len;i++) {
		p = (Node *)malloc(sizeof(Node));
		p->data = data[i];
		r->next = p;
		r = p;
	}

	r->next = NULL;

	Node *dummy = head;
	head = head->next;
	dummy->next = NULL;
	free(dummy);

	return head;
}

/*
create by tail
*/

LinkList CreateByTailWithHead(int input[], int len) {
	Node *head, *p, *r;
	head = (Node *)malloc(sizeof(Node));
	r = head;

	for (int i = 0;i < len;i++) {
		p = (Node *)malloc(sizeof(Node));
		p->data = input[i];
		r->next = p;
		r = p;
	}
	r->next = NULL;
	return head;
}

LinkList CreateByTail(int input[], int len) {
	Node *head, *p, *r;
	head = (Node *)malloc(sizeof(Node));
	head->data = input[0];
	head->next = NULL;
	r = head;

	for (int i = 1;i < len;i++) {
		p = (Node *)malloc(sizeof(Node));
		p->data = input[i];
		r->next = p;
		r = p;
	}
	r->next = NULL;
	return head;
}

