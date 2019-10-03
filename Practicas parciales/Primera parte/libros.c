#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include "libros.h"


//*Inicializacion*//

void iniciarSociosIsEmpty ( STR_Socios iniciando[],int cantidadElementos,int numeroQueSeAsigna )
{
    int i;
    for(i=0; i < cantidadElementos ; i++)

    {
        iniciando[i].isEmpty = numeroQueSeAsigna;
    }

    return;
}

void inciarIncrementalIdSocios (STR_Socios iniciando[], int cantidadElementos )
{
    int i;
    for(i=0; i < cantidadElementos ; i++)
    {
        iniciando[i].id = i+1;
    }
    return;
}


void iniciarPrestamosIsEmpty ( STR_Prestamos iniciando[],int cantidadElementos,int numeroQueSeAsigna )
{
    int i;
    for(i=0; i < cantidadElementos ; i++)

    {
        iniciando[i].isEmpty = numeroQueSeAsigna;
    }

    return;
}

void iniciarIncrementalIdPrestamos (STR_Prestamos iniciando[], int cantidadElementos )
{
    int i;
    for(i=0; i < cantidadElementos ; i++)
    {
        iniciando[i].id = i+1;
    }
    return;
}


//*Busqueda*//

int buscarIdVacioSocio (STR_Socios socio[], int cantidadSocios)
{

    int i=0;
    for (i=0; i<cantidadSocios; i++)
    {
        if (socio[i].isEmpty == 1)
        {
            return i;
        }
    };
    return -1;
}

int buscarIndexPorIdSocio (STR_Socios socio[],int cantidadSocios,int id)
{

    int i;
    for (i=0; i<cantidadSocios; i++)
    {
        if (socio[i].id == id && socio[i].isEmpty == 0)
        {
            return i;
        }
    };

    return -1;
}



int buscarIdVacioPrestamo (STR_Prestamos prestamo[], int cantidadPrestamos)
{

    int i=0;
    for (i=0; i<cantidadPrestamos; i++)
    {
        if (prestamo[i].isEmpty == 1)
        {
            return i;
        }
    };
    return -1;
}

int buscarIndexPorIdPrestamo (STR_Prestamos prestamo[],int cantidadPrestamos,int id)
{

    int i;
    for (i=0; i<cantidadPrestamos; i++)
    {
        if (prestamo[i].id == id && prestamo[i].isEmpty == 0)
        {
            return i;
        }
    };

    return -1;
}



//*Hardcode*//

void hardCodeLibros(STR_Libros lista[])
{
    int i;
    STR_Libros ejemplos[]=
    {
        {1, "Huckleberry Finn", 10},
        {2, "Hamlet", 9},
        {3, "La Iliada", 8},
        {4, "Cien Anyos de Soledad",7 },
        {5, "La divina comedia",6},
        {6, "Crimen y Castigo",5},
        {7, "1984",4},
        {8, "El Senyor de los Anillos", 2},
        {9, "Don Quijote de la Mancha", 1},
        {10, "El Principito", 3}
    };

    for(i=0; i < 10; i++)
    {
        lista[i] = ejemplos[i];
    };
}

void hardCodeAutores(STR_Autores lista[])
{
    int i;
    STR_Autores ejemplos[]=
    {
        {1, "Miguel", "De Cervantes"},
        {2, "J.R.R","Tolkien"},
        {3, "Antoine","de Saint Exupery"},
        {4, "George","Orwell"},
        {5, "Fiodor","Dostoievski"},
        {6, "Dante","Alighieri"},
        {7, "Gabriel","Garcia Marquez"},
        {8, "Homero"," "},
        {9, "William","Shakespeare"},
        {10,"Mark","Twain"},
    };

    for(i=0; i < 10; i++)
    {
        lista[i] = ejemplos[i];
    };
}

