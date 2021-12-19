#include <stdio.h>
// copies second string into the first
void mystrcpy(char* str1, char* str2)
{
	int i;
	for (i = 0; str2[i] != '\0'; ++i)
		str1[i] = str2[i];
	str1[i] = '\0';
}

int main(void) {
	char str1[50] = "Hello";
	char str2[50] = "World";

	mystrcpy(str1, str2);
	printf("\String 2 copied into string 1 : %s\n", str1);

	return 0;
}