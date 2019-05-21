#include <stdio.h>
#include <stdlib.h>

void f1 (int x[], int tam);

int main()
{
    int vec[]={3,4,5,6,7};

    f1(vec, 5);




    return 0;
}

void f1 (int x[], int tam)
{
    printf("%d\n",x);
}
