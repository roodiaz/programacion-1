#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mascotas.h"
#include "LinkedList.h"

mascota* mascota_new(void)
{
    mascota* aux = (mascota*) malloc (sizeof(mascota));
    return aux;
}

mascota* mascota_newParameters(char* id, char* nombre, char* edad, char* raza, char* reservado, char* genero)
{
    mascota* auxMascota = mascota_new();

    if( (auxMascota  != NULL) && (id != NULL) && (nombre!= NULL) && (edad!= NULL) && (raza != NULL) && (reservado != NULL) && (genero != NULL) )
    {
        int auxId, auxAge;

        auxId = atoi(id);
        auxAge = atoi(edad);

        employee_setId(auxMascota, auxId);
        employee_setName(auxMascota, nombre);
        employee_setAge(auxMascota, auxAge);

        employee_setRaza(auxMascota, raza);
        employee_setReservado(auxMascota,reservado);
        employee_setGenero(auxMascota,genero);

    }
    else
        mascota_delete(auxMascota);

    return auxMascota;
}

void mascota_delete(mascota* auxMascota)
{
    if(auxMascota != NULL)
        free(auxMascota);
}

/////////////////////

int employee_getId(mascota* auxMascota, int* auxId)
{
    int ok = 0;

    if((auxMascota != NULL) && (auxId != NULL) )
    {
        *auxId = auxMascota->id;
        ok = 1;
    }

    return ok;
}

int employee_getName(mascota* auxMascota, char* auxName )
{
    int ok = 0;

    if( (auxMascota != NULL) && (auxName != NULL) )
    {
        strcpy(auxName, auxMascota->nombre);
        ok = 1;
    }

    return ok;
}


int employee_getAge(mascota* auxMascota, int* auxAge )
{
    int ok = 0;

    if( (auxMascota != NULL) && (auxAge != NULL) )
    {
        *auxAge = auxMascota->dias;
        ok = 1;
    }

    return ok;
}

int employee_getRaza(mascota* auxMascota, char* auxRaza )
{
    int ok = 0;

    if( (auxMascota != NULL) && (auxRaza != NULL) )
    {
        strcpy(auxRaza, auxMascota->raza);
        ok = 1;
    }

    return ok;
}

int employee_getReservado(mascota* auxMascota, char* auxReservado )
{
    int ok = 0;

    if( (auxMascota != NULL) && (auxReservado  != NULL) )
    {
        strcpy(auxReservado, auxMascota->reservado);
        ok = 1;
    }

    return ok;
}

int employee_getGenero(mascota* auxMascota, char* auxGenero )
{
    int ok = 0;

    if( (auxMascota != NULL) && (auxGenero != NULL) )
    {
        strcpy(auxGenero,auxMascota->genero);
        ok = 1;
    }

    return ok;
}


/////////////////////

int employee_setId(mascota* auxMascota, int auxId )
{
    int ok = 0;

    if( (auxMascota != NULL) && (auxId > 0) )
    {
        auxMascota->id = auxId;
        ok = 1;
    }

    return ok;
}

int employee_setName(mascota* auxMascota, char* auxName )
{
    int ok = 0;

    if( (auxMascota!= NULL) && (auxName != NULL) )
    {
        strcpy(auxMascota->nombre, auxName);
        ok = 1;
    }

    return ok;
}

int employee_setAge(mascota* auxMascota, int auxAge )
{
    int ok = 0;

    if( (auxMascota != NULL) && (auxAge > 0) )
    {
        auxMascota->dias = auxAge;
        ok = 1;
    }

    return ok;
}

int employee_setRaza(mascota* auxMascota, char* auxRaza )
{
    int ok = 0;

    if( (auxMascota!= NULL) && (auxRaza  != NULL) )
    {
        strcpy(auxMascota->raza, auxRaza);
        ok = 1;
        //printf("%s\n",auxMascota->raza);
    }

    return ok;
}

int employee_setReservado(mascota* auxMascota, char* auxReservado )
{
    int ok = 0;

    if( (auxMascota!= NULL) && (auxReservado != NULL) )
    {
        strcpy(auxMascota->reservado, auxReservado );
        ok = 1;
    }

    return ok;
}

int employee_setGenero(mascota* auxMascota, char* auxGenero )
{
    int ok = 0;

    if( (auxMascota!= NULL) && (auxGenero != NULL) )
    {
        strcpy(auxMascota->genero,auxGenero);
        ok = 1;
    }

    return ok;
}


/////////////////

void employee_printEmployee(mascota* auxMascota)
{
    if(auxMascota!= NULL)
    {
        char name[20],raza[20], reservado[20], genero[20];
        int id, age;

        employee_getId(auxMascota, &id);
        employee_getName(auxMascota, name);
        employee_getAge(auxMascota, &age);
        employee_getRaza(auxMascota, raza);
        employee_getReservado(auxMascota,reservado);
        employee_getGenero(auxMascota,genero);

        printf("%d,%s,%d,%s,%s,%s\n",id,name,age,auxMascota->raza,reservado,genero);
    }
}

void employee_printListOfEmployees(LinkedList* pArrayList)
{
    if(pArrayList != NULL)
    {
        int i;
        mascota* auxEmployee;

        for(i=0; i<ll_len(pArrayList); i++)
        {
            auxEmployee = (mascota*)ll_get(pArrayList, i);
            employee_printEmployee(auxEmployee);
        }
    }
}


/////////////

int employee_filterUnder45(void* aux)
{
    int returnAux = 0;

    if(aux != NULL)
    {
        int age;
        aux = (mascota*)aux;

        employee_getAge(aux, &age);

        if(age > 45)
            returnAux = 1;
    }

    return returnAux;
}

int employee_filterMacho(void* aux)
{
    int returnAux = 0;

    if(aux != NULL)
    {
        char genero[20];
        aux = (mascota*)aux;

        employee_getGenero(aux, genero);

        for(int i=0; i<1; i++)
        {
            if(genero[i]!='M')
                 returnAux = 1;
        }

    }

    return returnAux;
}

int employee_filterRaza(void* aux)
{
    int returnAux = 0;

    if(aux != NULL)
    {
        char raza[20];
        aux = (mascota*)aux;

        employee_getGenero(aux, raza);

        if(strcmpi(raza,"Callejero")==0)
                 returnAux = 1;
    }

    return returnAux;
}
