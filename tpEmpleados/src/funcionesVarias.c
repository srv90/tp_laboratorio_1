/*
 * funcioneVarias.c
 *
 *  Created on: 11 may. 2021
 *      Author: Quique
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesVarias.h"
#include "arrayEmployees.h"


int menu()
{
    char auxCadena[200];
    int opcion;

    printf("*******************MENU DE OPCIONES*******************************\n");
    printf(" 1) ALTAS\n 2) MODIFICAR \n 3) BAJAS\n 4) INFORMAR\n");
    printf(" 5) SALIR\n");

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
            if(opcion < 1 || opcion > 5){
            	printf("Elije una de las opciones disponibles.\n");
            }

        }
    }
    while (!validateNumber(auxCadena));

    return opcion;
}

int menuModify(Employee empleado)
{
    int opcion;
    char auxCadena[200];

    printf("Elije el campo que deseas modificar: \n");
    printf("1- Nombre: %s\n", empleado.name);
    printf("2- Apellido: %s\n", empleado.lastName);
    printf("3- Sector: %d\n", empleado.sector);
    printf("4- Salario: %.2f\n", empleado.salary);
    printf("5- Salir\n");

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
            if(opcion < 1 || opcion > 5){
            	printf("Elije una de las opciones disponibles.\n");
            }

        }
    }
    while (!validateNumber(auxCadena) || (opcion < 1 || opcion > 5));


    return opcion;
}


void validateSector(int* sector){

    char auxCadena[200];

    do
    {
    	printf("Ingresa numero del sector: ");
    	fflush(stdin);
    	scanf("%s", auxCadena);

        if(!validateNumber(auxCadena))
        {
            printf("Solo puedes ingresar numeros.\n");

        }
    }
    while (!validateNumber(auxCadena));

    *sector = atoi(auxCadena);
}


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

void validateSalary(float* sueldo)
{

    char auxCadena [200];

    printf("Ingresa el sueldo: ");
    do
    {
        fflush(stdin);
        fgets(auxCadena, sizeof(auxCadena), stdin);
        auxCadena[strcspn(auxCadena, "\n")] = '\0';
        fflush(stdin);

        if(!validateFloat(auxCadena))
        {
            printf("Sueldo invalido. Intenta nuevamente: ");

        }

    }
    while (!validateFloat(auxCadena));

    *sueldo = atof(auxCadena);


}
int validateFloat(char* numero)
{

    int retorno = 1;
    int totalPuntos = 0;
    int flag = 0;

    for (int i=0; numero[i]!= '\0' ; i++ )
    {
        if(numero[i] == '.')
        {
            totalPuntos++;
        }
        else if((numero[i] < '0' || numero[i] > '9'))
        {
            flag = 1;
            break;
        }
    }
    if(totalPuntos > 1 || flag)
    {
        retorno = 0;
    }

    return retorno;
}
