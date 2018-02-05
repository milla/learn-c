// https://www.hackerrank.com/challenges/delete-a-node-from-a-linked-list/problem

#include "stdafx.h"
#include "LinkedList.h"

/*
Delete Node at a given position in a linked list
Node is defined as
struct Node
{
int data;
struct Node *next;
}
*/
Node* DeleteNth(Node *head, int position)
{
	// Complete this method
	if (!head || position < 0) {
		return NULL;
	}

	Node *p, *r, *newHead;
	int i = 0;
	p = r = newHead = head;

	if (position == 0) {
		newHead = head->next;
		head->next = NULL;
		free(head);
	} else {
		while (p && i < position) {
			r = p;
			p = p->next;
			i++;
		}

		if (!p) {
			printf("Error");
			return head;
		}

		r->next = p->next;
		free(p);
	}
	newHead = newHead ? newHead : head;
	return newHead;
}

/**
https://leetcode.com/problems/delete-node-in-a-linked-list/description/
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
void deleteNode(struct ListNode* node)
{
	if (!node) exit(1);

	//*(node) = *(node)->next;
}

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
Node* Delete(Node* head, int val)
{
	Node *p/*prev pointer*/, *q/*middle/current*/, *r/*rear*/, *dummy/*for missing headnode*/;
	dummy = (Node *)malloc(sizeof(Node));
	dummy->next = head;
	p = dummy;
	r = head;

	while (r) {
		if (p->next->data == val) {
			q = p->next;
			p->next = p->next->next;
			free(q);
			r = p->next;
		} else {
			p = p->next;
			r = r->next;
		}
	}

	return dummy->next;
}

// one-pass algorithm https://www.wikiwand.com/en/One-pass_algorithm
// fast pointer moves n, 
// slow pointer moves from n,  to complete the list, and left (len - n)

// from https://leetcode.com/problems/remove-nth-node-from-end-of-list/discuss/8804/Simple-Java-solution-in-one-pass
// 
// length - n: two pointer - slow - fast, get their difference 
Node* RemoveNthFromEnd(Node* head, int n)
{
	Node* start = (Node *)malloc(sizeof(Node));
	Node* slow = start;
	Node* fast = start;
	slow->next = head;
	int i=1;

	//Move fast in front so that the gap between slow and fast becomes n
	for(i=1; i<=n+1; i++)   {
		fast = fast->next;
	}
	
	//Move fast to the end, maintaining the gap
	while(fast != NULL) {
		slow = slow->next;
		fast = fast->next;
	}
	//Skip the desired node
	slow->next = slow->next->next;
	return start->next;
}
