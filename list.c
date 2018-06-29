#include <stdlib.h>
#include "list.h"


struct node *createList()
{

	struct node *list;

	list = malloc(sizeof(struct node));
	list->val = 0;
	list->next = NULL;

	return list;
}

struct node *makeEmpty(struct node *list)
{
	if (!isLast(list->next, list)) {
		makeEmpty(list->next);
	}
	free(list->next);
	list->next = NULL;
	return list;
}

int isEmpty(struct node *list)
{
	return list->next == NULL;
}

int isLast(struct node *position, struct node *list)
{
	return position->next == NULL;
}

struct node *find(int val, struct node *list)
{
	struct node *p;

	p = list->next;
	while (p != NULL && p->val != val)
		p = p->next;
	return p;
}

void delete(int val, struct node *list)
{
	struct node *previous, *target;

	previous = findPrevious(val, list);
	if (!isLast(previous, list)) {
		target = previous->next;
		previous->next = target->next;
		free(target);
	}
}

struct node *findPrevious(int val, struct node *list)
{
	struct node *p;

	p = list;
	while (p->next != NULL && p->next->val != val)
		p = p->next;
	return p;
}

void insert(int val, struct node *list, struct node *position)
{
	struct node *target;

	target = malloc(sizeof(struct node));
	target->val = val;
	target->next = position->next;
	position->next = target;
}

void deleteList(struct node *list)
{
	makeEmpty(list);
	free(list);
}

struct node *header(struct node *list)
{
	return list;
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
