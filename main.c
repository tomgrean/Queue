#include <stdio.h>
#include <malloc.h>
#include "queue.h"
/* TODO: test everything and finish the header file */

typedef struct {
	int id;
	Node n;
}msgq;

void freemsgq(Node *p) {
	free(container_of(p, msgq, n));
}
int main()
{
	unsigned long repeat = 1000000;
	int q_length;
	printf("Checking what happens if we do not free resources...");
	getchar();

//	for(; repeat > 0; repeat--)
	{
		Queue *q = init();
		for(q_length = 100; q_length > 0; q_length--)
		{
			msgq *m = malloc(sizeof(msgq));
			m->id = q_length;
			push(q, &m->n);
		}
		printf("%ld\n", repeat);
		Node *temp = pull(q);
		msgq *ms = container_of(temp, msgq, n);
		printf("pulled = %d\n", ms->id);
		free(ms);
		ms = pull_data(q, msgq, n);
		printf("pulled2 = %d\n", ms->id);
		free(ms);
		destroy(q, freemsgq);
	}


	return 0;
}
