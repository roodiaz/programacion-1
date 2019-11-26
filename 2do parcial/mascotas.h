#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    int dias;
    char raza[20];
    char reservado[20];
    char genero[20];

}mascota;

#endif // MASCOTAS_H_INCLUDED

#include "LinkedList.h"

mascota* mascota_new(void);
mascota* mascota_newParameters(char* id , char* nombre, char* edad , char* raza, char* reservado , char* genero);
void mascota_delete(mascota* auxMascota);

/////////////////////

int employee_getId(mascota* auxMascota , int* auxId);
int employee_getName(mascota* auxMascota , char* auxName );
int employee_getAge(mascota* auxMascota , int* auxAge );
int employee_getRaza(mascota* auxMascota , char* auxRaza );
int employee_getReservado(mascota* auxMascota , char* auxReservado );
int employee_getGenero(mascota* auxMascota , char* auxGenero );

/////////////////////

int employee_setId(mascota* auxMascota , int auxId );
int employee_setName(mascota* auxMascota , char* auxName );
int employee_setAge(mascota* auxMascota , int auxAge );
int employee_setRaza(mascota* auxMascota , char* auxRaza );
int employee_setReservado(mascota* auxMascota , char* auxReservado );
int employee_setGenero(mascota* auxMascota , char* auxGenero );

//////////

void employee_printEmployee(mascota* auxMascota);
void employee_printListOfEmployees(LinkedList* pArrayList);
int employee_filterUnder45(void* aux);
int employee_filterMacho(void* aux);
int employee_filterRaza(void* aux);
