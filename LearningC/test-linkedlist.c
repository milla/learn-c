#include "stdafx.h"
#include "test-linkedlist.h"

void TestLinkedListMain() {
	//TestLinkedList();
	//TestLinkedListDirect();
	//TestSplitList();
	//TestMergeList();
	//TestTransformList();
	//test_create_list_by_tail_from_input();
	//TestTransformList();
	//test_insert_at_tail();
	//test_reverse_print_nohead();
	//TestMergeList_nohaed();
	//TestReverseList();
	//TestRemoveDuplicates();
	//TestFindMergeNode();
	TestDiffSorted();
	//TestSwitchNode();
}

void TestLinkedList() {
	LinkList list1 = test_create_list_into_tail();
	printf("after insert '1' at 1\n");
	insert_into_linkedlist(list1, 1, 'l');
	print_linkedlist(list1);
	printf("after insert '2' at 0\n");
	insert_into_linkedlist(list1, 0, '2');
	print_linkedlist(list1);

	for (int i = 0; i < 5; i++) {
		printf("%d-%c\n", i, (get_node(list1, i))->data);
	}
	print_linkedlist(list1);

	DataType data = remove_from_linkedlist(list1, 0);
	printf("%d\n", data);
	print_linkedlist(list1);

	remove_from_linkedlist(list1, 1);
	printf("%d\n", data);
	print_linkedlist(list1);
}

void TestSplitList() {
	int data[] = { 1,2,3,4,5,6,7,8,9,10 };
	LinkList head = create_list_by_array(data);
	printf("whole list\n");
	print_linkedlist_d(head);
	LinkList head_even = split_list_even(head);
	printf("head odd list\n");
	print_linkedlist_d(head);
	printf("head even list\n");
	print_linkedlist_d(head_even);
}

void TestMergeList() {
	int dataa[] = { 1,3,4,6, 9,11 };
	LinkList a = create_list_by_array(dataa);
	int datab[] = { 2,3,5,7,8,10,13,14 };
	LinkList b = create_list_by_array(datab);

	LinkList c = merge_sorted_linkedlist(a, b);

	printf("merge list\n");
	print_linkedlist_d(c);
}

void TestTransformList() {
	int data[] = { 1,2,3,4,5,6,7,8,9,10 };
	LinkList head = create_list_by_array(data);

	reverse_linkedlist(head);
	print_linkedlist_d(head);

	reverse_linkedlist(NULL);
}

void test_create_list_by_tail_from_input(int input[10], int len) {
	int data[] = { 1,2,3,4,5,6,7,8,9,10, 11 };
	LinkList head = create_list_by_tail_input(data);
	print_linkedlist_d(head);
}
LinkList test_create_list_into_tail() {
	printf("please input a (create_list_into_tail_with_head):\n");
	LinkList head = create_list_into_tail();
	print_linkedlist(head);

	return head;
}

void test_insert_at_tail() {
	int data[] = { 1,2,3,4,5,6,7,8,9,10 };
	LinkList head = create_list_by_tail_input_nohead(data);
	print_linkedlist_d_nohaed(head);
	head = InsertNth(head, 30, 0);
	print_linkedlist_d_nohaed(head);

	head = NULL;
	head = InsertNth(head, 30, 0);
	print_linkedlist_d_nohaed(head);
}

void test_reverse_print_nohead() {
	int data[] = { 1,2,3,4,5,6,7,8,9,10 };
	LinkList head = create_list_by_tail_input_nohead(data);
	ReversePrint(head);

	int data1[] = { 1 };
	head = create_list_by_tail_input_nohead(data1);
	ReversePrint(head);
}

void TestMergeList_nohaed() {
	int dataa[] = { 1,3,4,6, 9,11 };
	LinkList a = create_list_by_tail_input_nohead(dataa);
	print_linkedlist_d_nohaed(a);
	int datab[] = { 2,3,5,7,8,10,13,14 };
	LinkList b = create_list_by_tail_input_nohead(datab);
	print_linkedlist_d_nohaed(b);
	printf("merge list\n");
	LinkList c = MergeLists(a, b);

	print_linkedlist_d_nohaed(c);
}

