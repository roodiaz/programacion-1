#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputDiaz.h"
#include "autos.h"
#include "trabajos.h"

void inicializarTrabajos(eTrabajo vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].estado=1;
    }
}

int buscarLibreTrabajo(eTrabajo vec[], int tam)
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

int altaTrabajo(eTrabajo vecT[], int tamT,eServicio vecS[], int tamS, eAuto vecA[],int tamA, eMarca vecM[], int tamM, eColor vecC[], int tamC, int id)
{
    int indice;
    int indicePatente;
    int idServicio;
    int todoOk=0;
    char patente[10];

    system("cls");

    printf("**** MENU DE ALTA TRABAJOS ****\n\n");

    indice=buscarLibreTrabajo(vecT,tamT);

    if(indice == -1)
    {
        printf("No hay mas lugar en el sistema.\n\n");
    }
    else
    {
        mostrarAutos(vecA,tamA,vecM,tamM,vecC,tamC);

        obtenerPatente(patente,"Ingrese patente LLLNNN: ");

        indicePatente = buscarPatente(vecA,tamA,patente);

        if(indicePatente== -1)
        {
            printf("\n\nNo existe esa patente en el sistema.\n\n");
        }
        else
        {
            vecT[indice].idTrabajo=id;
            strcpy(vecT[indice].patente,patente);

            mostrarServicios(vecS,tamS);

            printf("\nIngrese numero de servicio: ");
            scanf("%d",&idServicio);

            while(idServicio <20000 || idServicio>20003)
            {
                printf("\nIngrese numero de servicio valido: ");
                scanf("%d",&idServicio);
            }

            vecT[indice].idServicio=idServicio;

            printf("Fecha de trabajo:\n\n");

            getIntRange(&vecT[indice].fechaTrabajo.dia,1,31,"Ingrese dia:");
            getIntRange(&vecT[indice].fechaTrabajo.mes,1,12,"Ingrese mes:");
            getIntRange(&vecT[indice].fechaTrabajo.anio,2019,2020,"Ingrese anio:");

            vecT[indice].estado =0;

            printf("\n\nTrabajo dado de alta con exito\n\n");

            todoOk=1;
        }

        todoOk=1;

    }

    return todoOk;
}

void mostrarTrabajo(eTrabajo vec, eServicio vecS[],int tamS)
{
    char servicio[20];

    nombreServicio(vecS,tamS,vec.idServicio,servicio);

    printf("%d   %s    %10s     %02d/%02d/%d\n",vec.idTrabajo,vec.patente,servicio, vec.fechaTrabajo.dia,vec.fechaTrabajo.mes,vec.fechaTrabajo.anio);

}

void mostrarTrabajos(eTrabajo vec[],int tam,eServicio vecS[],int tamS)
{
    int cont=0;

    system("cls");

    printf("ID    PATENTE     SERVICIO    FECHA TRABAJO\n\n");

    for(int i=0; i<tam; i++)
    {
        if(vec[i].estado ==0)
        {
            mostrarTrabajo(vec[i],vecS,tamS);
            cont++;
        }
    }

    if(cont==0)
    {
        printf("No hay datos para mostrar\n\n");
    }
}

void mostrarServicio(eServicio vec)
{
    printf("%d   %10s      %d\n",vec.idServicio,vec.nomServicio,vec.precio);
}

void mostrarServicios(eServicio vec[], int tam)
{
    system("cls");
    printf("  ID      SERVICIOS     PRECIO\n\n");

    for(int i=0; i<tam; i++)
    {
        mostrarServicio(vec[i]);
    }

    printf("\n\n");
}



void nombreServicio(eServicio vec[], int tam,int id, char dondeAsignar[])
{
    for(int i=0; i<tam; i++)
    {
        if(vec[i].idServicio == id)
        {
            strcpy(dondeAsignar,vec[i].nomServicio);
        }
    }
}


