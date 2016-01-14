#include <stdio.h>
#include "queue.h"
/* TODO: test everything and finish the header file */

int main()
{
	unsigned long repeat = 1000000;
	int q_length;
	printf("Checking what happens if we do not free resources...");
	getchar();

	for(; repeat > 0; repeat--)
	{
		Queue *q = init();
		for(q_length = 1000; q_length > 0; q_length--)
		{
			push(q, q_length);
		}
		printf("%ld\n", repeat);
		destroy(q);
	}


	return 0;
}
