#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

int obtenerMaximo (int x, int y, int z)
{
   int max;

   max=x;

    if(y>max && y>z)
    {
        max=y;
    }
    else
    {
        if(z>max)
        {
            max=z;
        }
    }

    return max;
}


int sumarDosNumeros (int x, int y)
{
    int sumar;

    sumar = x + y;

    return sumar;
}

int restarDosNumeros (int x, int y)
{
    int resta;

    resta = x - y;

    return resta;
}

int multiplicarDosNumeros (int x, int y)
{
    int producto;

    producto = x * y;

    return producto;
}

float dividirDosNumeros (int x, int y)
{
    float resto;

    if( y == 0 )
    {
        printf("Error. No se puede dividir por 0.");
    }
    else
    {
        resto =(float) x / y;
    }

    return resto;
}

int factorial (int x)
{
    if ( x == 0 )
    {
        x = 1;
    }
    else
    {
        x = x * factorial(x-1);
    }

    return x;
}

int menuOpciones ()
{
    int opcion;

    printf("\n\n *** Menu de opciones *** \n\n");
    printf("1- Ingresar 1er operando (A = x).\n");
    printf("2- Ingresar 2do operando (B = y).\n");
    printf("3- Calcular todas las operaciones.\n");
    printf("4- Informar resultados.\n");
    printf("5- Salir.\n");
    printf("\nIngrese opcion: ");

    scanf("%d",&opcion);

    return opcion;
}


void obtenerSexo(char sexo[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        system("cls");
        printf("Ingrese el sexo: \n",i);
        fflush(stdin);
        sexo[i]=getchar();
        sexo[i]=tolower(sexo[i]);

        while(sexo[i]!='f' && sexo[i]!='m')
        {
            printf("Ingrese sexo valido: \n");
            fflush(stdin);
            sexo[i]=getchar();
            sexo[i]=tolower(sexo[i]);
        }
    }
}

void obtenerEdad(int edad[], int tam){

    for(int i=0 ; i<tam ; i++){
        system("cls");
        printf("Ingrese edad : ", i);
        scanf("%d", &edad[i]);

        while(edad[i]<0 || edad[i]>110){
            printf("Ingrese una edad valida: ");
            scanf("%d", &edad[i]);
        }
    }
}


void obtenerNomApe(char nomApe[][50], int tam)
{
    for(int i=0 ; i<tam ; i++){
        system("cls");
        printf("Ingrese nombre y apellido NRO: %d : \n", i);
        fflush(stdin);
        gets(nomApe[i]);
        strlwr(nomApe[i]);
        nomApe[i][0]=toupper(nomApe[i][0]);


        for(int j=0;j<50;j++)
        if(nomApe[i][j] != '\0')
        {
            if(nomApe[i][j] == ' ')
                {
                    nomApe[i][j+1] = toupper(nomApe[i][j+1]);
                }
        }
    }
}

void pedirLegajos(int legajos[], int tam){

    for(int i=0 ; i<tam ; i++){
        system("cls");
        printf("Ingrese legajo NRO : #%d : ", i);
        scanf("%d", &legajos[i]);

        while(legajos[i]<1000 || legajos[i]>9999){
            printf("Ingrese legajo valido : ", i);
            scanf("%d", &legajos[i]);
        }
    }
}

void duplicarVector(int vector[], int tam)
{
    int i;

    for(i=0 ; i<tam ; i++){
        vector[i]*=2;
    }
}

void ordenarVectores( int vector[], int vector2[], int vector3[], char vectorSex[], float vectorFloat[],char nomApe[][50], int vector4 [],int tam)
{

    int auxInt;
    char auxChar;
    char auxString[tam][50];
    float auxFloat;


    for(int i=0; i < tam - 1; i++)
    {
        for(int j= i+1; j < tam; j++ )
        {
            if( vectorSex[i] > vectorSex[j])
            {

                auxInt = vector[i];
                vector[i] = vector[j];
                vector[j] = auxInt;

                auxInt = vector2[i];
                vector2[i] = vector2[j];
                vector2[j] = auxInt;

                auxInt = vector3[i];
                vector3[i] = vector3[j];
                vector3[j] = auxInt;

                auxChar = vectorSex[i];
                vectorSex[i] = vectorSex[j];
                vectorSex[j] = auxChar;

                auxInt = vector4[i];
                vector4[i] = vector4[j];
                vector4[j] = auxInt;

                auxFloat = vectorFloat[i];
                vectorFloat[i] = vectorFloat[j];
                vectorFloat[j] = auxFloat;

                strcpy(auxString[0], nomApe[i]);
                strcpy(nomApe[i], nomApe[j]);
                strcpy(nomApe[j], auxString[0]);
            }
            else
            {
               if(vectorSex[i]==vectorSex[j] && (stricmp(nomApe[i], nomApe[j])==1))
            {

                    strcpy(auxString[0], nomApe[i]);
                    strcpy(nomApe[i], nomApe[j]);
                    strcpy(nomApe[j], auxString[0]);

                    auxInt = vector[i];
                    vector[i] = vector[j];
                    vector[j] = auxInt;

                    auxInt = vector2[i];
                    vector2[i] = vector2[j];
                    vector2[j] = auxInt;

                    auxInt = vector3[i];
                    vector3[i] = vector3[j];
                    vector3[j] = auxInt;

                    auxChar = vectorSex[i];
                    vectorSex[i] = vectorSex[j];
                    vectorSex[j] = auxChar;

                    auxFloat = vectorFloat[i];
                    vectorFloat[i] = vectorFloat[j];
                    vectorFloat[j] = auxFloat;

                    auxInt = vector4[i];
                    vector4[i] = vector4[j];
                    vector4[j] = auxInt;
                }
            }
        }
    }
}

