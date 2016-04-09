int calcularSuma(int x, int y)
    {
            printf("\nEl resultado de la suma es: %d\n", x+y);
    }
int calcularResta(int x, int y)
    {
            printf("\nEl resultado de la resta es: %d\n", x-y);
    }
float calcularDivision(int x, int y)
{
            printf("\nEl resultado de la division es: %.2f\n", (float)x/y);
}
int calcularMultiplicacion(int x, int y)
{
            printf("\nEl resultado de la multiplicacion es: %d\n", x*y);
}
int calcularFactoreo(int x)
{
            int acum=1;

            for(int i=x ; i>0 ; i--)
            {
                acum=acum*i;
            }

            printf("\nEl resultado del factoreo es: %d\n", acum);
}
