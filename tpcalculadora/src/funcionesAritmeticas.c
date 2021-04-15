/*
 * funcionesAritmeticas.c
 *
 *  Created on: 6 abr. 2021
 *      Author: Quique
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcionesAritmeticas.h"

/** \brief realiza la suma de dos operandos
 *
 * \param resultado float* resultado final
 * \param num1 int primer operando
 * \param num2 int segundo operando
 * \return int devuelve un 1 en caso de haber hecho la operacion, sino devuelve un 0
 *
 */
int sumar(float* resultado,int num1, int num2)
{
    int retorno = 0;
    if(resultado != NULL){
        *resultado = num1 + num2;
        retorno = 1;
    }
    return retorno;



}

/** \brief realiza la resta de ambos operandos
 *
 * \param resultado float* resultado final
 * \param num1 int primer operando
 * \param num2 int segundo
 * \return int devuelve un 1 en caso de haber hecho la operacion, sino devuelve un 0
 *
 */
int restar(float* resultado,int num1, int num2)
{
    int retorno = 0;
    if(resultado != NULL)
    {
        *resultado = num1 - num2;
        retorno = 1;
    }
    return retorno;

}
/** \brief realiza la multiplicacion de ambos operandos
 *
 * \param resultado float* resultado final
 * \param num1 int primero operando
 * \param num2 int segundo operando
 * \return int devuelve un 1 en caso de haber hecho la operacion, sino devuelve un 0
 *
 */
int multiplicar(float* resultado,int num1, int num2)
{
    int retorno = 0;
    if(resultado != NULL)
    {
        *resultado = num1 * num2;
        retorno = 1;
    }
    return retorno;
}
/** \brief realiza la division de ambos operandos
 *
 * \param resultado float* resultado final
 * \param num1 int primer operando
 * \param num2 int segundo operando
 * \return int devuelve un 1 en caso de haber hecho la operacion, sino devuelve un 0
 *
 */
int dividir(float* resultado,int num1, int num2)
{
    int retorno = 0;
    if(num2 != 0 && resultado != NULL){

        *resultado = (float)num1/num2;
        retorno = 1;

    }

    return retorno;
}
/** \brief realiza el factorial de un numero
 *
 * \param num int es el numero ingresado
 * \return int devuelve el factorial en caso de haberlo hecho, sino devuelve un 0
 *
 */
int factorial(int num)
{

    int fact = 1;

    if(num >= 0){
        for (int i=1; i<=num ; i++ ){
        fact *= i;
    }
        return fact;
    }
    return 0;
}


