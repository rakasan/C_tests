// C_SandBox.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>

using namespace std;


void sp_in_linie(const char* str);
int is_in(char* s, char c)
{
	while (*s)
	{
		if (*s == c)
			return 1;
		else
			s++;

	}

	return 0;
}

void sp_in_linie(const char* str)
{
	while (*str)
	{
		if (*str == ' ') printf("%c", '-');//cout << "-";
		else printf("%c", *str);//cout << *str;//
		str++;
	}
}

int _pwr(register int m, register int e)
{
	register int temp;
	temp = 1;
	for (; e; e--) temp = temp * m;
	return temp;
}

int xor (int a, int b)
{
	return (a || b) && !(a && b);
}

int main()
{
   //cout << "Hello World!\n";
	//char test[5] = {'A','B','C','D','E'};
	int test;
	//sp_in_linie("Acesta este un test");
	test =_pwr(4, 2);
	//is_in(test, 'F');
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