void hardCodeSocios (STR_Socios lista[])
{

    STR_Fecha fecha = {1,4,2000};
    STR_Fecha fechab = {2,6,2010};

    STR_Socios ejemplo[]=
    {


        {1, "Pamela ", "Subizar",'F', "11111111","Pamela@gmail.com",fechab,0},
        {22, "Martina", "Sosa",'F', "18001210", "Martina@gmail.com",fechab,0},
        {35, "Benjamín", "Garcia",'M', "324234342", "Benjamín@gmail.com",fecha,0},
        {42, "Sofia", "Flores",'F',"32324342", "Sofia@gmail.com",fechab, 0},
        {56, "Juan Ignacio", "Acosta",'M', "67555656", "Juan@gmail.com",fecha, 0},
        {1000, "Thiago ", "Suarez",'M'," 36663636","Thiago@gmail.com",fecha, 0},
        {73, "Valentina", "Garcia",'F'," 2622262", "Valentina@gmail.com",fechab,0},
        {99, "Romina", "Ruiz",'F', "262444445","Romina@gmail.com",fechab, 0},
        {980, "Antonio", "Garcia",'M', "8798978905","Antonio@gmail.com",fecha, 0},
        {21, "Julieta", "Villalba",'F', "456546545", "JulietaV@gmail.com",fechab,0}
    };

    for(int i=0; i < 10; i++)
    {
        lista[i] = ejemplo[i];
    };

}

//*Menu*//

void menu ()
{
    limpiar();
    printf(           "**Menu**\n"
                      "Ingrese A para dar de Alta un socio -\n\n"
                      "Ingrese B para Modificar los datos de un socio -\n\n"
                      "Ingrese C para dar de baja un socio -\n\n"
                      "Ingrese D para listar los socios ordenados por Apellido y Nombre -\n\n"
                      "Ingrese E para listar los libros cargados-\n\n"
                      "Ingrese F para listar los autores cargados-\n\n"
                      "Ingrese G para dar de alta un prestamo-\n\n"
                      "Ingrese H para listar los prestamos cargados-\n\n"
                      "Ingrese X para Salir -\n\n");

    return;
}

//*Listados*//

void listarLibros (STR_Autores autor[],int cantidadAutores,STR_Libros libro[], int cantidadLibros )
{


    /*STR_Libros temp;

    //ordeno por titulo del libro metodo insercion//

    for(i=1 ; i<cantidadLibros ; i++)
    {

        temp = libro[i];

        j=i-1;

        while(j>=0 && (strcmp (temp.nombre,libro[j].nombre) < 0) )
        {

            libro[j+1] = libro[j];
            j--;
        }

        libro[j+1]=temp;

    }
    */

    //Muestro los libros//

    int i,j,indexAutor;

    printf("LIBROS:\n");
    printf("Codigo Nombre:                     Autor:\n\n");

    for(i=0; i<cantidadLibros; i++)
    {
        //Busco el index del nombre del autor por su id
        for (j=0; j<cantidadAutores; j++)
        {
            if(libro[i].idAutor == autor[j].id)
            {
                indexAutor = j;
            }
        };

        printf("%3d %30s %10s %s\n", libro[i].id, libro[i].nombre,autor[indexAutor].nombre, autor[indexAutor].apellido);

    };

    return;
}

void listarAutores(STR_Autores autor [],int cantidadAutores)
{

    int i;

    printf("AUTORES:\n");
    printf("Codigo: Nombre Autor:\n\n");

    for(i=0; i<cantidadAutores; i++)
    {
        printf("%3d %15s %s\n",autor[i].id, autor[i].nombre, autor[i].apellido);
    };

    return;
}

