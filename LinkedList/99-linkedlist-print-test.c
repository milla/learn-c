#include <assert.h>
#include "stdafx.h"
#include "LinkedList.h"

void TestPrint() {
	int data[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	LinkList head = CreateByHead(data, sizeof(data)/ IntSize);
	Print(head);

	free(head);
}
