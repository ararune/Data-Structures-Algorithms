#include <stdio.h>
// append a string at the end of another string
void mystrcat(char* str1, char* str2)
{
	while (*++str1) //dodi do kraja stringa
		;
	while (*str2) {
		*str1++ = *str2++; //stavljaj drugi string na kraj prvog
	}
	*str1 = '\0';

}
int main(void)
{
	char str1[50] = "Hello";
	char str2[50] = "World";

	mystrcat(str1, str2);
	printf("\Concatenated string is : %s\n", str1);

	return 0;
}