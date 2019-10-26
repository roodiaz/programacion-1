#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct
{
    int id;
    char nombre[21];
    float sueldo;
    int estado;

}eEmpleado;

int inicializarEmp(eEmpleado* emp, int tam);
eEmpleado* newEmpleado();
int mostrarEmp(eEmpleado* emp);
eEmpleado* newEmpParam(int id, char* name, float salary);

int main()
{
    int tam=0;
    eEmpleado* aux;
    eEmpleado* lista = (eEmpleado*)malloc(sizeof (eEmpleado)*(tam+1));

   /* if(inicializarEmp(lista,tam))
    {
        printf("Empleados inicializados!\n\n");
    }
    else{

        printf("Problemas para inicializar!\n\n");
    }


    eEmpleado* emp1 = newEmpleado();

    emp1->id=123;
    strcpy(emp1->nombre,"juan");
    emp1->sueldo=30000;  //UNA FORMA DE CARGAR DATOS

    printf("Ingrese id: ");
    scanf("%d",&emp1->id);

    printf("\nIngrese nombre: ");
    fflush(stdin);
    gets(emp1->nombre);

    printf("\nIngrese sueldo: ");
    scanf("%f",&emp1->sueldo); //UNA FORMA DE CARGAR DATOS

    mostrarEmp(emp1); */

    eEmpleado* emp2 =newEmpParam(999,"lucas",34000);
    *(lista+tam)=*emp2;
    mostrarEmp(lista+tam);

    aux=(eEmpleado*)realloc(lista,sizeof(eEmpleado)*(tam+1));

    if(aux != NULL)
    {
        lista=aux;
    }


    return 0;
}

int inicializarEmp(eEmpleado* emp, int tam)
{
    int todoOk=0;

    if(emp != NULL && tam>=0)
    {
        for(int i=0; i<tam; i++)
        {
            (emp+i)->estado=0;
        }

        todoOk=1;
    }

    return todoOk;
}

eEmpleado* newEmpleado()
{
    eEmpleado* emp=(eEmpleado*) malloc(sizeof(eEmpleado));

    if(emp != NULL)
    {
        emp->id=0;
        strcpy(emp->nombre,"");
        emp->sueldo=0;
        emp->estado=0;
    }

    return emp;
}

eEmpleado* newEmpParam(int id, char* name, float salary)
{
    eEmpleado* emp =newEmpleado();

    if(emp != NULL)
    {
        emp->id=id;
        strcpy(emp->nombre,name);
        emp->sueldo=salary;
        emp->estado=0;
    }


    return emp;
}

int mostrarEmp(eEmpleado* emp)
{
   int todoOk=0;

    if(emp != NULL)
    {
       printf("%d %10s     %.2f\n",emp->id,emp->nombre,emp->sueldo);
       todoOk=1;
    }

    return todoOk;
}







