/*
 * queue.h
 *
 *  Created on: Dec 25, 2015
 *      Author: guy
 */

#ifndef QUEUE_H_
#define QUEUE_H_

typedef struct queue_node{
	int data;
	struct queue_node *previous;
} Node;


typedef struct queue{
	int length;
	Node *queue_head;
	Node *last_in_line;

} Queue;

Queue *init();

void push(Queue *q, int data);

void destroy(Queue *q);

int pull(Queue *q);

int head(Queue *q);

#endif /* QUEUE_H_ */
