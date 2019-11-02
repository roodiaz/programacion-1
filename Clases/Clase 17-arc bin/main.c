#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char marca[32];
    int modelo;
    float precio;

}eAuto;

//constructores
eAuto* new_auto();
eAuto* new_autoParam(int id,char* marca,int modelo,float precio);

//getters y setters
int setIdAuto(eAuto* unAuto, int id);
int getIdAuto(eAuto* unAuto);
int setMarcaAuto(eAuto* unAuto, char* marca);
int getMarcaAuto(eAuto* unAuto, char* marca);
int setModeloAuto(eAuto* unAuto, int modelo);
int getModeloAuto(eAuto* unAuto);
int setPrecioAuto(eAuto* unAuto, float precio);
float getPrecioAuto(eAuto* unAuto);

//mostrar autos
int mostrarAuto(eAuto* unAuto);
int mostrarAutos(eAuto** autos, int tam);

//funciones .bin
int guardarAutosBin(eAuto** lista, int tam,char* path);

int main()
{
    int tam=0;
    int cant=0;
    char buffer[4][32];//de la estrucutra 4 var ,30 max caracteres
    FILE* f=NULL;
    eAuto* autoAux=NULL;//inicializar en null sino use malloc o realloc
    eAuto** auxLista=NULL;
    eAuto** lista= (eAuto**)malloc(sizeof(eAuto*));

    if(lista==NULL)
    {
        printf("No se pudo conseguir memoria\n\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    f=fopen("autos.csv","r");

    if(f==NULL)
    {
        printf("No se pudo abrir el archivo\n\n");
        system("pause");
        exit(EXIT_FAILURE);
    }


        fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

        while(!feof(f))
        {
            cant=fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

            if(cant < 4)//cantidad de variables del archivo
            {
                break;
            }
            else{

                autoAux=new_autoParam(atoi(buffer[0]),buffer[1],atoi(buffer[2]),atof(buffer[3]));

                if(autoAux !=NULL)
                {
                    *(lista+tam)=autoAux;
                    tam++;
                    auxLista=(eAuto**) realloc(lista,sizeof(eAuto*)*(tam+1));

                    if(auxLista != NULL)
                    {
                        lista=auxLista;
                    }
                }
            }
        }
        fclose(f);
        mostrarAutos(lista,tam);


        //************ guardar en archivo bin ************//

        if(guardarAutosBin(lista,tam,"autos.bin"))// 1 true - 0 false
        {

            printf("\nAutos guardados en archivo bin\n\n");
        }
        else
        {
            printf("Error al guardar autos\n\n");
        }


        //haxer funcion de esto

        int tam2=0;
        eAuto** lista2= (eAuto**)malloc(sizeof(eAuto*));

        if(lista2==NULL)
        {
            printf("No se pudo conseguir memoria\n\n");
            system("pause");
            exit(EXIT_FAILURE);
        }

         f=fopen("autos.bin","rw");

        if(f==NULL)
        {
            printf("No se pudo abrir el archivo\n\n");
            system("pause");
            exit(EXIT_FAILURE);
        }

        while(!feof(f))
        {
            eAuto* auxAuto=new_auto();

            if(auxAuto == NULL)
            {
                break;
            }

            cant=fread(auxAuto,sizeof(eAuto),1,f);

            if(cant < 1)//cantidad de variables del archivo
            {
                break;
            }
            else{
                    *(lista2+tam2)=auxAuto;
                    tam2++;
                    auxLista=(eAuto**) realloc(lista2,sizeof(eAuto*)*(tam2+1));

                    if(auxLista != NULL)
                    {
                        lista2=auxLista;
                    }
            }
        }
        fclose(f);
        mostrarAutos(lista2,tam2);

    return 0;
}

eAuto* new_auto()
{
    eAuto* unAuto=(eAuto*)malloc(sizeof(eAuto));

    if(unAuto != NULL)
    {
        unAuto->id=0;
        strcpy(unAuto->marca,"Sin asignar");
        unAuto->modelo=0;
        unAuto->precio=0;
    }

    return unAuto;
}

eAuto* new_autoParam(int id,char* marca,int modelo,float precio)
{
    eAuto* unAuto=new_auto();

    if(unAuto != NULL)
    {
        if(
            setIdAuto(unAuto,id)
            &&setMarcaAuto(unAuto,marca)
            &&setModeloAuto(unAuto,modelo)
            &&setPrecioAuto(unAuto,precio)==0)
        {
            free(unAuto);
            unAuto=NULL;
        }
    }

    return unAuto;
}

int setIdAuto(eAuto* unAuto, int id)
{
    //id entre 1000-2000
    int todoOk=0;

    if(unAuto != NULL && id >=1000 && id<=2000)
    {
        unAuto->id=id;
        todoOk=1;
    }

    return todoOk;
}

int getIdAuto(eAuto* unAuto)
{
    int id=-1;

    if(unAuto != NULL)
    {
        id=unAuto->id;
    }

    return id;
}

int setMarcaAuto(eAuto* unAuto, char* marca)
{
    int todoOk=0;

    if(unAuto != NULL && marca != NULL && strlen(marca)>=3)
    {
        strcpy(unAuto->marca,marca);
        todoOk=1;
    }

    return todoOk;
}

int getMarcaAuto(eAuto* unAuto, char* marca)
{
    int todoOk=0;

    if(unAuto != NULL && marca!= NULL)
    {
        strcpy(marca,unAuto->marca);
        todoOk=1;
    }

    //no se retorna cadena
    return todoOk;
}

int setModeloAuto(eAuto* unAuto, int modelo)
{
    int todoOk=0;

    if(unAuto != NULL && modelo >=2020 && modelo <=1980)
    {
        unAuto->modelo=modelo;
        todoOk=1;
    }

    return todoOk;
}

int getModeloAuto(eAuto* unAuto)
{
    int modelo=-1;

    if(unAuto != NULL)
    {
        modelo=unAuto->modelo;
    }

    return modelo;
}

int setPrecioAuto(eAuto* unAuto, float precio)
{
    int todoOk=0;

    if(unAuto != NULL && precio>=500 && precio <= 1500)
    {
        unAuto->precio=precio;
        todoOk=1;
    }

    return todoOk;
}

float getPrecioAuto(eAuto* unAuto)
{
    float precio;

    if(unAuto != NULL)
    {
        precio=unAuto->precio;
    }

    return precio;
}

int mostrarAuto(eAuto* unAuto)
{
    int todoOk=0;

    if(unAuto != NULL)
    {
        printf("%d   %15s    %d    %.2f\n",unAuto->id,unAuto->marca,
               unAuto->modelo,unAuto->precio);
        todoOk=1;
    }

    return todoOk;
}

int mostrarAutos(eAuto** autos, int tam)
{
    int todoOk=0;

    if(autos != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            mostrarAuto(*(autos+i));
            todoOk=1;
        }
    }

    return todoOk;
}

int guardarAutosBin(eAuto** lista, int tam,char* path)
{
    int todoOk=0;
    FILE* f=NULL;

    if(lista != NULL && tam>0 && path!=NULL)
    {
        f=fopen(path,"wb");

        if(f==NULL)
        {
            printf("No se pudo abrir el archivo\n\n");
            system("pause");
            return todoOk;
        }

        for(int i=0; i<tam; i++)
        {
            fwrite(*(lista+i),sizeof(eAuto),1,f);
        }

        fclose(f);
        todoOk=1;
    }

    return todoOk;
}

int guardarAutosCSV(eAuto** lista, int tam,char* path)
{
    int todoOk=0;
    FILE* f=NULL;

    if(lista != NULL && tam>0 && path!=NULL)
    {
        f=fopen(path,"w");

        if(f==NULL)
        {
            printf("No se pudo abrir el archivo\n\n");
            system("pause");
            return todoOk;
        }

        fprintf(f,"id,marca,modelo,precio\n");

        for(int i=0; i<tam; i++)
        {
            /*fprintf(f,"%d,%s,%d,%.2f\n",((*(lista+i)->id,*(lista+i)->marca,
                                         *(lista+i)->modelo,*(lista+i)->precio);*/
        }

        fclose(f);
        todoOk=1;
    }

    return todoOk;
}
