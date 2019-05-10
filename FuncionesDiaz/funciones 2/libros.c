#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "libros.h"
#include "inputDiaz.h"

void hardCodeLibros(eLibros vec[])
{

    eLibros ejemplos[]=
    {
        {1, "ee1",{5},1},
        {2, "tt2",{4},1},
        {3, "uu3",{1},1},
        {4, "mm4",{3},1},
        {5, "bb5",{6},1},
        {6, "uu6",{2},1},
        {7, "zz7",{3},1},
        {8, "xx8",{4},1},
        {9, "dd9",{1},1}
    };

    for(int i=0; i < 10; i++)
    {
        vec[i] = ejemplos[i];
    }
};

void hardCodeAutores(eAutores vec[])
{
    eAutores ejemplos[]=
    {
        {1, "1z", "Z", 1},
        {2, "2m","m", 1},
        {3, "3y","y", 1},
        {4, "4z","z",1},
        {5, "5y","y",1},
        {6, "6m","m",1}
    };

    for(int i=0; i < 10; i++)
    {
        vec[i] = ejemplos[i];
    }
}

void hardCodeSocios (eSocio vec[])
{

    eSocio ejemplo[]=
    {
        {1, "1z", "z",'f', "111","1@gmail.com",{12,3,2000},1},
        {2, "2r", "r",'f', "222", "2@gmail.com",{18, 7,2011},1},
        {3, "3z", "z",'f', "333", "3@gmail.com",{12,3,2000},1},
        {4, "4p", "p",'m',"444","4@gmail.com",{18, 7,2011},1},
        {5, "5r", "r",'m', "555", "5@gmail.com",{12,3,2000},1},
        {6, "6p", "p",'f'," 666","6@gmail.com",{18, 7,2011},1},
        {7, "7a", "a",'m'," 777", "7@gmail.com",{18, 7,2011},1},
        {8, "8a", "a",'f', "888","8@gmail.com",{18, 7,2011},1},
    };

    for(int i=0; i < 10; i++)
    {
        vec[i] = ejemplo[i];
    }

}

void inicializarSocio(eSocio vec[], int tam)
{

    for(int i=0; i < tam; i++)
    {
        vec[i].ocupado = 0;
    }
}

void inicializarAutor(eAutores vec[], int tam)
{

    for(int i=0; i < tam; i++)
    {
        vec[i].ocupado = 0;
    }
}

void inicializarLibro(eLibros vec[], int tam)
{

    for(int i=0; i < tam; i++)
    {
        vec[i].ocupado = 0;
    }
}

void inicializarPrestamos(ePrestamo vec[], int tam)
{

    for(int i=0; i < tam; i++)
    {
        vec[i].ocupado = 0;
    }
}

