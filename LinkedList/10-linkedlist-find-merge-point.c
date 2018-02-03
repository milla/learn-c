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

// use moving steps which should be the same if a+b = b+a,
int FindMergeNode3(Node *headA, Node *headB)
{
	// Complete this function
	// Do not write the main method. 
	Node *pa, *pat, *pb, *pbt;
	pa = pat = headA;
	pb = pbt = headB;
	int ta = 0;
	int tb = 0;
	Node *meet = (Node*)malloc(sizeof(Node));

	while (pa || pb) {
		if (pa->next) {
			pa = pa->next;
			ta++;
		}
		else {
			pa = pbt;
			pbt = pbt->next;
		}
		if (pb->next) {
			pb = pb->next;
			tb++;
		}
		else {
			pb = pat;
			pat = pat->next;
		}

		if (pa->data == pb->data) {
			meet = pa;
			break;
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
int FindMergeNode4(Node *headA, Node *headB)
{
	// Complete this function
	// Do not write the main method. 
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
