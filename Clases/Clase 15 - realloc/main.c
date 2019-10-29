#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* num=(int*)malloc(sizeof (int)*5);
    int* aux;


    for(int i=0; i<5; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",num+i);
    }

    printf("\n\n");

    for(int i=0; i<5; i++)
    {
        printf("%d\n",*(num+i));

    }

    aux=(int*)realloc(num,sizeof(int)*10);

    if(aux!=NULL){
        num=aux;
    }

    for(int i=5; i<10; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",num+i);
    }

    printf("\n\n");

    for(int i=0; i<10; i++)
    {
        printf("%d\n",*(num+i));

    }

    num=(int*)realloc(num,sizeof(int)*6);

     for(int i=0; i<6; i++)
    {
        printf("%d\n",*(num+i));

    }

    free(num);
    return 0;
}
