#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "biblioteca.h"
#include "inputDiaz.h"

#define TAMMARCA 20
#define TAMCOLOR 10
#define TAMSERVICIO 20
#define TAMAUTO 30


int main()
{

    eAuto listaAuto[TAMAUTO];
    inicializarAuto(listaAuto, TAMAUTO);
    hardCodeAutos(listaAuto);

    eMarca listaMarcas[TAMMARCA];
    inicializarMarca(listaMarcas, TAMMARCA);
    hardCodeMarcas(listaMarcas);

    eColor listaColor[TAMCOLOR];
    hardCodeColores(listaColor);

    eServicio listaServicio[TAMSERVICIO];
    hardCodeServicio(listaServicio);

    int flag=0;
    char seguir = 's';
    char confirma;


    do
    {
        switch(menuABM())
        {
        case 1:
            altaAuto(listaAuto, TAMAUTO, listaMarcas, TAMMARCA, listaColor, TAMCOLOR);
            flag=1;
            break;

        case 2:
            if(flag == 0)
            {
                printf("\nPrimero debe dar de alta un auto!!!!.\n\n");
                system("pause");
            }
            else
            {
                modificacionAuto(listaAuto, TAMAUTO, listaColor, TAMCOLOR);
            }
            break;

        case 3:
            if(flag == 0)
            {
                printf("\nPrimero debe dar de alta un auto!!!!.\n\n");
                system("pause");
            }
            else
            {
                bajaAuto(listaAuto, TAMAUTO);
            }
            break;

        case 4:
            if(flag == 0)
            {
                printf("\nPrimero debe dar de alta un auto!!!!.\n\n");
                system("pause");
            }
            else
            {
                ordenarAutos(listaAuto, TAMAUTO);
                mostrarAutos(listaAuto, TAMAUTO);
            }

            break;

        case 5:
            mostrarMarcas(listaMarcas, TAMMARCA);
            break;

        case 6:
            mostrarColores(listaColor, TAMCOLOR);
            break;

        case 7:
            mostrarServicios(listaServicio, TAMSERVICIO);
            break;

        case 8:

            break;

        case 9:
            printf("\nConfirma salida s/n?: ");
            fflush(stdin);
            confirma = getche();

            if( tolower(confirma) == 's')
            {
                seguir = 'n';
            }
            break;

        default:
            printf("\n\nNo se ha ingresado una opcion valida!!!!.\n\n");
            system("pause");
            menuABM();
        }

    }
    while(seguir == 's');

    return 0;
}
