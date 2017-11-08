#include "queue.h"
#include <malloc.h>
#include <string.h>

static Node *init_node(void *data);

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
 * void push(Queue *q, void *data)
 *
 * pushes a node given the queue, the data and the size of the data
 * into the queue.
 * Note that there is a distinction in the code if the
 * queue is empty or not.
 *
 */
void push(Queue *q, void *data)
{
	Node *q_node = init_node(data);
	/* basically means if the queue is not empty */
	if(q->queue_head) {
		q->last_in_line->previous = q_node;
	} else {
		q->queue_head = q_node;
	}
	/* chaining everything to its place */
	q->last_in_line = q_node;
	q_node->previous = NULL;
	q->length++;
}

/*
 * void destroy(Queue *q)
 *
 * free all elements in a given queue
 * and destroys the queue.
 *
 */
void destroy(Queue *q, void (*gc)(void*))
{
	if(q == NULL) {
		return;
	}
	while(q->queue_head) {
		void *tmp = pull(q);
		if (gc) {
			gc(tmp);
		}
	}
	free(q);
}

/*
 * void *pull(Queue *q)
 *
 * free the head element of the given queue and returns
 * its data
 *
 */
void *pull(Queue *q)
{
	void *data;
	Node *temp;

	if(q == NULL || q->queue_head == NULL) {
		/* queue is empty */
		return NULL;
	}
	data = q->queue_head->data;
	temp = q->queue_head;
	q->queue_head = q->queue_head->previous;
	free(temp);
	q->length--;
	return data;
}

/*
 * void *head(Queue *q)
 *
 * returns the data inside queue head (the first element)
 * given a pointer to a queue if it isn't pointing to
 * 0
 *
 */
void *head(Queue *q)
{
	if (q) {
		return q->queue_head->data;
	}
	return NULL;
}

/*
 * Node *init_node(void *data)
 *
 * initialize a node - allocate size using malloc
 * for the node and the data, and return the node
 *
 */
static Node *init_node(void *data)
{
	Node *q_node = malloc(sizeof(Node));
	/* terminate if malloc has failed to allocate */
	if (q_node == NULL) {
		return NULL;
	}
	q_node->data = data;
	q_node->previous = NULL;
	return q_node;
}
