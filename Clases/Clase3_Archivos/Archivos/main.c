#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* f;
    char x;

    f = fopen("./archivo.txt", "a");

    if(f==NULL)
    {
        printf("No se pudo abrir el archivos\n");
        exit(1);
    }

    //fprintf(f,"Hola mundo\nPrimer archivo");

    fclose(f);

    f = fopen("./archivo.txt", "r");

    if(f==NULL)
    {
        printf("No se pudo leer el archivo\n");
        exit(1);
    }
    while(!feof(f))
    {
        x=fgetc(f);
        printf("%c",x);
    }

    return 0;
}
