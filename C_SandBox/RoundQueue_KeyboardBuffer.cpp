#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 80

char buf[MAX + 1];

int spos = 0;
int rpos = 0;

void qstore(char q);
char qretrieve(void);

void KeyboardBuffer_main(void)
{
	register char ch;
	int t;

	buf[80] = NULL;
	for (ch = ' ', t = 0; t < 32000 && ch != '\r'; ++t)
	{
		if (kbhit()) {
			ch = getch();
			qstore(ch);
		}
		printf("%d", t);
		if (ch == '\r') {
			printf("\n");
			while ((ch = qretrieve()) != NULL) printf("%c", ch);
			printf("\n");
		}
	}
}

void qstore(char q)
{
	if ((spos + 1 == rpos) || (spos + 1 == MAX && !rpos)) {
		printf("Full Queue");
		return;
	}
	buf[spos] = q;
	spos++;
	if (spos == MAX)spos = 0;
}

char qretrieve(void)
{
	if (rpos == MAX) rpos = 0;
	if (rpos == spos) return NULL;

	rpos++;
	return buf[rpos - 1];
}