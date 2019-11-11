#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include "ArrayEmployees.h"




void inicializarEmpleados(eEmpleado vec[], int tam)
{

    for(int i=0; i<tam; i++)
    {
        vec[i].ocupado=0;

    }

}

int buscarVacio(eEmpleado vec [], int tam)
{
    int indice=-1;

    for(int i = 0; i<tam; i++)
    {
        if(vec[i].ocupado==0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


int buscarEmpleado(eEmpleado vec[], int tam, int legajo)
{
    int indice = -1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].legajo==legajo && vec[i].ocupado ==1)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

int menuAbm()
{

    int opcion;

    system("cls");
    printf("#     # ####### #     # #     #       #    ######  #     #\n");
    printf("##   ## #       ##    # #     #      # #   #     # ##   ##\n");
    printf("# # # # #       # #   # #     #     #   #  #     # # # # #\n");
    printf("#  #  # #####   #  #  # #     #    #     # ######  #  #  #\n");
    printf("#     # #       #   # # #     #    ####### #     # #     #\n");
    printf("#     # #       #    ## #     #    #     # #     # #     #\n");
    printf("#     # ####### #     #  #####     #     # ######  #     #\n\n");
    printf("    1- Alta empleado: \n");
    printf("    2- Baja empleado: \n");
    printf("    3- Modificar empleado:  \n");
    printf("    4- Mostrar Empleados: \n");
    printf("    5- Cantidad de empleados por sector: \n");
    printf("    6- Sectores con mas empleados: \n");
    printf("    7- Sectores con mayor promedio de sueldos: \n");
    printf("    8- Cantidad Hombres y mujeres por sector;\n");
    printf("    9- Empleados mayor sueldo sector;\n");
    printf("    10- Salir: \n");

    scanf("%d", &opcion);

    return opcion;

}
void mostrarEmpleado(eEmpleado emp, eSector sectores [], int tam)
{
   char nombreSector[20];
    int consigioNombre;

   consigioNombre =  obtenerSectores(sectores, tam, emp.sector, nombreSector);

    if( !consigioNombre){
         strcpy(nombreSector, "Sin definir");
     }

    //obtenerSectores(sectores,tam,emp.sector,nombreSector);

    printf("%5d %12s %12s %10c %10.2f %7.02d/%02d/%4d %15s \n", emp.legajo, emp.nombre,emp.apellido,emp.sexo,emp.sueldo, emp.fechaing.dia,emp.fechaing.mes,emp.fechaing.anio,nombreSector);

}

void mostrarEmpleados(eEmpleado empleados[], int tam, eSector sectores[], int tamSec)
{
    int cont=0;

    system("cls");
    printf("\n");
    printf("%5s %12s %12s %10s %9s %15s %15s \n", "Legajo", "Nombre", "Apellido", "Sexo", "Salario","FechaIngreso","Sector");
    printf("%5s %12s %12s %10s %9s %15s %15s \n", "------", "------", "--------", "----", "-------","------------","------");

    for(int i = 0 ; i < tam ; i++)
    {
        if(empleados[i].ocupado==1)
        {
            mostrarEmpleado(empleados[i],sectores,tamSec);
            cont++;
        }

    }
    if(cont==0)
    {
        printf("No hay empleados que mostrar.\n");

    }

}


int altaEmpleado(eEmpleado vec[], int tam, eSector sec[], int tamsec)
{
    int enteroIng;
    int indice;
    int esta;
    float auxFloat;


    indice = buscarVacio(vec,tam);
    if(indice==-1)
    {
        printf("No hay lugar en el sistema para nuevos empleados. \n");
    }
    else
    {
        srand(time(0));
        enteroIng= rand() % 8999 + 1000;

        esta=buscarEmpleado(vec,tam,enteroIng);

        while(esta!=-1)
        {
            srand(time(0));
            enteroIng= rand() % 8999 + 1000;
        }

        if(esta==-1)
        {
            vec[indice].legajo=enteroIng;
            printf("Legajo : %d \n", enteroIng);

            ingresarNombre(vec,indice);

            ingresarApellido(vec,indice);

            pedirSexo(vec,indice);

            auxFloat=pedirFloat("Ingresar sueldo del empleado:");

            while(auxFloat<0)
            {
                auxFloat=pedirFloat("Error, ingresar sueldo valido del empleado: \n");
            }

            vec[indice].sueldo=auxFloat;


            mostrarSectores(sec,tamsec);
            enteroIng=pedirEntero("Ingresar Sector de la empresa: ");


            while(enteroIng<0 || enteroIng>tamsec)
            {
                enteroIng=pedirEntero("Error, ingresar sector valido");
            }

            vec[indice].sector=enteroIng;

            vec[indice].ocupado=1;

            printf("Ingrese fecha de ingreso dd/mm/aaaa: ");
            scanf("%d %d %d", &vec[indice].fechaing.dia, &vec[indice].fechaing.mes, &vec[indice].fechaing.anio);

            printf("\n El empleado a sido registrado!\n");

        }
        else
        {
            mostrarEmpleado(vec[esta],sec,tamsec);
        }
    }

    return 0;
}

void bajaEmpleado (eEmpleado vec[], int tam, eSector sectores[], int tamSec)
{
    int legajo;
    char confirma;
    int esta;

    printf("******Lista de empleados****** \n");
    mostrarEmpleados(vec,tam,sectores,tamSec);

    printf("Ingrese el legajo : \n");
    scanf("%d", &legajo);

    esta=buscarEmpleado(vec,tam,legajo);

    if(esta==-1)
    {
        printf("El legajo > %d No esta registrado en el sistema\n", legajo);
    }
    else
    {
        mostrarEmpleado(vec[esta],sectores,tamSec);

        printf("\n Quiere dar de baja al empleado? s/n\n");
        fflush(stdin);
        confirma=tolower(getche());

        if(confirma=='s')
        {
            vec[esta].ocupado=0;
        }
        else
        {
            printf("\n La eliminacion ha sido cancelada");
        }
    }
}

int pedirEntero(char mensaje[])
{
    char sNum[51];
    int num;
    int input=-1;

    printf("\n%s\n", mensaje);
    scanf("%s",sNum);
    num=atoi(sNum);

    if(num!=0)
    {
        input=num;
    }

    return input;
}

float pedirFloat(char mensaje[])
{
    char sNum[51];
    char punto= '.';
    float input=-1;
    int num1;

    printf("\n%s\n", mensaje);
    scanf("%s",sNum);
    num1=atoi(sNum);



    if(strchr(sNum,punto)==NULL)
    {
        if(num1!=0)
        {
            input=num1;
        }
    }
    else
    {
        input=atof(sNum);
    }




    return input;
}

void modificarSueldo(eEmpleado vec[], int tam, int esta, eSector sectores[], int tamSec)
{
    char confirma;
    float nuevoSueldo;

    mostrarEmpleado(vec[esta],sectores,tamSec);

    printf("\nQuiere cambiar el sueldo? s/n\n");
    fflush(stdin);
    confirma = tolower(getche());

    if(confirma == 's')
    {
       nuevoSueldo = pedirFloat("Ingrese el nuevo sueldo : \n");

        while(nuevoSueldo<0)
        {
            nuevoSueldo = pedirFloat("Error, ingrese sueldo valido : \n");
        }
        vec[esta].sueldo = nuevoSueldo;
    }
    else
    {
        printf("\nNo se ha modificado el sueldo\n");
    }



}


void modificarEmpleado(eEmpleado vec[], int tam, eSector sec[], int tamsec)
{

    int legajo;
    int esta;
    int auxInt;
    char auxChar;


    mostrarEmpleados(vec,tam,sec,tamsec);

    printf("\n\nIngrese legajo del empleado que desea modificar:\n ");
    scanf("%d", &legajo);

    esta = buscarEmpleado(vec, tam, legajo);

    if( esta == -1)
    {

        printf("\nEl legajo %d no esta registrado en el sistema\n", legajo);
    }
    else
    {
        switch(menuModificar())
        {
        case 1 :
            auxChar=preguntarSiEstaSeguro("Nombre");

            if(auxChar=='s')
            {
                ingresarNombre(vec,esta);
                printf("\nSe cambio el nombre del empleado con legajo %d\n",legajo);
            }
            else
            {
                break;
            }

            break;
        case 2 :
            auxChar=preguntarSiEstaSeguro("Apellido");

            if(auxChar=='s')
            {
                ingresarApellido(vec,esta);
                printf("\nSe cambio el apellido del empleado con legajo %d\n",legajo);
            }
            else
            {
                break;
            }
            break;
        case 3 :
            auxChar=preguntarSiEstaSeguro("Sexo");

            if(auxChar=='s')
            {
                pedirSexo(vec,esta);
                printf("\nSe cambio el sexo del empleado con legajo %d\n",legajo);
            }
            else
            {
                break;
            }

            break;
        case 4 :
            modificarSueldo(vec,tam,esta,sec,tamsec);
            break;
        case 5 :
            auxChar=preguntarSiEstaSeguro("Sector");

            if(auxChar=='s')
            {
                auxInt=pedirEntero("Ingresar el nuevo sector");
                vec[esta].sector=auxInt;
                printf("\nSe cambio el sector del empleado con legajo %d\n",legajo);
            }
            else
            {
                break;
            }

            break;

        }
    }

}

int menuModificar()
{
    int opcion;

    system("cls");
    printf("#     # ####### #     # #     #       #    ######  #     # \n");
    printf("##   ## #       ##    # #     #      # #   #     # ##   ## \n");
    printf("# # # # #       # #   # #     #     #   #  #     # # # # # \n");
    printf("#  #  # #####   #  #  # #     #    #     # ######  #  #  # \n");
    printf("#     # #       #   # # #     #    ####### #     # #     # \n");
    printf("#     # #       #    ## #     #    #     # #     # #     # \n");
    printf("#     # ####### #     #  #####     #     # ######  #     # \n\n");
    printf("1- Modificar nombre.\n");
    printf("2- Modificar apellido.\n");
    printf("3- Modificar sexo.\n");
    printf("4- Modificar sueldo.\n");
    printf("5- Modificar sector.\n");

    scanf("%d", &opcion);

    return opcion;

}



void ingresarNombre(eEmpleado vec[], int indice)
{
    char auxString[150];

    getValidString("Ingresar nombre del empleado:\n", "Error Ingresar un nombre valido\n", auxString);

    while(strlen(auxString)>50)
    {
        getValidString("Error Ingresar un nombre valido:\n", "Error Ingresar un nombre valido: \n", auxString);
    }

    strlwr(auxString);
    auxString[0]=toupper(auxString[0]);

    ajustarNombre(auxString,150);

    strcpy(vec[indice].nombre,auxString);

}
void ingresarApellido(eEmpleado vec[], int indice)
{
    char auxString[150];
    getValidString("Ingresar nombre apellido:\n", "Error Ingresar un apellido valido\n", auxString);

    while(strlen(auxString)>50)
    {
        getValidString("Error Ingresar un apellido valido:\n", "Error Ingresar un apellido valido: \n", auxString);
    }
    strlwr(auxString);
    auxString[0]=toupper(auxString[0]);

    ajustarNombre(auxString,150);

    strcpy(vec[indice].apellido,auxString);
}

void ajustarNombre(char vec[],int tam)
{
    int contador=0;

    while(vec[contador] != '\0')
    {
        if(vec[contador] == ' ')
        {
            vec[contador+1] = toupper(vec[contador+1]);
        }
        contador++;
    }
}

void ordenarEstructura(eEmpleado vec[], int tam)
{
    eEmpleado auxEmpleado;

    for(int i = 0 ; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(vec[i].sector>vec[j].sector)
            {
                auxEmpleado=vec[i];
                vec[i]=vec[j];
                vec[j]=auxEmpleado;
            }
            else
            {
                if(vec[i].sector==vec[j].sector && (stricmp(vec[i].apellido, vec[j].apellido)==1))
                {
                    auxEmpleado=vec[i];
                    vec[i]=vec[j];
                    vec[j]=auxEmpleado;
                }
            }
        }
    }
}

float promedioSueldos(eEmpleado vec[], int tam)
{
    float acumulador=0;
    float promedio;
    int contador=0;

    for(int i=0;i<tam;i++)
    {
        if(vec[i].ocupado==1)
        {
            acumulador+=vec[i].sueldo;
            contador++;
        }

    }

    promedio=acumulador/contador;

    return promedio;

}

float totalSalarios(eEmpleado vec [], int tam)
{
    float acumulador=0;


    for(int i=0;i<tam;i++)
    {
        if(vec[i].ocupado==1)
        {
            acumulador+=vec[i].sueldo;

        }
    }

    return acumulador;
}

int cantidadSuperaPromedio(eEmpleado vec [], int tam)
{
    float promedio = promedioSueldos(vec,tam);
    int contador=0;

    for(int i=0;i<tam;i++)
    {
        if(vec[i].ocupado==1)
        {
            if(vec[i].sueldo>promedio)
            {
                contador++;
            }
        }
    }

    return contador;

}

void hardCodearEmpleados(eEmpleado vec[], int tam)
{
    eEmpleado empleados [13]= {
    {1234, "juan", "perez", 'm', 1 , 24000,{12,3,2000},1},
    {8294, "cristina", "ferrera", 'f', 2 , 29000,{12,3,2000},1},
    {5648, "thiago", "corta", 'm', 3 , 34000,{12,3,2000},1},
    {1954, "diego", "fernandez", 'm', 3 , 44000,{12,3,2000},1},
    {5657, "camila", "celano", 'f', 3 , 18000,{12,3,2000},1},
    {9874, "federico", "callejeros", 'm', 2 , 19000,{12,3,2000},1},
    {1358, "nerea", "pereyra", 'f', 5 , 25000,{12,3,2000},1},
    {9999, "matias", "hamie", 'f', 5 , 30000,{12,3,2000},1},
    {1564, "dani", "class", 'm', 1 , 44000,{12,3,2000},1},
    {1954, "sabrina", "nosee", 'f', 1 , 14000,{12,3,2000},1},
    {1564, "victoria", "sanchez", 'f', 3 , 28000,{12,3,2000},1},
    {5668, "noseqponer", "bastaaa", 'm', 4 , 49000,{12,3,2000},1}};
    for(int i=0;i<tam;i++)
    {
        vec[i]= empleados[i];
    }

}

void pedirSexo(eEmpleado vec[], int indice)
{
    char sexoAux;

    printf("Ingresar el sexo del empleado : \n");
    fflush(stdin);
    sexoAux=getchar();
    sexoAux=tolower(sexoAux);

    while(sexoAux!='f' && sexoAux!='m')
    {
        printf("Error, ingrese sexo valido  : \n");
        fflush(stdin);
        sexoAux=getchar();
        sexoAux=tolower(sexoAux);
    }

    vec[indice].sexo=sexoAux;

}

int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}


