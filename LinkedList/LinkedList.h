#pragma once
#include <stdbool.h>
#include "stdafx.h"

/*0-linkedlist-create*/
LinkList CreateByTailConsole();
LinkList CreateByHead(int data[], int len);
LinkList CreateByTailWithHead(int input[], int len);
LinkList CreateByTail(int input[], int len);
LinkList CreateCycleListByTail(int input[], int len);
Dnode* GetNthDnode(Dnode *head, int position);

/*1-linkedlist-print*/
void Print(LinkList head);

/*2-linkedlist-insert*/
Node* InsertAtTail(Node *head, int data);
Node* InsertAtHead(Node *head, int data);
Node* InsertNth(Node *head, int data, int position);

/*3-linkedlist-delete*/
Node* DeleteNth(Node *head, int position);
Node* Delete(Node* head, int val);
Node* RemoveNthFromEnd(Node* head, int n);

/*4-linkedlist-reverse*/
void ReversePrint(Node *head);
Node* Reverse(Node *head);
Node* ReverseList(Node *head);
Node* SwitchNode(Node *head, Node * t);
Dnode * ReverseDoublyList(Dnode *head);
Node *SwapPairs(Node *head);

/*5-linkedlist-compare*/
int CompareLists(Node *headA, Node* headB);

/*6-linkedlist-merge*/
Node* MergeLists(Node *headA, Node* headB);
Node* MergeLists2(Node *headA, Node* headB);
LinkList MergeTwoSorted(LinkList heada, LinkList headb);
Node* MergeKLists(Node** lists, int listsSize) ;


/*7-linkedlist-get*/
int GetNthFromTail(Node *head, int positionFromTail);
int GetLength(Node *head);
int GetNth(Node *head, int positionFromTail);

/*8-linkedlist-distinct*/
Node* RemoveDuplicates(Node *head);
Node* RemoveDuplicates2(Node *head);

/*9-linkedlist-cycle-detection*/
bool HasCycle(Node* head);
bool HasCycle2(Node* head);

/*10-linkedlist-find-merge-point*/
int FindMergeNode1(Node *headA, Node *headB);
int FindMergeNode2(Node *headA, Node *headB);
int FindMergeNode3(Node *headA, Node *headB);
int FindMergeNode4(Node *headA, Node *headB);

/*11-linkedlist-split*/
LinkList SplitToEvenOdd(LinkList head);
Node** SplitListToParts(Node* root, int k, int* returnSize) ;
 
/*12-linkedlist-intersect*/
Node* Intersect(Node *heada, Node *headb);

/*13-linkedlist-diff*/
Node* Diff(Node *heada, Node *headb);

/*14-*/
Node* AddTwoNumbers(Node *l1, Node *l2);
