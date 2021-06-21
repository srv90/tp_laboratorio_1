

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "validations.h"


/** \brief crea y devuelve un empleado nuevo
 *
 * \return Employee*
 *
 */
Employee* employee_new()
{

    return (Employee*)malloc(sizeof(Employee));


}

/** \brief crea y devuelve un empleado con sus correspondientes parametros
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{

    Employee* auxEmp = employee_new();

    if(auxEmp != NULL)
    {
        if(!(employee_setId(auxEmp,atoi(idStr)) && employee_setNombre(auxEmp,nombreStr) &&
                employee_setHorasTrabajadas(auxEmp,atoi(horasTrabajadasStr)) && employee_setSueldo(auxEmp,atoi(sueldoStr))))
        {

            employee_delete(auxEmp);
            auxEmp = NULL;

        }

    }
    return auxEmp;


}

/** \brief elimina un empleado
 *
 * \param this Employee*
 * \return void
 *
 */
void employee_delete(Employee* this)
{
    if(this != NULL)
    {
        free(this);
    }

}


/** \brief asigna un  id a un nuevo empleado
 *
 * \param this Employee*
 * \param id int
 * \return int devuelve 1 si tuvo exito y 0 sino
 *
 */
int employee_setId(Employee* this,int id)
{

    int retorno = 0;
    if(this != NULL)
    {
        this->id = id;
        retorno =1;
    }

    return retorno;
}

/** \brief le asigna un nombre a un nuevo empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return int devuelve 1 si tuvo exito y 0 sino
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{

    int retorno = 0;
    if(this != NULL && (strlen(nombre) > 3) && strlen(nombre) < 20 )
    {
        strcpy(this->nombre, nombre);
        retorno =1;
    }

    return retorno;


}
/** \brief le asigna la cantidad de las horas trabajadas a un empleado
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int devuelve 1 si tuvo exito y 0 sino
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = 0;
    if(this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno =1;
    }

    return retorno;

}

/** \brief le asigna la cantidad de las horas trabajadas a un empleado
 *
 * \param this Employee*
 * \param horasTrabajadas char*
 * \return int devuelve 1 si tuvo exito y 0 sino
 *
 */
int employee_setHorasTrabajadasStr(Employee* this,char* horasTrabajadas)
{


    int retorno = 0;
    if(this != NULL && horasTrabajadas != NULL)
    {
        if(validateNumber(horasTrabajadas))
        {
            this->horasTrabajadas = atoi(horasTrabajadas);

            retorno =1;
        }
    }

    return retorno;


}
/** \brief le asigna un sueldo a un nuevo empleado
 *
 * \param this Employee*
 * \param sueldo char*
 * \return int devuelve 1 si tuvo exito y 0 sino
 *
 */
int employee_setSueldoStr(Employee* this, char* sueldo)
{

    int retorno = 0;
    if(this != NULL && sueldo != NULL)
    {
        if(validateNumber(sueldo))
        {
            this->sueldo = atoi(sueldo);

            retorno =1;
        }
    }

    return retorno;

}

/** \brief le asigna un sueldo a un nuevo empleado
 *
 * \param this Employee*
 * \param sueldo int
 * \return int devuelve 1 si tuvo exito y 0 sino
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = 0;
    if(this != NULL)
    {
        this->sueldo = sueldo;
        retorno =1;
    }

    return retorno;
}


/** \brief obtiene el sueldo de un empleado
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int devuelve 1 si tuvo exito y 0 sino
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = 0;
    if(this != NULL && sueldo != NULL)
    {

        *sueldo = this->sueldo;
        retorno = 1;

    }

    return retorno;
}

/** \brief obtiene el nombre de un empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return int devuelve 1 si tuvo exito y 0 sino
 *
 */
int employee_getNombre(Employee* this, char* nombre)
{
    int retorno = 0;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 1;
    }

    return retorno;
}

/** \brief obtiene las horas trabajadas de un empleado
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int devuelve 1 si tuvo exito y 0 sino
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = 0;
    if(this != NULL && horasTrabajadas != NULL)
    {

        *horasTrabajadas = this->horasTrabajadas;
        retorno = 1;
    }

    return retorno;
}

/** \brief obtiene el id de un empleado
 *
 * \param this Employee*
 * \param id int*
 * \return int devuelve 1 si tuvo exito y 0 sino
 *
 */
int employee_getId(Employee* this,int* id)
{

    int retorno = 0;
    if(this != NULL && id != NULL)
    {

        *id = this->id;
        retorno = 1;
    }

    return retorno;



}

/** \brief muestra la informacion de un empleado
 *
 * \param this Employee*
 * \return int devuelve 1 si tuvo exito y 0 sino
 *
 */
int display_employee(Employee* this)
{

    int retorno = 0;
    int id;
    char nombre [20];
    int sueldo;
    int horasTrabajadas;

    if(this != NULL && employee_getId(this, &id) && employee_getNombre(this,nombre)
            && employee_getHorasTrabajadas(this, &horasTrabajadas) && employee_getSueldo(this,&sueldo))
    {
        printf("% d         %-10s     %d      %d\n", id,nombre, horasTrabajadas, sueldo);
        retorno = 1;
    }


    return retorno;


}

/** \brief ordena a los empleados por nombre
 *
 * \param a void*
 * \param b void*
 * \return int devuelve 1 si el orden es descendente, -1 si es ascendente y 0 si son iguales
 *
 */
int sortByName(void* a, void* b)
{
    int retorno = 0;

    Employee* emp1 = (Employee*) a;
    Employee* emp2 = (Employee*) b;

    char nombre1[30];
    char nombre2[30];


    if(employee_getNombre(emp1,nombre1) && employee_getNombre(emp2,nombre2))
    {

    	retorno = strcmp(nombre1, nombre2);

    }
    return retorno;
}
