// C_SandBox.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
//#include <graph.h>
#include <conio.h>

using namespace std;

struct salariat
{
	char nume[80];
	int vasta;
} sal;

void lungime(char *mesaj)
{
	int lung;
	lung = strlen(mesaj);
	printf("%d",lung);
}

void  charRead(void)
{
	char ch;

	do
	{
		ch = getchar();

		if (islower(ch)) ch = toupper(ch);
		else ch = tolower(ch);

		putchar(ch);
	} while (ch != '.');
}

char IndexList[5];
char Counter = 1;

static void __rearanjaza(int StartingIndex)
{
	int LCounter;
	for (LCounter = StartingIndex; LCounter < Counter; LCounter++)
	{
		IndexList[LCounter] = IndexList[LCounter + 1];
	}
}

static void __adaugaElement(char ID_Box,int stare)
{
	int i;

	if (stare == 1) /* Adauga element in lista */
	{
		IndexList[Counter] = ID_Box;
		Counter++;
	}
	else /* Scoate element din lista */
	{
		for (i = 1; i <= Counter; i++)
		{
			if (ID_Box == IndexList[i]) /* Found the element*/
			{
				__rearanjaza(i);

				Counter--;
			}
		}
	}
}


int main()
{
	__adaugaElement('a', 1);
	__adaugaElement('b', 1);
	__adaugaElement('c', 1);
	__adaugaElement('d', 1);

	__adaugaElement('b', 0);
	__adaugaElement('b', 1);

	__adaugaElement('d', 0);

	__adaugaElement('c', 0);

	__adaugaElement('d', 1);

	
}

