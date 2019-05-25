#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char marca[20];
    float cilindrada;

} eAuto;

void mostrarAuto(eAuto* unAuto);
void mostrarAutos(eAuto* lista, int tam);

int main()
{

    eAuto* lista=(eAuto*)malloc(3*sizeof(eAuto));
    int cont=0;
    int cant;

   // mostrarAutos(lista,3);

   FILE* f;

   f=fopen("./autos.dat","rb");

   if(f==NULL)
   {
       printf("No se pudo abrir el archivo\n");
       exit(1);
   }

   while(!feof(f))
   {
       cant=fread(lista+cont,sizeof(eAuto),1,f);
       if(cant<1)
       {
            if(feof(f)==1)
            {
                break;
            }
            else
            {
                printf("Se produjo un error al leer el archivo");
                break;
            }
       }
       cont++;
   }

   fclose(f);

    return 0;
}

void mostrarAuto(eAuto* unAuto)
{
    if(unAuto!=NULL)
    {
        printf("%d   %8s   %.2f\n",unAuto->id,unAuto->marca,unAuto->cilindrada);
    }

}

void mostrarAutos(eAuto* lista, int tam)
{
    printf("ID       MARCA  CILINDRADA\n\n");
    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            mostrarAuto(lista+i);
        }
    }
}
