#include <stdbool.h>
#include "Types.h"
#include <stdlib.h>
#include <assert.h>

Stack InitStack(Stack s){
	s = (Stack)malloc(sizeof(Node));
	s->data = NULL;
	s->next = NULL;	
	
	return s;
}

bool IsEmpty(Stack s){
	if (!s) printf("Error! Stack s is not referencecd.");
	
	bool ret = true;
	if (s) ret = s->next == NULL;	
	return ret;
}

ValueType Peek(Stack s){
	ValueType top;	
	if (s && !IsEmpty(s)) top = s->data;	
	
	return top;
}

Stack Push(Stack s, ValueType c){
	if (!s) return s;
	else {
		Node *n = (Node *)malloc(sizeof(Node));
		n->data = c;
		n->next = s;
		
		return n;
	}
}

Stack Pop(Stack s, ValueType *top){
	Node *n = s;
	
	if (!s) return s;
	else if (IsEmpty(s)) {
		printf("Underflow");
		exit(1);
	}
	else {
		*top = s->data;
		n = s->next;
		s->next = NULL;
		free(s);
	}
	return n;
}

void Clear(Stack s){
	Node *p;
	while ((p = s->next)){
		s->next = NULL;
		free(s); 
		s = p;
	}
}

void Print(Stack head) {
	Node *p;
	
	if (head == NULL) {
		printf("wrong input, or error");
		return;
	}

	// check whether contains head node
	if (head->data) {
		p = head;
	}
	else {
		p = head->next;
	}

	printf("\n");
	while (p && p->data) {
			printf("%c\n", p->data);
		p = p->next;
	}
}

void Test01(){
	Stack s;
	s = InitStack(s);
	assert(IsEmpty(s) == true);
	s = Push(s, 'a');
	assert(IsEmpty(s) == false);
	s = Push(s, 'b');
	s = Push(s, 'c');
	Print(s);
	ValueType top;
	ValueType *t = &(top);
	s = Pop(s, t);
	assert(top == 'c');
	assert(Peek(s) == 'b');
	
	Clear(s);
}
