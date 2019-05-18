#include <stdio.h>
#include <stdlib.h>

#define TAM 4
void funcionModificar(int *p);
void f1(int x[], int tam); // ESTRUCTURA VECTORIAL_PROTOTIPO VECTORIAL -- BIEN
void f2(int x[], int tam); // ESTRUCTURA PUNTERO_PROTOTIPO VECTORIAL -- MAL
void f3(int* x, int tam); // ESTRUCTURA VECTORIAL_PROTOTIPO VECTORIAL -- MAL
void f4(int* x, int tam); // ESTRUCTURA PUNTERO_PROTOTIPO PUNTERO -- BIEN



/// NO HAY QUE MEZCLAR NOMENCLATURA VECTORIAL Y DE PUNTERO
typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;
typedef struct
{
    int legajo;
    char nombre[20];
    float sueldo;
    char sexo;
    eFecha ingreso;
}eEmpleado;

void mostrarEmpleados(eEmpleado* vec, int tam);

int main()
{
    int a=5;

    printf("Prueba funcion modifica variable:\n\n");
    printf("%d\n\n",a);

    funcionModificar(&a);

    printf("%d",a);
    printf("\n----------\n");

    //////////////////////

    int vec[]={3,4,5,6,2};

    printf("\nPrueba funciones con vectores:\n\n");
    f1(vec,5);
    printf("\n\n");
    f2(vec,5);
    printf("\n\n");
    f3(vec,5);
    printf("\n\n");
    f4(vec,5);
    printf("\n----------\n");

    //////////////////

    char cadena[20]= "Esto es una cadena";
    char* p;

    // p=&cadena[0];
    p=cadena;
    printf("\nPrueba mostrar cadena caracteres:\n\n");

    while(*p != '\0')
    {
        printf("%c",*p);
        p++; // == p+1 = p+sizeof
    }
    printf("\n----------\n");

    //////////////

    /*eEmpleado emp1 = {1234, "juan", 34000, 'm',{12,3,2019}};
    eEmpleado* pEmp;

    pEmp = &emp1;
    printf("\nPrueba mostrar estructuras con puntero:\n\n");
    printf("Nombre: %s\n\n", emp1.nombre);// mostrar nombre a traves de variable
    printf("Nombre: %s\n\n",pEmp->nombre);// mostrar nombre a traves de puntero

    printf("%02d/%02d/%d\n\n\n",pEmp->ingreso.dia,pEmp->ingreso.mes,pEmp->ingreso.anio);// mostrar nombre a traves de puntero

    printf("Pisar nombre y sueldo en estructura con puntero: ");
    printf("\n\nIngrese nombre: ");
    //scanf("%s",pEmp->nombre);
    gets(pEmp->nombre);

    printf("\nNombre: %s\n\n",pEmp->nombre);

    printf("Ingrese sueldo: ");
    scanf("%f",&pEmp->sueldo);
    printf("\nSueldo: %.2f\n\n",pEmp->sueldo);*/

    eEmpleado lista[TAM] ={{1234, "juan", 34000, 'm',{12,8,2019}},
                            {4141, "rocio", 35000, 'f',{1,9,2019}},
                            {5351, "ana", 30000, 'f',{13,11,2019}},
                            {5353, "juan", 36000, 'm',{11,6,2019}}
                            };

    mostrarEmpleados(lista,4);


    return 0;
}

void funcionModificar(int *p)
{
    *p=25;
}

void f1(int x[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        printf("%d",x[i]);
    }
}

void f2(int x[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        printf("%d",*(x+i));
    }
}

void f3(int* x, int tam)
{
    for(int i=0; i<tam; i++)
    {
        printf("%d",x[i]);
    }
}

void f4(int* x, int tam)
{
     for(int i=0; i<tam; i++)
    {
        printf("%d",*(x+i));
    }
}

void mostrarEmpleado(eEmpleado* vec)
{
    printf("%d  %5s  %.2f  %c  %02d/%02d/%d\n",
           vec->legajo,
           vec->nombre,
           vec->sueldo,
           vec->sexo,
           vec->ingreso.dia,
           vec->ingreso.mes,
           vec->ingreso.anio);
}

void mostrarEmpleados(eEmpleado* vec, int tam)
{
    for(int i=0; i<tam; i++)
    {
        mostrarEmpleado(vec+i);
    }
}
