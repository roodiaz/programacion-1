#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

int main()
{
    int cont=0;
    char nombre[20];
    char apellido[20];
    char nomApe[41];

    printf("ingrese nombre: ");
    gets(nombre);

    for(int i=0; i<strlen(nombre); i++)
    {
        while(strlen(nombre)>19 || isalpha(nombre[i])==0)
        {
            printf("ingrese nombre: ");
            gets(nombre);
        }
    }

    printf("ingrese apellido: ");
    gets(apellido);

     for(int i=0; i<strlen(apellido); i++)
    {
        while(strlen(apellido)>19 || isalpha(apellido[i])==0)
        {
            printf("ingrese apellido: ");
            gets(apellido);
        }
    }

    strcat(nomApe,apellido);
    strcat(nomApe,", ");
    strcat(nomApe,nombre);

    strlwr(nomApe);
    nomApe[0]=toupper(nomApe[0]);

    while(nomApe[cont] != '\0')
    {
        if(nomApe[cont]==' ')
        {
            nomApe[cont+1] = toupper(nomApe[cont+1]);
        }

        cont++;
    }

    printf("%s",nomApe);

    return 0;
}
