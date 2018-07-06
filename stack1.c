#include <stdio.h>
#include <stdlib.h>

#define EMPTY_TOP_OF_STACK (-1)

struct stackRecord {
	int capacity;
	int topOfStack;
	int *array;
};

void push(int val, struct stackRecord *stack);
void pop(struct stackRecord *stack);
int top(struct stackRecord *stack);
struct stackRecord *createStack(int capacity);
int isEmpty(struct stackRecord *stack);
int isFull(struct stackRecord *stack);


void push(int val, struct stackRecord *stack)
{
	if (isFull(stack)) {
		fprintf(stderr,"empty full!");
		exit(1);
	}
	stack->array[++stack->topOfStack] = val;
}

void pop(struct stackRecord *stack)
{
	if (isEmpty(stack))
		fprintf(stderr,"empty stack!");
	else
		stack->topOfStack--;
}

int top(struct stackRecord *stack)
{
	if(!isEmpty(stack))
		return stack->array[stack->topOfStack];
	fprintf(stderr,"empty stack!");
	return 0;
}

struct stackRecord *createStack(int capacity)
{
	struct stackRecord *stack;

	stack = malloc(sizeof(struct stackRecord));
	stack->array = malloc(sizeof(int) * capacity);
	stack->capacity = capacity;
	stack->topOfStack = EMPTY_TOP_OF_STACK;
	return stack;
}

int isEmpty(struct stackRecord *stack)
{
	return stack->topOfStack == EMPTY_TOP_OF_STACK;
}

int isFull(struct stackRecord *stack)
{
	return stack->topOfStack == stack->capacity - 1;
}
