#include <stdbool.h>
#include "Types.h"
#include <assert.h>

void InitStack(Stack *s){
	s->top = -1;
}

bool IsEmpty(Stack *s){
	if (!s) printf("Error! Stack s is not referencecd.");
	
	bool ret = true;
	if (s) ret = s->top == -1;	
	return ret;
}

bool IsFull(Stack *s){
	if (!s) printf("Error! Stack s is not referencecd.");

	bool ret = true;
	if (s) ret = s->top == STACK_SIZE - 1;	
	return ret;
}

ValueType GetTop(Stack *s){
	if (!s) printf("Error! Stack s is not referencecd.");
	
	ValueType top;	
	if (s) top = s->data[s->top];	
	return top;
}

void Push(Stack *s, ValueType c){
	if (!s) printf("Error! Stack s is not referencecd.");
	else {
		s->top = s->top + 1;
		s->data[s->top] = c;
	}
}

ValueType Pop(Stack *s){
	ValueType top ;
	if (!s) printf("Error! Stack s is not referencecd.");
	else if (IsEmpty(s)) printf("Warning! Stack s is empty. Nothing to pop out.");
	else {
		top = s->data[s->top];
		s->top = s->top - 1;
	}
	return top;
}

void Clear(Stack *s){
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
	Clear(&s);
	assert(top == 3);
}
