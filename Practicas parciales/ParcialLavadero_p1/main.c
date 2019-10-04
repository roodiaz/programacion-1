#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputDiaz.h"
#include "autos.h"
#include "trabajos.h"

#define TAM 50
#define TAMT 20
#define TAMM 5
#define TAMS 4
#define TAMC 5


int main()
{
    int salir;
    int idAuto=100;
    int idTrabajo=500;

    eMarca marcas[TAMM]= {{1000,"Renault"},{1001,"Fiat"},{1002,"Ford"},{1003,"Chevrolet"},{1004,"Peugeot"}};
    eColor colores[TAMC]= {{5000,"Negro"},{5001,"Blanco"},{5002,"Gris"},{5003,"Rojo"},{5004,"Azul"}};
    eServicio servicios[TAMS]= {{20000,"Lavado",250},{20001,"Pulido",300},{20002,"Encerado",400},{20003,"Completo",600}};
    eAuto autos[TAM];
    eTrabajo trabajo[TAMT];

    inicializarAutos(autos,TAM);
    inicializarTrabajos(trabajo,TAMT);

    do
    {
        switch(menuOpciones())
        {
        case 1 :
            if(altaAuto(autos,TAM,marcas,TAMM,colores,TAMC,idAuto)==1)
            {
                idAuto++;
            }
            break;

        case 2 :
            modificarAuto(autos,TAM,marcas,TAMM,colores,TAMC);
            break;

        case 3 :
            bajaAuto(autos,TAM,marcas,TAMM,colores,TAMC);
            break;

        case 4 :
            mostrarAutos(autos,TAM,marcas,TAMM,colores,TAMC);
            break;

        case 5 :
            mostrarMarcas(marcas,TAMM);
            break;

        case 6 :
            mostrarColores(colores,TAMC);
            break;

        case 7 :
            mostrarServicios(servicios,TAMS);
            break;

        case 8 :
            if(altaTrabajo(trabajo,TAMT,servicios,TAMS,autos,TAM,marcas,TAMM,colores,TAMC,idTrabajo))
            {
                idTrabajo++;
            }
            break;

        case 9 :
            mostrarTrabajos(trabajo,TAMT,servicios,TAMS);
            break;

        case 10 :
            salir=confimarSalir("\n\nDesea salir? s/n: ");
            break;

        default:
            printf("Opcion invalida.\n\n");

        }
        printf("\n\n");
        system("pause");

    }
    while(salir != 1);


    return 0;
}
