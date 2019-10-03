#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputDiaz.h"
#include "autos.h"
#include "trabajos.h"

int menuOpciones()
{
    int opcion;

    system("cls");

    printf("**** MENU DE OPCIONES ****\n\n");
    printf("1. Alta auto\n");
    printf("2. Modificar auto\n");
    printf("3. Baja auto\n");
    printf("4. Listar auto\n");
    printf("5. Listar marcas\n");
    printf("6. Listar colores\n");
    printf("7. Listar servicios\n");
    printf("8. Alta trabajo\n");
    printf("9. Listar trabajos\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

void mostrarAuto(eAuto vecA, eMarca vecM[], int tamM, eColor vecC[], int tamC)
{
    char color[20];
    char marca[20];

    nombreColor(vecC,tamC,vecA.idColor,color);
    nombreMarca(vecM,tamM,vecA.idMarca,marca);

    printf("%d   %6s   %10s    %8s   %d\n",vecA.idAuto,vecA.patente,marca,color,vecA.anioFabricacion);
}

void mostrarAutos(eAuto vecA[],int tamA, eMarca vecM[], int tamM, eColor vecC[], int tamC)
{
    int cont=0;

    system("cls");

    printf("ID   PATENTE     MARCA    COLOR    MODELO\n\n");

    for(int i=0; i<tamA; i++)
    {
        if(vecA[i].estado ==0)
        {
            mostrarAuto(vecA[i],vecM,tamM,vecC,tamC);
            cont++;
        }
    }

    if(cont==0)
    {
        printf("No hay datos para mostrar\n\n");
    }

}


void inicializarAutos(eAuto vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].estado=1;
    }
}

int buscarLibreAuto(eAuto vec[], int tam)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].estado==1)
        {
            indice=i;
        }

    }

    return indice;
}

int buscarPatente(eAuto vecA[],int tamA,char patente[])
{
    int indice=-1;

    for(int i=0; i<tamA; i++)
    {
        if(vecA[i].estado == 0 && strcmp(vecA[i].patente, patente) == 0)
        {
            indice =i;
        }
    }


    return indice;
}

int altaAuto(eAuto vecA[],int tamA, eMarca vecM[], int tamM, eColor vecC[], int tamC,int id)
{
    int indice;
    int idMarca;
    int idColor;
    int todoOk=0;

    system("cls");

    printf("**** MENU DE ALTA ****\n\n");

    indice=buscarLibreAuto(vecA,tamA);

    if(indice == -1)
    {
        printf("No hay mas lugar en el sistema.\n\n");
    }
    else
    {
        vecA[indice].idAuto=id;

        obtenerPatente(vecA[indice].patente,"Ingrese patente LLLNNN: ");

        mostrarMarcas(vecM,tamM);
        printf("\nIngrese numero de marca: ");
        scanf("%d",&idMarca);

        if(idMarca < 1000 || idMarca > 1004)
        {
            printf("\nIngrese numero de marca: ");
            scanf("%d",&idMarca);
        }

        vecA[indice].idMarca=idMarca;

        mostrarColores(vecC,tamC);
        printf("\nIngrese numero del color: ");
        scanf("%d",&idColor);

        if(idColor < 5000 || idColor > 5004)
        {
            printf("\nIngrese numero del color: ");
            scanf("%d",&idColor);
        }

        vecA[indice].idColor=idColor;

        getIntRange(&vecA[indice].anioFabricacion, 1900,2020,"Ingrese anio del auto: ");

        vecA[indice].estado=0;

        printf("\n\nAlta realizada con exito.\n\n");
        todoOk=1;

    }

    return todoOk;
}

int bajaAuto(eAuto vecA[],int tamA, eMarca vecM[], int tamM, eColor vecC[], int tamC)
{
    int todoOk=0;
    int indice;
    char patente[10];

    system("cls");

    printf("**** MENU DE BAJA ****\n\n");

    mostrarAutos(vecA,tamA,vecM,tamM,vecC,tamC);

    obtenerPatente(patente,"Ingrese patente: ");

    indice = buscarPatente(vecA,tamA,patente);

    if(indice== -1)
    {
        printf("No existe esa patente en el sistema.\n\n");
    }
    else
    {
        vecA[indice].estado=1;
        printf("\nOperacion realizada con exito\n\n");
        todoOk=1;
    }

    return todoOk;

}

int menuModificacion()
{
    int opcion;

    system("cls");

    printf("**** MENU DE MODIFICACION    ****\n\n");
    printf("1. Color\n");
    printf("2. Modelo\n");
    printf("3. Menu principal\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    while(opcion < 1 || opcion > 3)
    {
        printf("Ingrese opcion valida: ");
        scanf("%d",&opcion);
    }

    return opcion;
}

int modificarAuto(eAuto vecA[],int tamA, eMarca vecM[], int tamM, eColor vecC[], int tamC)
{
    int todoOk=0;
    int indice;
    int idColor;
    int confirma;
    char patente[10];

    system("cls");

    printf("**** MENU DE MODIFICACION   ****\n\n");

    mostrarAutos(vecA,tamA,vecM,tamM,vecC,tamC);

    obtenerPatente(patente,"Ingrese patente: ");

    indice = buscarPatente(vecA,tamA,patente);

    if(indice== -1)
    {
        printf("No existe esa patente en el sistema.\n\n");
    }
    else
    {
        do
        {
            switch(menuModificacion())
            {
            case 1:
                mostrarColores(vecC,tamC);
                printf("\nIngrese numero del color: ");
                scanf("%d",&idColor);

                if(idColor < 5000 || idColor > 5004)
                {
                    printf("\nIngrese numero del color: ");
                    scanf("%d",&idColor);
                }

                vecA[indice].idColor=idColor;
                break;

            case 2:
                getIntRange(&vecA[indice].anioFabricacion, 1900,2020,"Ingrese anio del auto: ");
                break;

            case 3:
                confirma=confimarSalir("\n\nVolver al menu principal? s/n: ");
                break;
            }

        }
        while(confirma == 1);

        todoOk=1;
    }

    return todoOk;

}

void mostrarColor(eColor vec)
{
    printf("%d  %10s\n",vec.idColor,vec.nomColor);
}

void mostrarColores(eColor vec[], int tam)
{
    system("cls");
    printf(" ID       COLORES\n\n");

    for(int i=0; i<tam; i++)
    {
        mostrarColor(vec[i]);
    }

    printf("\n\n");
}

void mostrarMarca(eMarca vec)
{
    printf("%d  %10s\n",vec.idMarca,vec.nomMarca);
}

void mostrarMarcas(eMarca vec[], int tam)
{
    system("cls");
    printf(" ID      MARCA\n\n");

    for(int i=0; i<tam; i++)
    {
        mostrarMarca(vec[i]);
    }

    printf("\n\n");
}

void nombreColor(eColor vec[], int tam,int id, char dondeAsignar[])
{
    for(int i=0; i<tam; i++)
    {
        if(vec[i].idColor == id)
        {
            strcpy(dondeAsignar,vec[i].nomColor);
        }
    }
}


void nombreMarca(eMarca vec[], int tam,int id, char dondeAsignar[])
{
    for(int i=0; i<tam; i++)
    {
        if(vec[i].idMarca == id)
        {
            strcpy(dondeAsignar,vec[i].nomMarca);
        }
    }
}

