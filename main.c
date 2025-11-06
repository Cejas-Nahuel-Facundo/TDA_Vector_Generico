#include <stdio.h>
#include <stdlib.h>
#include "TDA_Generico.h"

int main()
{
    tVector v;
    printf("Creando Vector...\n");

    if(CreateVec(&v, 3, sizeof(int)))
        printf("Vector Creado");
    else
        {
            printf("Error\n");
            return 1;
        }

    int x = 10, y = 2, z = 1;

    InsertOrd(&v, &x, cmpInt);
    InsertOrd(&v, &y, cmpInt);
    InsertOrd(&v, &z, cmpInt);

    printf("\n");
    MostrarVec(&v, mostrarInt);
    printf("\n");

    printf("Cerrando Vector..\n");
    DestroyVec(&v);
    if(VacioVec(&v))
        printf("Liberado exitosamente...\n");
    else
        printf("Error al Liberar...\n");

    return 0;
}
