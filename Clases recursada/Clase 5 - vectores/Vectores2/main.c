#include <stdio.h>
#include <stdlib.h>

void mostrarVector(int vec[], int tam)
{
    int max;
    int posMax;

    for(int i=0; i<tam; i++)
    {
        printf("%d ", vec[i]);
    }

    max=vec[0];

    for(int i=0; i<tam; i++)
    {
        if(vec[i] > max)
        {
            max=vec[i];
            posMax=i;
        }
    }

    printf("\n\nnumero mayor: %d ",max);
    printf("\n\nposicion numero mayor: %d ",posMax);
    printf("\n\n");

}

int main()
{
    int numeros[5];

    for(int i=0; i<5; i++)
    {
        printf("Ingrese numeros: ");
        scanf("%d",&numeros[i]);
    }

    printf("\n\n");

    mostrarVector(numeros, 5);

    return 0;
}
