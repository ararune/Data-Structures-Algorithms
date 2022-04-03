#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int N = 10000;
int HEAPLEN = 10;

typedef struct {
	void* s;
	int priority;
} Element;

typedef struct _Queue{
	Element* arr;
} Queue;

void printQueue(Queue* q) {
	for (int i = 0; i < N; i++) {
		printf("%d\n", q->arr[i].priority);
	}
}

void swapQueueElements(Queue* q, int index1, int index2) {
	Element tmp = q->arr[index1];
	q->arr[index1] = q->arr[index2];
	q->arr[index2] = tmp;
}

void popravi_prema_vrhu(Queue* q, int c) {

	/*if (c == 0) return;*/
	int parent_index = floor((c - 1) / 2);
	Element parent = q->arr[parent_index];
	if (parent.priority < q->arr[c].priority) {
		swapQueueElements(q, parent_index, c);
		popravi_prema_vrhu(q, parent_index);
	}
}
void dodaj_novi_na_kraj_niza(Queue* q, int i) {

	q->arr[i].priority = rand() % N;
	popravi_prema_vrhu(q, i);

}

void popravi_gomilu_prema_dnu(Queue* q, int r) {

	int l = 2 * r + 1;
	int d = 2 * r + 2;
	if (d >= N || l >= N) return;

	if (q->arr[r].priority < q->arr[l].priority && q->arr[l].priority >= q->arr[d].priority) {
		swapQueueElements(q, r, l);
		popravi_gomilu_prema_dnu(q, l);
	}
	else if (q->arr[r].priority < q->arr[d].priority && q->arr[d].priority >= q->arr[l].priority) {
		swapQueueElements(q, r, d);
		popravi_gomilu_prema_dnu(q, d);
	}
}

void ukloni_sa_vrha_gomile(Queue* q) {

	q->arr[0] = q->arr[N - 1];
	N = N - 1;
	q->arr = (Element*)realloc(q->arr, N * sizeof(Element));
	popravi_gomilu_prema_dnu(q, 0);
}

//dodatno: implementacija heaptsorta

void print_niz(int* niz, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d\n", niz[i]);
	}
}

void zamijeni_elemente_u_nizu(int* niz, int index1, int index2) {
	int tmp = niz[index1];
	niz[index1] = niz[index2];
	niz[index2] = tmp;
}

void heapify(int* niz, int r, int n) {
	int l = 2 * r + 1;
	int d = 2 * r + 2;

	//zamjena s lijevim elementom
	if ((l < n && d >= n && niz[l] > niz[r]) || (l < n && d < n && niz[l] >= niz[d] && niz[l] > niz[r])) {
		zamijeni_elemente_u_nizu(niz, r, l);
		heapify(niz, l, n);

	//zamjena s desnim elementom
	}
	else if ((d < n && l >= n && niz[d] > niz[r]) || (d < n && l < n && niz[d] >= niz[l] && niz[d] > niz[r])) {
		zamijeni_elemente_u_nizu(niz, r, d);
		heapify(niz, d, n);
	}
}

void napravi_gomilu(int* niz, int n) {
	int start_index = floor(n / 2);
	for (int i = start_index; i >= 0; i--) {
		heapify(niz, i, n);
	}
}

void heapsort(int* niz, int n) {
	if (n == 0) return;
	zamijeni_elemente_u_nizu(niz, 0, n - 1);
	heapify(niz, 0, n - 1);
	heapsort(niz, n - 1);
}

int main() {
	/*srand(time(NULL));
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->arr = (Element*)malloc(N * sizeof(Element));
	for (int i = 0; i < N; i++) {
		dodaj_novi_na_kraj_niza(q, i);
	}

	printf("-------prije uklanjanja sa vrha-------\n");
	printQueue(q);

	printf("-------posli uklanjanja sa vrha-------\n");
	ukloni_sa_vrha_gomile(q);
	printQueue(q);

	free(q->arr);
	free(q);*/

	int niz[] = { 2, 8, 5, 3, 9, 1 };
	int n = 6;

	printf("-------print niza prije gomile-------\n");
	print_niz(niz, n);
	napravi_gomilu(niz, n);
	printf("-------print niza posli gomile-------\n");
	print_niz(niz, n);
	heapsort(niz, n);
	printf("-------print niza posli heapsorta-------\n");
	print_niz(niz, n);

	return 0;
}