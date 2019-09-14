#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

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
















