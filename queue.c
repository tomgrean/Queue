#include "queue.h"
#include <malloc.h>
#include <string.h>

/*
 * Queue *init()
 *
 * initializes a queue and return a pointer to it
 *
 */
Queue *init()
{
	/* allocate mem block */
	Queue *q = malloc(sizeof(Queue));
	if (q == NULL) {
		return NULL;
	}
	/* inittialize members */
	q->length = 0;
	q->queue_head = NULL;
	q->last_in_line = NULL;
	return q;
}

/*
 * void push(Queue *q, Node *element)
 *
 * pushes a node given the queue element
 * Note that there is a distinction in the code if the
 * queue is empty or not.
 *
 * return 0 on success, -1 on error.
 */
int push(Queue *q, Node *element)
{
	if (q == NULL || element == NULL) {
		return -1;
	}
	/* basically means if the queue is not empty */
	if(q->queue_head) {
		q->last_in_line->previous = element;
	} else {
		q->queue_head = q_node;
	}
	/* chaining everything to its place */
	q->last_in_line = element;
	q_node->previous = NULL;
	q->length++;
	return 0;
}

/*
 * void destroy(Queue *q)
 *
 * free all elements in a given queue
 * and destroys the queue.
 *
 */
void destroy(Queue *q, void (*gc)(Node*))
{
	if(q == NULL) {
		return;
	}
	while(q->queue_head) {
		Node *tmp = pull(q);
		if (gc) {
			gc(tmp);
		}
	}
	free(q);
}

/*
 * void *pull(Queue *q)
 *
 * get the head element of the given queue and return
 *
 */
Node *pull(Queue *q)
{
	Node *temp;

	if(q == NULL || q->queue_head == NULL) {
		/* queue is empty */
		return NULL;
	}
	temp = q->queue_head;
	q->queue_head = q->queue_head->previous;
	q->length--;
	return temp;
}

/*
 * void *head(Queue *q)
 *
 * returns the queue head (the first element)
 * given a pointer to a queue if it isn't pointing to
 * 0
 *
 */
Node *head(Queue *q)
{
	if (q) {
		return q->queue_head;
	}
	return NULL;
}

