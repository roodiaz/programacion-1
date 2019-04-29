#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>

# define TAM 1000

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int ocupado;

} eEmployee;

int menuAMB();
int buscarLibre(eEmpleado vec[], int tam);
int buscarEmpleado(eEmpleado vec[], int tam, int id);

int main()
{
    char confirma;
    char seguir = 's';

    eEmployee lista [TAM];
    eSector sectores[]= {{1,"RRHH"},{2,"Ventas"},{3,"Legales"},{4,"Compras"},{5,"Sistemas"}};



    do
    {
        switch(menuAMB())
        {
            case 1:
            break;

            case 2:
            break;

            case 3:
            break;

            case 4:
            break;

            case 5:
            printf("\nConfirma salida s/n?: ");
            fflush(stdin);
            confirma = getche();

            if( tolower(confirma) == 's')
            {
                seguir = 'n';
            }
            break;
            break;

            default:
                printf("\n Opcion invalida\n\n");
                system("break");

        } while (seguir == 's');


    } while ();

    return 0;
}

int menuAMB()
{
    int opcion;

    printf("****** Menu ABM ******");
    printf("1_ Altas.");
    printf("2_ Modificar");
    printf("3_ Bajas.");
    printf("4_ Informar.");
    printf("5_ Salir");
    scanf("%d", &opcion);

    return opcion;
}

int buscarLibre(eEmpleado vec[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarEmpleado(eEmpleado vec[], int tam, int id)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1 && vec[i].id == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


void altaEmpleado(eEmployee vec[], int tam)
{

    int indice;
    int esta;

    indice = buscarLibre(vec, tam);

    if( indice == -1)
    {
        printf("\nNo hay lugar en el sistema para dar de alta\n");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarEmpleado(vec, tam, legajo);

        if( esta != -1)
        {
            printf("Existe un empleado de legajo %d en el sistema\n", legajo);
            mostrarEmpleado(sectores, tamSector, vec[esta]);
        }
        else
        {
            vec[indice].legajo = legajo;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(vec[indice].nombre);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &vec[indice].sexo );

            printf("Ingrese sueldo: ");
            scanf("%f", &vec[indice].sueldo );

            printf("Ingrese fecha de ingreso dd/mm/aaaa: ");
            scanf("%d %d %d", &vec[indice].fechaIngreso.dia, &vec[indice].fechaIngreso.mes, &vec[indice].fechaIngreso.anio);

            mostrarSectores(sectores, tamSector);

            printf("Ingrese id sector: ");
            scanf("%d", &vec[indice].idSector);


            vec[indice].ocupado = 1;

            printf("Alta empleado exitosa!!!\n\n");

        }
    }
}


