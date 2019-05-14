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
    printf("    4_ Volver al menu principal.\n");
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
    while(indiceColor==-1)
    {
        printf("\nNo existe ese id!!!\n");
        printf("\nIngrese el Id del color: ");
        scanf("%d",&idColor);
        indiceColor=buscarColorPorId(color, tamColor, idColor);
    }
}


void mostrarAutosPorMarca(eAuto lista[], int tam, eColor color[], int tamColor, eMarca marca[], int tamMarca)
{
    int idMarca;
    int indiceMarca;

    mostrarMarcas(marca, tamMarca);
    printf("\nIngrese el Id de la marca: ");
    scanf("%d",&idMarca);

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
    while(indiceMarca==-1)
    {
        printf("\nNo existe ese id!!!\n");
        printf("\nIngrese el Id de la marca: ");
        scanf("%d",&idMarca);

        indiceMarca=buscarMarcaPorId(marca, tamMarca, idMarca);
    }
}

void mostrarTrabajosUnAuto(eAuto listA[], int tamA, eTrabajo listT[], int tamT, eColor listC[], int tamC, eMarca listM[], int tamM)
{
    int patente;
    int indicePatente;

    mostrarAutos(listA, tamA, listC, tamC, listM, tamM);
    printf("\nIngrese numero patente: ");
    fflush(stdin);

}


