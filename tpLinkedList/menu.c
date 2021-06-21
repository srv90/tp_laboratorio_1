/*
 * menu.c
 *
 *  Created on: 13 jun. 2021
 *      Author: Quique
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "validations.h"




/** \brief retorna la opcion ingresada por el usuario
 *
 * \return int
 *
 */
int menu()
{
    char auxCadena[200];
    int opcion;

    printf("*******************MENU DE OPCIONES*******************************\n");
    printf(" 1) CARGAR DATOS MODO TEXTO\n 2) CARGAR DATOS MODO BINARIO \n 3) ALTA EMPLEADO\n 4) MODIFICAR\n");
    printf(" 5) BAJA\n 6) LISTAR \n 7) ORDENAR\n 8) GUARDAR MODO TEXTO\n 9) GUARDAR MODO BINARIO\n");
    printf(" 10) SALIR\n");

    do
    {
        printf("\nIngresa opcion: ");
        fflush(stdin);
        scanf("%s", auxCadena);

        if(!validateNumber(auxCadena))
        {
            printf("Solo puedes ingresar numeros: ");
            fflush(stdin);
        }else{
            opcion = atoi(auxCadena);
            if(opcion < 1 || opcion > 10){
            	printf("Elije una de las opciones disponibles.\n");
            }

        }
    }
    while (!validateNumber(auxCadena));

    return opcion;
}

/** \brief retorna la opcion ingresada por el usuario
 *
 * \return int
 *
 */
int menuModificacion(){

    char auxCadena[200];
    int opcion;

    printf("\nINGRESA EL DATO QUE DESEAS MODIFICAR: \n\n");
    printf(" 1) NOMBRE\n 2) HORAS TRABAJADAS\n 3) SUELDO\n 4)SALIR");

    do
    {
        printf("\nIngresa opcion: ");
        fflush(stdin);
        scanf("%s", auxCadena);

        if(!validateNumber(auxCadena))
        {
            printf("Solo puedes ingresar numeros: ");
        }else{
            opcion = atoi(auxCadena);
            if(opcion < 1 || opcion > 4){
            	printf("Elije una de las opciones disponibles.\n");
            }

        }
    }
    while (!validateNumber(auxCadena) || (opcion < 1 || opcion > 4)  );

    return opcion;
}
