#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeros[]={3,2,4,5,2,6,5,4,7,1,9,3};

    FILE* f;

    f=fopen("./numeros.txt","w");

    if(f==NULL)
    {
        printf("No se pudo abrir el archivos\n");
        exit(1);
    }

    for(int i=0; i<12; i++)
    {
        if((i+1)%4 != 0)
        {
            fprintf(f,"%d,",numeros[i]);
        }
        else
        {
            fprintf(f,"%d\n",numeros[i]);
        }
    }

    fclose(f);

    return 0;
}
