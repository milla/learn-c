#pragma once
#include <stdbool.h>
#include "stdafx.h"

LinkList create_list_into_head();
LinkList create_list_into_tail();
Node *get_node(LinkList list, int i);
DataType remove_from_linkedlist(LinkList list, int i);
LinkList transform_linkedlist(LinkList head);
LinkList merge_linkedlists(LinkList src_list, LinkList target_list);
void print_linkedlist(LinkList list);
void print_linkedlist_d(LinkList list);
void print_linkedlist_d_nohaed(LinkList head);
LinkList create_list_by_array(int data[]);
LinkList split_list_even(LinkList head);
LinkList create_list_by_tail_input(int input[10]);
LinkList create_list_by_tail_input_nohead(int input[10]);
void reverse_linkedlist(LinkList head);
Node* Insert(Node *head, int data);
Node* InsertNth(Node *head, int data, int position);
void ReversePrint(LinkList head);
Node* ReverseList(Node *head);
Node* ReverseList_mine(Node *head);
Node* RemoveDuplicates(Node *head);
int FindMergeNode(Node *headA, Node *headB);
Node * get_sorted_diff(Node *heada, Node *headb);
Node * switch_node(Node *head, Node * p);
Node * get_sorted_join(Node *heada, Node *headb);
