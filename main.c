#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cuerposFuncionesTP3.h"
int main()
{
    eMovie *cartelera;
    FILE* f;
    int resultado, resultado2;
    int opcion=0;
    int cantidad=0;
    int flagAltaPelicula;
    flagAltaPelicula=0;

    f=fopen("prueba.bin", "w");
    if(f==NULL)
    {
        printf("No se pudo crear el fichero");
        exit(1);
    }
    while(opcion!=5)
    {
        printf("Ingrese una opcion para continuar");
        printf("\n1. Agregar pelicula");
        printf("\n2. Modificar pelicula");
        printf("\n3. Borrar pelicula");
        printf("\n4. Generar pagina web");
        printf("\n5. Salir\n");
        printf("\n6. Mostrar");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                    if(flagAltaPelicula==0)
                    {
                        cartelera=(eMovie*)malloc((cantidad+1)*sizeof(eMovie));
                        if(cartelera == NULL)
                        {
                            printf("\nNo se pudo asignar memoria");
                            exit(1);
                        }
                    }
                    else
                    {
                        cartelera=(eMovie*)realloc(cartelera,(cantidad +1)*sizeof(eMovie));
                        if(cartelera == NULL)
                        {
                            printf("\no se pudo asignar memoria");
                            exit(1);
                        }
                    }
                     AltaPelicula(cartelera);
                     cantidad++;
            system("pause");
            break;
        case 2:
            modificarPelicula(cartelera, cantidad);
            break;
        case 3:
            break;
        case 4:
          	generarWeb(cartelera);
            break;
        case 5:
            printf("Gracias por usar mi programa!\n");
            exit(0);
            break;
        case 6:
            mostrarPelicula(cartelera, cantidad-1);
            printf("\nPeliculas cargadas hasta el momento: %d\n", cantidad);
            break;
        default:
            printf("Error, opcion ingresada no valda");
            system("pause");
            break;
        }
    }
    system("pause");
    return 0;
}
