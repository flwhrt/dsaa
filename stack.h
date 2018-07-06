
struct node {
	int val;
	struct node *next;
};

void push(int val, struct node *stack);
void pop(struct node *stack);
int top(struct node *stack);
struct node *createStack(void);
int isEmpty(struct node *stack);
