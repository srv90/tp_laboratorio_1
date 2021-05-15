/*
 * funcionesVarias.h
 *
 *  Created on: 11 may. 2021
 *      Author: Quique
 */
#include "arrayEmployees.h"
#ifndef FUNCIONESVARIAS_H_
#define FUNCIONESVARIAS_H_



#endif /* FUNCIONESVARIAS_H_ */


/** \brief returns the option selected by the user
 *
 * \return int
 */
int menu();



/** \brief receives the employee that user wants to modify
 * \param empleado Employee
 * \return int
 */
int menuModify(Employee empleado);

/** \brief receives and validate if the string contains only numbers
 *
 * \param numero char*
 * \return 1 if it is a number and 0 if not
 *
 */
int validateNumber(char* numero);

/** \brief receives and validate if the sector contains only numbers
 *
 * \param sector int*
 * \return void
 *
 */
void validateSector(int* sector);

/** \brief receives and validate if the salary contains only numbers
 *
 * \param sector int*
 * \return void
 *
 */
void validateSalary(float* sueldo);

/** \brief
 *receives and validate if the string contains only numbers and one dot
 * \param numero char*
 * \return 1 if it is ok and 0 if not
 *
 */
int validateFloat(char* numero);

