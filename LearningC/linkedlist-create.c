#include "stdafx.h"
#include "LinkedList.h"

LinkList create_list_into_tail() {
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


LinkList create_list_by_array(int data[]) {
	LinkList head = (Node *)malloc(sizeof(Node));
	Node *p, *r;
	p = head;
	r = head;
	int length = sizeof(data);

	for (int i = 0;i < length;i++) {
		p = (Node *)malloc(sizeof(Node));
		p->data = data[i];
		r->next = p; // r暂存当前p的位置，到下一个时，将r的next设成它
		r = p;
	}

	r->next = NULL;
	return head;
}



LinkList create_list_by_tail_input(int input[10]) {
	int len = sizeof(input);
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

LinkList create_list_by_tail_input_nohead(int input[]) {
	int len = sizeof(input);
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

