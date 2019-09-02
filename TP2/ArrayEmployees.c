#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include "ArrayEmployees.h"

int menuABM()
{
    int opcion;

    system("cls");
    printf("##### Menu ABM #####\n\n");
    printf("   1. Altas.\n");
    printf("   2. Modificar.\n");
    printf("   3. Bajas.\n");
    printf("   4. Informar.\n\n");
    printf("   5. Salir.\n\n");
    printf(">> Ingresar opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

void mostrarEmpleado(eEmpleado empleado)
{
    printf("\n%5d  %10s  %10s  %11.2f  %7d\n", empleado.id, empleado.nombre, empleado.apellido, empleado.sueldo, empleado.sector);
}

void mostrarEmpleados(eEmpleado vec[], int tam)
{
    int contador = 0;

    system("cls");

    printf("  ID      Nombre     Apellido      Sueldo    Sector\n");
    printf(" ----    --------   ----------    --------   ------\n\n");

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1)
        {
            mostrarEmpleado(vec[i]);
            contador++;
        }
    }
    printf("\n\n");

    if( contador == 0)
    {
        printf("\nNo hay empleados que mostrar\n");
    }
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

void altaEmpleado(eEmpleado vec[], int tam)
{

    int indice;
    int id;
    int ocupado;
    char auxChar[100];

    indice = buscarLibre(vec, tam);

    if( indice == -1)
    {
        printf("\nNo hay lugar en el sistema\n");
        system("pause");
    }
    else
    {
        srand(time(NULL));
        id = 1000 + rand() % (10000 - 1000);

        ocupado = buscarEmpleado(vec, tam, id);

        if( ocupado != -1)
        {
            srand(time(NULL));
            id = 1000 + rand() % (10000 - 1000);
        }
        else
        {
            vec[indice].id = id;

            printf("\nId: %d\n",id);

            printf("Ingresar nombre: ");
            fflush(stdin);
            gets(auxChar);


            while(strlen(auxChar)>50)
            {
                printf("Error. Ingresar nombre del empleado: ");
                gets(auxChar);
            }

            strlwr(auxChar);
            auxChar[0] = toupper(auxChar[0]);
            strcpy(vec[indice].nombre, auxChar);

            printf("Ingresar apellido: ");
            fflush(stdin);
            gets(auxChar);

            while(strlen(auxChar)>50)
            {
                printf("Error. Ingresar apellido del empleado: ");
                gets(auxChar);
            }

            strlwr(auxChar);
            auxChar[0] = toupper(auxChar[0]);

            strcpy(vec[indice].apellido, auxChar);


            printf("Ingrese sueldo: ");
            scanf("%f", &vec[indice].sueldo );

            while(vec[indice].sueldo<0)
            {
                printf("Error. Ingrese sueldo: ");
                scanf("%f", &vec[indice].sueldo );
            }

            printf("\n** Sectores **\n");
            printf("1. RRHH\n");
            printf("2. Sistemas\n");
            printf("3. Legales\n");
            printf("4. Ventas\n");
            printf("5. Compras\n\n");
            printf("Ingrese numero de sector: ");
            scanf("%d",&vec[indice].sector);

            while(vec[indice].sector < 1 || vec[indice].sector > 5)
            {
                printf("Error. Ingrese un sector valido: ");
                scanf("%d",&vec[indice].sector);
            }

            vec[indice].ocupado = 1;

            printf("\nAlta empleado realizada con exito.\n\n");
            system("pause");

        }
    }
}

void bajaEmpleado(eEmpleado vec[], int tam)
{
    int id;
    int indice;
    char confirma;

    printf("\nIngrese el Id: ");
    scanf("%d" ,&id);

    indice = buscarEmpleado (vec, tam, id);

    if (indice == -1)
    {
        printf ("El id %d no esta registrado en el sistema \n", id);
        system("pause");
    }
    else
    {

        printf ("\nDesea dar de baja al empleado? s/n: ");
        fflush(stdin);
        confirma=tolower(getche());

        if(confirma != 's' && confirma != 'n')
        {
            printf("No es una opcion valida. Ingrese s/n: ");
            fflush(stdin);
            confirma=tolower(getche());
        }

        if(confirma == 's')
        {
            vec[indice].ocupado = 0 ;
        }
        else
        {
            printf ("\n\nSe ha cancelado la operacion.\n\n" );
            system("pause");
        }
    }
}

void modificacionEmpleado(eEmpleado vec[], int tam)
{

    int id;
    int nuevoSector;
    int indice;
    int opcion;
    float nuevoSueldo;
    char confirma;
    char nuevoNombre[51];
    char nuevoApellido[51];
    char auxChar[100];

    printf("\nIngrese id: ");
    scanf("%d", &id);

    indice = buscarEmpleado(vec, tam, id);

    if(indice == -1)
    {
        printf ("\nEl id %d no esta registrado en el sistema\n\n", id);
        system("pause");
        menuABM();
    }
    else
    {
        printf ("\nDesea modificar empleado? s/n: ");
        fflush (stdin);
        confirma = tolower(getche());
    }
    if(confirma=='n')
    {
        menuABM();
    }
    else if(confirma=='s')
    {
            system("cls");
            printf(">>>> Ingrese opcion que desee modificar <<<<\n\n");

            printf("    1_ Nombre.\n");
            printf("    2_ Apellido.\n");
            printf("    3_ Salario.\n");
            printf("    4_ Sector.\n\n");
            printf("    5_ Volver al menu principal.\n");
            printf("\n\n>>>> Opcion: ");
            scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("\nIngresar nuevo nombre: ");
                fflush(stdin);
                scanf("%s", nuevoNombre);

                while(strlen(auxChar)>50)
                {
                    printf("Error. Ingresar nombre del empleado: ");
                    gets(auxChar);
                }

                strlwr(auxChar);
                auxChar[0] = toupper(auxChar[0]);
                strcpy(nuevoNombre, auxChar);
                strcpy(vec[indice].nombre, nuevoNombre);

                printf("\nModificacion realizada con exito.\n\n");
                system("pause");
            break;

            case 2:
                printf("\nIngresar nuevo apellido: ");
                fflush(stdin);
                gets(auxChar);

                while(strlen(auxChar)>50)
                {
                    printf("\nError. Ingresar apellido del empleado: ");
                    gets(auxChar);
                }

                strlwr(auxChar);
                auxChar[0] = toupper(auxChar[0]);
                strcpy(nuevoApellido, auxChar);
                strcpy(vec[indice].apellido, nuevoApellido);

                printf("\nModificacion realizada con exito.\n\n");
                system("pause");
            break;

            case 3:
                printf("\nIngrese nuevo sueldo: ");
                scanf("%f", &nuevoSueldo );

                while(strlen(auxChar)>50)
                {
                    printf("\nError. Ingrese sueldo mayor a 0: ");
                    scanf("%f", &nuevoSueldo );
                }

                vec[indice].sueldo = nuevoSueldo;

                printf("\nModificacion realizada con exito.\n\n");
                system("pause");
            break;

            case 4:
                system("cls");
                printf("\n** Sectores **\n");
                printf("1. RRHH\n");
                printf("2. Sistemas\n");
                printf("3. Legales\n");
                printf("4. Ventas\n");
                printf("5. Compras\n\n");
                printf("\nIngrese numero de nuevo sector: ");
                scanf("%d",&nuevoSector);

                while(nuevoSector < 1 || nuevoSector > 5)
                {
                    printf("\nError. Ingrese un sector valido: ");
                    scanf("%d",&nuevoSector);
                }

                vec[indice].sector = nuevoSector;

                printf("\nModificacion realizada con exito.\n\n");
                system("pause");
            break;

            case 5:
                menuABM();
            break;

            default:
                if(opcion > 6 || opcion < 0)
                {
                    printf("\nIngrese opcion valida: ");
                    scanf("%d",&opcion);
                }
        }
    }
}