int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


void getValidString(char requestMessage[],char errorMessage[], char input[])
{

    while(1)
    {
        if (!getStringLetras(requestMessage,input))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        fflush(stdin);
        break;
    }

}

char preguntarSiEstaSeguro(char mensaje[])
{
    char confirma;

    printf("\nQuiere cambiar el %s? s/n\n", mensaje);
    fflush(stdin);
    confirma = tolower(getche());

    while(confirma!='s' && confirma!='n')
    {
        printf("\nQuiere cambiar el %s? s/n\n", mensaje);
        fflush(stdin);
        confirma = tolower(getche());
    }

    return confirma;
}

int obtenerSectores(eSector sectores[], int tam, int idSector, char desc[])
{
    int todoOk=-1;
    for(int i= 0 ; i<tam;i++)
    {
        if(idSector == sectores[i].id)
        {
            strcpy(desc,sectores[i].descripcion);
            todoOk=1;
            break;
        }
    }
    return todoOk;


}

void mostrarSectores( eSector sectores[], int tam){

    printf("\n    Sectores\n");

    for(int i=0; i < tam; i++){
        printf("%d:      %10s\n", sectores[i].id, sectores[i].descripcion);
    }
}

void mostrarCantEmpleadosXSector(eEmpleado empleados[], int tam, eSector sectores[], int tamsec)
{
    int contador;

    printf("%10s%10s \n", "Sector", "Cantidad");
    printf("%10s%10s \n", "------", "--------");
    for(int i=0; i < tamsec; i++){
        contador = 0;
        printf("%10s", sectores[i].descripcion);

        for(int j=0; j < tam; j++){
            if( sectores[i].id == empleados[j].sector && empleados[j].ocupado == 1){
                contador++;
            }
        }

        printf("%10d\n", contador);
    }


}

