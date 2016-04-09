#include <stdio.h>
#include <stdlib.h>
#include "trabajoPractico1.h"
int main()
{
   int num1, num2, opcion, flag1=0, flag2=0;

    do
    {

        printf("\n\nQue operacion desea realizar?: \n\nIngrese el numero de la operacion deseada y luego presione Enter.");
        if(flag1==0)
        {
            num1=0;
        }
        printf("\n\n1- Ingresar el primer operando");printf("\tA=%d", num1);
        if(flag2==0)
        {
            num2=0;
        }
        printf("\n2- Ingresar el segundo operando");  printf("\tB=%d", num2);

        printf("\n3- Calcular la suma\n");
        printf("4- Calcular la resta\n");
        printf("5- Calcular la division\n");
        printf("6- Calcular la multiplicacion\n");
        printf("7- Calcular el factorial del primer numero\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");



        scanf("%d", &opcion);


    switch(opcion)
        {
        case 1:
            printf("\nIngrese aqui el primer numero:");
            scanf("%d",& num1);
            printf("\nEl primer numero ingresado es %d\n", num1);
            flag1++;
            break;
        case 2:
            printf("\nIngrese aqui el segundo numero:");
            scanf("%d",& num2);
            printf("\nEl segundo numero ingresado es %d\n", num2);
            flag2++;
            break;
            case 3:
                if(flag1==0&&flag2==0)
                {
                    printf("\nPor favor, ingrese dos numeros, (opciones 1 y 2), antes de realizar cualquier operacion.\n");

                }
                else
                {
                calcularSuma(num1, num2);
                }
            break;

            case 4:
                if(flag1==0&&flag2==0)
                {
                    printf("\nPor favor, ingrese dos numeros, (opciones 1 y 2), antes de realizar cualquier operacion.\n");
                }
                else
                {
                calcularResta(num1, num2);
                }
            break;

            case 5:
                    if(flag1==0&&flag2==0)
                    {
                        printf("\nPor favor, ingrese dos numeros, (opciones 1 y 2), antes de realizar cualquier operacion.\n");
                    }
                    else
                    {
                        if(num2==0)
                         {
                                printf("Error. No es posible dividir un numero por 0.\n");
                                break;
                         }
                         else
                         {
                                calcularDivision(num1, num2);
                         }
                    }
            break;

            case 6:
                if(flag1==0&&flag2==0)
                {
                    printf("\nPor favor, ingrese dos numeros, (opciones 1 y 2), antes de realizar cualquier operacion.\n");
                }
                else
                {
                calcularMultiplicacion(num1, num2);
                }
                break;
            case 7:
                if(flag1==0&&flag2==0)
                {
                    printf("\nPor favor, ingrese al menos el primer numero, (opcion 1), antes de intentar factorear.\n");
                }
                else
                {
                calcularFactoreo(num1);
                }
                break;
            case 8:
                if(flag1==0&&flag2==0)
                {
                    printf("\nPor favor, ingrese dos numeros, (opciones 1 y 2), antes de realizar cualquier operacion.\n");
                    break;
                }
                else
                {
                        calcularSuma(num1, num2);



                        calcularResta(num1, num2);



                        if(num2==0)
                             {
                                    printf("No es posible dividir un numero por 0.");

                             }
                             else
                             {
                                    calcularDivision(num1, num2);

                             }

                        calcularMultiplicacion(num1, num2);

                        calcularFactoreo(num1);
                        break;
                }

            case 9:
                printf("\tGracias por usar mi programa! \n");
                break;
            default:
                printf("\nError de ingreso de operacion\n");
                break;
        }



    system("pause");



    }while(opcion!=9);


    return 0;
}








