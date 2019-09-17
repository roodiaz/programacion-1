#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct
{
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    int nota1;
    int nota2;
    float promedio;

} eAlumno;

void mostrarAlumno(eAlumno vec)
{
    printf(" %d  %8s    %d     %c     %2d        %2d      %.2f\n",vec.legajo,vec.nombre,vec.edad,vec.sexo,vec.nota1,vec.nota2,vec.promedio);
}

void mostrarAlumnos(eAlumno vec[], int tam)
{
    printf("Legajo   Nombre   Edad   Sexo   Nota-1   Nota-2  Promedio\n\n");

    for(int i=0; i<tam; i++)
    {
        mostrarAlumno(vec[i]);
    }
}

int main()
{
    eAlumno alumnos[TAM]= { {3413,"ana",24,'f',7,9,8},
                            {5235,"juan",21,'m',6,6,6},
                            {1234,"lucia",19,'f',9,10,9.5},
                            {7453,"pedro",25,'m',7,7,7},
                            {2345,"juana",22,'f',6,7,6.5}};


   /* for(int i=0; i<TAM; i++)
    {
        printf("ingrese legajo: ");
        scanf("%d",&alumnos[i].legajo);

        printf("ingrese nombre: ");
        fflush(stdin);
        gets(alumnos[i].nombre);

        printf("ingrese edad: ");
        scanf("%d",&alumnos[i].edad);

        printf("ingrese sexo f/m: ");
        fflush(stdin);
        alumnos[i].sexo=getchar();

        printf("ingrese nota primer parcial: ");
        scanf("%d",&alumnos[i].nota1);

        printf("ingrese nota segundo parcial: ");
        scanf("%d",&alumnos[i].nota2);

        alumnos[i].promedio= (float) (alumnos[i].nota1 + alumnos[i].nota2)/2;

    } */

    mostrarAlumnos(alumnos,TAM);

    return 0;
}

