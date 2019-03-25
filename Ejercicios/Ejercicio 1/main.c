#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    int contPares = 0;
    int contImpar = 0;
    int acumulador = 0;
    int flag = 0;
    int contCeros = 0;
    int notas;
    int max;
    int min;
    float promedio;
    char sexo;
    char sexoMin;
    char sexoMax;
    char rta;

    do
    {
        i++;
        printf("Ingresar notas: ");
        scanf("%d", &notas);

        while(notas > 10)
        {
        printf("Ingresar notas: ");
        scanf("%d", &notas);
        }

        printf("Ingresar sexo F o M: ");
        scanf(" %c",&sexo);

        if(notas % 2 == 0)
        {
            contPares++;
        }
        if(notas % 2 != 0)
        {
            contImpar++;
        }

        if(notas > max || flag == 0)
        {
            max = notas;
            sexoMax = sexo;
        }
        if(notas < min || flag == 0)
        {
            min = notas;
            sexoMin = sexo;
            flag = 1;
        }

        if(notas == 0)
        {
            contCeros++;
        }

        acumulador = acumulador + notas;

        printf("Desea continuar?: ");
        scanf(" %c", &rta);


    }while (rta == 's');

    promedio = (float) acumulador / i;

    printf("La cantidad de numeros ingresados es: %d\n",i);
    printf("La cantidad de numeros pares es: %d\n",contPares);
    printf("La cantidad de numeris impares es: %d\n",contImpar);
    printf("La suma de todos los numeros es: %d\n",acumulador);
    printf("El promedio de todos los numeros es: %f\n",promedio);
    printf("El numero maximo ingresado es: %d\nEl numero minimo ingresado es: %d\n",max,min);
    printf("La cantidad de ceros ingresados es: %d\n",contCeros);
    printf("El alumno con la nota mas baja es de sexo: %c\n",sexoMin);
    printf("El alumno con la nota mas alta es de sexo: %c\n",sexoMax);


    return 0;
}
