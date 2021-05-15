/*
 ============================================================================
 Name        : tpEmpleados.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "arrayEmployees.h"
#include "funcionesVarias.h"

#define TAMEMPLEADOS 1000

int main(void) {

	setbuf(stdout, NULL);
	int id = 1;
	int flagAltaEmpleado = 0;
	char respuesta;

	Employee employees[TAMEMPLEADOS];

	initEmployees(employees, TAMEMPLEADOS);

	do {

		switch (menu()) {
		case 1:
			if (addEmployee(employees, TAMEMPLEADOS, &id) == -1) {
				printf("Ocurrio un error\n");
			} else {
				printf("Alta exitosa.\n");
				flagAltaEmpleado = 1;
			}
			break;
		case 2:
			if (flagAltaEmpleado) {
				if (!modifyEmployee(employees, TAMEMPLEADOS)) {
					printf("Ocurrio un error\n   ");
				} else {
					printf("Modificacion exitosa.\n");
				}
			} else {
				printf("Debe dar de alta algun empleado primero. \n");
			}
			break;
		case 3:
			if (flagAltaEmpleado) {
				if (deleteEmployee(employees, TAMEMPLEADOS)) {
					printf("Baja exitosa.");

				} else {
					printf("Ocurrio un error.\n");
				}
			} else {
				printf("Debe dar de alta algun empleado primero. \n");
			}
			break;
		case 4:
			if (flagAltaEmpleado) {
				if (!inform(employees, TAMEMPLEADOS)) {
					printf("Ocurrio un error.\n");
				}
			} else {
				printf("Debe dar de alta algun empleado primero. \n");
			}
			break;
		case 5: {
			printf("\nSeguro que deseas salir? s/n \n");
			fflush(stdin);
			respuesta = getchar();

		}
			while (respuesta != 's' && respuesta != 'n');
			break;
		}

		system("pause");
	} while (respuesta != 's');

	return EXIT_SUCCESS;
}
