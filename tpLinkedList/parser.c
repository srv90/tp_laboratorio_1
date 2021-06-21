#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{

    int retorno = 0;
    Employee* auxEmp = NULL;
    char auxSueldo[20];
    char auxHoras[20];
    char auxName [128];
    char auxId[20];

    if(pFile !=NULL && pArrayListEmployee != NULL)
    {

        fscanf(pFile, "%s\n", auxName);
        while(!feof(pFile))
        {
            if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,\n]\n", auxId, auxName, auxHoras, auxSueldo) == 4)
            {
                auxEmp = employee_newParametros(auxId,auxName,auxHoras,auxSueldo);
                ll_add(pArrayListEmployee,auxEmp);
            }
            else
            {
                break;
            }

        }

        retorno = 1;
    }
    return  retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{

    int retorno = 0;
    Employee* auxEmp = NULL;
    if(pFile != NULL && pArrayListEmployee != NULL)
    {

        while(!feof(pFile))
        {
            auxEmp = employee_new();
            if(auxEmp != NULL)
            {
              if((fread(auxEmp,sizeof(Employee),1, pFile)) < 1) {
                break;
              }
            ll_add(pArrayListEmployee, auxEmp);

            }

        }
        fclose(pFile);
        retorno = 1;
    }
    return retorno;
}
