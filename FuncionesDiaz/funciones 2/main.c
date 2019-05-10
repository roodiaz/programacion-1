#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "libros.h"
#include "inputDiaz.h"

#define TAMSOCIO 20
#define TAMAUTORES 10
#define TAMLIBROS 20
#define TAMPRESTAMOS 30


int main()
{

    eSocio lista[TAMSOCIO];
    inicializarSocio(lista, TAMSOCIO);
    hardCodeSocios(lista);

    eAutores listaAutor[TAMAUTORES];
    inicializarAutor(listaAutor, TAMAUTORES);
    hardCodeAutores(listaAutor);

    eLibros listaLibros[TAMLIBROS];
    inicializarLibro(listaLibros, TAMAUTORES);
    hardCodeLibros(listaLibros);

    ePrestamo listaPrestamos[TAMPRESTAMOS];
    inicializarPrestamos(listaPrestamos, TAMPRESTAMOS);

    char seguir = 's';
    char confirma;

    do
    {
        switch(menuABM())
        {
        case 1:
            altaSocio(lista, TAMSOCIO);
            break;

        case 2:
            modificacionSocio(lista, TAMSOCIO);
            break;

        case 3:
            bajaSocio(lista, TAMSOCIO);
            break;


        case 4:
            ordenarSocioApeNom(lista, TAMSOCIO);
            mostrarSocios(lista,TAMSOCIO);
            system("pause");
            break;

        case 5:
            ordenarLibrosTitulo(listaLibros, TAMLIBROS);
            mostrarLibros(listaLibros, TAMLIBROS);
            system("pause");
            break;

        case 6:
            ordenarAutoresApeNom(listaAutor, TAMAUTORES);
            mostrarAutores(listaAutor, TAMAUTORES);
            system("pause");
            break;

        case 7:
            altaPrestamo(listaPrestamos, TAMPRESTAMOS, listaLibros, TAMLIBROS, lista, TAMSOCIO);
            break;

        case 8:
            mostrarPrestamos(listaPrestamos, TAMPRESTAMOS);
            system("pause");
            break;

        case 9:
            printf("\nConfirma salida s/n?: ");
            fflush(stdin);
            confirma = getche();

            if( tolower(confirma) == 's')
            {
                seguir = 'n';
            }
            break;

        default:
            printf("\n\nNo se ha ingresado una opcion valida!!!!.\n\n");
            system("pause");
            menuABM();
        }

    }
    while(seguir == 's');

    return 0;
}

