#include <stdio.h>
#include <stdlib.h>
#include "inputDiaz.h"
#include "empleados.h"
#include "sectores.h"
#include "menus.h"
#include "almuerzos.h"

#define TAME 6
#define TAMA 15
#define TAMS 5
#define TAMM 5

int menuABM();

int main()
{
    int salir;
    int idEmp=1000;
    int idAlm=10000;

    eEmpleado emp[TAME];
    eSector sec[TAMS];
    eMenu menu[TAMM];
    eAlmuerzo alm[TAMA];

    inicializarEmpleados(emp,TAME);
    inicializarAlmuerzos(alm,TAMA);

    idEmp=idEmp+harcodearEmp(emp,TAME,5);
    idAlm=idAlm+harcodearAlmuerzos(alm,TAMA,11);
    harcodearSectores(sec,TAMS);
    harcodearMenus(menu,TAMM);

    do
    {
        switch(menuABM())
        {
        case 1:
            if(altaEmp(emp,TAME,sec,TAMS,idEmp)==1)
            {
                idEmp++;
            }
            break;

        case 2:
            modificarEmp(emp,TAME,sec,TAMS);
            break;

        case 3:
            bajaEmp(emp,TAME,sec,TAMS);
            break;

        case 4:
            ordenarEmp(emp,TAME);
            mostrarEmpleados(emp,TAME,sec,TAMS);
            break;

        case 5:
            break;

        case 6:
            mostrarAlmuerzos(alm,TAMA,menu,TAMM,emp,TAME);
            break;

        case 7:
            mostrarSectores(sec,TAMS);
            break;

        case 8:
            mostrarMenus(menu,TAMM);
            break;

        case 9:
            salir=confimarSalir("\nDesea salir? s/n: ");
            break;

        default:
            printf("\nOpcion invalida\n\n");
        }
        printf("\n\n");
        system("pause");

    }
    while(salir!=1);

    return 0;
}

int menuABM()
{
    int opcion;

    system("cls");
    printf("  ***  MENU DE OPCIONES ***   \n\n");
    printf("1. Alta empleado\n");
    printf("2. Modificar empleado\n");
    printf("3. Baja empleado\n");
    printf("4. Listar empleados\n");
    printf("5. Alta almuerzo\n");
    printf("6. Listar almuerzos\n");
    printf("7. Listar sectores\n");
    printf("8. Listar menus\n\n");
    printf("9. Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}
