#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* pNum;

    pNum=(int*)malloc(sizeof(int));

    if(pNum== NULL)
    {
        printf("No se consiguio espacio\n");
        system("pause");
        exit(1);
    }

        *pNum=30;
        printf("%d",*pNum);
        free(pNum);

    return 0;
}
