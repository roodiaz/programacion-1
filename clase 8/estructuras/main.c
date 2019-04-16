#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VACIO 0
#define OCUPADO 1

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int estado;

} Eempleado;

void mostrarEmpleado(Eempleado empleado[], int i);
void mostrarEmpleados(Eempleado empleado[], int tam);
int cargarEmpleado(Eempleado empleado[], int tam);
int buscarVacio(Eempleado empleado[], int tam);


int main()
{
    Eempleado nomina[3];
    int opcion;

    for(int i= 0 ; i<3 ; i++)
    {
        nomina[i].estado=VACIO;  // actualizo el estado a 0 para q sea el flag 0 y sepa q esta libre para agregar datos.
    }
    do
    {
        printf("1- Alta empleado: \n");
        printf("2- Mostrar empleado:\n ");
        printf("3- Ordenar empleado: \n");
        printf("4- Salir: \n");

        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            if(cargarEmpleado(nomina,3)==-1)
            {
                printf("No hay mas espacio..");
            }
            else
            {
                printf("Empleado generado.");
            }

            break;

        case 2:
            mostrarEmpleados(nomina,3);
            break;

        case 3:
            ordenarEstructura(nomina,3);
            break;

        }
    }
    while(opcion!=4);
    system("cls");



    /*Eempleado emp1;
    char auxString[100];

    printf("Ingresar legajo: ");
    scanf("%d", &emp1.legajo);

    while(emp1.legajo<1000 || emp1.legajo>9999)
    {
        printf("Error, ingresar legajo: ");
        scanf("%d", &emp1.legajo);
    }

    printf("Ingresar nombre del empleado: ");
    fflush(stdin);
    gets(auxString);

    while(strlen(auxString)>19)
    {
       printf("Error, ingresar nombre del empleado: ");
        gets(auxString);
    }

    strcpy(emp1.nombre, auxString);

    printf("Ingresar sexo del empleado sea f o m : ");
    fflush(stdin);
    scanf("%c", &emp1.sexo);

    while(emp1.sexo!='f' && emp1.sexo!='m')
    {
        printf("Error, ingresar sexo del empleado sea f o m: ");
        scanf("%c", &emp1.sexo);
    }

    printf("Ingresar sueldo del empleado: ");
    fflush(stdin);
    scanf("%f", &emp1.sueldo);

    while(emp1.sueldo<0)
    {
       printf("Ingresar sueldo del empleado: ");
        scanf("%f", &emp1.sueldo);
    }

    printf("      ******Empleados******\n\n");
    printf("Legajo     Nombre      sexo     sueldo \n");
    printf("%d    %s    %c      %.2f   ", emp1.legajo , emp1.nombre, emp1.sexo, emp1.sueldo);*/

    /*
        Eempleado empleado[3]={{8951, "jose", 'm', 25800},{1235, "juan", 'm',60580},{5015, "ana", 'f', 35874}};


        mostrarEmpleado(empleado,0);
        //mostrarEmpleado(empleado,2);
        //mostrarEmpleado(empleado,1);

        printf("Otra funcion \n");

        mostrarEmpleados(empleado,3);

        printf("Ahora ordenado!!!\n");

        ordenarEstructura(empleado,3);
        mostrarEmpleados(empleado,3);
        */
}

void mostrarEmpleado(Eempleado empleado[], int i)
{

    printf("Legajo : %d > Nombre : %s > Sexo : %c > Sueldo : %.2f\n", empleado[i].legajo, empleado[i].nombre, empleado[i].sexo, empleado[i].sueldo);
}

void mostrarEmpleados(Eempleado empleados[], int tam)
{
    for(int i = 0 ; i < tam ; i++)
    {
        if(empleados[i].estado==OCUPADO)
        {
            printf("Legajo : %d > Nombre : %s > Sexo : %c > Sueldo : %.2f\n", empleados[i].legajo, empleados[i].nombre, empleados[i].sexo, empleados[i].sueldo);
        }

    }
}

void ordenarEstructura(Eempleado empleado[], int tam)
{
    Eempleado auxEmpleado;

    for(int i = 0 ; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(empleado[i].legajo>empleado[j].legajo)
            {
                auxEmpleado=empleado[i];
                empleado[i]=empleado[j];
                empleado[j]=auxEmpleado;
            }
        }
    }
}

int cargarEmpleado(Eempleado empleado[], int tam)
{
    char auxString[100];
    int index = buscarVacio(empleado,tam);
    if(index!=-1)
    {
        printf("Ingresar legajo: ");
        scanf("%d", &empleado[index].legajo);

        while(empleado[index].legajo<1000 || empleado[index].legajo>9999)
        {
            printf("Error, ingresar legajo: ");
            scanf("%d", &empleado[index].legajo);
        }

        printf("Ingresar nombre del empleado: ");
        fflush(stdin);
        gets(auxString);

        while(strlen(auxString)>19)
        {
            printf("Error, ingresar nombre del empleado: ");
            gets(auxString);
        }

        strcpy(empleado[index].nombre, auxString);

        printf("Ingresar sexo del empleado sea f o m : ");
        fflush(stdin);
        scanf("%c", &empleado[index].sexo);

        while(empleado[index].sexo!='f' && empleado[index].sexo!='m')
        {
            printf("Error, ingresar sexo del empleado sea f o m: ");
            scanf("%c", &empleado[index].sexo);
        }

        printf("Ingresar sueldo del empleado: ");
        fflush(stdin);
        scanf("%f", &empleado[index].sueldo);

        while(empleado[index].sueldo<0)
        {
            printf("Ingresar sueldo del empleado: ");
            scanf("%f", &empleado[index].sueldo);
        }

        empleado[index].estado=OCUPADO;

    }
    else
    {
        printf("No hay espacio en la memoria...\n");
        system("cls");
    }

    return index;


}

int buscarVacio(Eempleado empleado[], int tam)
{
    int indice=-1;
    for(int i=0;i<tam;i++)
    {
        if(empleado[i].estado==VACIO)
        {
            indice=i;
            break;
        }
    }

    return indice;
}
