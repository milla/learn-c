#include "stdafx.h"
#include "LinkedList.h"
#include <assert.h>

void TestDeleteNth() {
	int data[] = { 1,2,3,4,5,6,7,8,9,10,11 };
	int len = sizeof(data) / IntSize;
	LinkList head = CreateByHead(data, len);

	head = DeleteNth(head, 0);
	assert(GetNth(head, 0) == 2);
	assert(GetLength(head) == len - 1);

	len--;
	head = DeleteNth(head, 50);
	assert(GetNth(head, len) == 11);
	assert(GetLength(head) == len);

	head = DeleteNth(head, 3);
	assert(GetNth(head, 3) == 5);
	assert(GetLength(head) == len-1);

}