int menuABM()
{
    int opcion;

    system("cls");
    printf("##### Menu ABM #####\n\n");
    printf("   1. Altas.\n");
    printf("   2. Modificar.\n");
    printf("   3. Bajas.\n");
    printf("   4. Listar Socios.\n");
    printf("   5. Listar Libros.\n");
    printf("   6. Listar Autores.\n");
    printf("   7. Prestamos.\n\n");
    printf("   8. Listar Prestamos.\n\n");
    printf("   9. Salir.\n\n");
    printf(">> Ingresar opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

int menuModificacionSocio()
{
    int opcion;

    system("cls");
    printf(">>>> Ingrese opcion que desee modificar <<<<\n\n");

    printf("    1_ Nombre.\n");
    printf("    2_ Apellido.\n");
    printf("    3_ Sexo.\n");
    printf("    4_ Telefono.\n");
    printf("    5_ Email.\n");
    printf("    6_ Volver al menu principal.\n");
    printf("\n\n>>>> Opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

int buscarLibreSocio(eSocio vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarLibrePrestamos(ePrestamo vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void incrementalSocio(eSocio vec[],int tam)
{
    for (int i=0; i<tam; i++)
    {
        vec[i].idSocio= i+1;
    }
}

void incrementalPrestamo(ePrestamo vec[],int tam)
{
    for (int i=0; i<tam; i++)
    {
        vec[i].idPrestamo= i+1;
    }
}

int buscarLibreAutor(eAutores autor[], int tamAutor)
{
    int indice = -1;

    for(int i=0; i <tamAutor; i++)
    {
        if(autor[i].ocupado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarSocioPorId(eSocio vec[], int tam, int idSocio)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1 && vec[i].idSocio==idSocio)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarLibroPorId(eLibros vec[], int tam, int idLibro)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1 && vec[i].idLibro==idLibro)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarSocio(eSocio socio)
{
    printf("\nId Socio: %d  //  Nombre Socio: %s  //  Apellido Socio: %s  //  Sexo Socio: %c  //  Telefono Socio: %s  //  Email Socio: %s  //  Fecha de alta: %02d/%02d/%4d", socio.idSocio, socio.nombre, socio.apellido, socio.sexo,socio.telefono, socio.eMail, socio.fechaIngreso.dia, socio.fechaIngreso.mes, socio.fechaIngreso.anio);
}

void mostrarSocios(eSocio vec[], int tam)
{
    int contador = 0;

    system("cls");

    for(int i=0; i <tam; i++)
    {
        if(vec[i].ocupado == 1)
        {
            mostrarSocio(vec[i]);
            contador++;
        }
    }
    printf("\n\n");

    if(contador == 0)
    {
        printf("No hay socio para mostrar\n");
        system("pause");
    }
}

void mostrarLibro(eLibros libro)
{
    printf("\nId Libro:%d  Titulo:%s  Codigo Autor:%d", libro.idLibro, libro.titulo, libro.idAutor.idAutor);
}

void mostrarLibros(eLibros vec[], int tam)
{
    int contador = 0;

    system("cls");

    for(int i=0; i <tam; i++)
    {
        if(vec[i].ocupado == 1)
        {
            mostrarLibro(vec[i]);
            contador++;
        }
    }
    printf("\n\n");

    if(contador == 0)
    {
        printf("No hay libros para mostrar\n");
        system("pause");
    }
}
void mostrarAutor(eAutores autor)
{
    printf("\nId autor: %d  //  Nombre Autor: %s  //  Apellido Autor: %s", autor.idAutor, autor.nombre, autor.apellido);
}

void mostrarAutores(eAutores vec[], int tam)
{
    int contador = 0;

    system("cls");

    for(int i=0; i <tam; i++)
    {
        if(vec[i].ocupado == 1)
        {
            mostrarAutor(vec[i]);
            contador++;
        }
    }
    printf("\n\n");

    if(contador == 0)
    {
        printf("No hay autores para mostrar\n");
        system("pause");
    }
}

void mostrarPrestamo(ePrestamo prestamo)
{
    printf("\nId Prestamo: %d  //  Id Libro: %d  //  Id Socio: %d  //  Fecha de prestamo: %02d/%02d/%4d", prestamo.idPrestamo, prestamo.idLibro, prestamo.idSocio, prestamo.fechaPrestamo.dia, prestamo.fechaPrestamo.mes, prestamo.fechaPrestamo.anio);
}

void mostrarPrestamos(ePrestamo vec[], int tam)
{
    int contador = 0;

    system("cls");

    for(int i=0; i <tam; i++)
    {
        if(vec[i].ocupado == 1)
        {
            mostrarPrestamo(vec[i]);
            contador++;
        }
    }
    printf("\n\n");

    if(contador == 0)
    {
        printf("No hay prestamos para mostrar\n");
        system("pause");
    }
}

void altaSocio(eSocio vec[], int tam)
{
    int indice;
    char auxSexo;
    char auxChar[100];
    eFecha auxfecha;

    indice = buscarLibreSocio(vec, tam);

    if(indice == -1)
    {
        printf("\nNo hay mas lugar en el sistema!!!\n");
        system("pause");
    }
    else
    {
        incrementalSocio(vec, tam);

        obtenerCadenaChar(auxChar, 31, "## Ingrese nombre: ");
        strcpy(vec[indice].nombre, auxChar);

        obtenerCadenaChar(auxChar, 31, "## Ingrese apellido: ");
        strcpy(vec[indice].apellido, auxChar);

        obtenerSexo(&auxSexo, "## Ingrese sexo f/m: ");
        vec[indice].sexo=auxSexo;

        obtenerTelefono(auxChar, 16, "## Ingrese telefono: ");
        strcpy(vec[indice].telefono,auxChar);

        obtenerEmail(auxChar, 31, "## Ingresar eMail: ");
        strcpy(vec[indice].eMail,auxChar);

        obtenerNumeroEntre(&auxfecha.dia, 31, 1, "## Ingrese dia de asociado: ");

        obtenerNumeroEntre(&auxfecha.mes, 12, 1, "## Ingrese mes de asociado: ");

        obtenerNumeroEntre(&auxfecha.anio, 2019, 2000, "## Ingrese anio de asociado: ");

        vec[indice].fechaIngreso = auxfecha;


        vec[indice].ocupado = 1;

        printf("\nAlta de socio realizada con exito!!!\n\n");
        system("pause");

    }

}

void bajaSocio(eSocio vec[], int tam)
{
    int id;
    int indice;
    char confirma;

    mostrarSocios(vec, tam);
    printf("\nIngrese el Id de socio: ");
    scanf("%d",&id);

    indice = buscarSocioPorId(vec, tam, id);

    if (indice == -1)
    {
        printf ("El id %d no esta registrado en el sistema \n", id);
        system("pause");
    }
    else
    {
        printf ("\nDesea dar de baja al socio? s/n: ");
        fflush(stdin);
        confirma=tolower(getche());

        if(confirma != 's' && confirma != 'n')
        {
            printf("\n*** Error ***");
            printf("Ingrese s/n: ");
            fflush(stdin);
            confirma=tolower(getche());
        }

        if(confirma == 's')
        {
            vec[indice].ocupado = 0;
            printf("\n\nSocio dado de baja con exito!!!\n\n");
            system("pause");
        }
        else
        {
            printf ("\n\nSe ha cancelado la operacion.\n\n" );
            system("pause");
        }
    }
}

void modificacionSocio(eSocio vec[], int tam)
{

    int id;
    int opcion;
    int indice;
    char confirma;
    char auxSexo;
    char auxChar[100];

    mostrarSocios(vec,tam);
    printf("\n>>> Ingrese Id: ");
    scanf("%d", &id);

    indice = buscarSocioPorId(vec, tam, id);

    if(indice == -1)
    {
        printf ("\nEl id %d no esta registrado en el sistema\n\n", id);
        system("pause");
        menuABM();
    }
    else
    {
        printf ("\nDesea modificar empleado? s/n: ");
        fflush (stdin);
        confirma = tolower(getche());
    }

    if(confirma=='n')
    {
        menuABM();
    }
    else
    {
        switch(menuModificacionSocio())
        {
        case 1:
            obtenerCadenaChar(auxChar, 31, "## Ingrese nombre: ");
            strcpy(vec[indice].nombre, auxChar);
            break;

        case 2:
            obtenerCadenaChar(auxChar, 31, "## Ingrese apellido: ");
            strcpy(vec[indice].apellido, auxChar);
            break;

        case 3:
            obtenerSexo(&auxSexo, "## Ingrese sexo f/m: ");
            vec[indice].sexo=auxSexo;
            break;

        case 4:
            obtenerTelefono(auxChar, 16, "## Ingrese telefono: ");
            strcpy(vec[indice].telefono,auxChar);
            break;

        case 5:
            obtenerEmail(auxChar, 31, "## Ingresar eMail: ");
            strcpy(vec[indice].eMail,auxChar);
            break;

        case 6:
            menuABM();
            break;

        default:
            if(opcion > 7 || opcion < 0)
            {
                printf("\nIngrese opcion valida: ");
                scanf("%d",&opcion);
            }
        }

    }
}

void ordenarSocioApeNom(eSocio vec[], int tam)
{
    eSocio aux;

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(stricmp(vec[i].apellido, vec[j].apellido)>0)
            {
                aux = vec[j];
                vec[j] = vec[i];
                vec[i] = aux;
            }

            if (stricmp(vec[i].apellido,vec[j].apellido) == 0)
            {

                if(stricmp(vec[i].nombre, vec[j].nombre)>0)
                {
                    aux = vec[j];
                    vec[j] = vec[i];
                    vec[i] = aux;
                }
            }
        }
    }
}

void ordenarAutoresApeNom(eAutores vec[], int tam)
{
    eAutores aux;

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(stricmp(vec[i].apellido, vec[j].apellido)>0)
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }

            if(stricmp(vec[i].apellido, vec[j].apellido)==0)
            {
                if(stricmp(vec[i].nombre, vec[j].nombre)>0)
                {
                    aux=vec[i];
                    vec[i]=vec[j];
                    vec[j]=aux;
                }
            }
        }
    }
}

void ordenarLibrosTitulo(eLibros vec[], int tam)
{
    eLibros aux;

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(stricmp(vec[i].titulo, vec[j].titulo)>0)
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
        }
    }
}

