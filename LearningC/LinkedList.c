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

Node *get_node(LinkList head, int i) {
	Node *p;
	p = head->next;
	int j = 0;

	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}

	if (p == NULL) {
		printf("error");exit(0);
	}

	return p;
}

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


void throw_exception() {
	printf("error");
	exit(1);
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

// 自考书籍，p55, 例2.5，将一个数字的list，奇数一个链表，偶数一个链表
LinkList split_list_even(LinkList head) {
	LinkList headb; // even list
	Node *p, *r, *bPtr, *bRear; // r是listA暂存, b_r是listB暂存
	p = head;
	if (head == NULL) throw_exception();
	headb = (Node *)malloc(sizeof(Node));
	bPtr = bRear = headb;
	int i = 0;
	DataType data;

	while (p != NULL) {
		r = p;
		p = p->next;
		if (p != NULL && p->data != NULL && p->data % 2 == 0) {
			r->next = r->next->next;
			// move p to headb
			bPtr->next = p;
			bPtr = p;
		}
	}

	bPtr->next = NULL;
	return headb;
}

// 自考书籍，p55, 例2.6，将两个有序链接，合并为一个
LinkList merge_sorted_linkedlist(LinkList heada, LinkList headb) {
	LinkList head = heada;
	Node *headPtr = head;
	Node *aPtr, *bPtr;
	aPtr = heada;
	bPtr = headb;
	aPtr = aPtr->next;
	bPtr = bPtr->next;

	// 将B表merge到A表，遍历两个表去找更小的值插入进去
	// while有个很好的用处，就是可以一直循环，直到结束，其中的逻辑不限定是几个数组或链表对象

	while (aPtr != NULL && bPtr != NULL) {
		if (aPtr->data <= bPtr->data) {
			headPtr->next = aPtr;
			headPtr = headPtr->next;
			aPtr = aPtr->next;
		}
		else {
			headPtr->next = bPtr;
			headPtr = headPtr->next; // 注意这个指针也要后移一格，越来越清楚了，果然是要刷题！
			bPtr = bPtr->next;
		}
	}
	headPtr->next = aPtr == NULL ? bPtr : aPtr;
	free(headb); // headPtr uese heada's head node, so we can free headb
	return head;
}

LinkList transform_linkedlist_failed1(LinkList head) {
	Node *p, *newhead;
	p = head;
	newhead = p;
	head->next = NULL;

	p = head;
	newhead = head->next;
	head->next = NULL;


	while (p != NULL) {
		p = p->next;
		p->next = newhead;
		newhead = p;
	}

	return newhead;
}
LinkList merge_linkedlists(LinkList src_list, LinkList target_list) {
	return 0;
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

Node* MergeLists(Node *headA, Node* headB)
{
	// This is a "method-only" submission. 
	// You only need to complete this method 
	if (!headA && !headB) return NULL;
	if (!headA) return headB;
	if (!headB) return headA;

	Node *pa, *pb, *newHead, *p;
	pa = p = newHead = headA;
	pb = headB;
	newHead = NULL;

	while (pa && pb) {
		if (pa->data <= pb->data) {
			if (!newHead) {
				newHead = pa;
				p = newHead;
			}
			else {
				p->next = pa;
				p = p->next;
			}
			pa = pa->next;
		}
		else {
			if (!newHead) {
				newHead = pb;
				p = newHead;
			}
			else {
				p->next = pb;
				p = p->next;
			}
			pb = pb->next;
		}
	}

	p->next = pa ? pa : pb;

	return newHead;
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
int FindMergeNode(Node *headA, Node *headB)
{
	// Complete this function
	// Do not write the main method. Node *pa,*pat, *pb,*pbt; 
	Node *pa, *pb, *pat, *pbt;
	pa = pat = headA;
	pb = pbt = headB;
	int ta = 0;
	int tb = 0;
	Node *meet = headA; meet = NULL;

	while (pa || pb) {
		if (pa->next) {
			pa = pa->next;
			ta++;
		}
		if (pb->next) {
			pb = pb->next;
			tb++;
		}
		if (pa->data == pb->data) {
			meet = pa;
			break;
		}
	}

	printf("%d, %d", ta, tb);

	if (ta != tb) {
		meet = NULL;
		pa = headA;
		pb = headB;
		while (ta > tb && --ta >= tb) {
			pa = pa->next;
		}
		while (ta < tb && --tb >= ta) {
			pb = pb->next;
		}
		while (pa && pb) {
			if (pa->data == pb->data) {
				meet = pa;
				break;
			}
			pa = pa->next;
			pb = pb->next;
		}
	}

	return meet->data;
}

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