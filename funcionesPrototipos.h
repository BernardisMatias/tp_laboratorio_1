typedef struct
{
    char nombre[50];
    int edad;
    int dni;
    int estaVacio;
}ePersona;
int pedirLugar(ePersona UnaPersona[]);
void inicializar(ePersona UnaPersona[]);
void altaPersona(ePersona unaPersona[]);
void mostrarPersona(ePersona UnaPersona[]);
void borrarPersona(ePersona UnaPersona[]);
void ordenarMenorAMayor(ePersona UnaPersona[]);
void ordenarMayorAMenor(ePersona UnaPersona[]);
void mostrarGraficoEdades(ePersona UnaPersona[]);

