#include <stdio.h>

void afiseaza_vertical(char* sir)
{
	while (*sir)
	{
		printf("%c/n", *sir++);
	}
}