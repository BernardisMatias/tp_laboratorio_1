typedef struct
{
    char* titulo;
    char* genero;
    int* duracion;
    char* descripcion;
    int* puntaje;
    char* linkImagen;
}eMovie;

void AltaPelicula(eMovie *x);
/** \brief Alta de las peliculas
 *
 * \param Recibe como primer parametro un puntero a eMovie.
 * \param Recibe como segundo parametro cantidad, como entero.
 * \return Retorna un entero con usos varios en el futuro.
 *
 */
void mostrarPelicula(eMovie *x, int largo);
/** \brief Muestra las peliculas cargadas
 *
 * \param Recibe como primer parametro un puntero a eMovie.
 * \param Recibe como segundo parametro un largo que sirve para indicar al for cuantas veces iterar.
 * \return No tiene retorno
 *
 */
 void modificarPelicula(eMovie* x, int cantidad);
 /** \brief Modifica las peliculas
  *
  * \param Recibe como primer parametro un puntero a eMovie
  * \param Recibe como segundo parametro, una cantidad que va a tener uso en la funcion mostrar dentro de la funcion.
  * \return No tiene retorno
  *
  */
void generarWeb(eMovie* x, int cantidad);
/** \brief Genera pagina web
 *
 * \param Recibe como primer parametro un puntero a eMovie.
 * \param Recibe como segundo parametro un puntero a cantidad.
 * \return No tiene retorno
 *
 */
