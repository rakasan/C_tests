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
int main()
{
	char str[80];
	//gets(str);
	printf("Lungimea este", strlen(str));
	//char str[20];

//	int x;

	//for (x = 0; x < 3 && strcmp(str, "parola"); ++x)
	//{
	//	printf("Data parola");
		//gets(str);// get string - nu stiu daca merge
	//}

	//if(x== 3) return /* passport was not given correctly*/
		/* Altfel user-ul este connectat la ... */

//	struct salariat* p = &sal;
//	char a[20] = {'A','B','C'};
	//int a, b;
	//a[3] = 'D';
//	lungime(a);
	//printf("numere");
	//scanf_s("%d%d", &a, &b);

	//b ? printf("%d\n", a / b) : printf("DIV by 0");
//	sal.vasta = 123; // apel prin referire la variabila
//	p->vasta = 123; //apel prin pointer
	
}

