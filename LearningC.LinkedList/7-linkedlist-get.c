// https://www.hackerrank.com/challenges/get-the-value-of-the-node-at-a-specific-position-from-the-tail/problem

#include "stdafx.h"
#include "LinkedList.h"

/*
Get Nth element from the end in a linked list of integers
Number of elements in the list will always be greater than N.
Node is defined as
struct Node
{
int data;
struct Node *next;
}
*/
int GetNthFromTail(Node *head, int positionFromTail)
{
	if (!head) return NULL;

	// This is a "method-only" submission. 
	// You only need to complete this method. 
	if (positionFromTail < 0 || !head) { exit(1); }
	Node *rear, *p;
	rear = p = head;
	int ret;

	int count = 0, i = 0, j = 0;
	while (p) {
		rear = p;
		p = p->next;
		count++;
	}
	// exceed
	if (positionFromTail >= count) { exit(1); }
	else if (positionFromTail == 0) { ret = rear->data; }
	else if (positionFromTail == count - 1) { ret = head->data; }
	else {
		j = (count - positionFromTail - 1); // reversed iterator
		i = 0; p = head;
		while (p && i < j) {
			p = p->next;
			i++;
		}
		ret = p->data;
	}
	return ret;
}

int GetLength(Node *head)
{
	if (!head) return 0;

	int length = 0;

	while (head) {
		length++;
		head = head->next;
	}
	return length;
}

int GetNth(Node *head, int position)
{
	if (!head) return NULL;
	int j = 0;
	Node *n = head;
	n = NULL;

	while (head && j <= position) {
		if (j == position)
			n = head;

		head = head->next;
		j++;
	}

	return n ? n->data : NullInt;
}
