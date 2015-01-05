#include "pqueue.c"
#include <stdio.h>

PQueue pq;
int n, t;
infotype x;

int main() 
{
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &t);
		if (t == 1)
		{
			scanf("%d", &x);
			PQPush(&pq, x);
		}
		else
		{
			PQPop(&pq, &x);
			printf("Poop %d\n", x);
		}
	}
}