#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int numero;
    char letra;

} eDato;

int ordenarDatos(eDato* datos, int tam);
int mostrarDatos(eDato* datos,  int tam);

int main()
{
    eDato misDatos[3]= {{1, 'z'},{2, 'a'}, {3, 'r'}};
    ordenarDatos(misDatos, 3);
    int estado=mostrarDatos(misDatos, 3);

    if(estado!=0)
    {
        printf("algo salio mal\n\n");
    }

    return 0;
}

int mostrarDato(eDato* unDato)
{
    int isNull=1;

    if(unDato != NULL)
    {
        printf("%d--%c\n",unDato->numero, unDato->letra);
        isNull=0;
    }

    return isNull;
}

int mostrarDatos(eDato* datos,  int tam)
{
    int i;
    int isNull=1;

    if(datos != NULL && tam>0)
    {
        for(i=0; i<tam; i++)
        {
            mostrarDato(datos+i);
        }

        isNull=0;
    }

    return isNull;
}

int ordenarDatos(eDato* datos, int tam)
{
    int isNull=1;
    eDato aux;

    if(datos!=NULL)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j= i+1; j<tam; j++)
            {
                if((datos+i)->letra > (datos+j) ->letra)
                {
                     aux =*(datos+i);
                    *(datos+i) = *(datos+j);
                    *(datos+j) = aux;
                }
            }
        }

        isNull=0;
    }

   return isNull;
}
