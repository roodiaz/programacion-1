#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int getStringAlpha(int longMax, int intentos, char* mensaje, char* dondeAsignar)
{
    int todoOk = 1;
    char aux[longMax];

    printf("%s",mensaje);
    fflush(stdin);
    gets(aux);

    for(int i; i<strlen(aux); i++)
    {
        if((isalpha(aux[i])==0) || strlen(aux) > longMax)
        {
            intentos--;
            if(intentos == 0)
            {
                todoOk=0;
                break;
            }
            printf("Error. %s",mensaje);
            fflush(stdin);
            gets(aux);
        }
    }

    if(intentos != 0)
    {
        strcpy(dondeAsignar, aux);
    }


    return todoOk;
}

int main()
{
    //char letra;
    char nombre [20];
    int todoOk;

    todoOk=getStringAlpha(10,3,"ingrese nombre: ",nombre);

    if(todoOk == 1)
    {

       printf("%s",nombre);
    }
    else
    {
        printf("no se pudo conseguir nombre");
    }


    return 0;
}
