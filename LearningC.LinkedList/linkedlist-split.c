#include "stdafx.h"
#include "LinkedList.h"

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