#include "TDA_Generico.h"

int CreateVec(tVector *v, size_t ce, size_t tam)
{
    if(ce <= 0 || tam == 0)
        return ERROR;
    v->v = malloc(ce*tam);
    if(!v->v)
        return ERROR;

    v->save = 0;
    v->ce = ce;
    v->tam = tam;
    return VERDADERO;

}
void DestroyVec(tVector *v)
{
    free(v->v);
    v->v = NULL;
    v->save = 0;
    v->ce = 0;
    v->tam = 0;
}
int VacioVec(tVector *v)
{
    return v->v == NULL && v->tam == 0 && v->ce == 0;
}
int InsertOrd(tVector *v, void *elemento, int cmp(const void*, const void*))
{
    if(v->ce == v->save) /* Si la cantidad disponible es igual a la cantidad guardada */
        return FALSO;
    if(v->ce == 0)
        {
            memcpy(v->v, elemento, v->tam);
            v->save++;
            return VERDADERO;
        }
    void *fin = v->v +(v->save*v->tam);
    void *ini = v->v;
    /*Buscar la posicion correcta para insertar*/
    while(ini < fin && cmp(ini, elemento)<0)
    {
       ini += v->tam;
    }

    /*Desplazar todo hacia la derecha */
    memmove(ini + v->tam, ini, (fin-ini));
    memcpy(ini, elemento, v->tam);
    v->save++;

    return VERDADERO;

}
int InsertarElem(tVector *v, void*elem)
{
    if(v->ce == v->save)
        return ERROR; /* Debe Redimensionar */

    void *destino = (char*)v->v + v->save*v->tam;
    memcpy(destino, elem, v->tam);
    v->save++;
    return VERDADERO;

}
int ReLong(tVector *v, size_t New)
{
    if(New<=0)
        return ERROR;

    void *aux = realloc(v->v, (v->ce + New)*v->tam); /* (5+3)*4Bytes */
    if(!aux)
        return ERROR;

    v->v = aux;
    v->ce = v->ce + New;
    return VERDADERO;

}
void MostrarVec(tVector *v, void (*accion)(const void*))
{
    for(int i = 0; i<v->save; i++)
    {
        void *elem = (char*)v->v + i * v->tam;
        accion(elem);
    }
}
void mostrarInt(void *dato)
{
    printf("%d ", *(int*)dato);
}
int  cmpInt(const void*a, const void*b)
{
    int x = *(int*)a;
    int y = *(int*)b;
    return (x-y);
}
int  cmpFloat(const void*a, const void*b)
{
    int x = *(float*)a;
    int y = *(float*)b;
    return (x-y);

}
int  cmpChar(const void*a, const void*b)
{
    int x = *(char*)a;
    int y = *(char*)b;
    return (x-y);
}