void SectorMasEmpleados( eEmpleado empleados[], int tam, eSector sectores[], int tamsec)
{


    int totales[tamsec];
    int mayor;

    for(int i=0; i < tamsec; i++)
    {

        totales[i] = 0;
        for(int j=0; j < tam; j++)
        {
            if( sectores[i].id == empleados[j].sector && empleados[j].ocupado == 1)
            {
                totales[i]++;
            }
        }


    }

    for(int i=0; i < tamsec; i++)
    {
        if( i == 0 || mayor < totales[i])
        {
            mayor = totales[i];

        }
    }
    printf("-------Sector/es con mas empleados-------\n\n");
    for(int i=0; i < tamsec; i++){
            if( totales[i] == mayor){
                printf("%10s Con %d empleados.\n", sectores[i].descripcion, mayor);
            }

      }

}

void sectorConMayorPromedioSueldo(eEmpleado emp[],int tam, eSector sec[], int tamsec)
{
    int totales[tamsec];
    int mayor;
    float acumulador[tamsec];
    float mayorAcu=0;
    float promedio;

    for(int i=0; i < tamsec; i++)
    {

        totales[i] = 0;
        acumulador[i]=0;
        for(int j=0; j < tam; j++)
        {
            if( sec[i].id == emp[j].sector && emp[j].ocupado == 1)
            {
                totales[i]++;
               acumulador[i]+=emp[j].sueldo;
            }
        }
    }

    for(int i=0; i < tamsec; i++)
    {
        if( i == 0 || mayorAcu < acumulador[i])
        {

            mayorAcu = acumulador[i];
            mayor = totales[i];

        }
    }

    promedio=mayorAcu/mayor;


    printf("-------Sector/es con mayor promedio de sueldo-------\n\n");
    for(int i=0; i < tamsec; i++){
            if( acumulador[i] == mayorAcu){
                printf("%10s Con %.2f promedio de sueldos con un total de %d empleados.\n", sec[i].descripcion, promedio,mayor);
            }

      }


}

