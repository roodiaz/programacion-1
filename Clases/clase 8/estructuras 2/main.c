#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#define TAM 10
#define TAMSEC 5

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int id;
    char descripcion[20];

}eSector;

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fechaIngreso;
    int idSector;
    int ocupado;

} eEmpleado;

int menu();
int buscarLibre(eEmpleado vec[], int tam);
int buscarEmpleado(eEmpleado vec[], int tam, int legajo);
int obtenerSector (eSector sectores[], int tam, int idSector, char desc[]);
void inicializarEmpleados(eEmpleado vec[], int tam);
void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSec);
void altaEmpleado(eEmpleado vec[], int tam);
void bajaEmpleado(eEmpleado vec[], int tam);
void ModificacionEmpleado(eEmpleado vec[], int tam);
void harcodearEmpleados(eEmpleado vec[], int tam);
void empleadosPorAnio (eEmpleado vec [], int tam, int anio);

int main()
{
    char seguir = 's';
    char confirma;
    int anio;
    eSector sectores
    eEmpleado lista[TAM];
    inicializarEmpleados(lista, TAM);
    harcodearEmpleados(lista, TAM);

    do
    {
        switch(menu())
        {

        case 1:
            altaEmpleado(lista, TAM);
            system("pause");
            break;

        case 2:
            bajaEmpleado(lista, TAM);
            system("pause");
            break;

        case 3:
            ModificacionEmpleado(lista,TAM);
            system("pause");
            break;

        case 4:
            printf("\nOrdenar empleados\n\n");
            system("pause");
            break;

        case 5:
            mostrarEmpleados(lista, TAM, sectores, TAMSEC);
            system("pause");
            break;

        case 6:
            printf("Informes\n");
            system("pause");

            printf("Ingrese anio: ");
            scanf("%d", &anio);
            empleadosPorAnio(lista, TAM, anio);

        case 7:
            printf("\nConfirma salida s/n?: ");
            fflush(stdin);
            confirma = getche();

            if( tolower(confirma) == 's')
            {
                seguir = 'n';
            }
            break;

        default:
            printf("\n Opcion invalida\n\n");
            system("break");
        }
    }
    while(seguir == 's');

    return 0;
}

void inicializarEmpleados(eEmpleado vec[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        vec[i].ocupado = 0;
    }
}

int menu()
{
    int opcion;

    system("cls");
    printf("  *** ABM Empleados ***\n\n");
    printf("1- Alta Empleado.\n");
    printf("2- Baja Empleado.\n");
    printf("3- Modificacion Empleado.\n");
    printf("4- Ordenar Empleados.\n");
    printf("5- Listar Empleados.\n");
    printf("6- Empleados por anio.\n");
    printf("7- Salir\n\n");
    printf("Ingrese opcion: ");
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

int buscarEmpleado(eEmpleado vec[], int tam, int legajo)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].legajo == legajo && vec[i].ocupado == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarEmpleado(eSector sectores[], int tamSec, eEmpleado emp)
{
    char nombreSector[20];
    int consigioNombre;

    consigioNombre = obtenerSector(sectores, tamSec, emp.idSector, nombreSector);

    if(!consigioNombre)
    {
        strcpy(nombreSector, "Sin definir");
    }
    printf("\nLegajo: %d\nNombre: %s\nSexo: %c\nSueldo: %.2f\nFecha ingreso: %02d/%02d/%d\nSector: %s\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo, emp.fechaIngreso.dia, emp.fechaIngreso.mes, emp.fechaIngreso.anio, nombreSector);
}

void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{
    int cont= 0;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1)
        {
            mostrarEmpleado(sec[i], tam, vec[i])
            cont++;
        }
    }
    if(cont == 0)
    {
        printf("No hay empleados que mostrar\n\n");
    }
}

