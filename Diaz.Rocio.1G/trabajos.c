#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "inputDiaz.h"
#include "autos.h"
#include "trabajos.h"

int buscarLibreTrabajo(eTrabajo vec[], int tam)
{
    int indice = -1;

    for(int i=0; i <tam; i++)
    {
        if(vec[i].ocupado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int obtenerServicios(eServicio servicio[], int tamServ, int idServicio, char dondeAsignar[])
{
    int todoOk=-1;

    for(int i= 0 ; i<tamServ; i++)
    {
        if(idServicio == servicio[i].idServicio)
        {
            strcpy(dondeAsignar, servicio[i].nombreServicio);
            todoOk=1;
            break;
        }
    }
    return todoOk;
}

void mostrarTrabajo(eTrabajo trabajo, eServicio servico[], int tamServicio)
{
    char nombreSer[25];

    obtenerServicios(servico, tamServicio, trabajo.idServicio, nombreSer);

    printf("ID: %d  Patente: %s  Servicio: %s Fecha:%02d/%02d/%d\n",trabajo.idTrabajo,trabajo.patente,nombreSer,trabajo.fechaTrabajo.dia,trabajo.fechaTrabajo.mes,trabajo.fechaTrabajo.anio);

}

void mostrarTrabajos(eTrabajo vecTrabajo[], int tamTrabajo, eServicio vecServ[], int tamServ)
{
    int cont=0;

    system("pause");

    for(int i=0; i<tamTrabajo; i++)
    {
        if(vecTrabajo[i].ocupado==1)
        {
            mostrarTrabajo(vecTrabajo[i], vecServ, tamServ);
            cont++;
        }
    }
}

void mostrarServicio(eServicio vec)
{
    printf("ID: %d  Servicio: %s  Precio: %d\n",vec.idServicio, vec.nombreServicio, vec.precio);
}

void mostrarServicios(eServicio vec[], int tam)
{
    int cont=0;

    system("cls");

    for(int i=0; i<tam; i++)
    {
        mostrarServicio(vec[i]);
        cont++;
    }
}

void incrementalTrabajo(eTrabajo vec[],int tam)
{
    for (int i=0; i<tam; i++)
    {
        vec[i].idTrabajo=i+1;
    }
}

int buscarServicioPorId(eServicio vec[], int tam, int idServicio)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].idServicio==idServicio)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void altaTrabajo(eTrabajo vecTrabajo[], int tamTrabajo, eServicio vecServ[], int tamServ, eAuto vecAuto[], int tamAuto, eColor vecColor[], int tamColor, eMarca vecMarca[], int tamMarca)
{
    int indice;
    int indicePatente;
    int indiceServicio;
    int id;
    char auxChar[50];

    indice=buscarLibreTrabajo(vecTrabajo, tamTrabajo);

    if(indice != -1)
    {
        incrementalTrabajo(vecTrabajo, tamTrabajo);

        printf("\n## ID: %d\n\n",vecTrabajo[indice].idTrabajo);
        system("pause");

        mostrarAutos(vecAuto, tamAuto, vecColor, tamColor, vecMarca, tamMarca);
        printf("\nIngrese patente: ");
        fflush(stdin);
        gets(auxChar);

        indicePatente=buscarAutoPorPatente(vecAuto, tamAuto, auxChar);

        if(indicePatente != -1)
        {
            strcpy(vecTrabajo[indice].patente, auxChar);

        }
        while(indicePatente==-1)
        {
            printf("\nAuto no registrado!!!\n");
            printf("\nIngrese patente: ");
            fflush(stdin);
            gets(auxChar);
            indicePatente=buscarAutoPorPatente(vecAuto, tamAuto, auxChar);
        }

      /////////////////

        mostrarServicios(vecServ, tamServ);
        printf("\nIngrese Id servicio: ");
        fflush(stdin);
        scanf("%d",&id);

        indiceServicio=buscarServicioPorId(vecServ, tamServ, id);

        if(indiceServicio == -1)
        {
            vecTrabajo[indice].idServicio=id;

        }
        while(indiceServicio==-1)
        {
            printf("\nServicio no registrado!!!\n");
            printf("\nIngrese Id servicio: ");
            fflush(stdin);
            scanf("%d",&id);
            indiceServicio=buscarServicioPorId(vecServ, tamServ, id);
        }

        vecTrabajo[indice].fechaTrabajo.dia=obtenerNumeroEntre(31, 1, "## Ingrese dia: ");
        vecTrabajo[indice].fechaTrabajo.mes=obtenerNumeroEntre(12, 1, "## Ingrese mes: ");
        vecTrabajo[indice].fechaTrabajo.anio=obtenerNumeroIgualA(2019, "## Ingresar anio: ");

        vecTrabajo[indice].ocupado=1;
    }
    else
    {
        printf("No hay mas lugar en el sistema!!!\n\n");
        system("pause");
    }
}