void ordenarEmpleados(eEmpleado vec[], int tam)
{
    eEmpleado aux;

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(vec[i].sector>vec[j].sector && vec[i].ocupado == 1 && vec[j].ocupado==1)
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
            else
            {
                if(vec[i].sector==vec[j].sector && (stricmp(vec[i].apellido, vec[j].apellido))>0)
                {
                    aux=vec[i];
                    vec[i]=vec[j];
                    vec[j]=aux;
                }
            }
        }
    }
}

void informacionEmpleados(eEmpleado vec[], int tam)
{
    int opcion;
    int contSueldos=0;
    int contEmpleados=0;
    float totalSueldos=0;
    float promedioSueldos;


    do
    {
        system("cls");
        printf("**** Infomes ****\n\n");
        printf("1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector.\n");
        printf("2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n\n");
        printf("3. Volver al menu principal\n\n");
        printf(">>> Ingrese opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                ordenarEmpleados(vec,tam);
                mostrarEmpleados(vec,tam);
                system("pause");
            break;

            case 2:

                for(int i=0; i<tam; i++)
                {
                    if(vec[i].ocupado==1)
                    {
                        totalSueldos+=vec[i].sueldo;
                        contSueldos++;
                    }
                }

                promedioSueldos=(float)totalSueldos/contSueldos;

                for(int i=0; i<tam; i++)
                {
                    if(vec[i].ocupado==1 && vec[i].sueldo>promedioSueldos)
                    {
                        contEmpleados++;
                    }
                }

                printf("\nEl total de los salarios es de %.2f",totalSueldos);
                printf("\nEl promedio de los sueldos es de: %.2f",promedioSueldos);
                printf("\nEl total de empleados que superan el sueldo promedio es de: %d\n\n",contEmpleados);
                system("pause");

            break;

            case 3:
                menuABM();
            break;

            default:
                printf("No se ha ingresado una opcion valida.\n\n");
        }

    }while(opcion!=3);


}

