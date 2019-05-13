#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "autos.h"
#include "trabajos.h"

#define TAMAUTO 10
#define TAMMARCA 5
#define TAMCOLOR 5
#define TAMSERVICIO 4
#define TAMTRABAJO 10

int main()
{
    eAuto listaAuto[TAMAUTO]= {{500,"zad-414", 1000, 6000, 2009, 1},{300, "jff-523", 1000, 9000, 2018, 1},{100, "aza-253", 4000, 8000, 2000, 1}, {600, "cbc-123", 3000, 7000, 2011, 1}};
    eMarca listaMarcas[TAMMARCA] = {{1000, "Fiat"},{2000, "Ford"},{3000, "Chevrolet"},{4000, "Renault"},{5000, "Peugeot"}};
    eColor listaColor[TAMCOLOR] = {{5000, "Rojo"},{6000, "Azul"},{7000, "Bordo"},{8000, "Negro"},{9000, "Gris"}};
    eServicio listaServicio[TAMSERVICIO] ={{40000, "Lavado", 250},{60000, "Pulido", 300},{70000, "Encerado", 400},{30000, "Completo", 600}};
    eTrabajo listTrabajo[TAMTRABAJO]={{1, "tew-624", 40000,{12,3,2019},1},{2,"hsg-733",70000,{4,10,2019},1},{3,"mgf-635",30000,{12,3,2019},1}};

    char salir = 'n';
    char confirma;

    do
    {
        switch(menuABM())
        {
        case 1:
            altaAuto(listaAuto, TAMAUTO, listaColor, TAMCOLOR, listaMarcas, TAMMARCA);
            break;
        case 2:
            modificarAuto(listaAuto, TAMAUTO, listaColor, TAMCOLOR, listaMarcas, TAMMARCA);
            break;
        case 3:
            bajaAuto(listaAuto, TAMAUTO, listaColor, TAMCOLOR, listaMarcas, TAMMARCA);
            break;
        case 4:
            ordenarAutos(listaAuto, TAMAUTO);
            mostrarAutos(listaAuto, TAMAUTO, listaColor, TAMCOLOR, listaMarcas, TAMMARCA);
            system("pause");
            break;
        case 5:
            mostrarMarcas(listaMarcas, TAMMARCA);
            system("pause");
            break;

        case 6:
            mostrarColores(listaColor, TAMCOLOR);
            system("pause");
            break;
        case 7:
            mostrarServicios(listaServicio, TAMSERVICIO);
            system("pause");
            break;
        case 8:
            altaTrabajo(listTrabajo, TAMTRABAJO, listaServicio, TAMSERVICIO, listaAuto, TAMAUTO, listaColor, TAMCOLOR, listaMarcas, TAMMARCA);
            system("pause");
            break;
        case 9:
            mostrarTrabajos(listTrabajo, TAMTRABAJO, listaServicio, TAMSERVICIO);
            system("pause");
            break;
        case 10:
            printf("\nDesea salir? s/n: ");
            fflush(stdin);
            confirma = getche();

            if( tolower(confirma) == 's')
            {
                salir = 'n';
            }
            break;

        default:
            printf("\n\nNo se ha ingresado una opcion valida!!!!.\n\n");
            system("pause");
            menuABM();

        }
    }while(salir == 'n');


    return 0;
}
