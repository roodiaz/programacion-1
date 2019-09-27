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

    if(intentos != 0)
    {
        strcpy(dondeAsignar, aux);
    }


    return todoOk;
}

int getIntRange(int* dondeAsignar, int min, int max, int intentos, char* mensaje)
{
    int todoOk = 1;
    int auxInt;
    char aux[2];

    printf("%s",mensaje);
    gets(aux);

    while(isdigit(aux[0])==0)
    {
        intentos--;
        if(intentos == 0)
        {
            todoOk=0;
            break;
        }
        printf("Error. %s",mensaje);
        gets(aux);

        auxInt=atoi(aux);

        while(auxInt < min || auxInt > max)
        {
            intentos--;
            if(intentos == 0)
            {
                todoOk=0;
                break;
            }
            printf("Error. %s",mensaje);
            scanf("%d",&auxInt);
        }
    }

    if(intentos != 0)
    {
        *dondeAsignar = auxInt;
    }

    return todoOk;
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

int getFloatRange(float min, float max, int intentos, float* dondeAsignar, char* mensaje)
{
    int todoOk = 1;
    float aux;
    char auxFloat[2];

    printf("%s",mensaje);
    fflush(stdin);
    gets(auxFloat);

    while(isdigit(auxFloat[0])==0)
    {
        intentos--;
        if(intentos == 0)
        {
            todoOk=0;
            break;
        }

        printf("error. %s",mensaje);
        fflush(stdin);
        gets(auxFloat);

        aux=atof(auxFloat);

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
   }

    if(intentos != 0)
    {
        *dondeAsignar = aux;
    }

    return todoOk;

}
















