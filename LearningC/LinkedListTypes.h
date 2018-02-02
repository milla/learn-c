#define ListSize 100

typedef int DataType;

typedef struct Node {
	struct Node* next;
	int data;
} Node;

typedef Node *LinkList;
#pragma once
