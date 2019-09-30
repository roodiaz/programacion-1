#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

int confimarSalir(char mensaje[])
{
    int retorno;
    char confirma;

    printf("%s",mensaje);
    fflush(stdin);
    confirma=getchar();
    confirma=tolower(confirma);

    while(confirma != 's' && confirma != 'n')
    {
        printf("Error. %s",mensaje);
        fflush(stdin);
        confirma=getchar();
        confirma=tolower(confirma);
    }

    if(confirma == 's')
    {
        retorno = 1;
    }
    else
    {
        retorno =0;
    }

    return retorno;

}

int getStringAlpha(int longMax, int intentos, char* mensaje, char* dondeAsignar)
{
    int todoOk = 1;
    char aux[longMax];

    printf("%s",mensaje);
    fflush(stdin);
    gets(aux);

    for(int i=0; i<strlen(aux); i++)
    {
        while((isalpha(aux[i])==0) || strlen(aux) > longMax)
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

    strlwr(aux);
    aux[0]=toupper(aux[0]);

    if(intentos != 0)
    {
        strcpy(dondeAsignar, aux);
    }


    return todoOk;
}

void getIntRange(int* dondeAsignar, int min, int max, char* mensaje)
{

    int auxInt;
    char aux[20];

    printf("%s",mensaje);
    gets(aux);


    for(int i=0; i<strlen(aux); i++)
    {
        while(isdigit(aux[i])==0)
        {
            printf("Error. %s",mensaje);
            gets(aux);
        }
    }

    auxInt=atoi(aux);

    while(auxInt < min || auxInt > max)
    {
        printf("Error. %s",mensaje);
        scanf("%d",&auxInt);
    }


    *dondeAsignar = auxInt;

}

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

int getChar(int intentos, char* dondeAsignar, char* mensaje)
{
    int todoOk = 1;
    char aux;

    printf("%s",mensaje);
    fflush(stdin);
    aux=getchar();

    while(isalpha(aux)==0)
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

void getFloatRange(float min, float max, float* dondeAsignar, char* mensaje)
{
    float auxFloat;
    char aux[20];

    printf("%s",mensaje);
    gets(aux);

    for(int i=0; i<strlen(aux); i++)
    {
        while((isdigit(aux[i])==0))
        {
            printf("Error. %s",mensaje);
            fflush(stdin);
            gets(aux);
        }
    }

    auxFloat=atoi(aux);


    while(auxFloat < min || auxFloat > max)
    {
        printf("Error. %s",mensaje);
        scanf("%f",&auxFloat);
    }

        *dondeAsignar = auxFloat;

}
















