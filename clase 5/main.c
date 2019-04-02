#include <stdio.h>
#include <stdlib.h>

int main()
{

    int legajos [5];
    int nota1 [5];
    int nota2 [5];
    float promedio [5];
    char sexo [5];

    for(int i = 0; i < 5; i++)
    {
        printf("ingrese numero de legajo: ");
        scanf("%d",&legajos[i]);

        printf("ingrese nota uno: ");
        scanf("%d",&nota1[i]);

        printf("ingrese nota dos: ");
        scanf("%d",&nota2[i]);

        promedio[i] = (float) (nota1[i]+nota2[i]) / 2;

        printf("ingrese sexo del alumno: ");
        fflush(stdin);
        scanf("%c",&sexo[i]);
    }

    for(int i = 0; i < 5; i++)
    {
        printf("Numero de legajo: %d\nNota 1: %d\nNota 2: %d\nPromedio: %f\nSexo: %c\n",legajos[0],nota1[0],nota2[0],promedio[0],sexo[0]);
        printf("Numero de legajo: %d\nNota 1: %d\nNota 2: %d\nPromedio: %f\nSexo: %c\n",legajos[1],nota1[1],nota2[1],promedio[1],sexo[1]);
        printf("Numero de legajo: %d\nNota 1: %d\nNota 2: %d\nPromedio: %f\nSexo: %c\n",legajos[2],nota1[2],nota2[2],promedio[2],sexo[2]);
        printf("Numero de legajo: %d\nNota 1: %d\nNota 2: %d\nPromedio: %f\nSexo: %c\n",legajos[3],nota1[3],nota2[3],promedio[3],sexo[3]);
        printf("Numero de legajo: %d\nNota 1: %d\nNota 2: %d\nPromedio: %f\nSexo: %c\n",legajos[4],nota1[4],nota2[4],promedio[4],sexo[4]);
    }



    return 0;
}

