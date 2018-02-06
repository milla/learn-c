#define ListSize 100
#define IntSize sizeof(1)
#define NullInt -20000

typedef int DataType;

typedef struct Node {
	struct Node* next;
	int data;
} Node;

typedef struct dnode {
	struct dnode* next;
	struct dnode* prev;
	int data;
} Dnode;

typedef Node *LinkList;

struct ListNode {
    int val;
    struct ListNode *next;
 };
#pragma once
