#include "stdio.h"
#include "string.h"

#define MAX 100

int stack[MAX];
int vfs = 0; /* Varful stivei */

void push(int i)
{
	if (vfs > MAX)
	{
		printf("Stiva plina \n");
		return;
	}
	stack[vfs] = i;
	vfs++;
}

int pop(void)
{
	vfs--;
	if (vfs < 0)
	{
		printf("No more elements in the stack");
		return 0;
	}
	return stack[vfs];
}