int buscarEntero(int num, int vec[], int tam)
{
    int indice = -1;

    for(int i=0; i< tam; i++)
    {
        if( num == vec[i])
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarEntero(int entero[], int tam){

    int i;

    for(i=0 ; i<tam ; i++)
    {
        printf("\n\tEntero posicion %d: %d", i, entero[i]);
    }
}

void inicializarEmpleados(eEmpleado vec[], int tam)
{

    for(int i=0; i < tam; i++)
    {
        vec[i].ocupado = 0;
    }
}

int menu()
{
    int opcion;

    system("cls");
    printf("  *** ABM Empleados ***\n\n");
    printf("1- Alta Empleado\n");
    printf("2- Baja Empleado\n");
    printf("3- Modificacion Empleado\n");
    printf("4- Ordenar Empleados\n");
    printf("5- Listar Empleados\n");
    printf("6- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int buscarLibre(eEmpleado vec[], int tam)
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

int buscarEmpleado(eEmpleado vec[], int tam, int legajo)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].legajo == legajo && vec[i].ocupado == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


void mostrarEmpleado(eEmpleado emp)
{
    printf("\nLegajo: %d\n Nombre: %s\n Sexo: %c\n Sueldo: %.2f\n Fecha ingreso: %02d/%02d/%d\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo, emp.fechaIngreso.dia, emp.fechaIngreso.mes, emp.fechaIngreso.anio);
}


void mostrarEmpleados(eEmpleado vec[], int tam)
{
    int cont= 0;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1)
        {
            mostrarEmpleado(vec[i]);
            cont++;
        }
    }
    if(cont == 0)
    {
        printf("No hay empleados que mostrar\n\n");
    }
}

void altaEmpleado(eEmpleado vec[], int tam)
{
    int indice;
    int legajo;
    int esta;
    int i;

    indice = buscarLibre(vec, tam);

    if(indice == -1)
    {
        printf("No hay lugar");
    }
    else
    {

        printf("\nIngrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarEmpleado(vec, tam, legajo);

        if( esta == -1)
        {
            vec[indice].legajo = legajo;

            system("cls");
            printf("Ingrese nombre y apellido: ");
            fflush(stdin);
            gets(gets(vec[indice].nombre);
            strlwr(gets(vec[indice].nombre);

            vec[indice].nombre[0] = toupper(vec[indice].nombre[0]);


            for(int j=0;j<50;j++)
            if(vec[indice].nombre [i][j] != '\0')
            {
                if(vec[indice].nombre[i][j] == ' ')
                {
                    vec[indice].nombre[i][j+1] = toupper(vec[indice].nombre[i][j+1]);
                }
            }

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &vec[indice].sexo);

            while(vec[indice].sexo != 'f' || vec[indice].sexo != 'm')
            {
                printf("No es un sexo valido. Ingrese de nuevo: ");
                fflush(stdin);
                scanf("%c", &vec[indice].sexo);
                i++;
            }

            printf("Ingrese sueldo: ");
            scanf("%f", &vec[indice].sueldo);

            printf("Ingrese fecha de ingreso dd mm aa: ");
            scanf("%d %d %d", &vec[indice].fechaIngreso.dia, &vec[indice].fechaIngreso.mes, &vec[indice].fechaIngreso.anio);

            vec[indice].ocupado = 1;

            printf("\nEl empleado ha sido registrado con exito!!!\n\n");

        }
        else
        {
            printf("Ya existe un empleado con el legajo %d\n", legajo);

            mostrarEmpleado(vec[esta]);
        }
    }
}

void bajaEmpleado(eEmpleado vec[], int tam){

    int legajo;
    char confirma;
    int esta;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    esta = buscarEmpleado(vec, tam, legajo);

    if( esta == -1){

        printf("\nEl legajo %d no esta registrado en el sistema\n", legajo);
    }
    else{
        mostrarEmpleado(vec[esta]);

        printf("\nConfirma la eliminacion? s/n");
        fflush(stdin);
        confirma = tolower(getche());

        if(confirma == 's'){
            vec[esta].ocupado = 0;
        }
        else{
            printf("\nLa eliminacion ha sido cancelada\n");
        }
    }

}

void ModificacionSueldoEmpleado(eEmpleado vec[], int tam)
{
    int legajo;
    char confirma;
    float nuevoSueldo;
    int esta;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    esta = buscarEmpleado(vec, tam, legajo);

    if( esta == -1){

        printf("\nEl legajo %d no esta registrado en el sistema\n", legajo);
    }
    else{
        mostrarEmpleado(vec[esta]);

        printf("\nQuiere cambiar el sueldo? s/n");
        fflush(stdin);
        confirma = tolower(getche());

        if(confirma == 's'){
            printf("\nIngrese nuevo sueldo: ");
            scanf("%f", &nuevoSueldo);
            //valido sueldo
            vec[esta].sueldo = nuevoSueldo;
        }
        else{
            printf("\nNo se ha modificado el sueldo\n");
        }
    }
}



