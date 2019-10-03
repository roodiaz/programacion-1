#include <stdio.h>
#include <stdlib.h>
#include "inputElian.h"

typedef struct
{
    int dia;
    int mes;
    int anyo;
} STR_Fecha;

typedef struct
{
    int id; //incremental
    char nombre[31];
    char apellido[31];
} STR_Autores;

typedef struct
{
    int id; //incremental
    char nombre[51];
    int idAutor; // debe existir
} STR_Libros;

typedef struct
{
    int id;
    char nombre[31];
    char apellido[31];
    char sexo;
    char telefono[16];
    char email [31];
    STR_Fecha fecha_Asociado;
    int isEmpty;
} STR_Socios;


typedef struct
{
    int id; //incremental
    int idLibro; // debe existir
    int idSocio; // debe existir
    STR_Fecha fecha_Prestamo;
    int isEmpty;
} STR_Prestamos;



//*Inicializacion*//

void iniciarSociosIsEmpty ( STR_Socios iniciando[],int cantidadElementos,int numeroQueSeAsigna );
void inciarIncrementalIdSocios (STR_Socios iniciando[], int cantidadElementos );

void iniciarPrestamosIsEmpty ( STR_Prestamos iniciando[],int cantidadElementos,int numeroQueSeAsigna );
void iniciarIncrementalIdPrestamos (STR_Prestamos iniciando[], int cantidadElementos );

//*Busqueda*//

int buscarIdVacioSocio (STR_Socios socio[], int cantidadSocios);
int buscarIndexPorIdSocio (STR_Socios socio[],int cantidadSocios, int id);

int buscarIdVacioPrestamo (STR_Prestamos prestamo[], int cantidadPrestamos);
int buscarIndexPorIdPrestamo (STR_Prestamos prestamo[],int cantidadPrestamos,int id);

//*Hardcode*//

void hardCodeLibros(STR_Libros lista[]);
void hardCodeAutores(STR_Autores lista[]);
void hardCodeSocios(STR_Socios lista[]);

//*Menu*//

void menu (void);

//*Listar*//

void listarLibros (STR_Autores autor[],int cantidadAutores,STR_Libros libro[], int cantidadLibros );
void listarAutores(STR_Autores autor [],int cantidadAutores);
void listarSocios (STR_Socios socio [], int cantidadSocios);
void listarPrestamos (STR_Prestamos prestamo[], int cantidadPrestamos,STR_Socios socio[], int cantidadSocios, STR_Libros libro[]);

//*Altas*//

void altaSocio (STR_Socios socio [], int cantidadSocios);
void altaPrestamo( STR_Prestamos prestamos[], STR_Libros libro [],int cantidadLibros, STR_Socios socio[],int cantidadSocios, STR_Autores autor[],int cantidadAutores);

//*Modificacion*//

void modificarSocio (STR_Socios socio [], int cantidadSocios);


//*Baja*//

void bajaSocio(STR_Socios socio [], int cantidadSocios);
