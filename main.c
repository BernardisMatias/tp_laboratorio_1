#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define CANT 20
#include "funcionesPrototipos.h"
int main()
{
    int opcion, indice, opcionOrdenar, flagOrdenar=0, flagGrafico=0;
    ePersona UnaPersona[CANT];
    inicializar(UnaPersona);
    printf("\t\t\tBienvenido");
    while(opcion!=5)
    {
            printf("\n\n\n\n\tIngrese la opcion deseada para continuar: ");
            printf("\n\n\t1. Agregar a una persona");
            printf("\n\n\t2. Borrar a una persona");
            printf("\n\n\t3. Imprimir una lista ordenada por nombres");
            printf("\n\n\t4. Imprimir grafico de edades");
            printf("\n\n\t5. Salir\n");
            scanf("%d", &opcion);
            while(opcion<0||opcion>5)
            {
                printf("\nError. Reingrese una opcion valida\n");
                scanf("%d", &opcion);
            }
            switch(opcion)
            {
                case 1:
                    system("cls");
                    indice=pedirLugar(UnaPersona);
                    altaPersona(UnaPersona);
                    flagGrafico++;
                    flagOrdenar=1;
                    break;
                case 2:
                    borrarPersona(UnaPersona);
                    break;
                case 3:
                   if(flagOrdenar==1)
                    {
                        printf("\nComo desea ordenarlos? \n\n1. A - Z | 2. Z - A \n");
                        scanf("%d", &opcionOrdenar);
                        if(opcionOrdenar<1||opcionOrdenar>2)
                            printf("\nError. Opcion no valida");
                        else
                        {
                           if(opcionOrdenar==1)
                            {
                                ordenarMenorAMayor(UnaPersona);
                            }
                            else if(opcionOrdenar==2)
                            {
                                ordenarMayorAMenor(UnaPersona);
                            }

                        }
                    }
                    else if(flagOrdenar==0)
                    {
                        printf("Error. No hay ningun dato ingresado.");
                        break;
                    }
                        break;
                case 4:
                    mostrarGraficoEdades(UnaPersona);
                    break;
                case 5:
                    printf("Gracias por usar mi programa!\n\n");
                    break;
            }
    }
    system("pause");
    return 0;
}
