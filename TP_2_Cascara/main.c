#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"

#define CANT 1

int main()
{
    char seguir='s';
    int opcion=0;
    EPersona persona[CANT];

    init(persona);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarEPersona(persona);
                break;
            case 2:
                borrarPersona(persona);
                break;
            case 3:
                listaOrdenadaPorNombre(persona);
                break;
            case 4:
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    getch();
    return 0;
}