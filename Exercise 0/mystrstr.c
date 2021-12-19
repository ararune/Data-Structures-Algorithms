#include <stdio.h>
// return pointer to the first occurence of a substring within a string, if not found; return NULL
char* mystrstr(const char* str, const char* substring)
{
	char* pstr;
	char* psubstr;

	psubstr = substring;
	if (*psubstr == 0) {
		return (char*)str;
	}
	for (; *str != 0; str++) {
		if (*str != *psubstr) {
			continue;
		}

		pstr = str;
		while (1) {
			if (*psubstr == 0) {
				return (char*)str;
			}
			if (*pstr++ != *psubstr++) {
				break;
			}
		}
		psubstr = substring;
	}


	return NULL;
}


int main(void)
{
	char str[50] = "abaaaaabaa";
	char substr[50] = "aaab";
	char* p;
	p = mystrstr(str, substr);
	if (p != 0)
	{
		printf("Prvo ponavljanje podstringa : %s", p);
	}
	else
	{
		printf("Nema podstringa");
	}
	printf("\nAdresa indeksa podstringa : 0x%p", p);

	return 0;
}

