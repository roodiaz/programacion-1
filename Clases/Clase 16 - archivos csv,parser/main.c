#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo;
    char nombre[30];
    char apellido[30];
    float sueldo;

}eEmpleado;

//castear es pasar tipo numerico a numerico
//parsear es pasar tipo de dato cadena(string) a tipo de dato numerico
eEmpleado* newEmpleado();

int main()
{
    FILE* miArchivo;
    int i=0;
    char legajo[10];
    char nombre[20];
    char apellido[20];
    char sueldo[20]; //buffer

    eEmpleado* lista[50];//array que guarda 10 punteros a estrucutra eEmpleados
    eEmpleado* emp;

    miArchivo=fopen("datos.csv","r");

    if(miArchivo != NULL)
    {
        fscanf(miArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",legajo,nombre,apellido,sueldo);
        //para leer primer linea de datos sin que tire null

        while(!feof(miArchivo))
        {
            fscanf(miArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",legajo,nombre,apellido,sueldo);

            emp=newEmpleado();

            emp->legajo=atoi(legajo);
            strcpy(emp->nombre,nombre);
            strcpy(emp->apellido,apellido);
            emp->sueldo=atof(sueldo);

            *(lista+i) =emp; //= lista[i]=emp;
            i++;

        }

        fclose(miArchivo);

        for(int i=0; i<50; i++)
        {
            printf("%d %15s %15s %.2f\n",lista[i]->legajo,lista[i]->nombre
                   ,lista[i]->apellido,lista[i]->sueldo);
        }

    }

    return 0;
}

//constructor por defecto(no recibe parametros,contruye memoria, devuelve direccion de memoria)
eEmpleado* newEmpleado()
{
    eEmpleado* emp=(eEmpleado*) malloc(sizeof(eEmpleado));

    return emp;
}


