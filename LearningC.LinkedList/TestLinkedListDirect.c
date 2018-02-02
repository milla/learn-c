#include "stdafx.h"
#include "TestLinkedListDirect.h"

void TestLinkedListDirect() {
	LinkList list1 = test_create_list_into_head();
	LinkList list2 = test_create_list_into_tail();
	printf("after insert '1' at 0\n");
	LinkList list2r = insert_into_linkedlist(list2, 0, '1');
	read_linkedlist(list2r);
	printf("after insert '2' at 1\n");
	list2r = insert_into_linkedlist(list2, 1, '2');
	read_linkedlist(list2r);
	for (int i = 0; i < 5; i++) {
		printf("%d-%c\n", i, (get_node(list2r, i))->data);
	}
}

LinkList test_create_list_into_head() {
	printf("please input a (create_list_into_head):\n");
	LinkList head = create_list_into_head();
	read_linkedlist(head);

	return head;
}

LinkList test_create_list_into_tail() {
	printf("please input a (create_list_into_tail):\n");
	LinkList head = create_list_into_tail();
	read_linkedlist(head);

	return head;
}

LinkList test_create_list_into_tail_with_head() {
	printf("please input a (create_list_into_tail_with_head):\n");
	LinkList head = create_list_into_tail_with_head();
	read_linkedlist_with_head(head);

	return head;
}
