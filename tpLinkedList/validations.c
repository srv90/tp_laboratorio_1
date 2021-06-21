/*
 * validations.c
 *
 *  Created on: 13 jun. 2021
 *      Author: Quique
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validations.h"




/** \brief valida si una cadena esta conformada solamente por numeros
 *
 * \param numero char*
 * \return int
 *
 */
int validateNumber(char* numero)
{

    int retorno = 1;

    for (int i=0; numero[i]!= '\0' ; i++ )
    {
        if(numero[i] < '0' || numero[i] > '9')
        {
            retorno = 0;
            break;
        }
    }

    return retorno;
}
