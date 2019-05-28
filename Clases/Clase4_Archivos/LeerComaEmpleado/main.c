#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nombre[30];
    char apellido[30];
    float sueldo;

}eEmpleado;

int main()
{
    eEmpleado* lista = (eEmpleado*)malloc(sizeof(eEmpleado));
    eEmpleado* auxEmp;
    int cont=0;
    int cant;
    FILE* f;

    char buffer[4][30];

    f=fopen("./empleados2.csv","r");

    if(f==NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(1);
    }

    while(!feof(f))
    {
        cant = fscanf(f,"%[^,],%[^,],%[^,],%[^\n]",buffer[0],buffer[1],buffer[2],buffer[3]);
        printf("%2d %12s %12s    %.2f\n",atoi(buffer[0]),buffer[1],buffer[2],atof(buffer[3]));

        (lista+cont)->id = atoi(buffer[0]);
        strcpy((lista+cont)->nombre,buffer[1]);
        strcpy((lista+cont)->apellido,buffer[2]);
        (lista+cont)->sueldo=atof(buffer[3]);

        cont++;

        auxEmp=(eEmpleado*)realloc(lista, sizeof(eEmpleado)*cont+1);

        if(auxEmp!=NULL)
        {
            lista=auxEmp;
        }

        if(cant<4)
        {
            if(feof(f))
            {
                break;
            }
            else
            {
                printf("Problemas para leer el archivo.\n");
                break;
            }
        }
    }
    printf("\n\n");

    fclose(f);

    for(int i=0; i<cont; i++)
    {
        printf("%2d %12s %12s    %.2f\n",(lista+i)->id,(lista+i)->nombre,(lista+i)->apellido,(lista+i)->sueldo);

    }

    return 0;
}
