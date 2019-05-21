#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* arrayInt;

    arrayInt=(int*)malloc(sizeof(int)*5);

    if(arrayInt== NULL)
    {
        printf("No se consiguio espacio\n");
        system("pause");
        exit(1);
    }

    for(int i=0; i<5; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",arrayInt+i);
    }

    printf("\n");

    for(int i=0; i<5; i++)
    {
        printf("%d\n",*(arrayInt+i));
    }

    free(arrayInt);

    return 0;
}
