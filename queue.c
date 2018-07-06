#include <stdlib.h>
#include <stdio.h>

struct queue {
	int capacity;
	int front;
	int rear;
	int size;
	int *vals;
};

int isEmpty(struct queue *qp);
int isFull(struct queue *qp);
struct queue *createQueue(int capacity);
void enqueue(int val, struct queue *qp);
int dequeue(struct queue *qp);


int isEmpty(struct queue *qp)
{
	return qp->size == 0;
}

int isFull(struct queue *qp)
{
	return qp->size == qp->capacity;
}

struct queue *createQueue(int capacity)
{
	struct queue *qp;

	qp = malloc(sizeof(struct queue));
	qp->capacity = capacity;
	qp->front = 0;
	qp->rear = 0;
	qp->size = 0;
	qp->vals = malloc(sizeof(int) * capacity);
	return qp;
}

static int succ(int value, struct queue *qp)
{
	if (++value == qp->capacity)
		value = 0;
	return value;
}

void enqueue(int val, struct queue *qp)
{
	if (isFull(qp)) {
		fprintf(stderr, "queue is full\n");
		return;
	}
	qp->size++;
	qp->vals[qp->rear] = val;
	qp->rear = succ(qp->rear, qp);
}

int dequeue(struct queue *qp)
{
	int val;

	if(isEmpty(qp)) {
		fprintf(stderr, "queue is empty!\n");
		exit(1);
	}
	qp->size--;
	val = qp->vals[qp->front];
	qp->front = succ(qp->front, qp);
	return val;
}

int main(void)
{
	struct queue *qp;
	int i;

	qp = createQueue(5);
	enqueue(1, qp);
	enqueue(2, qp);
	enqueue(3, qp);
	enqueue(4, qp);
	enqueue(5, qp);
	for (i = 6; i < 10; i++) {
		printf("%d\n", dequeue(qp));
		enqueue(i, qp);
	}

	while(!isEmpty(qp))
		printf("%d\t", dequeue(qp));
	printf("\n");
	return 0;
}