void altaEmpleado(eEmpleado vec[], int tam)
{
    int indice;
    int legajo;
    int esta;
    char auxString [100];

    indice = buscarLibre(vec, tam);

    if(indice == -1)
    {
        printf("No hay lugar");
    }
    else
    {

        printf("\nIngrese legajo: ");
        scanf("%d", &legajo);

        while(legajo <1000 || legajo>9999)
        {
            printf("Error, ingresar legajo: ");
            scanf("%d", &legajo);
        }

        esta = buscarEmpleado(vec, tam, legajo);

        if( esta == -1)
        {
            vec[indice].legajo = legajo;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(auxString);

            while(strlen(auxString)>19)
            {
                printf("Error, ingresar nombre del empleado: ");
                gets(auxString);
            }

            strcpy(vec[indice].nombre, auxString);


            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &vec[indice].sexo);

            while(vec[indice].sexo!='f' && vec[indice].sexo!='m')
            {
                printf("Error, ingresar sexo del empleado f/m: ");
                fflush(stdin);
                scanf("%c", &vec[indice].sexo);
            }

            printf("Ingrese sueldo: ");
            scanf("%f", &vec[indice].sueldo);

            while(vec[indice].sueldo<0)
            {
                printf("Ingresar sueldo mayor a 0: ");
                scanf("%f", &vec[indice].sueldo);
            }

            printf("Ingrese fecha de ingreso dd mm aa: ");
            scanf("%d %d %d", &vec[indice].fechaIngreso.dia, &vec[indice].fechaIngreso.mes, &vec[indice].fechaIngreso.anio);



            vec[indice].ocupado = 1;

            printf("\nEl empleado ha sido registrado con exito!!!\n\n");

        }
        else
        {

            printf("Ya existe un empleado con el legajo %d\n", legajo);

            mostrarEmpleado(vec[esta]);
        }
    }
}

void bajaEmpleado(eEmpleado vec[], int tam){

    int legajo;
    char confirma;
    int esta;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    esta = buscarEmpleado(vec, tam, legajo);

    if( esta == -1){

        printf("\nEl legajo %d no esta registrado en el sistema\n", legajo);
    }
    else{
        mostrarEmpleado(vec[esta]);

        printf("\nConfirma la eliminacion? s/n");
        fflush(stdin);
        confirma = tolower(getche());

        if(confirma == 's'){
            vec[esta].ocupado = 0;
        }
        else{
            printf("\nLa eliminacion ha sido cancelada\n");
        }
    }
}

void ModificacionEmpleado(eEmpleado vec[], int tam){

    int legajo;
    char confirma;
    float nuevoSueldo;
    int esta;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    esta = buscarEmpleado(vec, tam, legajo);

    if( esta == -1){

        printf("\nEl legajo %d no esta registrado en el sistema\n", legajo);
    }
    else{
        mostrarEmpleado(vec[esta]);

        printf("\nQuiere cambiar el sueldo? s/n: ");
        fflush(stdin);
        confirma = tolower(getche());

        if(confirma == 's'){
            printf("\nIngrese nuevo sueldo: ");
            scanf("%f", &nuevoSueldo);
            //valido sueldo
            vec[esta].sueldo = nuevoSueldo;
        }
        else{
            printf("\nNo se ha modificado el sueldo\n");
        }
    }
}

void harcodearEmpleados(eEmpleado vec[], int tam)
{
    eSector sectores[] =
    {
        {1, "Sistemas"},
        {2, "Compras"},
        {3, "RRHH"},
        {4, "Ventas"},
        {5, "Legales"},
    };

    eEmpleado empleados [10]=
    {
    {123, "Ana", 'm', 3364,{9,8,2012}, 1, 1},
    {183, "Nicolas", 'm', 52355,{15,11,2014}, 1, 1},
    {293, "Rocio", 'f', 24563,{28,8,2016}, 3, 1},
    {324, "Lucas", 'm', 35253,{21,10,2009}, 4, 1},
    {923, "Abril", 'f', 76400,{15,5,2007}, 5, 1},
    {194, "Mariela", 'f', 41400,{11,4,2008}, 2, 1},
    {412, "Diego", 'm', 14345,{3, 7, 2011}, 2, 1},
    {343, "Sofia", 'f', 13453,{12, 6, 2019}, 4, 1},
    {531, "Lautaro", 'm', 45233,{19, 4, 2018}, 3, 1},
    {644, "Juana", 'f', 53000, {12, 3, 2000}, 4, 1},
    };

    for(int i=0;i<tam;i++)
    {
        vec[i]= empleados[i];
    }
}


void empleadosPorAnio(eEmpleado vec [], int tam, int anio)
{
    int cont= 0;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1 && vec[i].fechaIngreso.anio == anio)
        {
            mostrarEmpleado(vec[i]);
            cont++;
        }
    }
    if(cont == 0)
    {
        printf("No hay empleados que mostrar\n\n");
    }
}

int obtenerSector(eSector sectores[], int tamSec, int idSector, char desc[])
{
    int todoOk = 0;

    for(int i=0; i<tam; i++)
    {
        if(idSector == sectores[i].id)
        {
            strcpy(desc, sectores[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}

void mostrarEmpleadosPorSector(eEmpleado vec[], int tam, eSector [], int tamSec)
{

}
