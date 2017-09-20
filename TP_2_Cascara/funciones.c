#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define CANT 2

typedef struct
{
    char nombre[50];
    int edad;
    int estado;
    long int dni;

} EPersona;

void init(EPersona persona[])
{
    int i;

    for(i=0; i<CANT; i++)
    {
        persona[i].estado = 0;
    }
}

void agregarEPersona(EPersona persona[])
{
    int i;

    for(i = 0; i < CANT; i++)
    {
        if(persona[i].estado == 0)
        {
            printf("Ingrese su nombre: ");
            fflush(stdin);
            scanf("%[^\n]", persona[i].nombre);

            printf("Ingrese su edad: ");
            scanf("%d", &persona[i].edad);

            printf("Ingrese su DNI: ");
            scanf("%ld", &persona[i].dni);

            persona[i].estado = 1;
            printf("Nombre: %s\nEdad: %d\nDNI: %ld\nEstado: %d\n",persona[i].nombre,persona[i].edad,persona[i].dni,persona[i].estado);
        }
    }
}

void listaOrdenadaPorNombre(EPersona persona[])
{
    int i,j;
    char nombreAux[51];
    for(i = 0; i < CANT -1; i++)
    {
        for (j=i+1; j<CANT; j++)
        {
                if (strcmp(persona[i].nombre,persona[j].nombre)>0)
                {
                    strcpy(nombreAux,persona[i].nombre);
                    strcpy(persona[i].nombre,persona[j].nombre);
                    strcpy(persona[j].nombre,nombreAux);
                }
        }
    }
    for(i = 0; i<CANT; i++)
        {
            if(persona[i].estado == 1)
            {
                printf("LISTA\n");
                printf("%s\n" ,persona[i].nombre);
            }

        }
}

void borrarPersona(EPersona persona[])
{
    EPersona aux;
    char vacio[] = "vacio";
    int i;

    printf("Ingrese el DNI de la persona a eliminar: ");
    scanf("%ld", &aux.dni);

    for(i = 0; i<CANT;i++)
    {
        if(aux.dni == persona[i].dni)
        {
            persona[i].estado = 0;
            strcpy(persona[i].nombre,vacio);
            persona[i].edad = 0;
            persona[i].dni = 0;
            printf("La persona a sido eliminada!\n");
            printf("Nombre: %s\nEdad: %d\nDNI: %ld\nEstado: %d\n",persona[i].nombre,persona[i].edad,persona[i].dni,persona[i].estado);
            break;
        }
        else
        {
            printf("No se encontro la persona.\n");
            break;
        }
    }
}

void graficoEdades(EPersona persona[])
{
    int i;
    int menor,mayor,viejo;
    long int edadAux;

    for(i = 0;i<CANT;i++)
    {
        strcpy(edadAux,persona[i].edad);
        if(edadAux <= 18)
        {
            menor = edadAux;
        }
        else if(edadAux >= 19 && edadAux <= 35)
        {
            mayor = edadAux;
        }
        else if(edadAux > 35)
        {
            viejo = edadAux;
        }
    }




}


#endif // FUNCIONES_H_INCLUDED
