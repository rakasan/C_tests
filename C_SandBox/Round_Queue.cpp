#include "stdio.h"
#include "string.h"

#define MAX 100

char* p[MAX];

int spos = 0;
int rpos = 0;
void qstore(char* q)
{
	if ((spos + 1 == rpos) || (spos + 1 == MAX && !rpos)) {
		printf("Full queue");
		return;
	}
	p[spos] = q;
	spos++;
	if (spos == MAX) spos = 0;
}

/* Retrieve a value*/
char* qretrieve(void)
{
	if (rpos == MAX) rpos = 0;
	if (rpos == spos)
	{
		printf("There are is no more data \n");
		return NULL;
	}

	rpos++;
	return p[rpos - 1];
}