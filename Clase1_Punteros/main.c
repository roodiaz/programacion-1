#include <stdio.h>
#include <stdlib.h>

void funcionModificar(int *p);
void f1(int x[], int tam); // ESTRUCTURA VECTORIAL_PROTOTIPO VECTORIAL -- BIEN
void f2(int x[], int tam); // ESTRUCTURA PUNTERO_PROTOTIPO VECTORIAL -- MAL
void f3(int* x, int tam); // ESTRUCTURA VECTORIAL_PROTOTIPO VECTORIAL -- MAL
void f4(int* x, int tam); // ESTRUCTURA PUNTERO_PROTOTIPO PUNTERO -- BIEN

/// NO HAY QUE MEZCLAR NOMENCLATURA VECTORIAL Y DE PUNTERO

int main()
{
    int a=5;

    printf("%d\n\n",a);

    funcionModificar(&a);

    printf("%d",a);
    printf("\n\n");

    //////////////////////
    int vec[]={3,4,5,6,2};

    f1(vec,5);
    printf("\n\n");
    f2(vec,5);
    printf("\n\n");
    f3(vec,5);
    printf("\n\n");
    f4(vec,5);
    printf("\n\n");

    return 0;
}

void funcionModificar(int *p)
{
    *p=25;
}

void f1(int x[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        printf("%d",x[i]);
    }
}

void f2(int x[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        printf("%d",*(x+i));
    }
}

void f3(int* x, int tam)
{
    for(int i=0; i<tam; i++)
    {
        printf("%d",x[i]);
    }
}

void f4(int* x, int tam)
{
     for(int i=0; i<tam; i++)
    {
        printf("%d",*(x+i));
    }
}
