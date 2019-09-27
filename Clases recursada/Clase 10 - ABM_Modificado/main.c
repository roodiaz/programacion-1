#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define TAM 15
#define TAMC 3

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
    float promedio;
    eFecha fechaIngreso;
    int idCarrera;
    int isEmpty;
} eAlumno;

typedef struct
{
    int idCarrera;
    char descripcion[20];
} eCarrera;

void mostrarAlumno(eAlumno x,eCarrera vec[],int tamC);
void mostrarAlumnos(eAlumno vec[], int tam,eCarrera carrera[],int tamC);
int ordenarAlumnos(eAlumno vec[], int tam);
void inicializarAlumnos(eAlumno vec[], int tam);
int buscarLibre(eAlumno vec[], int tam);
int buscarAlumno(int legajo, eAlumno vec[], int tam);
int altaAlumno(eAlumno vec[], int tam, int legajo, eCarrera vecC[], int tamC);
eAlumno newAlumno(int leg,char nombre[],int edad, char sexo, int nota1, int nota2, eFecha f, int carrera);
int bajaAlumno(eAlumno vec[], int tam, eCarrera vecC[], int tamC);
int ModificarAlumno(eAlumno vec[], int tam, eCarrera vecC[], int tamC);
int menu();
int hardcodearAlumnos( eAlumno vec[],int tam,int cant);
void mostrarCarrera(eCarrera datos);
void mostrarCarreras(eCarrera vec[], int tamC);
int obtenerNomCarrera(eCarrera vec[], int tamC, int id, char dondeAsinar[]);

int main()
{
    eAlumno lista[TAM];
    eCarrera carreras[TAMC]= {{1000,"TUP"},{1001,"TUSI"},{1002,"LIC"}};

    int legajo=20000;
    char salir = 'n';

    inicializarAlumnos( lista, TAM);

    legajo=legajo+hardcodearAlumnos(lista,TAM, 9);

    do
    {
        switch( menu())
        {
        case 1:
            if(altaAlumno(lista, TAM,legajo,carreras,TAMC))
            {
                legajo++;
            }
            break;

        case 2:
            bajaAlumno(lista, TAM,carreras, TAMC);
            break;

        case 3:
            ModificarAlumno(lista, TAM,carreras,TAMC);
            break;

        case 4:
            mostrarAlumnos(lista, TAM,carreras,TAMC);
            break;

        case 5:
            if(ordenarAlumnos(lista, TAM) != -1)
            {
                system("cls");
                printf("Datos ordenados!!\n\n");
            }
            else
            {
                printf("Error al ordenar\n\n");
                system("cls");
            }
            break;

        case 6:
            printf("Informes Alumno\n\n");
            break;

        case 7:
            mostrarCarreras(carreras,TAMC);
            break;

        case 8:
            printf("Confirma salir?:");
            fflush(stdin);
            salir = getche();
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }
    while(salir == 'n');

    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    printf("****** ABM Alumnos *******\n\n");
    printf("1-Alta alumno\n");
    printf("2-Baja alumno\n");
    printf("3-Modificar alumno\n");
    printf("4-Listar alumnos\n");
    printf("5-Ordenar alumnos\n");
    printf("6-Informes alumno\n");
    printf("7-Mostrar carreras\n");
    printf("8-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void mostrarAlumno(eAlumno x,eCarrera vec[],int tamC)
{
    char nomCarrera[20];

    obtenerNomCarrera(vec,tamC,x.idCarrera,nomCarrera);

    printf("  %d     %8s   %d    %c    %2d     %2d     %.2f    %02d/%02d/%d   %5s\n",
           x.legajo,
           x.nombre,
           x.edad,
           x.sexo,
           x.nota1,
           x.nota2,
           x.promedio,
           x.fechaIngreso.dia,
           x.fechaIngreso.mes,
           x.fechaIngreso.anio,
           nomCarrera);
}

void mostrarAlumnos(eAlumno vec[], int tam,eCarrera carrera[],int tamC)
{

    int flag = 0;
    system("cls");

    printf(" Legajo     Nombre   Edad  Sexo  Nota1  Nota2  Promedio  FIngreso   Carrera\n");
    printf(" ------     ------   ----  ----  -----  -----  --------  --------   -------\n\n");

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            mostrarAlumno(vec[i],carrera,tamC);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay alumnos que mostrar\n");
    }

    printf("\n\n");
}

int ordenarAlumnos(eAlumno vec[], int tam)
{
    eAlumno auxAlumno;
    int retorno=-1;

    for(int i= 0; i < tam-1 ; i++)
    {
        for(int j= i+1; j <tam; j++)
        {
            if( vec[i].promedio > vec[j].promedio)
            {
                auxAlumno = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAlumno;
                retorno=1;
            }
        }
    }

    return retorno;
}

void inicializarAlumnos(eAlumno vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}


int buscarLibre(eAlumno vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarAlumno(int legajo, eAlumno vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].legajo == legajo && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaAlumno(eAlumno vec[], int tam, int legajo, eCarrera vecC[], int tamC)
{
    int todoOk = 0;
    int indice;
    char nombre[20];
    char sexo;
    int edad;
    int n1;
    int n2;
    int carrera;
    eFecha fecha;

    system("cls");

    printf("*****Alta Alumno*****\n\n");

    indice = buscarLibre(vec, tam);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombre);

        printf("Ingrese edad: ");
        scanf("%d", &edad);

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &sexo);

        printf("Ingrese nota 1: ");
        scanf("%d", &n1);

        printf("Ingrese nota 2: ");
        scanf("%d", &n2);

        printf("Ingrese fecha ingreso: ");
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

        mostrarCarreras(vecC,tamC);

        printf("Ingrese numero de carrera: ");
        scanf("%d",&carrera);

        vec[indice] = newAlumno(legajo, nombre, edad, sexo, n1, n2, fecha,carrera);
        todoOk = 1;
        printf("Alta exitosa!!\n\n");
    }

    return todoOk;
}

