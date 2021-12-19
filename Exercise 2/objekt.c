#include <stdio.h>
#include <stdlib.h>
#include "objekt.h"

Objekt3D* citaj_bin(FILE* fp) {
    Objekt3D* objekt3d = (Objekt3D*)malloc(sizeof(Objekt3D));
    fseek(fp, 80, SEEK_SET); 
    fread(&(objekt3d->n), sizeof(unsigned int), 1, fp); //prva 4 bajta nakon 80 pozicije su ukupni broj trokuta
    int i = 0;
    objekt3d->niz_trokuta = (Trokut*)malloc(objekt3d->n * sizeof(Trokut));
    while (fread(&objekt3d->niz_trokuta[i++], 50, 1, fp)); 
    return objekt3d;
}

void zapisi_u_binarnu(Objekt3D* objekt3d, FILE* fp) {

    fwrite("0", sizeof(int), 20, fp);
    fwrite(&objekt3d->n, sizeof(unsigned int), 1, fp);
    for (int i = 0; i < objekt3d->n; i++) {
        fwrite(&objekt3d->niz_trokuta[i], 50, 1, fp);
    }
}

void zapisi_u_tekstualnu(Objekt3D* objekt3d, FILE* fp) {

    char solid_name[] = "JOSIP";
    fprintf(fp, "solid %s\n", solid_name);
    for (int i = 0; i < objekt3d->n; i++) {
        fprintf(fp, "facet normal %f %f %f\n", objekt3d->niz_trokuta[i].ni, objekt3d->niz_trokuta[i].nj, objekt3d->niz_trokuta[i].nk);
        fprintf(fp, "outer loop\n");
        for (int j = 0; j < 3; j++) {
            fprintf(fp, "vertex %f %f %f\n", objekt3d->niz_trokuta[i].vrhovi[j].x, objekt3d->niz_trokuta[i].vrhovi[j].y, objekt3d->niz_trokuta[i].vrhovi[j].z);
        }
        fprintf(fp, "endloop\n");
    }
    fprintf(fp, "endsolid %s", solid_name);
}

void izbrisi_objekt3d(Objekt3D* objekt3d) {
    if (objekt3d != NULL) {
        free(objekt3d->niz_trokuta);
        free(objekt3d);
    }
}

Objekt3D* citaj_tekstualnu(FILE* fp) {
    char str[1000];
}