void altaPrestamo(ePrestamo vecPrestamo[], int tamPrestamo, eLibros vecLibros[], int tamLibros, eSocio vecSocio[], int tamSocio)
{
    int indiceLibre;
    int indiceLibro;
    int indiceSocio;
    int idLibro;
    int idSocio;
    eFecha auxfecha;

    indiceLibre = buscarLibrePrestamos(vecPrestamo, tamPrestamo);

    if(indiceLibre == -1)
    {
        printf("\nNo hay mas lugar en el sistema!!!\n");
        system("pause");
    }
    else
    {
        incrementalPrestamo(vecPrestamo, tamPrestamo);

        mostrarLibros(vecLibros, tamLibros);
        printf("\nIngrese el Id del Libro: ");
        scanf("%d",&idLibro);

        indiceLibro = buscarLibroPorId(vecLibros, tamLibros, idLibro);

        while (indiceLibro == -1)
        {
            printf("\n*** Error ***");
            printf("\nIngrese el Id del Libro: ");
            scanf("%d",&idLibro);
        }

        vecPrestamo[indiceLibre].idLibro=idLibro;
        system("cls");


        mostrarSocios(vecSocio, tamSocio);
        printf("\nIngrese el Id del socio: ");
        scanf("%d",&idSocio);

        indiceSocio = buscarSocioPorId(vecSocio, tamSocio, idSocio);

        while (indiceSocio == -1)
        {
            printf("\n*** Error ***");
            printf("\nIngrese el Id del socio: ");
            scanf("%d",&idSocio);
        }

        vecPrestamo[indiceLibre].idSocio=idSocio;
        system("cls");


        obtenerNumeroEntre(&auxfecha.dia, 31, 1, "## Ingrese dia de prestamo: ");

        obtenerNumeroEntre(&auxfecha.mes, 12, 1, "## Ingrese mes de prestamo: ");

        obtenerNumeroEntre(&auxfecha.anio, 2019, 2000, "## Ingrese anio de prestamo: ");

        vecPrestamo[indiceLibre].fechaPrestamo = auxfecha;


        vecPrestamo[indiceLibre].ocupado = 1;

        printf("\nPrestamo realizado con exito!!!\n\n");
        system("pause");

    }
}
