#include "stdio.h"
#include "string.h"


#define MAX 100

char* p[MAX];

int spos = 0;
int rpos = 0;

/* Store a value*/
void qstore(char* q)
{
	if (spos == MAX)
	{
		printf("Lista este plina \n");
		return;
	}
	p[spos] = q;
	spos++;
}

/* Retrieve a value*/
char* qretrieve(void)
{
	if (rpos == spos)
	{
		printf("There are is no more data \n");
		return NULL;
	}

	rpos++;
	return p[rpos - 1];
}
