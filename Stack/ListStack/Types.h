typedef char ValueType;
typedef struct Node {
	struct Node *next;
	ValueType data;
} Node;
typedef Node * Stack;	
