// https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists/problem

#include "stdafx.h"
#include "LinkedList.h"

/*
Merge two sorted lists A and B as one linked list
Node is defined as
struct Node
{
int data;
struct Node *next;
}
*/
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

// merge two sorted singly linked list
LinkList MergeTwoSorted(LinkList heada, LinkList headb) {
	LinkList head = heada;
	Node *headPtr = head;
	Node *aPtr, *bPtr;
	aPtr = heada;
	bPtr = headb;
	
	while (aPtr != NULL && bPtr != NULL) {
		if (aPtr->data <= bPtr->data) {
			headPtr->next = aPtr;
			headPtr = headPtr->next;
			aPtr = aPtr->next;
		}
		else {
			headPtr->next = bPtr;
			headPtr = headPtr->next; 
			bPtr = bPtr->next;
		}
	}
	headPtr->next = aPtr == NULL ? bPtr : aPtr;
	free(headb); // headPtr uese heada's head node, so we can free headb
	return head;
}
