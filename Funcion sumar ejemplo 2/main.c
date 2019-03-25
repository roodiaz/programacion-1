#include <stdio.h>
#include <stdlib.h>

int sumar2 (void);

int main()
{
    int suma;

    suma = sumar2;

    printf("La suma es de: %d",sumar2);
    return 0;
}

int sumar2 (void)
{
    int numero1;
    int numero2;
    int resultado;

    printf("Ingresar primer numero: ");
    scanf("%d", &numero1);

    printf("Ingresar segundo numero: ");
    scanf("%d", &numero2);

    resultado = numero1 + numero2;

    return resultado;
}
