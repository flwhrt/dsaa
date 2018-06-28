#include <stdlib.h>
#include "list.h"

struct node {
	int val;
	struct node *next;
};


struct node *createList()
{

	struct node *list;
	struct node *lastNode;

	list = malloc(sizeof(struct node));
	list->val = 5;
	list->next = NULL;
	lastNode = list;

	lastNode->next = malloc(sizeof(struct node));
	lastNode = lastNode->next;
	lastNode->val = 6;
	lastNode->next = NULL;

	return list;
}

struct node *makeEmpty(struct node *list)
{
	return NULL;
}

int isEmpty(struct node *list)
{
	return list == NULL;
}

int isLast(struct node *position, struct node *list)
{
	return position->next == NULL;
}

struct node *find(int val, struct node *list)
{
	struct node *p;

	p = list;
	while (p != NULL && p->val != val)
		p = p->next;
	return p;
}

void delete(int val, struct node *list)
{
	struct node *pre, *temp;

	pre = findPrevious(val, list);

	if (pre != NULL) {
		temp = pre->next;
		pre->next = temp->next;
		free(temp);
	}
}

struct node *findPrevious(int val, struct node *list)
{
	return NULL;
}

void insert(int val, struct node *list, struct node *position)
{
}

void deleteList(struct node *list)
{
}

struct node *header(struct node *list)
{
	return NULL;
}

struct node *first(struct node *list)
{
	return NULL;
}

struct node *advance(struct node *position)
{
	return NULL;
}

int retrieve(struct node *position)
{
	return 0;
}
