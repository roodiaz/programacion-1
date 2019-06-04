#include "Employee.h"
#include <stdlib.h>
#include <string.h>

Employee* employee_new()
{
    Employee* this = (Employee*) malloc(sizeof(Employee));

    if(this != NULL)
    {
        this->id = 0;
        strcpy(this->nombre, "");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }
    return this;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* this;

    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        this = employee_new();

        if(this != NULL)
        {
            if(employee_setId(this, atoi(idStr))||
                employee_setNombre(this, nombreStr)||
                    employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr))||
                        employee_setSueldo(this,atoi(sueldoStr)))
                        {
                            free(this);
                        }
        }
    }

    return this;
}

void employee_delete()
{
    Employee* this = (Employee*) malloc(sizeof(Employee));

    if(this != NULL)
    {
        this->id = 0;
        strcpy(this->nombre, "");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }
}

int employee_setId(Employee* this,int id)
{
    int estado=0;

    if(this != NULL && id > 0)
    {
        this->id=id;
        estado=1;
    }
    return estado;
}

int employee_getId(Employee* this,int* id)
{
    int estado=0;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        estado=1;
    }

    return estado;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int estado=0;

    if(this != NULL && nombre!= NULL && strlen(nombre)>3)
    {
        strcpy(this->nombre, nombre);
        estado=1;
    }

    return estado;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int estado=0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        estado=1;
    }
    return estado;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int estado=0;

    if(this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas=horasTrabajadas;
        estado=1;
    }
    return estado;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int estado=0;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        estado=1;
    }

    return estado;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int estado=0;

    if(this != NULL && sueldo > 0)
    {
        this->sueldo=sueldo;
        estado=1;
    }
    return estado;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int estado=0;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        estado=1;
    }

    return estado;
}

void mostrarEmployee(Employee* emp)
{
    printf("%d  %s  %d  %d\n",emp->id,emp->nombre,emp->horasTrabajadas,emp->sueldo);
}
