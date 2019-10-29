#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///ARCHIVOS DE .TXT Y .BIN:

int main()
{
    FILE* f;
    char nombre[]="Juan, Carlos";
    char nombre2[20];
    char x;

    f=fopen("archivo.txt","r");

    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        system("pause");
        exit(EXIT_FAILURE);
        /// define 1
    }

    //fprintf(f,"%s",nombre); // para escribir .txt
    //puntero a FILE - cadena de carac

    //fwrite(nombre,sizeof(char),strlen(nombre),f); // escribit .bin .txt
    //origen de datos,tamanio de tipo de dato,cantidad de carac,destino donde guardar

    while(!feof(f))//feof devuelve 1 o 0 si llega al final del archivo o no
    {
         //fread(nombre2,sizeof(char),19,f);
         //printf("%s",nombre2);


         //x= fgetc(f);
         // printf("%c",x);

          fgets(nombre2,19,f);
          printf("%s",nombre2);


    }



    fclose(f);
    //puntero a file

    return 0;
}
