#include <stdio.h>
#include <stdlib.h>

/* Hacer el programa que imprima todos los n�meros naturales que hay
desde la unidad hasta un n�mero que introducimos por teclado */


int main()
{
    int num;
    int cont=0;

    printf("ingrese numero: ");
    scanf("%d",&num);

    while(cont < num-1)
    {
        cont++;
        printf("%d-",cont);
    }

    return 0;
}
