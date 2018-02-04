// https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle/problem

#include "stdafx.h"
#include "LinkedList.h"

/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as:
struct Node {
int data;
struct Node* next;
}
*/

bool HasCycle(Node* head) {
	// Complete this function
	// Do not write the main method

	if (!head) return 0;

	bool ret = 0;
	Node *slow, *fast;
	slow = fast = head;

	while (slow && fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast) {
			ret = 1;
			break;
		}
	}

	return ret;
}

/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as:
struct Node {
int data;
struct Node* next;
}
*/
// 拆路式 break nextptr
bool HasCycle2(Node* head) {
	// Complete this function
	// Do not write the main method

	Node *dummy = (Node*)malloc(sizeof(Node));
	Node *t = head;
	Node *p = head;
	bool ret = false;
	

	while (p && p->next) {
		if (p->next == dummy) {
			ret = true;
			break;
		}
		t = p->next;
		p->next = dummy;

		p = t;
	}

	return ret;

}
