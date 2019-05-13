#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include "inputDiaz.h"


int validarCararteres(char letra[], char mensaje[])
{

    for(int i=0; i<strlen(letra); i++)
    {
        while(!(isalpha(letra[i])))
        {
            printf("%s",mensaje);
            fflush(stdin);
            scanf("%s",letra);
        }
    }

    return 1;
}

int validarAlphaNumeric(char letra[], char mensaje[])
{

    for(int i=0; i<strlen(letra); i++)
    {
        while(!(isalnum(letra[i])))
        {
            printf("%s",mensaje);
            fflush(stdin);
            scanf("%s",letra);
        }
    }

    return 1;
}

int validarNumeros(char numero[],char mensaje[])
{

    for(int i=0; i<strlen(numero); i++)
    {
        while(!(isdigit(numero[i])))
        {
            printf("%s",mensaje);
            fflush(stdin);
            scanf("%s",numero);
        }
    }
    return 1;
}

int preguntarSiEstaSeguro(char mensaje[])
{
    char confirma;
    int i;

    printf("\n%s",mensaje);
    fflush(stdin);
    confirma = tolower(getche());

    while(confirma!='s' && confirma!='n')
    {
        printf("\n\n*** Error ***");
        printf("\n%s",mensaje);
        fflush(stdin);
        confirma = tolower(getche());
    }
    if (confirma == 's')
    {
        i=1;
    }
    else
    {
        i=0;
    }

    return i;
}

void obtenerCadenaChar(char dondeAsginar[], int tamMax, char mensaje[])
{
    char auxChar[100];
    char letra;


    printf("\n%s",mensaje);
    fflush(stdin);
    gets(auxChar);

    letra=validarCararteres(auxChar, mensaje);

    if(letra==1)
    {

        while(strlen(auxChar)>tamMax || strlen(auxChar) < 1)
        {
            printf("\n*** Error ***");
            printf("\n%s",mensaje);
            fflush(stdin);
            gets(auxChar);
        }

        strlwr(auxChar);
        auxChar[0] = toupper(auxChar[0]);
        strcpy(dondeAsginar, auxChar);
    }
}

void obtenerCadenaAlpaNumerica(char dondeAsginar[], int tamMax, char mensaje[])
{
    char auxChar[100];
    char letra;

    printf("\n%s",mensaje);
    fflush(stdin);
    gets(auxChar);

    letra=validarAlphaNumeric(auxChar, mensaje);

    if(letra==1)
    {

        while(strlen(auxChar)>tamMax || strlen(auxChar) < 1)
        {
            printf("\n*** Error ***");
            printf("\n%s",mensaje);
            fflush(stdin);
            gets(auxChar);
        }

        strlwr(auxChar);
        auxChar[0] = toupper(auxChar[0]);
        strcpy(dondeAsginar, auxChar);
    }
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

void obtenerTelefono(char dondeAsignar[], int tamMax, char mensaje[])
{
    char auxTel[100];
    char tel;


    printf("\n%s",mensaje);
    fflush(stdin);
    gets(auxTel);

    tel=validarNumeros(auxTel, "## Ingresar telefono: ");

    if(tel==1)
    {

        while(strlen(auxTel)>tamMax || strlen(auxTel) < 7)
        {
            printf("*** Error ***\n");
            printf("\n%s",mensaje);
            fflush(stdin);
            gets(auxTel);
        }

        strcpy(dondeAsignar, auxTel);
    }
}

void obtenerSexo(char dondeAsignar, char mensaje[])
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

    dondeAsignar=aux;
}

int obtenerNumeroEntre(int tamMax, int tamMin, char mensaje[])
{
    int num;

    printf("\n%s",mensaje);
    scanf("%d",&num);

    while(num > tamMax || num < tamMin)
    {
        if(!isdigit(num))
        {
            printf("\n*** Error ***\n");
            printf("\n%s",mensaje);
            scanf("%d",&num);
        }
    }

    return num;

}

int obtenerNumeroIgualA(int numReferencia, char mensaje[])
{
    int aux;

    printf("\n%s",mensaje);
    scanf("%d",&aux);


    while(aux != numReferencia)
    {
        printf("\n*** Error ***\n");
        printf("\n%s",mensaje);
        scanf("%d",&aux);
    }

    return aux;

}

int generarIdAletatorio(int tamMax, int tamMin)
{
    int id;

    srand(time(NULL));
    id = tamMin + rand() % (tamMax - tamMin);


    printf("\nId: %d\n",id);

    return id;
}

void validarFecha(int asignarDia, int asignarMes, int asignarAnio)
{
    int auxInt;

    while(auxInt<0 || auxInt>31)
    {
        printf ("\n*** ERROR ***");
        printf("\nIngresar dia: ");
        fflush(stdin);
        scanf ("%d",&auxInt);
    }

    asignarDia=auxInt;

    while(auxInt<0 || auxInt>12)
    {
        printf ("\n*** ERROR ***");
        printf("\nIngresar mes: ");
        fflush (stdin);
        scanf ("%d",&auxInt);
    }

    asignarMes=auxInt;

    while(auxInt<1980 || auxInt>2020)
    {
        printf ("\n*** ERROR ***");
        printf("\nIngresar anio: ");
        fflush (stdin);
        scanf ("%d",&auxInt);
    }

    asignarAnio=auxInt;
}

void validarPatente(char dondeAsignar[], char mensaje[])
{
    char auxChar[10];

    printf("\n%s", mensaje);
    fflush(stdin);
    gets(auxChar);

    while(!(isalpha(auxChar[0])) || !(isalpha(auxChar[1])) || !(isalpha(auxChar[2])))
    {
        printf("\n*** ERROR ***");
        printf("\n%s", mensaje);
        fflush(stdin);
        gets(auxChar);
    }

    while(auxChar[3] != '-')
    {
        printf("\n*** ERROR ***");
        printf("\n%s", mensaje);
        fflush(stdin);
        gets(auxChar);
    }

    while(!(isdigit(auxChar[4])) || !(isdigit(auxChar[5])) || !(isdigit(auxChar[6])))
    {
        printf("\n*** ERROR ***");
        printf("\n%s", mensaje);
        fflush(stdin);
        gets(auxChar);
    }

    auxChar[0]=tolower(auxChar[0]);
    auxChar[1]=tolower(auxChar[1]);
    auxChar[2]=tolower(auxChar[2]);
    strcpy(dondeAsignar, auxChar);
}
