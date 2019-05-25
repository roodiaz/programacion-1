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
    eAuto auto1 = {1234,"Ford",1.6};
    eAuto auto2 = {1235,"Renault",1.8};
    eAuto auto3 = {1236,"Peugeot",1.2};

    eAuto* lista=(eAuto*)malloc(3*sizeof(eAuto));

    *lista=auto1;
    *(lista+1)=auto2;
    *(lista+2)=auto3;

   // mostrarAutos(lista,3);

   FILE* f;

   f=fopen("./autos.dat","wb");

   if(f==NULL)
   {
       printf("No se pudo abrir el archivo\n");
       exit(1);
   }

   //fwrite(lista, sizeof(eAuto),3,f);

   for(int i=0; i<3; i++)
   {
       fwrite(lista+i, sizeof(eAuto),1,f);
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

