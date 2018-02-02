#include "stdafx.h"
#include "LinkedListDirect.h"

// Create list and insert at head
// return head which represents the linkedList
LinkList create_list_into_head() {
	// as different from c#, here's no such a thing of List in this case,
	// as "head" is actually a pointer pointing to head which is a Node, so, to correct by removing LinkList *head;
	ListNode *p;
	char ch;
	ListNode *head;
	head = NULL;
	ch = getchar(); // you cannot write ch=getchar() in while and expect it runs everything time within the loop <- different from c# again.
	while (ch != '\n') {
		p = (ListNode *)malloc(sizeof(ListNode));
		p->next = head;
		p->data = ch;
		head = p;
		ch = getchar();
	}

	return head;
};

LinkList create_list_into_tail() {
	LinkList head, tail;
	ListNode *p;
	head = NULL;
	tail = NULL;

	char ch;
	ch = getchar();

	while (ch != '\n') {
		p = (ListNode *)malloc(sizeof(ListNode));
		p->data = ch;

		if (head == NULL) head = p;
		else tail->next = p;
		tail = p;

		ch = getchar();
	}

	if (tail != NULL) tail->next = NULL; // set it NULL otherwise loop reference
										 // error: tail currently points to the last item of the list, tail is not another space, it's a pointer.
										 // you shouldn't free tail; free(tail);

	return head;
}

LinkList insert_into_linkedlist(LinkList head, int i, DataType data) {
	ListNode *p, *r, *q;
	int j = 0;
	p = head;
	LinkList newlist;

	// p is the to-be-inserted node's prev 
	q = (ListNode *)malloc(sizeof(ListNode));
	q->data = data;

	if (i == 0) {
		// 设存在一方法 dosomething(A *param)，如在方法内部，将传进来的指针参数修改为其它对象的指针，
		// 你以为这是改变了这个参数本身，
		// 但其实传进去的A对象还是没有变，因为并没有改动它... 在外面，仍然使用这个地址的变量，并没有被改动，
		// 所以这种不带头结点的链表，考虑到第一个结点之前插入，导致这个链表的对象生成了新的对象，所以要返回...
		newlist = q;
		q->next = head;

		return newlist;
	}
	else {
		while (p != NULL && j < i - 1) { // 因为[0]被计算进去
			p = p->next;
			j++;
		}
		if (p == NULL) {
			printf("error");exit(0);
		}
		//和头结点的相似，除了index少1；
		r = p;
		q->next = r->next;
		p->next = q;

		return head;
	}
}

ListNode *get_node(LinkList head, int i) {
	ListNode *p;
	p = head;
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

void remove_from_linkedlist(LinkList head, int i) {
	ListNode *p, *r;
	int j = 0;
	p = head;

	// get prev
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}

	r = p;
	if (r->next != NULL)
		p->next = r->next->next;
	free(r);
}

void transform_linkedlist(LinkList head) {
}
LinkList merge_linkedlists(LinkList src_list, LinkList target_list) {
	return 0;
}

void print_linkedlist(LinkList head) {
	ListNode *p;
	if (head == NULL) {
		printf("wrong input, or error");
		exit(1);
	}

	p = head;
	while (p != NULL) {
		printf("%c\n", p->data);
		p = p->next;
	}
}

