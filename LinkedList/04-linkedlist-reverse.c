// https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list-in-reverse/problem
// https://www.hackerrank.com/challenges/reverse-a-linked-list

#include "stdafx.h"
#include "LinkedList.h"

/*
Print elements of a linked list in reverse order as standard output
head pointer could be NULL as well for empty list
Node is defined as
struct Node
{
int data;
struct Node *next;
}
*/
void ReversePrint(Node *head)
{
	// This is a "method-only" submission. 
	// You only need to complete this method. 

	if (!head) {}

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

/*
Reverse a linked list and return pointer to the head
The input list will have at least one element
Node is defined as
struct Node
{
int data;
struct Node *next;
}
*/
Node* Reverse(Node *head)
{
	// Complete this method
	if (!head) { return NULL; }

	Node *p, *r, *newHead;
	p = r = newHead = head;
	r = NULL;

	while (p) {
		newHead = p;
		p = p->next;
		newHead->next = r;
		r = newHead;
	}

	return newHead;
}

/*
recursion
*/
Node* ReverseList(Node *head) {
	if (!head || !(head->next)) return head;

	Node *newPtr = head->next;

	Node *newHead = ReverseList(newPtr);

	newPtr->next = head;
	head->next = NULL;
	return newHead;
}

// 自考数据结构书习题
// switch a node with its succeeder
Node * SwitchNode(Node *head, Node * t) {
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

// https://www.hackerrank.com/challenges/reverse-a-doubly-linked-list/problem
Dnode * ReverseDoublyList(Dnode *head){
	if (!head) return head;
	
	// Complete this function
    // Do not write the main method. 
    Dnode *q, *p, *r; // sequence by link: q - p - r
    q = head; 
	p = q->next;
	
	q->next = NULL;
	
    while (q && p){
    	r = p->next;
		
		p->next = q;	
		p->prev = r;
		
		q = p;
		p = r;
	}
    
    return q;
}


Node *swap(Node *p){
	if (!p || !p->next) return p;
	
	Node *q = p->next;
	p->next = NULL;
	
	q->next = p;
	
	return p;
}

// https://leetcode.com/problems/swap-nodes-in-pairs/description/ LeetCode #24
Node *SwapPairs(Node *head){
	if (!head || !head->next) return head;
	
	int pair = 0;
	Node *t, *q, *p, *dummy;
	p = head;
	dummy = (Node*)malloc(sizeof(Node));
	t = dummy;
	
	while (p && p->next){
		q = p->next->next;
		t->next = p->next;		
		p = swap(p);		
		t = p;
		p->next = q;
		p = p->next;
		
		if (!q) break;
	}
	
	return dummy->next;
}
