#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    char nombre[30];
    float salario;
}eEmpleado;

void escribirBinario(char* path);
void leerBinario(char* path);

int main()
{
    escribirBinario("miArchivo.dat");
    leerBinario("miArchivo.dat");


    return 0;
}

void escribirBinario(char* path)
{
    eEmpleado miEmpleado[2] ={{100,"Pepe",1000},{101,"Luis",2000}} ;
    FILE* miArchivo;
    int contDatos=2; //para contar cantidad de datos en archivo

    miArchivo=fopen(path,"wb"); // .bin = .dat

    if(miArchivo != NULL)
    {
        fwrite(&contDatos,sizeof(int),1,miArchivo);//para contar cantidad de datos en archivo

        for(int i=0; i<2;i++)
        {
            fwrite(miEmpleado+i,sizeof(eEmpleado),1,miArchivo);// 1er size tamanio del dato
            //devuelve 1 si pudo guardar 0 sino
            //&miEmpleado[i] = miEmpleado+i
        }

       fclose(miArchivo);
    }
}

void leerBinario(char* path)
{
    eEmpleado miEmpleado[2];//pedir espacio en memoria con malloc!!!!!!!!!!!!!!!
    FILE* miArchivo;
    int contDatos;

    miArchivo=fopen(path,"rb"); // .bin = .dat

    if(miArchivo != NULL)
    {
        fread(&contDatos,sizeof(int),1,miArchivo);


        printf("Cantidad de datos: %d\n\n",contDatos);

        fread(&miEmpleado,sizeof(eEmpleado),contDatos,miArchivo);
        //verificar el cont de datos y usar realloc si hace falta!!!!!!!!!


        /*int i=0;
        while(!feof(miArchivo))
        {
            fread(miEmpleado+i,sizeof(eEmpleado),1,miArchivo);
            i++
        }*/

        fclose(miArchivo);

        for(int i=0; i<2; i++)
        {
            printf("%d  %10s    %.2f\n",miEmpleado[i].legajo,miEmpleado[i].nombre,miEmpleado[i].salario);
            //crear funcion que muestre empleado!!!!!!!!!!
        }

    }
    else
    {
        printf("No se pudo encontrar el archivo\n\n");
    }
}
