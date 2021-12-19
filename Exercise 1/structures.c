#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	float x;
	float y;
}tocka;

typedef struct
{
	tocka* niz_vrhova;
	int n;
}poligon;


poligon* novi_poligon(float* niz_x, float* niz_y, int n)
{
	if (n < 3)
	{
		printf("Broj tocaka mora biti 3 ili vise");
		return NULL;

	}
	poligon* newPolygon = (poligon*)malloc(sizeof(poligon));
	newPolygon->niz_vrhova = (tocka*)malloc(sizeof(tocka) * n);
	for (int i = 0; i < n; i++)
		{
			newPolygon->niz_vrhova[i].x = niz_x[i];
			newPolygon->niz_vrhova[i].y = niz_y[i];
		}

	return newPolygon;
	
}

tocka** pozitivni(poligon* p, int* np)
{
	int j = 0, brojac = 0;
	for (int i = 0; i < (*np); i++)
	{
		if ((0 < p->niz_vrhova[i].x) && (0 < p->niz_vrhova[i].y))
		{
			brojac++;
		}
	}

	tocka** poz = (tocka**)malloc(sizeof(tocka*) * brojac);

	for (int i = 0; i < (*np); i++)
	{
		if ((0 > p->niz_vrhova[i].x) && (0 > p->niz_vrhova[i].y))
		{
			poz[j] = p->niz_vrhova + i;
			j++;
		}
	}

	*np = j;
	return poz;
}

int main()
{
	int n;

	printf("Unesite broj tocaka: ");
	scanf_s("%d", &n);

	float* t_x = (float*)malloc(sizeof(float) * n);
	float* t_y = (float*)malloc(sizeof(float) * n);

	//Unos tocaka poligona
	for (int i = 0; i < n; i++)
	{
		printf("Unesi tocku (x, y): ");
		scanf_s("%f %f", &t_x[i], &t_y[i]);
	}

	poligon* newPolygon = novi_poligon(t_x, t_y, n);

	//Ispisivanje tocaka poligona
	printf("Tocke poligona:\n");
	for (int i = 0; i < n; i++)
	{
		printf("x: %f   y: %f\n", newPolygon->niz_vrhova[i].x, newPolygon->niz_vrhova[i].y);
	}

	tocka** poz = pozitivni(newPolygon, &n);

	printf("Negativne tocke:\n");
	for (int i = 0; i < n; i++)
		printf("%f %f\n", poz[i]->x, poz[i]->y);
}
