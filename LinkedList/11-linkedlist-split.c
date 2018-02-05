#include "stdafx.h"
#include "LinkedList.h"

// split a linked list to two list,
// one should contain all even numbers,
// another should all odd
LinkList SplitToEvenOdd(LinkList head)
{
	LinkList headb; // even list
	Node *p, *r, *bPtr, *bRear; // r是listA暂存, b_r是listB暂存
	p = head;
	if (head == NULL) return NULL;

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
	return headb->next;
}

// https://leetcode.com/problems/split-linked-list-in-parts/description/
Node** SplitListToParts(Node* root, int k, int* returnSize)
{
	// length: L
	// count: L/k
	// count with (L/k): l - L/k
	// count with L/k + 1: mod(L/k)
	// e.g., 26 items, k = 8; [4 items] [ 4 items] [3 items] [3 items] [3 items] [3 items] [3 items] [3 items]
	int i, j, n = 0;
    Node *prev, *head = prev = NULL;
    Node *t;
    for ( t = root ; t ; t = t->next ) ++n;
    int parts_num = (n < k) ? 1 : (n/k);
    int extra = (n < k) ? (0) : (n % k);

    Node** ans = calloc(k , sizeof(Node*));
    returnSize = &(k);
    head = root;
    for ( i = 0; i < k; i++, --extra ) 
    {

        ans[i] = head;
        for (j = 0 ; j < parts_num + (extra > 0) && head ; j++) {
            prev = head;      
            head = head->next;
        }
        if (prev) prev->next = NULL; //breaking list became a independent list.
    }

    return ans;
}	
