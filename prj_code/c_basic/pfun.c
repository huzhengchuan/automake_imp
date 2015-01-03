#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef char * (*pf1)(int a, int b);
typedef char *(*pf2(int c))(int a, int b);

char *hello1(int a, int b)
{
	printf("%d %d\r\n", a,b);
	return NULL;
}


char *hello3(int a, int b)
{
	printf("a=%d b=%d\r\n", a,b);
	return NULL;
}

char * (*hello2(int c))(int a, int b)
{
	printf("c=%d\r\n", c);
	return hello3;
}




int main()
{
	pf1 fun = hello1;
	fun(1,1);
	pf1 fun2 = hello2(2);
	
	fun2(2,2);
}
