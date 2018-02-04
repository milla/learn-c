// https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists/problem

#include "stdafx.h"
#include "LinkedList.h"

/*
Find merge point of two linked lists
Node is defined as
struct Node
{
int data;
Node* next;
}
*/
int FindMergeNode1(Node *headA, Node *headB)
{
	// Complete this function
	// Do not write the main method. Node *pa, *pat, *pb, *pbt;
	Node *pa, *pb, *pat, *pbt;
	pa = pat = headA;
	pb = pbt = headB;
	int ta = 0;
	int tb = 0;
	Node *meet = headA;
	meet = NULL;

	while (pa || pb) {
		if (pa->data == pb->data) {
			meet = pa;
			break;
		}
		if (pa->next) {
			pa = pa->next;
			ta++;
		}
		if (pb->next) {
			pb = pb->next;
			tb++;
		}
	}

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


/*
Find merge point of two linked lists
Node is defined as
struct Node
{
int data;
Node* next;
}
*/
int FindMergeNode2(Node *headA, Node *headB)
{
	// Complete this function
	// Do not write the main method. Node *pa, *pat, *pb, *pbt;
	Node *pa, *pb, *pat, *pbt;
	pa = pat = headA;
	pb = pbt = headB;
	int ta = 0;
	int tb = 0;
	Node *meet = headA;
	meet = NULL;

	while (pa || pb) {
		if (pa->data == pb->data) {
			meet = pa;
			break;
		}
		if (pa->next) {
			pa = pa->next;
			ta++;
		}
		if (pb->next) {
			pb = pb->next;
			tb++;
		}
	}

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

/*
Find merge point of two linked lists
Node is defined as
struct Node
{
int data;
Node* next;
}
*/

// pointer-a walks thru list-a, and then walks from head of list-b
// pointer-b walks thru list-b, and then walks from head of list-a
// can get merge point when the two points meet
// use moving steps which should be the same if a+b = b+a,
int FindMergeNode3(Node *headA, Node *headB)
{
	// Complete this function
	// Do not write the main method.
	if (!headB) return headA ? headA->data : NULL;
	if (!headA) return headB ? headB->data : NULL;

	Node *pa, *pat, *pb, *pbt;
	pa = pat = headA;
	pb = pbt = headB;
	Node *meet = (Node*)malloc(sizeof(Node));

	while (pa || pb) {	
		if (pa && pb && pa->data == pb->data) {
			meet = pa;
			break;
		}
		
		// pointer-a walks thru list-a
		if (pa->next) {
			pa = pa->next;
		} else {
			// if done, go from the head of list-b
			pa = pbt;
			pbt = pbt->next;
		}

		// pointer-b walks thru list-b
		if (pb->next) {
			pb = pb->next;
		} else {
			// if done, go from the head of list-a
			pb = pat;
			pat = pat->next;
		}

	}

	return meet->data;
}

/*
Change list-a node's next to a dummy node, 
loop list-b, when any node's next points to the dummy node,
the crossing point found. 

but this requires the merging point should be same object reference, but not value. 
*/
int FindMergeNode4(Node *headA, Node *headB)
{
	// Complete this function
	// Do not write the main method.
	if (!headB) return headA ? headA->data : NULL;
	if (!headA) return headB ? headB->data : NULL;
		
	int ret = 0;
	Node *dummy = (Node*)malloc(sizeof(Node));
	Node *t = headA;

	while (headA) {
		t = headA->next;
		headA->next = dummy;

		headA = t;
	}

	while (headB) {
		if (headB->next == dummy) {
			ret = headB->data;
			break;
		}
		headB = headB->next;
	}

	return ret;
}
