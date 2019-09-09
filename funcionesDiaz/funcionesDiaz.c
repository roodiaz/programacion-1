#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

int getSexo(int intentos, char* dondeAsignar, char* mensaje)
{
    int todoOk = 1;
    char aux;

        printf("%s",mensaje);
        fflush(stdin);
        aux=getchar();

        while(aux !='f' && aux!='m')
        {
            intentos--;

            if(intentos == 0)
            {
                todoOk =0;
                break;
            }

            printf("Error. %s",mensaje);
            fflush(stdin);
            aux=getchar();
        }

        if(intentos != 0)
        {
            *dondeAsignar = aux;
        }

        return todoOk;

}

int getIntRange(int* dondeAsignar, int min, int max, int intentos, char* mensaje)
{
    int aux;
    int todoOk = 1;

    printf("%s",mensaje);
    scanf("%d",&aux);

    while(aux < min || aux > max)
    {
        intentos--;
        if(intentos == 0)
        {
            todoOk=0;
            break;
        }
        printf("Error. %s",mensaje);
        scanf("%d",&aux);
    }

    if(intentos != 0)
    {
        *dondeAsignar = aux;
    }

    return todoOk;
}

int getFloatRange(float min, float max, int intentos, float* dondeAsignar, char* mensaje)
{
    float aux;
    int todoOk = 1;

    printf("%s",mensaje);
    scanf("%f",&aux);

    while(aux < min || aux > max)
    {
        intentos--;
        if(intentos == 0)
        {
            todoOk=0;
            break;
        }
        printf("Error. %s",mensaje);
        scanf("%f",&aux);
    }

    if(intentos != 0)
    {
        *dondeAsignar = aux;
    }

    return todoOk;

}

int getStringAlpha(int longMax, int intentos, char* mensaje, char* dondeAsignar)
{
    int todoOk = 1;
    char aux[longMax];

        printf("%s",mensaje);
        fflush(stdin);
        gets(aux);

    for(int i; i<strlen(aux); i++)
    {
        if(!(isalpha(aux[i])) || strlen(aux) > longMax)
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
















