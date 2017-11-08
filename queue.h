/*
 * queue.h
 *
 *  Created on: Dec 25, 2015
 *      Author: guy
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#define container_of(ptr, type, member) ({                 \
	const typeof( ((type*)0)->member ) *__mptr = (ptr);   \
	__mptr ? (type*)((char*)__mptr - offsetof(type,member)) : NULL;})

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

void destroy(Queue *q, void (*gc)(Node*));

Node *pull(Queue *q);
#define pull_data(q,type,member) container_of(pull(q),type,member)

Node *head(Queue *q);
#define head_data(q,type,member) container_of(head(q),type,member)

#endif /* QUEUE_H_ */

