typedef struct
{
    int  idAutor; // incremental
    char nombre[31];
    char apellido[31];
    int ocupado;

} eAutores;

typedef struct
{
    int  idLibro; // incremental
    char titulo[31];
    eAutores idAutor;
    int ocupado;

} eLibros;

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int idSocio; //incremental
    char nombre[31];
    char apellido[31];
    char sexo;
    char telefono[16];
    char eMail[31];
    eFecha fechaIngreso;
    int ocupado;

} eSocio;

typedef struct
{
    int idPrestamo; //incremental
    int idLibro;
    int idSocio;
    eFecha fechaPrestamo;
    int ocupado;

} ePrestamo;

void hardCodeAutores(eAutores vec[]);

void hardCodeLibros(eLibros vec[]);

void hardCodeSocios (eSocio vec[]);



void inicializarSocio(eSocio vec[], int tam);

void inicializarAutor(eAutores vec[], int tam);

void inicializarLibro(eLibros vec[], int tam);

void inicializarPrestamos(ePrestamo vec[], int tam);



int menuABM();

int menuModificacionSocio();



int buscarLibreSocio(eSocio vec[], int tam);

int buscarLibreAutor(eAutores autor[], int tamAutor);

int buscarLibrePrestamos(ePrestamo vec[], int tam);



void incrementalSocio(eSocio vec[],int tam);

void incrementalPrestamo(ePrestamo vec[],int tam);



int buscarSocioPorId(eSocio vec[], int tam, int idSocio);

int buscarLibroPorId(eLibros vec[], int tam, int idLibro);



void mostrarSocio(eSocio socio);

void mostrarSocios(eSocio vec[], int tam);



void mostrarAutor(eAutores autor);

void mostrarAutores(eAutores vec[], int tam);



void mostrarLibro(eLibros libro);

void mostrarLibros(eLibros vec[], int tam);



void mostrarPrestamo(ePrestamo prestamo);

void mostrarPrestamos(ePrestamo vec[], int tam);


void altaSocio(eSocio vec[], int tam);

void altaPrestamo(ePrestamo vecPrestamo[], int tamPrestamo, eLibros vecLibros[], int tamLibros, eSocio vecSocio[], int tamSocio);

void bajaSocio(eSocio vec[], int tam);

void modificacionSocio(eSocio vec[], int tam);



void ordenarSocioApeNom(eSocio vec[], int tam);

void ordenarAutoresApeNom(eAutores vec[], int tam);

void ordenarLibrosTitulo(eLibros vec[], int tam);





