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

void obtenerEmail(char dondeAsignar[], int tamMax, char mensaje [])
{
    int cantidadArrobas;
    int cantidadPuntos;
    int pusoArroba;
    int invalido;
    char aux[tamMax];

    do
    {
        cantidadArrobas = 0, cantidadPuntos = 0, invalido = 0, pusoArroba = 0;
        fflush(stdin);
        printf("\n%s",mensaje);
        gets(aux);
        strlwr(aux);

        for(int i=0 ; i<strlen(aux)-1 ; i++)
        {

            if (aux[i] == ' ')
            {
                invalido = 1;
                break;
            }

            if (i==0 && (aux[i] == '@' || aux[i] == '.'))
            {
                invalido = 1;
                break;
            }

            if ( ((aux[i] < 'a' || aux[i] > 'z') && (aux[i]<'0' || aux[i]>'9')) && (aux[i] != '@') && (aux[i] != '.') && (aux[i] != '_') && (aux[i] =! '-')  )
            {
                invalido=1;
                break;
            }

            if (aux[i] == '@')
            {
                if (cantidadArrobas >= 1)
                {
                    invalido=1;
                    break;
                }
                pusoArroba = 1;
                cantidadArrobas ++;
            }

            if (aux[i] == '.')
            {

                if (cantidadPuntos >= 1 || pusoArroba == 0)
                {
                    invalido = 1;
                    break;
                }
                cantidadPuntos ++;
            }

        }

        if(cantidadPuntos == 0 || pusoArroba == 0)
        {
            invalido = 1;
        }

        if ( invalido == 1 )
        {
            printf("\n*** eMail invalido ***\n");
        }

    }
    while (invalido == 1);


    int len = strlen(aux);

    if(aux[len-1]=='\n')
    {

        aux[len-1]='\0';
    }

    strcpy(dondeAsignar, aux);
}


char obtenerSexo(char mensaje[])
{

    char aux;

    printf("\n%s",mensaje);
    fflush(stdin);
    scanf("%c",&aux);
    aux =tolower(aux);

    while(!((aux=='f')||(aux=='m')) )
    {
        printf("\n*** Error ***\n");
        printf("\n%s",mensaje);
        scanf("%c",&aux);
        aux =tolower(aux);
    }

    return aux;
}

void obtenerPatente(char* dondeAsigncar, char* mensaje)
{
    char patente[7];

    printf("\n%s",mensaje);
    fflush(stdin);
    gets(patente);

    for(int i=0; i<3; i++)
    {
        while(isalpha(patente[i]) ==0 || strlen(patente)>6)
        {
            printf("\n%s",mensaje);
            fflush(stdin);
            gets(patente);
        }

    }

    for(int i=3; i<6; i++)
    {
        while(isdigit(patente[i])==0|| strlen(patente)>6)
        {
            printf("\n%s",mensaje);
            fflush(stdin);
            gets(patente);
        }
    }

    strlwr(patente);
    strcpy(dondeAsigncar,patente);
}





















