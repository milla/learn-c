#define ListSize 100
#define IntSize sizeof(1)
#define NullInt -20000

typedef int DataType;

typedef struct Node {
	struct Node* next;
	int data;
} Node;

typedef Node *LinkList;
#pragma once
