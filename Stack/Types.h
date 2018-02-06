#define IntSize sizeof(1)
#define NullInt -20000
#define STACK_SIZE 10000

typedef char ValueType;
typedef struct Node {
	struct Node *next;
	int data;
} Node;

typedef struct SequentialStack {
	int size;
	int top;
	ValueType data[STACK_SIZE];
} Stack;

typedef Node * LLStack;	
