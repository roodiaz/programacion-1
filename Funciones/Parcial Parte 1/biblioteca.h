
typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int idMarca;
    char descripcion[20];
    int ocupado;

}eMarca;

typedef struct
{
    int idColor;
    char nombreColor[20];
    int ocupado;

}eColor;

typedef struct
{
    int idAuto;
    char patente[7];
    int idMarca;
    int idColor;
    int modelo;
    int ocupado;

}eAuto;

typedef struct
{
    int idServicio;
    char descripcion[25];
    int precioServicio;
    int ocupado;

}eServicio;

typedef struct
{
    int idTrabajo;
    int patenteTrabajo;
    int idServicio;
    eFecha trabajo;
    int ocupado;

}eTrabajo;

void hardCodeMarcas(eMarca vec[]);

void hardCodeColores(eColor vec[]);

void hardCodeServicio(eServicio vec[]);

void hardCodeAutos(eAuto vec[]);

int menuABM();

int buscarLibreAuto(eAuto vec[], int tam);

int buscarLibreServicio(eServicio vec[], int tam);

void inicializarAuto(eAuto vec[], int tam);

void inicializarMarca(eMarca vec[], int tam);

int buscarMarcaPorId(eMarca vec[], int tam, int idMarca);

int buscarAutoPorId(eAuto vec[],int tam, int idAuto);

int buscarAutoPorPatente(eAuto vec[],int tam, int patente);

int buscarColorPorId(eColor vec[],int tam, int idColor);

int buscarServicioPorId(eServicio vec[],int tam, int idServicio);

void obtenerIdAuto(char dondeAsignar[], int tamMax, char mensaje[], int tamMin);

void mostrarMarca(eMarca vec);

void mostrarMarcas(eMarca vec[], int tam);

void mostrarColor(eColor vec);

void mostrarColores(eColor vec[], int tam);

void mostrarAuto(eAuto vec);

void mostrarAutos(eAuto vec[], int tam);

void mostrarServicio(eServicio vec);

void mostrarServicios(eServicio vec[], int tam);

void altaAuto(eAuto vecAuto[], int tamAuto, eMarca vecMarca[], int tamMarca, eColor vecColor[], int tamColor);

int menuModificacionAuto();

void modificacionAuto(eAuto vecAuto[], int tamAuto, eColor vecColor[], int tamColor);


void bajaAuto(eAuto vec[], int tam);

void ordenarAutos(eAuto vec[], int tam);

void incrementalTrabajo(eTrabajo vec[],int tam);
