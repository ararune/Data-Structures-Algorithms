#include <stdio.h>
// reverse a string
unsigned short mystrlen(const char* str1)
{
	int i;
	for (i = 0; str1[i] != '\0'; i++);
	return i;
}

void reverse(char* str1, char* str2) // copies a reversed string into another string
{
	char* pstring = str1 + mystrlen(str1) - 1; 

	for (; *str1 != 0; str1++, str2++, pstring--)
		*str2 = *pstring;

	*str2 = '\0';
}

int main(void)
{
	char str1[50] = "Hello";
	char str2[50] = "World";

	reverse(str1, str2);
	printf("Reversed string : %s", str2);

	return 0;
}