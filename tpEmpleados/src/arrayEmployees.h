/*
 * empleado.h
 *
 *  Created on: 11 may. 2021
 *      Author: Quique
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_

struct
{
int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;
}typedef Employee;

#endif /* EMPLEADO_H_ */

int initEmployees(Employee* list, int len);
int addEmployee(Employee* list, int len, int* id);
int findEmployeeById(Employee* list, int len,int id);
int removeEmployee(Employee* list, int len, int id);
int printEmployees(Employee list[], int len);
int inform(Employee list [], int len);
void printEmployee(Employee empleado);
int findFreePosition(Employee list[], int len);
int sortEmployees(Employee* list, int len, int order);
int deleteEmployee(Employee* list, int len);
int modifyEmployee(Employee* list, int len);


