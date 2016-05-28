#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cuerposFuncionesTP3.h"
void AltaPelicula(eMovie *x)
{
    int resultado=0;
    int cantidad=0;
    char aux[400];
    int auxNum;
    int longitud;
            printf("Por favor, ingrese el titulo de la pelicula:\n");
            fflush(stdin);
            gets(aux);
            longitud=strlen(aux);
            (x+cantidad)->titulo=(char*)malloc((longitud+1)*sizeof(char));
            if((x+cantidad)->titulo==NULL)
            {
                printf("\nNo se pudo asignar espacio en memoria");
                resultado=0;
                exit(1);
            }
            strcpy((x+cantidad)->titulo, aux);
            printf("\nPor favor, ingrese el genero de la pelicula:\n");
            fflush(stdin);
            gets(aux);
            longitud=strlen(aux);
            (x+cantidad)->genero=(char*)malloc((longitud+1)*sizeof(char));
            if((x+cantidad)->genero==NULL)
            {
                printf("\nNo se pudo asignar espacio en memoria");
                resultado=0;
                exit(1);
            }
            strcpy((x+cantidad)->genero, aux);
            printf("\nPor favor, ingrese la duracion de la pelicula (en minutos) :\n");
            scanf("%d", &((x+cantidad)->duracion));
            printf("\nPor favor, ingrese la descripcion de la pelicula:\n");
            fflush(stdin);
            gets(aux);
            longitud=strlen(aux);
            (x+cantidad)->descripcion=(char*)malloc((longitud+1)*sizeof(char));
            if((x+cantidad)->descripcion==NULL)
            {
                printf("\nNo se pudo asignar espacio en memoria");
                resultado=0;
                exit(1);
            }
            strcpy((x+cantidad)->descripcion, aux);
            printf("\nPor favor, ingrese el puntaje de la pelicula:\n");
            scanf("%d", &(x+cantidad)->puntaje);

            printf("\nPor favor, copie y pegue el link de la imagen de la pelicula:\n");
            fflush(stdin);
            gets(aux);
            longitud=strlen(aux);
            (x+cantidad)->linkImagen=(char*)malloc((longitud+1)*sizeof(char));
            if(x->linkImagen==NULL)
            {
                printf("\nNo se pudo asignar espacio en memoria");
                resultado=0;
                exit(1);
            }
            strcpy((x+cantidad)->linkImagen, aux);
}
void mostrarPelicula(eMovie* x, int largo)
{
    for(int i=0;i<largo+1;i++)
    {
        printf("Titulo de la pelicula: %s\n", (x+i)->titulo);
        printf("Genero de la pelicula: %s\n", (x+i)->genero);
        printf("Duracion de la pelicula: %d\n", (x+i)->duracion);
        printf("Descripcion de la pelicula: %s\n", (x+i)->descripcion);
        printf("Puntaje de la pelicula: %d\n", (x+i)->puntaje);
        printf("Link de la imagen de la pelicula: %s\n", (x+i)->linkImagen);
        printf("\n\n");
    }
}
void modificarPelicula(eMovie* x, int cantidad)
{
    char aux[50];
    char aux2[100];
    fflush(stdin);
    for(int i=0; i<cantidad; i++)
    {
        printf("%s\n", (x+i)->titulo);
    }
    printf("\n");
    printf("Por favor, ingrese el titulo de la pelicula que desea modificar: ");
    fflush(stdin);
    gets(aux);
    for(int i=0; i<cantidad; i++)
    {
        if(strcmp(aux,(x+i)->titulo)==0)
        {
            printf("\nIngrese el nuevo titulo: ");
            fflush(stdin);
            gets(aux2);
            strcpy(x->titulo[i], aux2);
        }
    }
}
void generarWeb(eMovie* x, int cantidad)
{
    FILE* f;
    for(int i=0; i<largo; i++)
    {
        f=fopen("index.html", "a+");
        if(f==NULL)
        {
            printf("No se pudo crear\n");
            exit(1);
        }
        fprintf(f, "<article class='col-md-4 article-intro'>");
        fprintf(f, "<a href='#'>");
        fprintf(f, "<img class='img-responsive img-rounded' src='%s'", (M+i)->linkImagen);
        fprintf(f, "alt=''>");
        fprintf(f, "</a>");
        fprintf(f, "<h3>");
        fprintf(f, "<a href='#'>%s</a>", (x+i)->titulo);
        fprintf(f, "</h3>");
        fprintf(f, "<ul>");
        fprintf(f, "<li>Género:%s</li>", (x+i)->genero);
        fprintf(f, "<li>Puntaje:%d</li>", (x+i)->puntaje);
        fprintf(f, "<li>Duración:%d</li>", (x+i)->duracion);
        fprintf(f, "</ul>");
        fprintf(f, "<p>%s</p>", (x+i)->descripcion);
        fprintf(f, "</article>");
    }
    fclose(f);
}
