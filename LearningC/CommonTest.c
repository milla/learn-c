#include "stdafx.h"
#include "CommonTest.h"

void TestCommonTestMain() {
	test_increase_pointer_by_integer();
	test_reference_param();
}

void test2() {
	int n;
	scanf_s("%d", &n);
	long int ret = test1(n);
	printf("%d", ret);
}

static test1(int n) {
	if (n <= 1) return 1;
	return n * test1(n - 1);
}

void testPointer() {

	Node *a = (Node *)malloc(sizeof(Node));
	Node *b = a;
	Node *c = b;
	a->data = 2;

	struct Node* nod = (struct node*)malloc(sizeof(struct Node));
	(*nod).data = 20;
	nod->data = 20;

	int* ptr;
	int i = 6;
	ptr = i;
	int* ptr2;
	ptr2 = &(i);
	*ptr2 = (i);
}

void testString()
{
	char string[20];
	strcpy(string, "binkys");
	char tmp;
	int len = strlen(string);
	//两种方法，1. 取一半长度，首尾交换，2.增加变量j，从尾部计数，递减，直到i>=j停止 
	for (int i = 0;i < len / 2;i++) {
		tmp = string[i];
		string[i] = string[len - i - 1];
		string[len - i - 1] = tmp;
	}
}
void swap_xy(int *x, int *y) {
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void test_reference_param() {
	int a, b;
	a = 6;
	b = 8;
	swap_xy(&(a), &(b));
}

void test_array2() {
	Node* list[10];
	for (int i = 0;i < 10;i++) {
		list[i] = (Node*)malloc(sizeof(Node));
		list[i]->data = i;
	}

	for (int i = 0;i < 10;i++) {
		Node *a = *(list + i);
		printf("%d\n", a->data);
		free(a);
	}
}

void test_array() {
	int listint[10];
	for (int i = 0;i < 10;i++) {
		listint[i] = i;
	}

	for (int i = 0;i < 10;i++) {
		int *a = listint + i;
		printf("%d\n", *a);
	}
}

void test_increase_pointer_by_integer() {
	int *p;
	int i = 4;
	p = &(i); // &(6)不合法，只能是变量
	printf("%d\n", p);//e.g., 7337576
	p = p + 12; // 指针向前移动12个字节，但因为p的size是int，有可能int占用4字节，故这儿是加了48字节
				// 前移一个sizeof(pointee)
	printf("%d\n", p); //e.g., 7337624, 增加了48字节
					   //如果只想要加12字节，可以转为char类型指针再增加
	p = (int*)((char*)p + 12);
	printf("%d\n", p); //e.g., 7337636, 增加了48字节
}