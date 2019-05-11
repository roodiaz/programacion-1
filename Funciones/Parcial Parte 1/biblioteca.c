#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "inputDiaz.h"
#include "biblioteca.h"

void hardCodeMarcas(eMarca vec[])
{

    eMarca ejemplos[]=
    {
        {2000, "Fiat",1},
        {4000, "Ford",1},
        {1000, "Chevrolet",1},
        {2342, "Renault",1},
        {4134, "Peugeot",1}
    };

    for(int i=0; i < 10; i++)
    {
        vec[i] = ejemplos[i];
    }
};

void hardCodeColores(eColor vec[])
{
    eColor ejemplos[] =
    {
        {5756, "Rojo",1},
        {7000, "Azul",1},
        {5000, "Bordo",1},
        {6000, "Negro",1},
        {8500, "Gris",1}
    };

    for(int i=0; i < 10; i++)
    {
        vec[i] = ejemplos[i];
    }
}

void hardCodeServicio(eServicio vec[])
{
    eServicio ejemplos[]=
    {
        {40000, "Lavado", 250},
        {60000, "Pulido", 300},
        {20000, "Encerado", 400},
        {30000, "Completo", 600}
    };

    for(int i=0; i < 10; i++)
    {
        vec[i] = ejemplos[i];
    }
}

void hardCodeAutos(eAuto vec[])
{
    eAuto ejemplos[]=
    {
        {500,"fad414", 4000, 6000, 2009, 1},
        {300, "jff523", 2000, 7000, 2018, 1},
        {100, "vza253", 2342, 5756, 2000, 1},
        {200, "pou975", 4134, 8500, 2016, 1},
    };

    for(int i=0; i < 10; i++)
    {
        vec[i] = ejemplos[i];
    }
}


