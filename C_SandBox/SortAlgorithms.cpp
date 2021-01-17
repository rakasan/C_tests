#include "stdio.h"
#include "string.h"
/* Bubble sort*/ 
/* Bubble: test steps
	initial : dcab
	Step 1 : adcb
	Step 2 : abdc
	Step 3 : abcd*/
void bubbleSort(char* tab, int contor)
{
	register int a, b;
	register char t;
	for(a=1;a<contor;++a)
		for(b= contor-1;b>=1;--b)
			if (tab[b - 1] > tab[b])
			{
				t = tab[b - 1];
				tab[b - 1] = tab[b];
				tab[b] = t;
			}
}

void selectSort(char* tab, int contor)
{
	register int a, b, c;
	int schimb;
	char t;

	for (a = 0; a < contor - 1; ++a)
	{
		schimb = 0;
		c = a;
		t = tab[a];
		for (b = a + 1; b < contor; ++b)
		{
			if (tab[b] > t)
			{
				c = b;
				t = tab[b];
				schimb = 1;

			}
		}
		if (schimb == 1)
		{
			tab[c] = tab[a];
			tab[a] = t;
		}
	}
}

/*  Insert Sort*/
void insertSort(char* element, int contor)
{
	register int a, b;
	char t;
	for (a = 1; a < contor; ++a)
		t = element[a];
	for (b = a - 1; b >= 0 && t < element[b]; b--)
		element[b + 1] = element[b];
		element[b + 1] = t;
}

/* ShellSort  */
void shellSort(char* tab, int contor)
{
	register int i, j, pas, k;
	char x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;
	for (k = 0; k < 5; k++)
	{
		pas = a[k];
		for (i = pas; i < contor; ++i)
		{
			x = tab[i];
			for (j = i - pas; x < tab[j] && j >= 0; j = j - pas)
				tab[j + pas] = tab[j];
			tab[j + pas] = x;
		}
	}
}
void qs(char* tab, int stanga, int dreapta)
{
	register int i, j;
	char x, y;

	i = stanga; j = dreapta;

	x = tab[(stanga + dreapta) / 2];

	do {
		while (tab[i] < x && i < dreapta) i++;
		while (x < tab[j] && j > stanga) j--;

		if (i <= j) {
			y = tab[i];
			tab[i] = tab[j];
			tab[j] = y;
			i++; j--;
		}
	} while (i <= j);

		if (stanga < j) qs(tab, stanga, j);
		if (i < dreapta) qs(tab, i, dreapta);
}

void quickSort(char* tab, int cont)
{
	qs(tab, 0, cont - 1);
}


/*  Character stream sort*/
void qs_string(char tab[][10], int stg, int drp)
{
	register int i, j;

	char* x;
	char temp[10];

	i = stg; j = drp;
	x = tab[(stg + drp) / 2];

	do
	{
		while (strcmp(tab[i], x) < 0 && i < drp) i++;
		while (strcmp(tab[j], x) > 0 && j > stg) j--;
		if (i <= j)
		{
			strcpy_s(temp, tab[1]);
			strcpy_s(tab[i], tab[j]);
			strcpy_s(tab[j], temp);
		}

	} while (i <= j);

	if (stg < j) qs_string(tab, stg, j);
	if (i < drp) qs_string(tab, i, drp);
}

void sort_stream(char tab[][10], int count)
{
	qs_string(tab, 0, count - 1);
}
