#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* Dise�ar en un programa que permita registrar de los empleados de una f�brica
(no se sabe cu�ntos) su peso y saber cu�ntos pesan hasta 80 kg. inclusive y
cuantos pesan m�s de 80 kg. */

int main()
{
    int pesos[50];
    int i=0;
    int contMin=0;
    int contMax=0;
    char seguir;

    do
    {
        printf("\ningrese peso: ");
        scanf("%d",&pesos[i]);


        printf("desea seguir s/n: ");
        fflush(stdin);
        seguir=getche();

        if(pesos[i]<80)
        {
            contMin++;
        }
        if(pesos[i]>80)
        {
            contMax++;
        }
        i++;

    }while(seguir == 's');

    printf("\n\npesos mayores a 80: %d\npesos menores a 80: %d\n\n",contMax,contMin);

    return 0;
}