int menuABM()
{
    int opcion;

    system("cls");
    printf("##### Menu ABM #####\n\n");
    printf("   1. Alta Autos.\n");
    printf("   2. Modificar Auto.\n");
    printf("   3. Baja Auto.\n");
    printf("   4. Listar Autos.\n");
    printf("   5. Listar Marcas.\n");
    printf("   6. Listar Colores.\n");
    printf("   7. Listar Servicio.\n");
    printf("   1. Alta Trabajos.\n");
    printf("   8. Listar trabajos.\n\n");
    printf("   9. Salir.\n\n");
    printf(">> Ingresar opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

int buscarLibreAuto(eAuto vec[], int tam)
{
    int indice = -1;

    for(int i=0; i <tam; i++)
    {
        if(vec[i].ocupado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarLibreServicio(eServicio vec[], int tam)
{
    int indice = -1;

    for(int i=0; i <tam; i++)
    {
        if(vec[i].ocupado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void inicializarAuto(eAuto vec[], int tam)
{

    for(int i=0; i < tam; i++)
    {
        vec[i].ocupado = 0;
    }
}

void inicializarMarca(eMarca vec[], int tam)
{

    for(int i=0; i < tam; i++)
    {
        vec[i].ocupado = 0;
    }
}

void obtenerIdAuto(char dondeAsignar[], int tamMax, char mensaje[], int tamMin)
{
    char aux[100];
    char id;


    printf("\n%s",mensaje);
    fflush(stdin);
    gets(aux);

    id=validarNumeros(aux, "## Ingresar telefono: ");

    if(id==1)
    {

        while(strlen(aux)>tamMax || strlen(aux) < tamMin)
        {
            printf("*** Error ***\n");
            printf("\n%s",mensaje);
            fflush(stdin);
            gets(aux);
        }

        strcpy(dondeAsignar, aux);
    }
}

int buscarMarcaPorId(eMarca vec[], int tam, int idMarca)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1 && vec[i].idMarca==idMarca)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarColorPorId(eColor vec[],int tam, int idColor)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1 && vec[i].idColor==idColor)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarAutoPorId(eAuto vec[],int tam, int idAuto)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1 && vec[i].idAuto==idAuto)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarServicioPorId(eServicio vec[],int tam, int idServicio)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1 && vec[i].idServicio==idServicio)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int buscarAutoPorPatente(eAuto vec[],int tam, int patente)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1 && vec[i].patente==patente)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarMarca(eMarca vec)
{
    printf("\nId Marca: %d // Descripcion Marca: %s",vec.idMarca, vec.descripcion);
}

void mostrarMarcas(eMarca vec[], int tam)
{
    int contador = 0;

    system("cls");

    for(int i=0; i <tam; i++)
    {
        if(vec[i].ocupado==1)
        {
            mostrarMarca(vec[i]);
            contador++;
        }

    }
    printf("\n\n");

    if(contador == 0)
    {
        printf("No hay marcas para mostrar\n");
        system("pause");
    }
}

void mostrarServicio(eServicio vec)
{
    printf("\nId Servicio: %d // Descripcion Servicio: %s //  Precio: %d",vec.idServicio, vec.descripcion,vec.precioServicio);
}

void mostrarServicios(eServicio vec[], int tam)
{
    int contador = 0;

    system("cls");

    for(int i=0; i <tam; i++)
    {
        if(vec[i].ocupado == 1)
        {
            mostrarServicio(vec[i]);
            contador++;
        }

    }
    printf("\n\n");

    if(contador == 0)
    {
        printf("No hay colores para mostrar\n");
        system("pause");
    }
}


void mostrarColor(eColor vec)
{
    printf("\nId Color: %d // Color: %s",vec.idColor, vec.nombreColor);
}

void mostrarColores(eColor vec[], int tam)
{
    int contador = 0;

    system("cls");

    for(int i=0; i <tam; i++)
    {
        if(vec[i].ocupado == 1)
        {
            mostrarColor(vec[i]);
            contador++;
        }

    }
    printf("\n\n");

    if(contador == 0)
    {
        printf("No hay colores para mostrar\n");
        system("pause");
    }
}

void mostrarAuto(eAuto vec)
{
    printf("\nId auto: %d  //  Patente: %s  //  Id Marca: %d  //  Id Color: %d  //  Anio Modelo: %d",vec.idAuto,vec.patente,vec.idMarca,vec.idColor,vec.modelo);
}

void mostrarAutos(eAuto vec[], int tam)
{
    int contador = 0;

    system("cls");

    for(int i=0; i <tam; i++)
    {
        if(vec[i].ocupado == 1)
        {
            mostrarAuto(vec[i]);
            contador++;
        }

    }
    printf("\n\n");

    if(contador == 0)
    {
        printf("No hay autos para mostrar\n");
        system("pause");
    }
}

void altaAuto(eAuto vecAuto[], int tamAuto, eMarca vecMarca[], int tamMarca, eColor vecColor[], int tamColor)
{
    int libreAuto;
    int indiceMarca;
    int indiceColor;
    int idMarca;
    int idColor;
    char auxId[50];
    char auxPatente[50];

    libreAuto = buscarLibreAuto(vecAuto, tamAuto);

    if(libreAuto == -1)
    {
        printf("\nNo hay mas lugar en el sistema!!!\n");
        system("pause");
    }
    else
    {
        obtenerIdAuto(auxId,1000, "## Ingrese ID de auto: ",1);
        vecAuto[libreAuto].idAuto=atoi(auxId);

        ///////

        obtenerCadenaAlpaNumerica(auxPatente, 6, "## Ingrese patente: ");
        strcpy(vecAuto[libreAuto].patente, auxPatente);

        //////
        mostrarMarcas(vecMarca, tamMarca);
        printf("\nIngrese el Id de la marca: ");
        scanf("%d",&idMarca);

        indiceMarca = buscarMarcaPorId(vecMarca, tamMarca, idMarca);

        if (indiceMarca== -1)
        {
            printf("\n*** Error ***");
            printf("\nIngrese el Id de la marca: ");
            scanf("%d",&idMarca);
        }
        else
        {
            vecAuto[libreAuto].idMarca=idMarca;
            system("cls");
        }

        ////////////

        mostrarColores(vecColor, tamColor);
        printf("\nIngrese el Id del color: ");
        scanf("%d",&idColor);

        indiceColor = buscarColorPorId(vecColor, tamColor, idColor);

        while (indiceColor == -1)
        {
            printf("\n*** Error ***");
            printf("\nIngrese el Id del color: ");
            scanf("%d",&idColor);
        }

        vecColor[libreAuto].idColor=idColor;
        system("cls");

        //////////

        obtenerNumeroEntre(vecAuto[libreAuto].modelo, 2020, 1970,  "## Ingrese anio del auto: ");

        vecAuto[libreAuto].ocupado = 1;

        printf("\nAuto dado de alta con exito!!!\n\n");
        system("pause");

    }
}

int menuModificacionAuto()
{
    int opcion;

    system("cls");
    printf("#####  Menu de Modificion  ####\n\n");

    printf("    1_ Color.\n");
    printf("    2_ Modelo.\n");
    printf("    3_ Volver al menu principal.\n");
    printf("\n\n>>>> Opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

void modificacionAuto(eAuto vecAuto[], int tamAuto, eColor vecColor[], int tamColor)
{

    int idAuto;
    int idColor;
    int opcion;
    int indiceAuto;
    int indiceColor;
    char confirma;

    mostrarAutos(vecAuto, tamAuto);
    printf("\n>>> Ingrese Id: ");
    scanf("%d", &idAuto);

    indiceAuto = buscarAutoPorId(vecAuto, tamAuto, idAuto);

    if(indiceAuto == -1)
    {
        printf ("\nEl id %d no esta registrado en el sistema\n\n", idAuto);
        system("pause");
        menuABM();
    }
    else
    {
        printf ("\nDesea modificar auto? s/n: ");
        fflush (stdin);
        confirma = tolower(getche());
    }

    if(confirma=='n')
    {
        menuABM();
    }
    else
    {
        switch(menuModificacionAuto())
        {
        case 1:
            mostrarColores(vecColor, tamColor);
            printf("\nIngrese el Id del color: ");
            scanf("%d",&idColor);

            indiceColor = buscarColorPorId(vecColor, tamColor, idColor);

            while (indiceColor == -1)
            {
                printf("\n*** Error ***");
                printf("\nIngrese el Id del color: ");
                scanf("%d",&idColor);
            }

            vecColor[indiceAuto].idColor=idColor;
            system("cls");
            break;

        case 2:
            obtenerNumeroEntre(vecAuto[indiceAuto].modelo, 2020, 1970,  "## Ingrese anio del auto: ");
            break;

        case 3:
            menuABM();
            break;

        default:
            if(opcion > 3 || opcion < 0)
            {
                printf("\nIngrese opcion valida: ");
                scanf("%d",&opcion);
            }
        }

    }
}

void bajaAuto(eAuto vec[], int tam)
{
    int id;
    int indice;
    char confirma;

    mostrarAutos(vec, tam);
    printf("\nIngrese el Id de socio: ");
    scanf("%d",&id);

    indice = buscarAutoPorId(vec, tam, id);

    if (indice == -1)
    {
        printf ("El id %d no esta registrado en el sistema \n", id);
        system("pause");
    }
    else
    {
        printf ("\nDesea dar de baja al auto? s/n: ");
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
            printf("\n\nAuto dado de baja con exito!!!\n\n");
            system("pause");
        }
        else
        {
            printf ("\n\nSe ha cancelado la operacion.\n\n" );
            system("pause");
        }
    }
}

void ordenarAutos(eAuto vec[], int tam)
{
    eAuto aux;

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(vec[i].idMarca >vec[j].idMarca)
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }

            if(vec[i].idMarca == vec[j].idMarca)
            {
                if(stricmp(vec[i].patente, vec[j].patente)>0)
                {
                    aux=vec[i];
                    vec[i]=vec[j];
                    vec[j]=aux;
                }
            }
        }
    }
}

void incrementalTrabajo(eTrabajo vec[],int tam)
{
    for (int i=0; i<tam; i++)
    {
        vec[i].idTrabajo= i+1;
    }
}

void altaTrabajo(eTrabajo vecTrabajo[], int tamTrabajo, eAuto vecAuto[], int tamAuto, eServicio vecServicio[], int tamServicio)
{
    int indice;
    int indicePatente;
    int indiceServicio;
    int idServicio;
    int patente;


    indice = buscarLibreServicio(vecTrabajo, tamTrabajo);

    if(indice == -1)
    {
        printf("\nNo hay mas lugar en el sistema!!!\n");
        system("pause");
    }
    else
    {
        incrementalTrabajo(vecTrabajo, tamTrabajo);

        ////////////77

        mostrarAutos(vecAuto, tamAuto);
        printf("\nIngrese la patente: ");
        scanf("%d",&patente);

        indicePatente = buscarAutoPorPatente(vecAuto, tamAuto, patente);

        if (indicePatente== -1)
        {
            printf("\n*** Error ***");
            printf("\nIngrese la patente: ");
            scanf("%d",&patente);
        }
        else
        {
            vecTrabajo[indice].patenteTrabajo=patente;
            system("cls");
        }

        ////////////

        mostrarServicios(vecServicio, tamServicio);
        printf("\nIngrese el Id del servicio: ");
        scanf("%d",&idServicio);

        indiceServicio = buscarServicioPorId(vecServicio, tamServicio);

        while (indiceServicio == -1)
        {
            printf("\n*** Error ***");
            printf("\nIngrese el Id del Servicio: ");
            scanf("%d",&idServicio);
        }

        vecServicio[indice].idServicio=idServicio;
        system("cls");




        vec[indice].ocupado = 1;

        printf("\nAlta de socio realizada con exito!!!\n\n");
        system("pause");

    }

}
