#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    int a=5;

    printf("Prueba funcion modifica variable:\n\n");
    printf("%d\n\n",a);

    funcionModificar(&a);

    printf("%d",a);
    printf("\n\n\n");

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
    printf("\n\n\n");

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
    printf("\n\n\n\n");

    //////////////

    eEmpleado emp1 = {1234, "juan", 34000, 'm',{12,3,2019}};
    eEmpleado* pEmp;

    pEmp = &emp1;
    printf("\nPrueba mostrar estructuras con puntero:\n\n");
    printf("%s\n\n", emp1.nombre);// mostrar nombre a traves de variable
    printf("%s\n\n",pEmp->nombre);// mostrar nombre a traves de puntero

    printf("%02d/%02d/%d\n\n",pEmp->ingreso.dia,pEmp->ingreso.mes,pEmp->ingreso.anio);// mostrar nombre a traves de puntero

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
