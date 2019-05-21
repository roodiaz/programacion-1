#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* x[5];

    x[5]=(int*)malloc(sizeof(int));


    if(x== NULL)
    {
        printf("No se consiguio espacio\n");
        system("pause");
        exit(1);
    }

    x[]={1, 2, 3, 4, 5};
    printf("%d",*x);
    free(x);


    return 0;
}
