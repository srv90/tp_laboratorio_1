/*
 * funcionesVarias.c
 *
 *  Created on: 6 abr. 2021
 *      Author: Quique
 */


#include <stdio.h>
#include <stdlib.h>

/** \brief menu de opciones
 *
 * \param opcion int es la opcion que elige el usuario
 * \param flagPrimerOperando int evalua si ya ha sido ingresado el primer operando
 * \param flagSegundoOperando int evalua si ya ha sido ingresado el segundo operando
 * \param num1 int primer operando
 * \param num2 int segundo operando
 * \return int devuelve la opcion que eligio el usuario
 *
 */
int menu(int flagPrimerOperando, int flagSegundoOperando, int num1, int num2)
{
    int opcion;

    printf("***************************************MENU DE OPCIONES*************************************\n");
    if(flagPrimerOperando)
    {
        printf("1.Ingresar primer operando (A=%d) \n", num1);
    }
    else
    {
        printf("1.Ingresar primer operando (A=x). \n");
    }
    if(flagSegundoOperando)
    {
        printf("2.Ingresar segundo operando (B=%d)", num2);
    }
    else
    {
        printf("2.Ingresar segundo operando (B=y).");
    }
    printf("\n3. Calcular todas las operaciones.\n");
    printf(" a-Calcular suma (A+B)\n b-Calcular resta (A-B)\n c-Calcular division (A/B)\n d-Calcular multiplicacion (A*B)\n e-Calcular factorial (!A)\n");
    printf("4. Mostrar resultados\n5.Salir \n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);


    return opcion;

}

/** \brief activa o desactiva las banderas segun corresponda
 *
 * \param flag int* la bandera a evaluar
 * \return void
 *
 */
void activarDesactivarFlag(int* flag)
{
    if(flag != NULL)
    {
        if(*flag !=1)
        {
            *flag = 1;
        }
        else
        {
            *flag = 0;
        }
    }
}

