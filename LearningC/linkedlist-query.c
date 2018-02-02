#include "stdafx.h"
#include "LinkedList.h"

Node *get_node(LinkList head, int i) {
	Node *p;
	p = head->next;
	int j = 0;

	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}

	if (p == NULL) {
		printf("error");exit(0);
	}

	return p;
}


int FindMergeNode(Node *headA, Node *headB)
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

	printf("%d, %d", ta, tb);

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
