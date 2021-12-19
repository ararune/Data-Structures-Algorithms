#include <stdio.h>
// return the length of a string
unsigned short mystrlen(const char* str1)
{
	int i;
	for (i = 0; str1[i] != '\0'; i++);
	return i;
}

int main(void)
{
	char str1[50] = "Hello";
	printf("String length : %d", mystrlen(str1));
}
