#include <stdio.h>
// compare 2 strings, return negative integer if string < other string, positive if string > other string, 0 if equal
int mystrcmp(char* str1, char* str2)
{
    int i;
    for (i = 0; str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0'; i++);

    return str1[i] - str2[i];
}

int main(void)
{
    char str1[50] = "abc";
    char str2[50] = "abce";

    printf("String compare : %d", mystrcmp(str1, str2));

    return 0;

}