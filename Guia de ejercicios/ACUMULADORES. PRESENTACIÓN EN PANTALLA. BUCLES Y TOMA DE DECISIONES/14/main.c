#include <stdio.h>
#include <stdlib.h>

// Dise�ar un programa que imprima y sume la serie de n�meros 3,6,9,12,...,99.

int main()
{
    int cont =0;
    int total=0;

    while(cont < 99)
    {
        cont+=3;

        printf("%d\n",cont);

        total+=cont;
    }

    printf("\ntotal %d\n",total);

    return 0;
}
