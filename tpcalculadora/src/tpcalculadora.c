/*
 ============================================================================
 Name        : tpcalculadora.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcionesAritmeticas.h"
#include "funcionesVarias.h"


int main(void) {

	setbuf(stdout, NULL);

    int num1;
    int num2;
    float resultado;
    char respuesta;
    int flagPrimerOperando = 0;
    int flagSegundoOperando = 0;
    int flagEcuacionesRealizadas = 0;


    do
    {
        switch (menu(flagPrimerOperando, flagSegundoOperando, num1,num2))
        {
        case 1 :
            if(flagPrimerOperando)
            {
                printf("Ya has ingresado el primer operando:  %d   ", num1);
                break;
            }
            else
            {
                printf("Ingrese primer operando:  ");
                while (scanf("%d",&num1)!=1)
                {
                    printf("Solo puedes ingresar numeros\n");
                    printf("Ingrese primer operando:  ");
                    fflush(stdin);
                }
                activarDesactivarFlag(&flagPrimerOperando);
            }
            break;
        case 2:
            if(!flagPrimerOperando)
            {
                printf("Primero debes ingresar el primer operando.  ");
                break;
            }
            else if(flagSegundoOperando)
            {
                printf("Ya has ingresado el segundo operando:  %d   ", num2);
                break;
            }
            else
            {
                printf("Ingrese segundo operando:  ");
                while (scanf("%d",&num2)!=1)
                {
                    printf("Solo puedes ingresar numeros\n");
                    printf("Ingrese segundo operando:  ");
                    fflush(stdin);
                }
               activarDesactivarFlag(&flagSegundoOperando);
            }
            break;
        case 3:
            if(flagPrimerOperando && flagSegundoOperando)
            {
                sumar(&resultado,num1, num2);
                restar(&resultado,num1, num2);
                dividir(&resultado,num1, num2);
                multiplicar(&resultado,num1, num2);
                factorial(num1);
                factorial(num2);

                activarDesactivarFlag(&flagEcuacionesRealizadas);
            }
            else
            {
                printf("Primero debes ingresar ambos operandos.   ");
            }
            break;
        case 4:
            if(flagEcuacionesRealizadas)
            {
                    if(sumar(&resultado,num1, num2))
                    {
                        printf("a)El resultado de %d + %d es %.f ",num1, num2, resultado);
                    }
                    else
                    {
                        printf("No se pudo realizar la operacion. ");
                    }
                    if(restar(&resultado,num1,num2))
                    {
                        printf("\nb)El resultado de %d - %d es %.f ", num1,num2,resultado);
                    }
                    else
                    {
                        printf("No se pudo realizar la operacion. ");
                    }
                    if(dividir(&resultado,num1, num2))
                    {
                        printf("\nc)El resultado de %d / %d es %f ", num1,num2,resultado);
                    }
                    else
                    {
                        printf("\nc)No se puede dividir por 0 ");
                    }
                    if(multiplicar(&resultado, num1, num2))
                    {
                        printf("\nd)El resultado de %d * %d es %.f: ",  num1,num2,resultado);
                    }
                    else
                    {
                        printf("No se pudo realizar la operacion. ");

                    }
                    if(factorial(num1) && !factorial(num2))
                    {
                        printf("\ne)El factorial de %d es %d y el segundo numero debe ser mayor o igual a 0  ",
                               num1,factorial(num1));
                    }
                    else if(!factorial(num1) && factorial(num2))
                    {

                        printf("\ne)El primer numero debe ser mayor o igual 0 y el factorial de %d es %d ",
                               num2,factorial(num2));
                    }
                    else if(factorial(num1) && factorial(num2))
                    {
                        printf("\ne)El factorial de %d es %d y el factorial de %d es %d  ",
                               num1,factorial(num1), num2,factorial(num2));
                    }else{
                        printf("\ne)Ningun numero es mayor o igual a 0.");
                    }

                    activarDesactivarFlag(&flagPrimerOperando);
                    activarDesactivarFlag(&flagSegundoOperando);
                    activarDesactivarFlag(&flagEcuacionesRealizadas);
            }
            else
            {
                printf("Primero debes realizar todas las operaciones correspondientes.   ");
            }
            break;
        case 5:
            do
            {
                printf("Seguro que deseas salir? s/n \n");
                fflush(stdin);
                respuesta = getchar();
            }
            while (respuesta != 's' && respuesta != 'n' );
            break;
        default:
            printf("Debes ingresar alguna de las opciones que figura en pantalla.     ");
            fflush(stdin);
            break;
        }
        system("pause");
        system("cls");

    }
    while (respuesta != 's');
}
