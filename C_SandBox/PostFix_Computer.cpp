#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int* p;
int* vfs;
int* bzs;

void push(int i);
int pop(void);

void PostFix_main(void)
{
	int a, b;
	char s[80];

	p = (int*) malloc(MAX * sizeof(int)); /* allocate the memory size*/
	
	if (!p)
	{
		printf("There is no memory available");
		exit(1);
	}

	vfs = p;
	bzs = p + MAX - 1;

	do {
		printf(": ");
		/* gets(s);  - no longer supported */
		*s = '+';
		switch (*s)
		{
			case '+' :
			{
				a = pop();
				b = pop();
				push(a + b);
				break;
			}

			case '-':
			{
				a = pop();
				b = pop();
				push(a - b);
				break;
			}

			case '*':
			{
				a = pop();
				b = pop();
				push(a * b);
				break;
			}

			case '/':
			{
				a = pop();
				b = pop();
				if (b == 0) {
					printf("Devide by 0 is not allowed");
					break;
				}
				push(a / b);
				break;
			}
			case '.': /*  Show the top of the stack*/
			{
				a = pop();
				push(a);
				printf("Top values is %d", a);
				break;
			}

			default:
			{
				push(atoi(s));
			}
		}

	} while (*s != 'q');
}

void push(int i)
{
	if (p > bzs)
	{
		printf("Full Stack");
	}
	*p = i;
	p++;
}

int pop(void)
{
	p--;
	if (p < vfs)
	{
		printf("Underflow in progress");
		return 0;
	}

	return* p;
}