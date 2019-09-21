#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define TAM 2

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    int nota1;
    int nota2;
    int isEmpty;
    float promedio;
    eFecha fechaIngreso;

} eAlumno;

int menuOpciones();
void inicializarAlumnos(eAlumno vec[],int tam);
int buscarLibre(eAlumno vec[], int tam);
int buscarAlumnoLeg(eAlumno vec[], int tam,int legajo);
void mostrarAlumno(eAlumno vec);
void mostrarAlumnos(eAlumno vec[], int tam);
int altaAlumno(eAlumno vec[],int tam);
void ordenarAlumnosNombre( eAlumno vec[], int tam);

int main()
{
    eAlumno alumnos[TAM];
    char salir = 's';

    inicializarAlumnos(alumnos,TAM);

    do
    {
        switch(menuOpciones())
        {
        case 1:
            system("cls");
            if(altaAlumno(alumnos,TAM)==1)
            {
                printf("Alta realizada con exito!!\n\n");
            }
            else
            {
                printf("Error al dar de alta!!\n\n");
            }
            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            system("cls");
            mostrarAlumnos(alumnos, TAM);
            break;

        case 5:
            break;

        case 6:
            break;

        case 7:
            printf("Desea salir? s/n: ");
            fflush(stdin);
            salir=getchar();
            break;

        default:
            system("cls");
            printf("Opcion invalida!!!\n");

        }
    }
    while(salir != 's');


    return 0;
}

int menuOpciones()
{
    int opcion;

    system("cls");
    printf("----- MENU DE OPCIONES ------\n\n");
    printf("1_ Alta alumno\n");
    printf("2_ Baja alumno\n");
    printf("3_ Modifica alumno\n");
    printf("4_ Listar alumnos\n");
    printf("5_ Ordenar alumnos\n");
    printf("6_ Informes\n");
    printf("7_ Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

void inicializarAlumnos(eAlumno vec[],int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty=1;
    }
}

//-1 lleno
// 1 vacio
int buscarLibre(eAlumno vec[], int tam)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 1)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

// -1 no esta el legajo
int buscarAlumnoLeg(eAlumno vec[], int tam,int legajo)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].legajo == legajo)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

int altaAlumno(eAlumno vec[],int tam)
{
    int retorno=0;
    int legajo;
    int libre;
    int indice;

    printf("----- Alta Alumno -----\n\n");

    libre=buscarLibre(vec,tam);

    if(libre == -1)
    {
        printf("\nNo hay lugar en el sistema!!\n\n");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d",&legajo);

        indice=buscarAlumnoLeg(vec,tam, legajo);

        if(indice == -1)
        {
            vec[indice].legajo=legajo;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(vec[libre].nombre);

            printf("Ingrese edad: ");
            scanf("%d", &vec[libre].edad);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &vec[libre].sexo);

            printf("Ingrese nota parcial 1: ");
            scanf("%d", &vec[libre].nota1);

            printf("Ingrese nota parcial 2: ");
            scanf("%d", &vec[libre].nota2);

            printf("Ingrese fecha ingreso dd/mm/aaaa: ");
            scanf("%d/%d/%d", &vec[libre].fechaIngreso.dia, &vec[libre].fechaIngreso.mes, &vec[libre].fechaIngreso.anio);

            vec[libre].promedio = (float) (vec[libre].nota1 + vec[libre].nota2) / 2;

            retorno=1;

        }
        else
        {
            printf("Ya existe ese numero de legajo!! \n\n");
            mostrarAlumno(vec[indice]);
        }

    }

    return retorno;
}

void mostrarAlumno(eAlumno vec)
{
    printf(" %d  %8s    %d     %c     %2d        %2d      %.2f   %02d/%02d/%d\n",vec.legajo,vec.nombre,vec.edad,vec.sexo,vec.nota1,vec.nota2,vec.promedio,vec.fechaIngreso.dia,vec.fechaIngreso.mes,vec.fechaIngreso.anio);
}

void mostrarAlumnos(eAlumno vec[], int tam)
{
    int flag=0;

    printf("Legajo   Nombre   Edad   Sexo   Nota-1   Nota-2  Promedio    Fecha Ingreso\n\n");

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            mostrarAlumno(vec[i]);
            flag=1;
        }
    }

    if(flag == 0)
    {
        printf("\nNo hay alumnos para mostrar\n\n");
    }
}

void ordenarAlumnosNombre( eAlumno vec[], int tam)
{
    eAlumno auxAlumno;

    for(int i=0; i < tam-1; i++)
    {
        for(int j = i+1; j < tam; j++)
        {
            if( strcmp(vec[i].nombre, vec[j].nombre) > 0)
            {
                auxAlumno = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAlumno;
            }
        }
    }
}

int bajaAlumno(eAlumno vec[],int tam)
{
    int retorno=0;
    int indice;
    int legajo;
    char confirma;

    printf("Ingrese legajo: ");
    scanf("%d",&legajo);

    indice=buscarAlumnoLeg(vec,tam,legajo);

    if(indice == -1)
    {
        printf("No existe ese numero de legajo!!\n\n");
    }
    else
    {
        mostrarAlumno(vec[indice]);

        printf("Desea dar de baja ese legajo? s/n: ");
        fflush(stdin);
        confirma=getchar();

        if(confirma == 's')
        {
            vec[indice].isEmpty=1;
            retorno=1;
            printf("Baja dada con exito!!\n\n");
        }
        else
        {
            printf("No se ha dado de baja el legajo!!\n\n");
        }
    }

    return retorno;
}

int modificaAlumno(eAlumno vec[],int tam)
{
    int retorno=0;
    int indice;
    int legajo;
    int opcion;
    char confirma;

    printf("Ingrese legajo: ");
    scanf("%d",&legajo);

    indice=buscarAlumnoLeg(vec,tam,legajo);

    if(indice == -1)
    {
        printf("No existe ese numero de legajo!!\n\n");
    }
    else
    {
        mostrarAlumno(vec[indice]);

        printf("Desea modificar ese legajo? s/n: ");
        fflush(stdin);
        confirma=getchar();

        if(confirma == 's')
        {
            printf("1_ Modifica nota 1\n");
            printf("1_ Modifica nota 2\n\n");
            printf("Ingrese opcion: ");
            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                printf("Ingrese nota parcial 1: ");
                scanf("%d", &vec[indice].nota1);
                vec[indice].promedio = (float) (vec[indice].nota1 + vec[indice].nota2) / 2;
                break;

            case 2:
                printf("Ingrese nota parcial 2: ");
                scanf("%d", &vec[indice].nota2);
                vec[indice].promedio = (float) (vec[indice].nota1 + vec[indice].nota2) / 2;
                break;

            default:
                printf("Opcion invalida!!\n\n");
            }

            retorno=1;
            printf("Modificacion exitosa!!!\n\n");
        }
        else
        {
            printf("Operacion cancelada!!\n\n");
        }
    }

    return retorno;
}




