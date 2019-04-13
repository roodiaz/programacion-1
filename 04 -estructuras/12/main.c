#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

typedef struct
{
    int legajo;
    int ocupado;
    char nombre[20];
    char sexo;
    float sueldo;

}Eempleado;

int menuOpciones();
int buscarLibre(Eempleado vec[], int tam);
int buscarEmpleado(Eempleado vec[], int tam,int legajo);
void mostrarEmpleado(Eempleado emp);
void inicializarEmpleados(Eempleado vec[], int tam);
void mostrarEmpleados(Eempleado vec[], int tam);
void altaEmpleado(Eempleado vec[], int tam);


int main()
{
    int TAM = 3;
    Eempleado lista [TAM];
    inicializarEmpleados(lista, TAM); //llamada
    char seguir;
    char confirma;

    do
    {
        switch(menuOpciones())
        {
            case 1:
                printf("\nAlta empleado\n");
                system("pause");
            break;

            case 2:
                printf("\nBaja empleado\n");
                system("pause");
            break;

            case 3:
                printf("\nModificacion empleado\n");
                system("pause");
            break;

            case 4:
                printf("\nOrdenar empleados\n");
                system("pause");
            break;

            case 5:
                printf("\nListar empleados\n");
                system("pause");
            break;

            case 6:
                printf("\n\nConfirmar salida? s/n: ");
                fflush(stdin);
                confirma = getch();

                if(tolower(confirma) == 'S')
                {
                    seguir = 'n';
                }
            break;

            default:
                printf("\nOpcion incorrecta\n\n");
            break;
        }

    }while(seguir == 's');


    return 0;
}

void inicializarEmpleados(Eempleado vec [], int tam)
{
    for(int i=0; i < tam; i++)
    {
        vec[i].ocupado = 0;
    }
}

int buscarLibre(Eempleado vec[], int tam)
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

int buscarEmpleado(Eempleado vec[], int tam, int legajo)
{
    int indice = -1;

    for(int i=0; i< tam; i++)
    {
        if( vec[i].legajo == legajo && vec[i].ocupado == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

void mostrarEmpleado(Eempleado emp)
{
    printf("\nNombre   Legajo   Sexo   Sueldo");
    printf("    %s       %d       %c      %.2f");
}

void mostrarEmpleados(Eempleado vec[], int tam)
{
     for(int i=0; i< tam; i++)
    {
        if( vec[i].ocupado == 1)
        {
            mostrarEmpleado(vec[i]);
        }
    }
}

void altaEmpleado(Eempleado vec[], int tam)
{
    int indice;

    indice = buscarLibre(vec, tam);

    if(indice == -1)
    {
        printf("No hay lugar");
    }
    else
    {

    }
}

int menuOpciones()
{
    int opcion;

    system("cls");
    printf("  *** ABM Empleados  ***\n\n");
    printf("1- Alta empleado.\n");
    printf("2- Baja empleado.\n");
    printf("3- Modificar empleado.\n");
    printf("4- Ordenar.\n");
    printf("5- Listar.\n");
    printf("6- Salir.\n");
    printf("\n>>> Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}



