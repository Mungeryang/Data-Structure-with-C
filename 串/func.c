#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int main()
{
	char *s="Golden Global View";
	char *p;
	
	//clrscr();
	
	strchr(s,'V');
	if(p)
		printf("%s",p);
	else
		printf("Not Found!");
	
	getchar();
	return 0;
}
