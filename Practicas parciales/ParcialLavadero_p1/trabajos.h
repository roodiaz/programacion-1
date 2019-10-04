#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;


typedef struct
{
    int idTrabajo;
    char patente[7];
    int idServicio;
    eFecha fechaTrabajo;
    int estado;
} eTrabajo;

typedef struct
{
    int idServicio;
    char nomServicio[25];
    int precio;
} eServicio;


#endif // TRABAJOS_H_INCLUDED


//FUNCIONES TRABAJOS
void inicializarTrabajos(eTrabajo vec[], int tam);
int buscarLibreTrabajo(eTrabajo vec[], int tam);
int altaTrabajo(eTrabajo vecT[], int tamT,eServicio vecS[], int tamS, eAuto vecA[],int tamA, eMarca vecM[], int tamM, eColor vecC[], int tamC, int id);
void mostrarTrabajo(eTrabajo vec, eServicio vecS[],int tamS);
void mostrarTrabajos(eTrabajo vec[],int tam,eServicio vecS[],int tamS);

//FUNCIONES SERVICIOS
void mostrarServicio(eServicio vec);
void mostrarServicios(eServicio vec[], int tam);
void nombreServicio(eServicio vec[], int tam,int id, char dondeAsignar[]);




