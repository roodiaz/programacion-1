#include <stdio.h>
#include <stdlib.h>

/* Ingresar un n�mero entero por consola y efectuar la suma de todos los n�meros
que le anteceden, comenzando desde 0 y mostrar el resultado por pantalla */

int main()
{
    int num;
    int suma=0;
    int cont=0;

    printf("ingrese un numero: ");
    scanf("%d",&num);

    while(cont < num && cont > 0)
    {
        cont--;
        suma+=cont;
    }

    printf("\nsuma de numeros menores a %d es %d\n",num,suma);
    return 0;
}
