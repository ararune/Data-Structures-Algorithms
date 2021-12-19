#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// generate randomly populated arrays, shuffle them, measure intersect finding time and contrast for unsorted, 1 sorted and both sorted
int* generiraj(int n) {
	int* niz = (int*)malloc(sizeof(int) * n);
	niz[0] = rand() % 5;
	for (int i = 1; i < n; i++) {
		niz[i] = niz[i - 1] + 1 + rand() % 5;
	}
	return niz;
}
void shuffle(int* niz, int n) {
	for (int i = 0; i < n; i++) {
		int j = (rand() * rand()) % n;
		int tmp = niz[i];
		niz[i] = niz[j];
		niz[j] = tmp;
	}
}
void print(int* niz, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", niz[i]);
	}
	printf("\n");
}

int* presjek(int* niz1, int n1, int* niz2, int n2, int* n3) {
	int* niz3 = (int*)malloc(n1 * sizeof(int));
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			if (niz1[i] == niz2[j]) {
				niz3[*n3] = niz1[i];
				(*n3)++;
				break;
			}
		}
	}
	niz3 = (int*)realloc(niz3, *n3 * sizeof(int));
	return niz3;
}

int cmpfunc(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int* presjek_sortirani(int* niz1, int n1, int* niz2, int n2, int* n4) {

	int* niz4 = (int*)malloc(n1 * sizeof(int));
	int* p;
	for (int i = 0; i < n1; i++) {
		p = (int*)bsearch(&(niz1[i]), niz2, n2, sizeof(int), cmpfunc);
		if (p != NULL) {
			niz4[*n4] = *p;
			(*n4)++;
		}
	}
	niz4 = (int*)realloc(niz4, *n4 * sizeof(int));
	return niz4;
}

void oba_sortirana(int* niz1, int n1, int* niz2, int n2) {
	int index1 = 0, index2 = 0;
	/* dok ne prodje kroz jedan od nizova */
	while (index1 < n1 && index2 < n2) {
		if (niz1[index1] < niz2[index2])
			/* ako je index prvog niza manji, inkrementaj ga */
			index1++;
		else if (niz2[index2] < niz1[index1])
			/*ako je index drugog niza manji, inkrementaj ga */
			index2++;
		else {
			/* ako su jednaki, inkrementaj oba */
			index1++;
			index2++;
		}
	}

}


int main(void)
{
	srand(time(NULL));

	int n1 = 3000000, n2 = 3000000, n3 = 0, n4 = 0, i = 1;
	int* niz1, * niz2, * niz3, * niz4;
	niz1 = generiraj(n1);
	niz2 = generiraj(n2);
	shuffle(niz1, n1);
	shuffle(niz2, n2);
	/*	// presjek nesortirani
	clock_t start1 = clock();
	niz3 = presjek(niz1, n1, niz2, n2, &n3);
	clock_t end1 = clock();
	double time_spent1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
	printf("Ukupno vrijeme izvršavanja za funckiju presjek: %f\n", (double)time_spent1);
	free(niz3);*/
	/*		// presjek jedan sortirani
	clock_t start2 = clock();
	qsort(niz2, n2, sizeof(int), cmpfunc);
	clock_t start3 = clock();
	niz4 = presjek_sortirani(niz1, n1, niz2, n2, &n4);
	clock_t end2 = clock();
	clock_t end3 = clock();
	double time_spent2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
	double time_spent3 = (double)(end3 - start3) / CLOCKS_PER_SEC;
	printf("Ukupno vrijeme izvrsavanja za funckiju presjek_sortirani ukljucujuci qsortom: %f\n", (double)time_spent2);
	printf("Ukupno vrijeme izvsšavanja za funckiju presjek_sortirani ne ukljucujuci qsorta: %f\n", (double)time_spent3);
	free(niz4);*/
	// presjek oba sortirana
	clock_t start2 = clock();
	qsort(niz2, n2, sizeof(int), cmpfunc);
	qsort(niz1, n1, sizeof(int), cmpfunc);
	clock_t start3 = clock();
	oba_sortirana(niz1, n1, niz2, n2);
	clock_t end2 = clock();
	clock_t end3 = clock();
	double time_spent2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
	double time_spent3 = (double)(end3 - start3) / CLOCKS_PER_SEC;
	printf("Ukupno vrijeme izvrsavanja za funckiju presjek_sortirani ukljucujuci qsortom: %f\n", (double)time_spent2);
	printf("Ukupno vrijeme izvsšavanja za funckiju presjek_sortirani ne ukljucujuci qsorta: %f\n", (double)time_spent3);
	free(niz1);
	free(niz2);


}