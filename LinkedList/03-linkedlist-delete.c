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
	if (!head || position < 0) { return NULL; }

	Node *p, *r, *newHead;
	int i = 0;
	p = r = newHead = head;

	if (position == 0) {
		newHead = head->next;
		head->next = NULL;
		free(head);
	}
	else {
		while (p && i < position) {
			r = p;
			p = p->next;
			i++;
		}

		if (!p) { printf("Error"); return head; }

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
void deleteNode(struct ListNode* node) {
	if (!node) exit(1);

	//*(node) = *(node)->next;
}