void cantidadMyFPorSector(eEmpleado emp[],int tam, eSector sec[], int tamsec)
{
    int cantMujer[tamsec];
    int cantHombres[tamsec];


    for(int i=0; i < tamsec; i++)
    {

        cantMujer[i] = 0;
        cantHombres[i]=0;
        for(int j=0; j < tam; j++)
        {
            if( sec[i].id == emp[j].sector && emp[j].ocupado == 1)
            {
               if(emp[j].sexo=='f')
               {
                   cantMujer[i]++;
               }
               else
               {
                   if(emp[j].sexo=='m')
                   {
                       cantHombres[i]++;
                   }

               }
            }
        }
    }


    printf("-------Cantidad de Hombres y Mujeres por sectores-------\n\n");
    for(int i=0; i < tamsec; i++){
        printf("Sector : %10s", sec[i].descripcion);
        printf("    Cantidad Hombres: %d  Cantidad Mujeres: %d \n", cantHombres[i],cantMujer[i]);


      }


}

void empleadoMayorSueldoSec( eEmpleado emp[], int tam, eSector sec[], int tamsec)
{

    float mayor[tamsec];
    float acumulador[tamsec];
    int flag;

    for(int i=0; i < tamsec; i++)
    {

        acumulador[i]=0;
        mayor[i]=0;
        flag=0;
        for(int j=0; j < tam; j++)
        {
            if( sec[i].id == emp[j].sector && emp[j].ocupado == 1)
            {
                if( flag == 0 || mayor[i] < emp[j].sueldo)
                {

                    acumulador[i] = emp[j].sueldo;
                    mayor[i] = acumulador[i];
                    flag=1;

                }

            }
        }
    }


    printf("-------Empleado con mayor sueldo por sector-------\n\n");
    for(int i=0; i < tamsec; i++){
            for(int j=0; j<tam ; j++)
            {
                if( emp[j].sector == sec[i].id &&emp[j].sueldo >= mayor[i] && emp[j].ocupado==1){
                mostrarEmpleado(emp[j],sec,tamsec);

            }


            }

      }


}







