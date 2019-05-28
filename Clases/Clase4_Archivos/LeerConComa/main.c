#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* f;
    int num1;
    int num2;
    int num3;
    int num4;
    int cant;

    f=fopen("./numeros.txt","r");

    if(f==NULL)
    {
        printf("No se pudo abrir el archivos\n");
        exit(1);
    }

    while(!feof(f))
    {
        cant = fscanf(f,"%d,%d,%d,%d\n",&num1,&num2,&num3,&num4);
        printf("%d %d %d %d ",num1, num2, num3, num4);

        if(cant<4)
        {
            if(feof(f))
            {
                break;
            }
            else
            {
                printf("Problemas para leer el archivo.\n");
            }
        }
    }

    fclose(f);

    return 0;
}
