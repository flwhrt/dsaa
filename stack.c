#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

void push(int val, struct node *stack)
{
	struct node *tmpNode;

	tmpNode = malloc(sizeof(struct node));
	if (tmpNode == NULL) {
		fprintf(stderr, "malloc fail\n");
		exit(1);
	}
	tmpNode->val = val;
	tmpNode->next = stack->next;
	stack->next = tmpNode;
}

void pop(struct node *stack)
{
	struct node *tmpNode;
	if(isEmpty(stack)) {
		fprintf(stderr, "pop node on a empty stack\n");
		exit(1);
	}
	tmpNode = stack->next;
	stack->next = tmpNode->next;
	free(tmpNode);
}

int top(struct node *stack)
{
	if(!isEmpty(stack)) {
		return stack->next->val;
	}
	fprintf(stderr, "empty stack!");
	return 0;
}

struct node *createStack(void)
{
	struct node *stack;

	stack = malloc(sizeof(struct node));
	if (stack == NULL) {
		fprintf(stderr, "malloc fail\n");
		exit(1);
	}
	stack->next = NULL;
	return stack;
}

int isEmpty(struct node *stack)
{
	if (stack == NULL) {
		fprintf(stderr, "malloc fail\n");
		exit(1);
	}
	return stack->next == NULL;
}