eAlumno newAlumno(int leg,char nombre[],int edad,char sexo,int nota1,int nota2,eFecha fecha, int carrera)
{
    eAlumno al;

    al.legajo = leg;
    strcpy( al.nombre, nombre);
    al.sexo = sexo;
    al.edad = edad;
    al.nota1 = nota1;
    al.nota2 = nota2;
    al.promedio = (float) (nota1 + nota2 )/2;
    al.fechaIngreso = fecha;
    al.isEmpty = 0;
    al.idCarrera=carrera;

    return al;
}

int bajaAlumno(eAlumno vec[], int tam, eCarrera vecC[], int tamC)
{
    int todoOk = 0;
    int legajo;
    int indice;
    char confirma;
    system("cls");
    printf("***** Baja Alumno *****\n\n");
    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarAlumno(legajo, vec, tam);

    if( indice == -1)
    {
        printf("No existe un alumno con ese legajo\n\n");

    }
    else
    {

        mostrarAlumno(vec[indice],vecC, tamC);

        printf("\nConfirma baja?");
        fflush(stdin);
        scanf("%c", &confirma);

        if( confirma == 's')
        {
            vec[indice].isEmpty = 1;
            todoOk = 1;
            printf("Baja exitosa!!!");
        }
        else
        {
            printf("Se ha cancelado la operacion");
        }
    }

    return todoOk;
}
int ModificarAlumno(eAlumno vec[], int tam, eCarrera vecC[], int tamC)
{

    int todoOk = 0;
    int legajo;
    int indice;
    system("cls");
    printf("***** Modificar Alumno *****\n\n");
    printf("Ingrese legajo: ");
    scanf("%d", &legajo);
    int opcion;

    indice = buscarAlumno(legajo, vec, tam);

    if( indice == -1)
    {
        printf("No existe un alumno con ese legajo\n\n");

    }
    else
    {

        mostrarAlumno(vec[indice],vecC, tamC);

        printf("1- Modificar nota1\n");
        printf("2- Modificar nota2\n");
        printf("3- Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            printf("Ingrese nueva nota: ");
            scanf("%d", &vec[indice].nota1);
            vec[indice].promedio = (float) (vec[indice].nota1  + vec[indice].nota2)/2;
            break;

        case 2:
            printf("Ingrese nueva nota: ");
            scanf("%d", &vec[indice].nota2);
            vec[indice].promedio = (float) (vec[indice].nota1  + vec[indice].nota2)/2;
            break;
        case 3:
            printf("Se ha cancelado la mofdificacion ");
            break;

        }
    }
    return todoOk;
}

int hardcodearAlumnos( eAlumno vec[],int tam,int cant)
{
    int cont=0;

    eAlumno datos []=
    {
        {20000, "Rosario", 22, 'f', 9, 7, 8,{8, 3, 2010},1001,0},
        {20001, "Juan", 20, 'm', 4, 6, 5,{16, 9, 2019},1000,0},
        {20002, "Juana", 19, 'f', 7, 4, 5.5,{20, 3, 2018},1001,0},
        {20003, "Ariel", 21, 'm', 10, 2, 6,{12, 11, 2013},1000,0},
        {20004, "Jazmin", 20, 'f', 8, 8, 8,{9, 8, 2018},1002,0},
        {20005, "Abril", 22, 'f', 4, 5, 4.5,{4, 5, 2015},1001,0},
        {20006, "Lucas", 22, 'm', 6, 6, 6,{17, 12, 2017},1000,0},
        {20007, "Rocio", 24, 'f', 7, 5, 6,{23, 11, 2019},1001,0},
        {20008, "Diego", 21, 'm', 10, 2, 6,{11, 4, 2012},1002,0},
        {20009, "Mariela", 18, 'f', 8, 9, 8.5,{7, 4, 2011},1001,0},
        {20010, "Micaela", 23, 'f', 4, 7, 5.5,{8, 3, 2010},1000,0},
        {20011, "Tomas", 21, 'm', 7, 6, 6.5,{17, 12, 2017},1001,0},
        {20012, "Camila", 20, 'f', 7, 8, 7.5,{23, 11, 2019},1002,0},
        {20013, "Lucas", 19, 'm', 10, 4, 7,{11, 4, 2012},1002,0},
        {20014, "Valentina", 18, 'f', 9, 9, 9,{7, 4, 2011},1002,0}
    };

    if(cant <= 15 && tam >= cant)
    {
        for(int i=0; i<cant; i++)
        {
            vec[i] = datos[i];
            cont++;
        }
    }

    return cont;
}

void mostrarCarrera(eCarrera datos)
{
    printf("  %d   %8s\n",datos.idCarrera,datos.descripcion);
}

void mostrarCarreras(eCarrera vec[], int tamC)
{
    int flag = 0;
    system("cls");

    printf("   Id     Descripcion\n");
    printf(" ------   ----------- \n\n");

    for(int i=0; i < tamC; i++)
    {
            mostrarCarrera(vec[i]);
            flag = 1;
    }

    if( flag == 0)
    {
        printf("\nNo hay carreras que mostrar\n");
    }

    printf("\n\n");
}

int obtenerNomCarrera(eCarrera vec[], int tamC, int id, char dondeAsinar[])
{
    int todoOk=-1;

    for(int i= 0 ; i<tamC; i++)
    {
        if(id == vec[i].idCarrera)
        {
            strcpy(dondeAsinar,vec[i].descripcion);
            todoOk=1;
            break;
        }
    }

    return todoOk;
}
