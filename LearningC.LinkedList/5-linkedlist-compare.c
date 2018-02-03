// https://www.hackerrank.com/challenges/compare-two-linked-lists/problem

#include "stdafx.h"
#include "LinkedList.h"

/*
Compare two linked lists A and B
Return 1 if they are identical and 0 if they are not.
Node is defined as
struct Node
{
int data;
struct Node *next;
}
*/
int CompareLists(Node *headA, Node* headB)
{
	// This is a "method-only" submission. 
	// You only need to complete this method 
	Node *pa, *pb;
	if (!headA || !headB) { return 0; }
	pa = headA;pb = headB;
	int ret = 0; // false;
	while (pa && pb) {
		if (pa->data != pb->data) {
			break;
		}
		pa = pa->next;
		pb = pb->next;
	}
	if ((pa == NULL) && (pb == NULL)) {
		ret = 1;
	}
	return ret;
}
