#include "assert.h"
#include "stdio.h"
#include "string.h"

void lungime(char *mesaj)
{
	int lung,lung2;
	lung = strlen(mesaj);
        lung2 = sizeof(mesaj);
	printf("%d",lung);
	printf("%d",lung2);
}

int main()
{
  char vector[20] = {'A','B','C'};
  
  vector[4] = 'D';
  
  lungime(vector);
  
  printf("test");
  printf("test1");
  printf("test2");
  printf("test3");
  return 0;
  
}
