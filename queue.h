/*
 * queue.h
 *
 *  Created on: Dec 25, 2015
 *      Author: guy
 */

#ifndef QUEUE_H_
#define QUEUE_H_

typedef struct queue_node{
	struct queue_node *previous;
} Node;

typedef struct queue{
	int length;
	Node *queue_head;
	Node *last_in_line;
} Queue;

Queue *init();

int push(Queue *q, Node *element);

void destroy(Queue *q, void (*gc)(void*));

Node *pull(Queue *q);

Node *head(Queue *q);

#endif /* QUEUE_H_ */