void listarSocios (STR_Socios socio [], int cantidadSocios)
{

    STR_Socios aux;

    int i,j;
    int invalido;

    //Veo si hay socios cargados//
    invalido = 1;

    for (i=0 ; i< cantidadSocios ; i++)
    {
        if (socio[i].isEmpty == 0)
        {
            invalido = 0;
        };
    };

    //si NO hay socios
    if (invalido == 1)  //significa que no hay socios cargados
    {
        printf("\nNo hay socios cargados\n");
        return;
    };

    //Ordeno los socios por Apellido , si tienen el mismo apellido , por nombre//

    for(i=0; i<cantidadSocios-1; i++)
    {

        for(j=i+1; j<cantidadSocios; j++)
        {
            if( strcmp (socio[i].apellido, socio[j].apellido)>0 )
            {
                aux = socio[j];
                socio[j] = socio[i];
                socio[i] = aux;
            };

            if ( strcmp(  socio[i].apellido,socio[j].apellido) == 0 )
            {

                if( strcmp( socio[i].nombre, socio[j].nombre)>0 )
                {
                    aux = socio[j];
                    socio[j] = socio[i];
                    socio[i] = aux;
                };
            };
        };
    };
    //Muestro los socios y sus datos//

    printf("SOCIOS :\n");
    printf("Codigo: Apellido y nombre:       Sexo:  Email:              Tel:    Fecha:\n");

    for (i=0; i<cantidadSocios ; i++)
    {
        if (socio[i].isEmpty == 0)
        {
            printf("%4d %10s %-15s %1c %20s %10s %2d/%2d/%4d\n",socio[i].id,socio[i].apellido,socio[i].nombre,
                   socio[i].sexo,socio[i].email,socio[i].telefono,socio[i].fecha_Asociado.dia,socio[i].fecha_Asociado.mes,
                   socio[i].fecha_Asociado.anyo);
        };
    };
    return;
}

void listarUnSocio (STR_Socios socio [], int id)
{

    printf("Codigo: Apellido y nombre:       Sexo:  Email:              Tel:    Fecha:\n");
    printf("%4d %10s %-15s %1c %20s %10s %2d/%2d/%4d\n",socio[id].id,socio[id].apellido,socio[id].nombre,
           socio[id].sexo,socio[id].email,socio[id].telefono,socio[id].fecha_Asociado.dia,socio[id].fecha_Asociado.mes,
           socio[id].fecha_Asociado.anyo);
    return;
}

void listarPrestamos (STR_Prestamos prestamo[], int cantidadPrestamos,STR_Socios socio[], int cantidadSocios, STR_Libros libro[])
{

    int i,j,invalido;
    int indexSocio;

    invalido = 1;

    //Veo que haya almenos UN prestamo cargado.
    for (i=0; i<cantidadPrestamos; i++)
    {
        if (prestamo[i].isEmpty == 0)
        {
            invalido = 0;
        }
    }
    //Si NO hay
    if (invalido == 1)
    {
        printf("No hay prestamos cargados");
        return;
    };
    //Si SI hay , los listo

    printf("Prestamo:\n");
    printf("Codigo Socio:                   Libro:                        Fecha:\n\n");

    for(i=0; i < cantidadPrestamos ; i++)
    {

        //busco el index de los socios//
        for (j=0; j<cantidadSocios; j++)
        {
            if(prestamo[i].idSocio == socio[j].id)
            {
                indexSocio = j;
            }
        };

        if (prestamo[i].isEmpty == 0)
        {

            printf("%4d %10s %-15s %-30s %2d/%2d/%2d\n",prestamo[i].id, socio[indexSocio].apellido, socio[indexSocio].nombre,
                   libro[prestamo[i].idLibro].nombre, prestamo[i].fecha_Prestamo.dia, prestamo[i].fecha_Prestamo.mes,
                   prestamo[i].fecha_Prestamo.anyo);
        };
    };

    return;

}


//*Altas*//

void altaSocio (STR_Socios socio [], int cantidadSocios)
{

    char auxName [31];
    char auxLastName[31];
    char auxSexo;
    char auxEmail[31];
    char auxTelef[16];
    STR_Fecha auxfecha;
    int invalido, id;

    invalido = buscarIdVacioSocio(socio, cantidadSocios);  //Busco el primer id vacio

    if (invalido == -1) // si NO se encuentra un id vacio
    {
        printf("\nNo queda lugar\n");
        return;
    };

    //si SI se encuentra un id vacio le cargo los datos//

    id = invalido;
    limpiar();
    f_i_PedirNombre(auxName, 31, "\nIngrese el Nombre del socio:");
    limpiar();
    f_i_PedirNombre(auxLastName, 31, "\nIngrese el Apellido del socio:");
    limpiar();
    f_i_PedirSexo(&auxSexo, "\nIngrese el sexo del socio:");
    limpiar();
    f_i_PedirTelefono(auxTelef,16,"\nIngrese el telefono del socio:");
    limpiar();
    f_i_PedirEmail(auxEmail, 31, "\nIngrese el email del socio:");
    limpiar();
    pedirFecha(&auxfecha.dia,&auxfecha.mes,&auxfecha.anyo,"Se registro el socio","Se registro el socio","Se registro el socio");
    limpiar();

    strcpy(socio[id].nombre, auxName);
    strcpy(socio[id].apellido, auxLastName);
    socio[id].sexo = auxSexo;
    strcpy(socio[id].telefono, auxTelef);
    strcpy(socio[id].email, auxEmail);
    socio[id].fecha_Asociado = auxfecha;
    socio[id].isEmpty = 0;

    printf("\nSocio cargado correctamente\n");

    fflush(stdin);
}

