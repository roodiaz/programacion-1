#include <stdio.h>
#include <stdlib.h>

//prototipo de la funcion
int sumar1(int, int);

int main()
{
    int numero1;
    int numero2;
    int resultado;

    printf("Ingrese primer numero: ");
    scanf("%d", &numero1);

    printf("Ingrese segundo numero: ");
    scanf("%d", &numero2);

    resultado = sumar1 (numero1, numero2);

    printf("La suma es de: %d", resultado);

    return 0;
}

//desarrollo de la funcion
int sumar1 (int num1, int num2)
{
    int suma;

    suma = num1 + num2;
}
