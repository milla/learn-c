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
	Node *aPtr, *bPtr;
	aPtr = heada;
	bPtr = headb;
	Node *dummy;
	Node *p;
	
	p = dummy = (Node*)malloc(sizeof(Node));
	
	while (aPtr != NULL && bPtr != NULL) {
		if (aPtr->data <= bPtr->data) {
			p->next = aPtr;
			p = p->next;
			aPtr = aPtr->next;
		}
		else {
			p->next = bPtr;
			p = p->next; 
			bPtr = bPtr->next;
		}
	}
	p->next = aPtr == NULL ? bPtr : aPtr;
	return dummy->next;
}

Node* MergeLists2(Node* l1, Node* l2) {
	// recursive runs at call stack, much quicker than heap (esp., for C#, java)
	if (!l1) return l2;
	if (!l2) return l1;

	if (l1->data <= l2->data) {
		l1->next = MergeLists2(l1->next, l2);
		return l1;
	}
	else {
		l2->next = MergeLists2(l1, l2->next);
		return l2;
	}
}

Node* mergeTwoLists(Node* p1, Node* p2) {
    if (!p1) return p2;
    if (!p2) return p1;
    
    Node *head = (Node *)malloc(sizeof(Node));
    Node *p = head;
       
	while (p1 && p2){
        if (p1->data <= p2->data){
            p->next = p1;
            p1 = p1->next;
        }else{
            p->next = p2;
            p2 = p2->next;
        }
        p = p->next;
    }
    
    p->next = p1 ? p1 : p2;
    return head->next;
}

// https://leetcode.com/problems/merge-k-sorted-lists/description/ LeetCode #23
Node* MergeKLists(Node** lists, int listsSize) {
    if (listsSize <= 0) return NULL;
    if (listsSize <= 1) return lists[0];
    int i = 0;
    
    // 13 ms
    int interval = 1;
    // enhance in pairs, to shorten length of list: https://leetcode.com/problems/merge-k-sorted-lists/solution/     	
	while (interval < listsSize){
    	for (i = 0; i < listsSize - interval; i = i + interval*2){
    		lists[i] = mergeTwoLists(lists[i], lists[i + interval]);        	
		}
		interval*=2;    	
    }
    
    return lists[0];    
}
