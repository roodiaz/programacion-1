#ifndef AUTOS_H_INCLUDED
#define AUTOS_H_INCLUDED

typedef struct
{
    int idAuto;
    char patente[7];
    int idMarca;
    int idColor;
    int anioFabricacion;
    int estado;

}eAuto;

typedef struct
{
    int idColor;
    char nomColor[20];
} eColor;

typedef struct
{
    int idMarca;
    char nomMarca[20];
} eMarca;


#endif // AUTOS_H_INCLUDED



int menuOpciones();

//FUNCIONES AUTOS
void mostrarAuto(eAuto vecA, eMarca vecM[], int tamM, eColor vecC[], int tamC);
void mostrarAutos(eAuto vecA[],int tamA, eMarca vecM[], int tamM, eColor vecC[], int tamC);
void inicializarAutos(eAuto vec[], int tam);
int buscarLibreAuto(eAuto vec[], int tam);
int buscarPatente(eAuto vecA[],int tamA,char patente[]);
int altaAuto(eAuto vecA[],int tamA, eMarca vecM[], int tamM, eColor vecC[], int tamC,int id);
int bajaAuto(eAuto vecA[],int tamA, eMarca vecM[], int tamM, eColor vecC[], int tamC);
int menuModificacion();
int modificarAuto(eAuto vecA[],int tamA, eMarca vecM[], int tamM, eColor vecC[], int tamC);

//FUNCIONES COLORES
void mostrarColor(eColor vec);
void mostrarColores(eColor vec[], int tam);
void nombreColor(eColor vec[], int tam,int id, char dondeAsignar[]);


//FUNCIONES MARCAS
void mostrarMarca(eMarca vec);
void mostrarMarcas(eMarca vec[], int tam);
void nombreMarca(eMarca vec[], int tam,int id, char dondeAsignar[]);
