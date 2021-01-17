#include "stdio.h"

int SequentialSerch(char* lista, int cont, char car)
{
	register int t;

	for (t = 0; t < cont, ++t)
	{
		if (car == lista[t]) return t;
	}
	return -1U;
}

int BinarySearch(char* lista, int cont, char car)
{
	int med, min, max;
	while (min <= max)
	{
		med = (min + max) / 2;

		if (car < lista[med]) max = med - 1;
		else if (car > lista[med]) min = med + 1;
		else return med;
	}

	return -1;
}