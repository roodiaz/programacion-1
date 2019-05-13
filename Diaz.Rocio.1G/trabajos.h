typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int idServicio;
    char nombreServicio[25];
    int precio;

} eServicio;

typedef struct
{
    int idTrabajo;
    char patente[8];
    int idServicio;
    eFecha fechaTrabajo;
    int ocupado;

}eTrabajo;

int buscarLibreTrabajo(eTrabajo vec[], int tam);
int obtenerServicios(eServicio servicio[], int tamServ, int idServicio, char dondeAsignar[]);
void incrementalTrabajo(eTrabajo vec[],int tam);
void mostrarTrabajo(eTrabajo vecTrabajo, eServicio vecServ[], int tamServ);
void mostrarTrabajos(eTrabajo vecTrabajo[], int tamTrabajo, eServicio vecServ[], int tamServ);
void mostrarServicio(eServicio vec);
void mostrarServicios(eServicio vec[], int tam);
int buscarServicioPorId(eServicio vec[], int tam, int idServicio);
void altaTrabajo(eTrabajo vecTrabajo[], int tamTrabajo, eServicio vecServ[], int tamServ, eAuto vecAuto[], int tamAuto, eColor vecColor[], int tamColor, eMarca vecMarca[], int tamMarca);
