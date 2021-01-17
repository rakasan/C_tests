#include <stdio.h>

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

int _xor (int a, int b)
{
	return (a || b) && !(a && b);
}

int fake_main(void)
{
	//cout << "Hello World!\n";
 //char test[5] = {'A','B','C','D','E'};
	int test;
	//sp_in_linie("Acesta este un test");
	test = _pwr(4, 2);
	//is_in(test, 'F');

	return 1;
}