void altaPrestamo( STR_Prestamos prestamo[], STR_Libros libro [],int cantidadLibros, STR_Socios socio[],int cantidadSocios, STR_Autores autor[],int cantidadAutores)
{

    int invalido = 1, id, seleccionUsuario,i,auxIdSocio;
    STR_Fecha auxFecha;

    //Veo si hay socios cargados//
    for (i=0; i<cantidadSocios; i++)
    {
        if (socio[i].isEmpty == 0)
        {
            invalido=0;
        }
    }
    //Si NO hay socios cargados
    if (invalido == 1)
    {
        printf("No hay socios cargados.No se puede cargar un prestamo");
        return;
    };

    //si SI hay socios cargados, veo si hay lugar para prestamos

    invalido = buscarIdVacioPrestamo(prestamo, cantidadSocios);  //Busco el primer id vacio

    if (invalido == -1) // si NO se encuentra un id vacio
    {
        printf("\nNo queda lugar\n");
        return;
    };

    //si SI se encuentra un id vacio, cargo los datos//
    id = invalido;

    //Pido codigo Socio
    limpiar();

    listarSocios(socio,cantidadSocios);
    f_i_PedirIntEntre(&seleccionUsuario, 1, cantidadSocios,"\nIngrese el codigo del socio que realizo el prestamo:");

    auxIdSocio = seleccionUsuario; // guardo el valor del id del socio

    //valido que exista y saco el index del socio
    seleccionUsuario = buscarIndexPorIdSocio(socio,cantidadSocios,seleccionUsuario);

    //si no existe
    if (seleccionUsuario == -1)
    {
        limpiar();
        printf("Codigo de socio invalido");
        return;
    };

    //si si existe
    prestamo[id].idSocio = auxIdSocio; //uso este porque seleccionUsuario es el valor del index del socio , no del id.

    //Pido codigo de libro//
    limpiar();
    listarLibros(autor,cantidadAutores,libro,cantidadLibros);
    f_i_PedirIntEntre(&seleccionUsuario, 1, cantidadLibros,"\nIngrese el codigo del libro prestado:");
    prestamo[id].idLibro = seleccionUsuario-1;

    //Pido fecha de prestamo
    limpiar();
    pedirFecha(&auxFecha.dia,&auxFecha.mes,&auxFecha.anyo,"se realizo el prestamo","se realizo el prestamo","se realizo el prestamo");
    prestamo[id].fecha_Prestamo = auxFecha;

    prestamo[id].isEmpty = 0 ; // ocupo el prestamo

    limpiar();
    printf("\nPrestamo cargado correctamente");
    return;
}


//*Modificacion*//

