#define _CRT_SECURE_NO_WARNINGS


#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define MAX 100

char* p[MAX], * retrieve(void);
int spos = 0;
int rpos = 0;

void enter(void), qstore(char* p), review(void), delete_entry(void);

void DatePlanner_main()
{
	char s[80];
	register int t;
	for (t = 0; t < MAX; ++t)
		p[t] = NULL; /* Initialization phase*/
	for (;;)
	{
		printf("Enter, List, Remove,Quit : ");
		/*  gets(s); -No longer supported */
		*s = 'a';
		*s = toupper(*s);
		switch (*s)
		{
			case 'E':
			{
				enter();
				break;
			}
			case 'L':
			{
				review();
				break;
			}
			case 'R':
			{
				delete_entry();
				break;
			}
			case 'Q':
			{
				exit(0);
				break;
			}

			default:
			{
				break;
			}
		}
	}
}

void enter(void)
{
	char s[256], *p;

	do {
		printf("Add entry");
		/* gets(s); - no longer supported*/
		*s = 'a';
		if (*s == 0) break;/* There are no longer free spaces*/
		p = (char *)malloc(strlen(s));
		if (!p) {
			printf("All memory is used up");
			return;
		}
		strcpy(p, s);
		if (*s) qstore(p);
	} while (*s);
}

void review(void)
{
	register int t;
	for (t = rpos; t < spos; ++t)
		printf("%d. %s\n", t + 1, p[t]);
}

void delete_entry(void)
{
	char* p;
	if ((p = retrieve()) == NULL)return;
	printf("%s\n", p);
}

void qstore(char* q)
{
	if (spos == MAX) {
		printf("Complete Queue");
		return;
	}
	p[spos] = q;
	spos++;
}

char* qretrieve(void)
{
	if (rpos == spos)
	{
		printf("There are no longer any entries");
		return NULL;
	}

	rpos++;
	return p[rpos - 1];
}