#ifndef OBJEKT
#define OBJEKT

typedef struct {
    float x;
    float y;
    float z;
}Vrh;

typedef struct {
    float ni;
    float nj;
    float nk;
    Vrh vrhovi[3];
    unsigned short boja;
}Trokut;

typedef struct {
    Trokut* niz_trokuta;
    unsigned int n;
}Objekt3D;

Objekt3D* citaj_bin(FILE* fp);
void zapisi_u_binarnu(Objekt3D* objekt3d, FILE* fp);
void zapisi_u_tekstualnu(Objekt3D* objekt3d, FILE* fp);
void izbrisi_objekt3d(Objekt3D* objekt3d);
Objekt3D* citaj_tekstualnu(FILE* fp);
#endif /