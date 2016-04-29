#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define CANT 20
#include "funcionesPrototipos.h"

void inicializar(ePersona UnaPersona[])
{
   for(int i=0;i<CANT;i++)
   {
      UnaPersona[i].estaVacio=1;
   }
}
void altaPersona(ePersona unaPersona[])
{
    system("cls");
    fflush(stdin);
    int indice = pedirLugar(unaPersona);
    if(indice!=-1)
    {
        printf("\nIngrese el nombre de la persona: ");
        gets(unaPersona[indice].nombre);
        printf("\nIngrese la edad de la persona: ");
        scanf("%d",&unaPersona[indice].edad);

        if(unaPersona[indice].edad<1||unaPersona[indice].edad>110)
        {
            printf("\nError. Edad no valida (1-110)");
            unaPersona[indice].estaVacio=1;
        }
        else
            unaPersona[indice].estaVacio=0;
            if(unaPersona[indice].estaVacio==0)
            {
                printf("\nIngrese el DNI de la persona: ");
                scanf("%d",&unaPersona[indice].dni);
                if(unaPersona[indice].dni<=1000000||unaPersona[indice].dni>=99000000)
                {
                    printf("\nError, DNI no valido \n(1.000.000-99.000.000)");
                    unaPersona[indice].estaVacio=1;
                }
                else
                unaPersona[indice].estaVacio=0;
            }
    }
    else
        printf("\nLa memoria esta llena. \nSi desea continuar, borre uno de los registros (opcion 2)\n");
}
int pedirLugar(ePersona UnaPersona[])
{
    int indice=-1;
    for(int i=0;i<CANT;i++)
    {
        if(UnaPersona[i].estaVacio==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
void mostrarPersona(ePersona UnaPersona[])
{
    system("cls");
    for(int i=0;i<CANT;i++)
    {
        if(UnaPersona[i].estaVacio!=1)
            {
                printf("Nombre: %s -- Edad: %d -- Dni: %d", UnaPersona[i].nombre, UnaPersona[i].edad, UnaPersona[i].dni);
                printf("\n");
            }
    }
}
void borrarPersona(ePersona UnaPersona[])
{
    int auxDNI;
    system("cls");
    mostrarPersona(UnaPersona);
    printf("\nIngrese el DNI de la persona a borrar: ");
    scanf("%d", &auxDNI);
        for(int i=0;i<CANT;i++)
        {
            if(auxDNI==UnaPersona[i].dni)
            {
                UnaPersona[i].estaVacio=1;
                system("cls");
                printf("\n\tLa persona que tiene el DNI %d ha sido eliminada exitosamente\n\n", auxDNI);
                break;
            }
            else
            {
                system("cls");
                printf("\n\tEl DNI ingresado no coincide con ninguno en la base de datos\n\n");
            }
        }
}
void ordenarMenorAMayor(ePersona UnaPersona[])
{
    ePersona auxP;
    for(int i=0; i<CANT-1; i++)
    {
        for(int j=i+1; j<CANT; j++)
        {
            if(UnaPersona[j].estaVacio!=1)
            {
                if(stricmp(UnaPersona[i].nombre,UnaPersona[j].nombre)>0)
                {
                    auxP=UnaPersona[i];
                    UnaPersona[i]=UnaPersona[j];
                    UnaPersona[j]=auxP;
                }
            }
        }
    }
    for(int i=0;i<CANT;i++)
    {
         if(UnaPersona[i].estaVacio!=1)
            {
                printf("Nombre: %s -- Edad: %d -- Dni: %d", UnaPersona[i].nombre, UnaPersona[i].edad, UnaPersona[i].dni);
                printf("\n");
            }
    }
}
void ordenarMayorAMenor(ePersona UnaPersona[])
{
    ePersona auxP;
    for(int i=0; i<CANT-1; i++)
    {
        for(int j=i+1; j<CANT; j++)
        {
            if(UnaPersona[j].estaVacio!=1)
            {
                if(stricmp(UnaPersona[i].nombre,UnaPersona[j].nombre)<0)
                {
                    auxP=UnaPersona[i];
                    UnaPersona[i]=UnaPersona[j];
                    UnaPersona[j]=auxP;
                }
            }
        }
    }
    for(int i=0;i<CANT;i++)
    {
         if(UnaPersona[i].estaVacio!=1)
            {
                printf("Nombre: %s -- Edad: %d -- Dni: %d", UnaPersona[i].nombre, UnaPersona[i].edad, UnaPersona[i].dni);
                printf("\n");
            }
    }
}
void mostrarGraficoEdades(ePersona UnaPersona[])
{
    int auxEdad;
    int menor18=0;
    int de19a35=0;
    int mayorDe35=0;
    int mayor;
    int flag=0;

    for(int i=0;i<CANT;i++)
    {
        if(UnaPersona[i].estaVacio!=1)
        {
            auxEdad=UnaPersona[i].edad;
            if(auxEdad<=18)
            {
                menor18++;
            }
            else if(auxEdad>=19&&auxEdad<=35)
            {
                de19a35++;
            }
            else if(auxEdad>=36)
            {
                mayorDe35++;
            }
        }
    }
    if(menor18>=de19a35&&menor18>=mayorDe35)
    {
        mayor=menor18;
    }
    else
    {
        if(de19a35>=menor18&&de19a35>=mayorDe35)
        {
            mayor=de19a35;
        }
        else
        {
             mayor=mayorDe35;
        }
    }
    for(int i=mayor;i>0;i--)
    {
        if(i<10)
        {
            printf("%02d|",i);
        }
        else
            printf("%02d|",i);

        if(i<= menor18)
        {
            printf("*");
        }
        if(i<= de19a35)
        {
            flag=1;
            printf("\t*");
        }
        if(i<= mayorDe35)
        {
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");
        }
    printf("\n");
    }

    printf("--+-----------------");
    printf("\n  |<18\t19-35\t<35");
    printf("\n   %d\t%d\t%d", menor18, de19a35, mayorDe35);
}