void modificarSocio (STR_Socios socio [], int cantidadSocios)
{


    int i, invalido, id;

    //Veo si hay socios cargados//
    invalido = 1;

    for (i=0; i<cantidadSocios; i++)
    {

        if (socio[i].isEmpty == 0)
        {
            invalido = 0;
        };
    };
    //Si NO hay socios cargados
    if (invalido == 1 )
    {
        limpiar();
        printf("No hay socios cargados\n");
        return;
    };
    //Si SI hay socios cargados , los listo//
    listarSocios(socio,cantidadSocios);

    //pido el id del socio a modificar//
    f_i_PedirIntEntre(&id,1,cantidadSocios,"Ingrese el codigo del socio a modificar");

    //Busco si hay un socio cargado en ese id//
    invalido = buscarIndexPorIdSocio(socio,cantidadSocios,id);

    if (invalido == -1) // si no se encuentra el id ingresado
    {
        limpiar();
        printf("\nCodigo de socio invalido\n");
        return;
    };

    //si SI se encuentra//
    id = invalido;
    //confirmo
    limpiar();
    listarUnSocio(socio,id);
    invalido = f_i_SioNo("Desea modificar este socio?");

    if (invalido == 0)
    {
        limpiar();
        printf("\nNo se modifico el socio");
        return;
    };

    //Si se ingresa S , modifico los datos//

    int opcion;
    char auxName [31];
    char auxLastName[31];
    char auxSexo;
    char auxEmail[31];
    char auxTelef[16];
    STR_Fecha auxfecha;

    limpiar();
    f_i_PedirIntEntre(&opcion,1,7,"1-Modificar Nombre\n2-Modificar Apellido\n3-Modificar Sexo\n"
                      "4-Modificar Telefono\n5-Modificar Email\n6-Modificar Fecha de asociado\n7-Salir\nOpcion: ");

    switch (opcion)
    {

    case 1 :
        limpiar();
        f_i_PedirNombre(auxName,31,"\nIngrese el Nombre del Socio:\n");
        strcpy(socio[id].nombre,auxName);
        break;

    case 2 :
        limpiar();
        f_i_PedirNombre(auxLastName,31,"\nIngrese el Apellido del Socio:\n");
        strcpy(socio[id].apellido,auxLastName);
        break;

    case 3 :
        limpiar();
        f_i_PedirSexo(&auxSexo,"\nIngrese el sexo del Socio:\n");
        socio[id].sexo = auxSexo;
        break;

    case 4 :
        limpiar();
        f_i_PedirTelefono(auxTelef,16,"\nIngrese el Telefono del Socio:\n");
        strcpy(socio[id].telefono,auxTelef);
        break;

    case 5 :
        limpiar();
        f_i_PedirEmail(auxEmail,31,"\nIngrese el Email del Socio:\n");
        strcpy(socio[id].email,auxEmail);
        break;

    case 6 :
        limpiar();
        pedirFecha(&auxfecha.dia,&auxfecha.mes,&auxfecha.anyo,"Se registro el socio","Se registro el socio","Se registro el socio");
        socio[id].fecha_Asociado = auxfecha;
        break;
    case 7:
        return;
    }
    limpiar();
    printf("\n*Socio Modificado Correctamente*\n");
    return;


}



//*Baja*//

void bajaSocio(STR_Socios socio [], int cantidadSocios)
{

    int i, invalido, id;

    //Veo si hay socios cargados//
    invalido = 1;

    for (i=0; i<cantidadSocios; i++)
    {

        if (socio[i].isEmpty == 0)
        {
            invalido = 0;
        };
    };
    //Si NO hay socios cargados
    if (invalido == 1 )
    {
        limpiar();
        printf("No hay socios cargados\n");
        return;
    };
    //Si SI hay socios cargados , los listo//
    listarSocios(socio,cantidadSocios);

    //pido el id del socio a modificar//
    f_i_PedirIntEntre(&id,1,cantidadSocios,"Ingrese el codigo del socio a dar de baja");

    //Busco si hay un socio cargado en ese id//
    invalido = buscarIndexPorIdSocio(socio,cantidadSocios,id);

    if (invalido == -1) // si no se encuentra el id ingresado
    {
        limpiar();
        printf("\nCodigo de socio invalido\n");
        return;
    };

    //si SI se encuentra//
    id = invalido;
    //confirmo
    limpiar();
    listarUnSocio(socio,id);
    invalido = f_i_SioNo("Desea dar de baja este socio?");

    if (invalido == 0)
    {
        limpiar();
        printf("\nNo se dio de baja el socio");
        return;
    };

    limpiar();
    socio[id].isEmpty = 1;
    printf("\nSe dio de baja el socio");
    return;


}
