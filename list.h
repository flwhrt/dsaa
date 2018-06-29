#ifndef LIST_H
#define LIST_H

struct node {
	int val;
	struct node *next;
};


struct node *createList();
struct node *makeEmpty(struct node *list);
int isEmpty(struct node *list);
int isLast(struct node *position, struct node *list);
struct node *find(int val, struct node *list);
void delete(int val, struct node *list);
struct node *findPrevious(int val, struct node *list);
void insert(int val, struct node *list, struct node *position);
void deleteList(struct node *list);
struct node *header(struct node *list);
struct node *first(struct node *list);
struct node *advance(struct node *position);
int retrieve(struct node *position);

#endif
