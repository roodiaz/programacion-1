#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "mascotas.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int estado=0;
    int cant;
    char buffer[6][20];
    mascota* list = mascota_new();

    if(pArrayListEmployee != NULL && pFile != NULL )
    {
        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3],buffer[4],buffer[5]);
        while(!feof(pFile))
        {
            cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3],buffer[4],buffer[5]);

            if(list !=NULL)
            {
                list = mascota_newParameters(buffer[0],buffer[1], buffer[2],buffer[3],buffer[4],buffer[5]);


                ll_add(pArrayListEmployee,list);
               // employee_printEmployee(list);
                estado=1;
              // printf("%s\n",list->raza);
            }
            if(cant < 4)
            {
                if( feof(pFile))
                {
                    break;
                }
                else
                {
                    printf("Problemas para leer el archivo\n");
                    break;
                }
            }

        }
    }

    return estado;
}

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int estado=0;
    FILE* f;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        f = fopen(path, "r");

        if(f==NULL)
        {
            estado=0;
            exit(1);
        }
        else
        {
            parser_EmployeeFromText(f, pArrayListEmployee);
            fclose(f);
            estado=1;
        }

    }

    return estado;
}

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int len;
    int i;
    int estado=0;
    FILE* f;
    mascota* aux;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        f=fopen(path,"w");
        len=ll_len(pArrayListEmployee);

        if(f != NULL)
        {
            for(i=0; i<len; i++)
            {
                aux= (mascota*)ll_get(pArrayListEmployee, i);
                fprintf(f, "%d,%s,%d,%s,%s,%s\n", aux->id, aux->nombre, aux->dias, aux->raza,aux->reservado,aux->genero);
            }

            fclose(f);

            if(i == len)
            {
                estado=1;
            }
            else
            {
                estado=0;
            }
        }
        else
        {
            estado=0;
        }
    }

    return estado;
}

/*

int parser_EmployeeListToText(FILE* pFile, LinkedList* pArrayList)
{
    int ok = 0;

    if( (pFile != NULL) && (pArrayList != NULL) )
    {
        mascota* auxMascota;
        char name[20],raza[20], reservado[20];
        char genero;
        int id, age;
        int i;

        fprintf(pFile,"ID_cachorro,nombre,dias,raza,reservado,genero\n");

        for(i=0; i<ll_len(pArrayList); i++)
        {
            auxMascota = (mascota*) ll_get(pArrayList, i);

            if(auxMascota != NULL)
            {
                employee_getId(auxMascota, &id);
                employee_getName(auxMascota, name);
                employee_getAge(auxMascota, &age);
                employee_getRaza(auxMascota, raza);
                employee_getReservado(auxMascota,reservado);
                employee_getGenero(auxMascota,&genero);

                fprintf(pFile,"%d,%s,%d,%s,%s,%s\n",id,name,age,raza,reservado,genero);
            }
        }

        ok = 1;
    }

    return ok;
}

FILE* openFileRead(char* path, LinkedList* pArrayList)
{
    FILE* auxFile = NULL;

    if( (path != NULL) && (pArrayList != NULL) )
    {
        auxFile = fopen(path,"r");

        if(auxFile == NULL)
        {
            printf("\nNo es posible abrir el archivo.\n");
            exit(1);
        }

        parser_EmployeeFromText(auxFile, pArrayList);
        printf("\nArchivo cargado con exito.\n");
        fclose(auxFile);
    }

    return auxFile;
}

FILE* openFileWrite(char* path, LinkedList* pArrayList)
{
    FILE* auxFile = NULL;

    if( (path != NULL) && (pArrayList != NULL) )
    {
        auxFile = fopen(path,"w");

        if(auxFile == NULL)
        {
            printf("\nNo es posible abrir el archivo.\n");
            exit(1);
        }

        parser_EmployeeListToText(auxFile, pArrayList);
        printf("\nArchivo guardado con exito.\n");
        fclose(auxFile);
    }

    return auxFile;
}


}*/

