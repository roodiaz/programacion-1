#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int main()
{
    char sexo;
    int todoOk;

    todoOk=getSexo(3, &sexo, "ingrese sexo: ");

    if(todoOk == 1)
    {

       printf("%c",sexo);
    }
    else
    {
        printf("no se pudo conseguir nombre");
    }


    return 0;
}
