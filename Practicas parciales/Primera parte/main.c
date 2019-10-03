#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#include "libros.h"
#include "inputElian.h"

#define CANTIDADAUTORES 10
#define CANTIDADLIBROS 10
#define CANTIDADSOCIOS 1000
#define CANTIDADPRESTAMOS 100

#define TRUE 1
#define FALSE 0

int main()
{
    noVeo();
    //Variables//
    STR_Autores autores[CANTIDADAUTORES];
    STR_Libros libros [CANTIDADLIBROS];
    STR_Socios socios[CANTIDADSOCIOS];
    STR_Prestamos prestamos [CANTIDADPRESTAMOS];

    char seleccion;

    //Inicializacion de prestamos y socios//

    iniciarSociosIsEmpty ( socios,CANTIDADSOCIOS, TRUE);// 1 Significa que NO hay un socio cargado
    inciarIncrementalIdSocios (socios, CANTIDADSOCIOS);  // pongo los id del 0 al -> CANTIDADSOCIOS de uno en uno

    iniciarPrestamosIsEmpty(prestamos,CANTIDADPRESTAMOS,TRUE);// 1 Significa que NO hay un prestamo cargado
    iniciarIncrementalIdPrestamos(prestamos,CANTIDADPRESTAMOS);// pongo los id del 0 al -> CANTIDADPRESTAMOS de uno en uno

    //Hardcode//
    hardCodeAutores(autores);
    hardCodeLibros(libros);
    hardCodeSocios(socios); // este no va es pa probar ///////////////////////////////////////////////////////////////////////////////

    //Menu//
    do
    {
        menu();

        //Switch//

        fflush(stdin);
        seleccion = getchar();
        seleccion = tolower(seleccion);

        switch(seleccion)
        {

        case 'a':
            limpiar();
            altaSocio(socios,CANTIDADSOCIOS);
            f_i_continuar();
            break;

        case 'b':
            limpiar();
            modificarSocio(socios,CANTIDADSOCIOS);
            f_i_continuar();
            break;

        case 'c':
            limpiar();
            bajaSocio(socios,CANTIDADSOCIOS);
            f_i_continuar();
            break;

        case 'd':
            limpiar();
            listarSocios (socios,CANTIDADSOCIOS);
            f_i_continuar();
            break;


        case 'e':
            limpiar();
            listarLibros (autores,CANTIDADAUTORES,libros,CANTIDADLIBROS);
            f_i_continuar();
            break;

        case 'f':
            limpiar();
            listarAutores(autores,CANTIDADAUTORES);
            f_i_continuar();
            break;

        case 'g':
            limpiar();
            altaPrestamo(prestamos,libros,CANTIDADLIBROS,socios,CANTIDADSOCIOS,autores,CANTIDADAUTORES);
            f_i_continuar();
            break;

        case 'h':
            limpiar();
            listarPrestamos(prestamos,CANTIDADPRESTAMOS,socios,CANTIDADSOCIOS,libros);
            f_i_continuar();
            break;

        case 'x':
            limpiar();
            break;

        default :
            limpiar();
            printf("**Opcion Invalida**\n");
            f_i_continuar();
            break;
        } //switch

    }
    while (seleccion != 'x');    // do

    printf("Chau");
    return 0;
}


