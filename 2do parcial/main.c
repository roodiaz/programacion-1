#include <stdio.h>
#include <stdlib.h>

#include "inputDiaz.h"
#include "LinkedList.h"
#include "parser.h"
#include "mascotas.h"

int menu();

int main()
{
    int flag=0;
    int salir;
    LinkedList* lista=ll_newLinkedList();
    LinkedList* pArraySubList;
    LinkedList* pArraySubListRaza;


    do
    {
        switch(menu())
        {
        case 1:
            controller_loadFromText("cachorros.csv", lista);
            flag=1;
            break;

        case 2:
             employee_printListOfEmployees(lista);
            break;

        case 3:
            if(flag==1)
            {
               pArraySubList = ll_filter(lista, employee_filterUnder45);
               controller_saveAsText("cachorros45.csv",pArraySubList);
                employee_printListOfEmployees(pArraySubList);
            }
            else{
                printf("primero se tiene que cargar el archivo!!");
            }


            break;

        case 4:
            if(flag==1)
            {
                pArraySubList = ll_filter(lista,employee_filterMacho);
                controller_saveAsText("cachorrosmachos.csv",pArraySubList);
               employee_printListOfEmployees(pArraySubList);
            }
            else{
                printf("primero se tiene que cargar el archivo!!");
            }

            break;

        case 5:
            if(flag==1)
            {
              pArraySubListRaza = ll_filter(lista, employee_filterRaza);
                employee_printListOfEmployees(pArraySubListRaza);
            }
            else{
                printf("primero se tiene que cargar el archivo!!");
            }

            break;

        case 6:
            salir=confimarSalir("Desae salir? ");
            break;
        }
    system("pause");
    }while(salir != 1);

    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    printf("*** MENU OPCIONES ***\n\n");
    printf("1. Cargar archivos\n");
    printf("2. Imprimir lista\n");
    printf("3. Filtrar menores de 45 dias\n");
    printf("4. Filtrar machos\n");
    printf("5. Generar listado de callejers\n\n");
    printf("6  Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;

}
