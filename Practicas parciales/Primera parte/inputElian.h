#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

/*Funciones para obtener valores*/

void f_i_PedirInt (int * var_dondeAsignar, char mensaje[]);

void f_i_PedirIntEntre(int * var_dondeAsignar, int min, int max, char mensaje[]);

void f_i_PedirFloat (float * var_dondeAsignar, char mensaje[]);

void f_i_PedirChar (char * var_dondeAsignar, char mensaje[]);

void f_i_PedirString(char var_dondeAsignar[], int longitudMaxString, char mensaje[]);

/*Funciones para obtener datos especificos*/

void f_i_PedirNombre(char var_dondeAsignar[],int longitudMaxString, char mensaje[]);

void f_i_PedirStringSoloNumeros(char var_dondeAsignar[],int longitudMaxString,char mensaje[]);

void f_i_PedirStringSoloLetras(char var_dondeAsignar[],int longitudMaxString,char mensaje[]);

void f_i_PedirStringSoloFloat(char var_dondeAsignar[],int longitudMaxString,char mensaje[]);

void f_i_PedirStringAlfaNumerico(char var_dondeAsignar[],int longitudMaxString,char mensaje[]);

void f_i_PedirPatenteVieja(char var_DondeAsignar[], char mensaje[]);

void f_i_PedirEmail (char var_dondeAsignar [], int longitudMaxString, char mensaje [] );

void f_i_PedirTelefono (char var_dondeAsignar[], int longitudMaxString, char mensaje[]);

void f_i_PedirSexo(char * var_dondeAsignar, char mensaje[]);

void f_i_PedirEdad (int * var_dondeAsignar,char mensaje[]);

void pedirFecha (int *dia , int* mes , int *anyo ,char diaEnQue[],char mesEnQue[],char anyoEnQue[]);

int f_i_SioNo(char mensaje[]);

void f_i_continuar(void);

/*Funciones para otras funciones y general*/

void limpiar (void);

void esperar (int ms);

void noVeo(void);

/*Funciones de ordenamiento*/

void f_o_IniciarArrayInt (int var_dondeAsignar[],int asignarleEsteNumero,int cantidadElementos);

void f_o_IniciarArrayIntIncremental(int var_dondeAsignar[],int cantidadElementos);

int f_o_BuscarIndicePrimerOcurrencia (int var_dondeAsignar[],int cantidadElementos,int indicadorPrimerOcurrencia);

void f_o_OrdernarArrayMayorAMenor (int var_dondeAsignar[],int cantidadElementos);

void f_o_OrdernarArrayMenorAMayor (int var_dondeAsignar[],int cantidadElementos);

void f_o_OrdenarArrayAlfabeticamente(int cantidadElementos,int longitudMaxString,
                                     char var_dondeAsignar[cantidadElementos][longitudMaxString]);

void f_o_ArreglarCaps (int cantidadElementos,int longitudMaxString,
                       char var_dondeAsignar[cantidadElementos][longitudMaxString]);


