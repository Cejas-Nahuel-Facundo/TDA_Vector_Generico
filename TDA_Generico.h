#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VERDADERO 1
#define FALSO 0
#define ERROR -1

typedef struct
{
    void *v; // Bloque de Memoria
    size_t save; // Cantidad de Memoria Usada
    size_t ce; // Cantidad Maxima que se puede almacenar
    size_t tam; // tamaño de cada elemento

}tVector;

int CreateVec(tVector *v, size_t ce, size_t tam);
void DestroyVec(tVector *v);
int VacioVec(tVector *v);
int InsertOrd(tVector *v, void *elemento, int cmp(const void*, const void*));
int InsertarElem(tVector *v, void*elem);
int  ReLong(tVector *v, size_t New);
void MostrarVec(tVector *v, void (*accion)(const void*));
void mostrarInt(void *dato);
int  cmpInt(const void*, const void*);
int  cmpFloat(const void*, const void*);
int  cmpChar(const void*, const void*);