void TestReverseList() {

	int dataa[] = { 1,2,3 };
	LinkList a = create_list_by_tail_input_nohead(dataa);
	print_linkedlist_d_nohaed(a);
	printf("\n");
	LinkList head = ReverseList(a);
	print_linkedlist_d_nohaed(head);

}

void TestRemoveDuplicates() {
	int dataa[] = { 1,1,2,3,3 };
	LinkList a = create_list_by_tail_input_nohead(dataa);
	print_linkedlist_d_nohaed(a);
	printf("\n");
	LinkList head = RemoveDuplicates(a);
	print_linkedlist_d_nohaed(head);
}

LinkList createList(int data[]) {
	LinkList a = create_list_by_tail_input_nohead(data);
	print_linkedlist_d_nohaed(a);
	printf("\n");
	return a;
}

void TestFindMergeNode() {
	int dataa[] = { 3,4,1,2,6,7,8 };
	LinkList a = createList(dataa);
	int datab[] = { 3,7,8 };
	LinkList b = createList(datab);

	int ret = FindMergeNode(a, b);
	printf("%d\n", ret);

}

void TestDiffSorted() {
	int dataa[] = { 3,4,6,7,8,12,99 };
	LinkList a = createList(dataa);
	int datab[] = { 3,5,7,8,20 };
	LinkList b = createList(datab);
	Node * ret = get_sorted_diff(a, b);
	print_linkedlist_d_nohaed(ret);
	printf("\nA:\n");
	print_linkedlist_d_nohaed(a);
	printf("\nB:\n");
	print_linkedlist_d_nohaed(b);

	printf("\n----------Next:\n");
	int dataa2[] = { 6,7,8,12,99 };
	a = createList(dataa2, 5);
	int datab2[] = { 5,7,8,9,10,11,12,20,100,120,122,130 };
	b = createList(datab2, 18);
	ret = get_sorted_diff(a, b);
	print_linkedlist_d_nohaed(ret);
	printf("\nA:\n");
	print_linkedlist_d_nohaed(a);
	printf("\nB:\n");
	print_linkedlist_d_nohaed(b);

	printf("\n---------Next:\n");
	int dataa3[] = { 3,6,7,8,12,99,130 };
	a = createList(dataa3);
	int datab3[] = { 5,7,8,20,100,120,122,130 };
	b = createList(datab3);
	ret = get_sorted_diff(a, b);
	print_linkedlist_d_nohaed(ret);
	printf("\nA:\n");
	print_linkedlist_d_nohaed(a);
	printf("\nB:\n");
	print_linkedlist_d_nohaed(b);
}


void TestSwitchNode() {
	int dataa[] = { 3,4,6,7};
	LinkList a = createList(dataa);
	Node * ret = switch_node(a, a->next->next);
	print_linkedlist_d_nohaed(ret);

	printf("\nNext:\n");
	a = createList(dataa);
	ret = switch_node(a, a);
	print_linkedlist_d_nohaed(ret);

	printf("\nNext:\n");
	a = createList(dataa, 4);
	ret = switch_node(a, a->next->next->next->next);
	print_linkedlist_d_nohaed(ret);
}


void TestJoinSorted() {
	int dataa[] = { 3,4,6,7,8,12,99 };
	LinkList a = createList(dataa);
	int datab[] = { 3,5,7,8,20 };
	LinkList b = createList(datab);

	Node * ret = get_sorted_join(a, b);
	print_linkedlist_d_nohaed(ret);

	printf("\nNext:\n");
	int dataa2[] = { 3,4,6,7,8,12,99 };
	a = createList(dataa2);
	int datab2[] = { 5,3, 7,8,20,100,120,122,130 };
	b = createList(datab2);

	ret = get_sorted_join(a, b);
	print_linkedlist_d_nohaed(ret);
}
