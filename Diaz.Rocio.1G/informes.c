#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "inputDiaz.h"
#include "autos.h"
#include "trabajos.h"
#include "informes.h"

int menuInformes()
{
    int opcion;

    system("cls");
    printf("#####  Menu de Informes  ####\n\n");

    printf("    1_ Listar autos por color.\n");
    printf("    2_ Mostrar autos de marca seleccionada.\n");
    printf("    3_ Mostrar todos los trabajos aplicado a un auto.\n");
    printf("    4_ Listar autos que no tuvieron trabajos.\n");
    printf("    5_ Importe total de trabajos realizados a un auto.\n");
    printf("    6_ Mostrar servicio mas pedido.\n");
    printf("    7_ Mostrar recaudacion en fecha especifica.\n");
    printf("    8_ Mostrar autos que realizaron encerado y fecha.\n");
    printf("    9_ Trabajos realizados a autos blancos.\n");
    printf("    10_ Facturacion total por pulidos.\n");
    printf("    11_ Listar autos que recibieron trabajos en una fecha especifica.\n");
    printf("    12_ Volver al menu principal.\n");
    printf("\n\n>>>> Opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

void mostrarAutosPorColor(eAuto lista[], int tam, eColor color[], int tamColor, eMarca marca[], int tamMarca)
{
    int idColor;
    int indiceColor;

    mostrarColores(color, tamColor);
    printf("\nIngrese el Id del color: ");
    scanf("%d",&idColor);


    while(buscarColorPorId(color, tamColor, idColor)==-1)
    {
        printf("\nNo existe ese id!!!\n");
        printf("\nIngrese el Id del color: ");
        scanf("%d",&idColor);
    }

    indiceColor=buscarColorPorId(color, tamColor, idColor);

    if(indiceColor != -1)
    {
        system("cls");
        printf("   ID       Patente      Marca    Color     Modelo    Nombre   Sexo");
        printf("\n");
        for(int i=0; i<tam; i++)
        {
            if(lista[i].ocupado == 1 && lista[i].idColor == idColor)
            {
                mostrarAuto(lista[i],color, tamColor, marca, tamMarca);
            }
        }
    }
}

void mostrarAutosPorMarca(eAuto lista[], int tam, eColor color[], int tamColor, eMarca marca[], int tamMarca)
{
    int idMarca;
    int indiceMarca;

    mostrarMarcas(marca, tamMarca);
    printf("\nIngrese el Id de la marca: ");
    scanf("%d",&idMarca);

    while(buscarMarcaPorId(marca, tamMarca, idMarca)==-1)
    {
        printf("\nNo existe ese id!!!\n");
        printf("\nIngrese el Id de la marca: ");
        scanf("%d",&idMarca);
    }

    indiceMarca=buscarMarcaPorId(marca, tamMarca, idMarca);

    if(indiceMarca != -1)
    {
        system("cls");
        printf("   ID       Patente      Marca    Color     Modelo    Nombre   Sexo");
        printf("\n");
        for(int i=0; i<tam; i++)
        {
            if(lista[i].ocupado==1 && lista[i].idMarca==idMarca)
            {
                mostrarAuto(lista[i],color, tamColor, marca, tamMarca);
            }
        }
    }
}

void trabajosUnAuto(eAuto listA[], int tamA, eServicio listaS[], int tamS, eTrabajo listT[], int tamT, eColor listC[], int tamC, eMarca listM[], int tamM)
{
    int indicePatente;
    char patente[10];

    mostrarAutos(listA, tamA, listC, tamC, listM, tamM);
    validarPatente(patente, "Ingrese patente: ");

    while(buscarAutoPorPatente(listA, tamA, patente)==-1)
    {
        printf("\nNo existe esa patente!!!\n");
        validarPatente(patente, "Ingrese patente: ");
    }

    indicePatente=buscarAutoPorPatente(listA, tamA, patente );

    if(indicePatente != 1)
    {
        system("cls");
        printf(" ID    PATENTE    TRABAJO   FECHA");
        printf("\n");

        for(int i=0; i<tamT; i++)
        {
            if(stricmp(listT[i].patente, patente)==0 && listT[i].ocupado==1)
            {
                mostrarTrabajo(listT[i], listaS, tamS);
            }
        }
    }
}

void autosSinTrabajos(eAuto listA[], int tamA, eTrabajo listaT[], int tamT, eColor listaC[], int tamC, eMarca listaM[], int tamM)
{

    system("cls");
    printf("   ID       Patente      Marca    Color     Modelo    Nombre   Sexo");
    printf("\n");

    for(int i=0; i<tamT; i++)
    {
        for(int j=0; j<tamA; j++)
        {
            if(stricmp(listaT[i].patente, listA[j].patente)==0 && listaT[i].ocupado!=1)
            {
                mostrarAuto(listA[i], listaC, tamC, listaM, tamM);
            }
        }
    }
}

void importePorAuto(eAuto listA[], int tamA, eServicio listaS[], int tamS, eTrabajo listT[], int tamT, eColor listC[], int tamC, eMarca listM[], int tamM)
{
    int indicePatente;
    int acumulador=0;
    char patente[10];

    mostrarAutos(listA, tamA, listC, tamC, listM, tamM);
    validarPatente(patente, "Ingrese patente: ");

    while(buscarAutoPorPatente(listA, tamA, patente)==-1)
    {
        printf("\nNo existe esa patente!!!\n");
        validarPatente(patente, "Ingrese patente: ");
    }

    indicePatente=buscarAutoPorPatente(listA, tamA, patente );

    if(indicePatente != 1)
    {
        system("cls");
        printf(" ID    PATENTE    TRABAJO   FECHA");
        printf("\n");

        for(int i=0; i<tamT; i++)
        {
            for(int j=0; j<tamS; j++)
            {
                if(stricmp(listT[i].patente, patente)==0 && listT[i].idServicio==listaS[j].idServicio)
                {
                    mostrarTrabajo(listT[i], listaS, tamS);
                    acumulador+=listaS[j].precio;
                }
            }
        }
        printf("\nImporte total: %d.\n\n", acumulador);
        system("pause");
    }
}

void servicioMasPedido(eTrabajo listaT[], int tamT, eServicio listaS[], int tamS)
{

    int cont[tamS];
    int flag=0;
    int mayor;


    for(int i=0; i<tamS; i++)
    {
        cont[i] = 0;

        for(int j=0; j<tamT; j++)
        {
            if(listaS[i].idServicio==listaT[j].idServicio && listaT[j].ocupado==1)
            {
                cont[i]++;
            }
        }
    }

    for(int i=0; i<tamS; i++)
    {
        for(int j=i+1; i<tamS; i++)
        {
            if(flag == 0 || cont[i]>cont[j])
            {
                mayor=cont[i];
                flag=1;
            }
            else
            {
                if(cont[i]<cont[j])
                {
                    mayor=cont[j];
                }
            }
        }
    }

    for(int i=0 ; i<tamS;i++)
    {
        if( cont[i] >= mayor)
        {
            printf("El servicio mas popular es : %s con %d trabajos\n", listaS[i].nombreServicio,cont[i]);
        }
    }
}
