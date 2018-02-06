#include <stdbool.h>
#include "Types.h"
#include <assert.h>

/*
void InitLLStack(LLStack s){
	s->top = NULL;
}

bool IsEmpty(LLStack s){
	if (!s) printf("Error! LLStack s is not referencecd.");
	
	bool ret = true;
	if (s) ret = s->top == -1;	
	return ret;
}

bool IsFull(LLStack s){
	if (!s) printf("Error! LLStack s is not referencecd.");

	bool ret = true;
	if (s) ret = (s->next != NULL);	
	return ret;
}

ValueType GetTop(LLStack s){
	if (!s) printf("Error! LLStack s is not referencecd.");
	
	ValueType top;	
	if (s) top = s->data;	
	return top;
}

LLStack Push(LLStack s, ValueType c){
	if (!s) printf("Error! LLStack s is not referencecd.");
	else {
		Node *n = (Node *)malloc(sizeof(Node));
		n->next = s;
		s = n;
		s->data = c;
	
		return s;
	}
}

ValueType Pop(LLStack s){
	ValueType top ;
	if (!s) printf("Error! LLStack s is not referencecd.");
	else if (IsEmpty(s)) printf("Warning! LLStack s is empty. Nothing to pop out.");
	else {
		top = s->data[s->top];
		s->top = s->top - 1;
	}
	return top;
}

void Dispose(LLStack s){
	if (!s) {}
	else if (IsEmpty(s))  {}
	else{
		int i;
		for (i = 0; i < s->top; i++){
			free(s->data[i]);
		}
	}
}

void Test01(){
	Stack s;
	InitStack(&s);
	Push(&s, 1);
	Push(&s, 2);
	Push(&s, 3);
	ValueType top = Pop(&s);
	Dispose(&s);
	assert(top == 3);
}
*/
