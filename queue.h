/*
 * queue.h
 *
 *  Created on: Dec 25, 2015
 *      Author: guy
 */

#ifndef QUEUE_H_
#define QUEUE_H_

typedef struct queue_node{
	void *data;
	struct queue_node *previous;
} Node;

typedef struct queue{
	int length;
	Node *queue_head;
	Node *last_in_line;
} Queue;

Queue *init();

void push(Queue *q, void *data);

void destroy(Queue *q, void (*gc)(void*));

void *pull(Queue *q);

void *head(Queue *q);

#endif /* QUEUE_H_ */
