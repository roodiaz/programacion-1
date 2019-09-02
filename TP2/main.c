#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"

#define TAM 1000

int main()
{
    eEmpleado lista[TAM];
    float flag=0;
    char salir = 'n';

    do
    {
        switch(menuABM())
        {
            case 1:
                altaEmpleado(lista, TAM);
                flag =1;
            break;

            case 2:
                if(flag == 0)
                {
                    printf("\nPrimero debe dar de alta algun empleado!!!!\n\n");
                    system("pause");
                }
                else
                {
                    modificacionEmpleado(lista, TAM);
                }
            break;

            case 3:
                if(flag == 0)
                {
                    printf("\nPrimero debe dar de alta algun empleado!!!!\n\n");
                    system("pause");
                }
                else
                {
                    bajaEmpleado(lista, TAM);
                }
            break;

            case 4:
                if(flag == 0)
                {
                    printf("\nPrimero debe dar de alta algun empleado!!!!\n\n");
                    system("pause");
                }
                else
                {
                    informacionEmpleados(lista,TAM);
                }
            break;

            case 5:
                printf("\nDesea salir?s/n: ");
                fflush(stdin);
                scanf("%c",&salir);
            break;

            default:
                printf("\n\nNo se ha ingresado una opcion valida!!!!.\n\n");
                system("pause");
                menuABM();
        }

    }while(salir == 'n');


    return 0;
}
