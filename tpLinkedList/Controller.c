#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "validations.h"
#include "Controller.h"
#include "menu.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = 0;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        FILE* f = fopen(path, "r");
        if(f == NULL)
        {
            perror("Error: ");
        }
        else
        {
            parser_EmployeeFromText(f, pArrayListEmployee);
        }
        fclose(f);
        retorno = 1;
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{

    int retorno = 0;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        FILE* f = fopen(path, "rb");
        if(f == NULL)
        {
            perror("Error: ");
        }
        else
        {
            parser_EmployeeFromBinary(f, pArrayListEmployee);
        }
        fclose(f);
        retorno = 1;
    }
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* pId)
{
    int retorno =0;
    char sueldo[100];
    char horasTrabajadas [100];
    char nombre[25];

    Employee* auxEmp = employee_new();

    if(pArrayListEmployee != NULL && auxEmp !=NULL && pId != NULL)
    {

        printf("Ingresa nombre: ");
        scanf("%s", nombre);

        while(!employee_setNombre(auxEmp, nombre))
        {
            printf("Error ingresalo nuevamente: ");
            scanf("%s", nombre);
        };

        printf("Ingresa las horas trabajadas: ");
        fflush(stdin);
        scanf("%s", horasTrabajadas);
        while(!employee_setHorasTrabajadasStr(auxEmp, horasTrabajadas))
        {
            printf("Error, ingresa las horas nuevamente: ");
            scanf("%s", horasTrabajadas);

        }
        printf("Ingresa el sueldo: ");
        fflush(stdin);
        scanf("%s", sueldo);

        while(!employee_setSueldoStr(auxEmp, sueldo))
        {
            printf("Error, ingresa el sueldo nuevamente: ");
            fflush(stdin);
            scanf("%s", sueldo);

        }
        employee_setId(auxEmp, *pId);

        (*pId)++;

        if(ll_add(pArrayListEmployee, auxEmp) == 0)
        {
            printf("Alta exitosa!\n");

        }
        else
        {
            printf("Error en el alta,\n");
        }

        retorno = 1;


    }
    return retorno;


    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno =0;
    int flag =0;
    char sueldo [100];
    char horasTrabajadas [100];
    int sueldoNum;
    int horasTrabajadasNum;
    int id;
    int idEmp;
    char respuesta;
    char nombre [25];
    char cadAux[20];

    Employee* auxEmp = NULL;

    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        do
        {
            printf("Ingresa el id del empleado que deseas modificar: ");
            fflush(stdin);
            fgets(cadAux, sizeof(cadAux), stdin);
            cadAux[strcspn(cadAux, "\n")] = '\0';

            if(!(validateNumber(cadAux)))
            {
                printf("Solo puedes ingresar numeros.\n");
            }
            else
            {
                id = atoi(cadAux);

                for (int i=0; i<ll_len(pArrayListEmployee) ; i++ )
                {
                    auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
                    employee_getId(auxEmp, &idEmp);

                    if(idEmp == id)
                    {
                        flag = 0;
                        break;
                    }
                    else flag =1;
                }
                if(flag){

                    printf("EL id ingresado no existe\n");
                }
            }
        }
        while(!(validateNumber(cadAux)) || flag);

        system("cls");
        printf("ID         NOMBRE        HORAS    SUELDO\n");
        if(!display_employee(auxEmp))
        {
            printf("Ocurrio un error al intentar mostrar el empleado");
        }

        printf("\nSeguro que deseas modificarlo? Presiona s para Si o n para No  ");
        fflush(stdin);
        scanf("%c", &respuesta);
        if(respuesta == 's')
        {
            system("cls");
            do
            {
                switch (menuModificacion())
                {
                case 1 :
                    system("cls");
                    if(!employee_getNombre(auxEmp,nombre))
                    {
                        printf("Ocurrio un error con el nombre");
                    }
                    printf("Nombre actual: %s\n", nombre);
                    printf("Ingresa el nuevo nombre: ");
                    scanf("%s", nombre);
                    while(!employee_setNombre(auxEmp, nombre))
                    {
                        printf("Error ingresalo nuevamente: ");
                        scanf("%s", nombre);
                    };
                    printf("Modificacion exitosa!\n");
                    break;
                case 2 :
                    system("cls");
                    if(!employee_getHorasTrabajadas(auxEmp,&horasTrabajadasNum))
                    {
                        printf("Ocurrio un error con las horas");
                    }
                    printf("Horas actuales trabajadas: %d\n", horasTrabajadasNum);
                    printf("Ingresa las nuevas horas: ");
                    scanf("%s", horasTrabajadas);
                    while(!employee_setHorasTrabajadasStr(auxEmp, horasTrabajadas))
                    {
                        printf("Error, ingresa las horas nuevamente: ");
                        scanf("%s", horasTrabajadas);

                    }
                    printf("Modificacion exitosa!\n");
                    break;
                case 3 :
                    system("cls");
                    if(!employee_getSueldo(auxEmp,&sueldoNum))
                    {
                        printf("Ocurrio un error con el sueldo");
                    }
                    printf("Sueldo actual: %d\n", sueldoNum);
                    printf("Ingresa el nuevo sueldo: ");
                    scanf("%s", sueldo);

                    while(!employee_setSueldoStr(auxEmp, sueldo))
                    {
                        printf("Error, ingresa el sueldo nuevamente: ");
                        fflush(stdin);
                        scanf("%s", sueldo);

                    }
                    printf("Modificacion exitosa!\n");
                    break;
                case 4:
                    printf("\nSeguro que deseas salir? s/n \n");
                    fflush(stdin);
                    respuesta = getchar();
                    while (respuesta != 's' && respuesta != 'n' )
                    {
                        printf("Ingresa s o n \n");
                        fflush(stdin);
                        respuesta = getchar();
                    }
                    break;
                }
            }
            while(respuesta != 's');

        }
        else if(respuesta == 'n')
        {
            printf("Se ha cancelado la modficacion.  ");
        }

        retorno = 1;


    }
    return retorno;

}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno =0;
    char cadAux[30];
    int id;
    int idEmp;
    int flag = 0;
    Employee* auxEmp = NULL;

    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        do
        {
            printf("Ingresa el id del empleado que deseas borrar: ");
            fflush(stdin);
            fgets(cadAux, sizeof(cadAux), stdin);
            cadAux[strcspn(cadAux, "\n")] = '\0';

            if(!(validateNumber(cadAux)))
            {
                printf("Solo puedes ingresar numeros.\n");
            }
            else
            {
                id = atoi(cadAux);
                for (int i=0; i<ll_len(pArrayListEmployee) ; i++ )
                {
                    auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
                    employee_getId(auxEmp, &idEmp);

                    if(idEmp == id)
                    {
                        flag = 1;
                        if(ll_remove(pArrayListEmployee,i) == 0)
                        {
                            printf("El empleado ha sido eliminado.\n");
                        }
                        else
                        {
                            printf("No se ha podido eliminar el empleado\n");
                        }
                    }
                }
                if(!flag)
                {
                printf("EL id ingresado no existe\n");

                }
            }
        }
        while(!(validateNumber(cadAux)) || !flag );


        retorno = 1;


    }
    return retorno;

}



/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno =0;
    Employee* auxEmp = NULL;
    if(pArrayListEmployee != NULL)
    {
        printf(" ID            NOMBRE        HORAS    SUELDO\n");
        for (int i=0; i<ll_len(pArrayListEmployee) ; i++ )
        {
            auxEmp = (Employee*)ll_get(pArrayListEmployee,i);
            display_employee(auxEmp);
        }
        retorno =1;
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    printf("El listado esta siendo ordenado...");


    if(pArrayListEmployee != NULL && ll_sort(pArrayListEmployee, sortByName, 1) != -1)
    {

        retorno = 1;

    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{

    int retorno = 0;
    int id;
    int sueldo;
    int horasTrabajadas;
    char nombre[128];
    Employee* auxEmp;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        FILE* f = fopen(path, "w");
        if(f == NULL)
        {
            perror("Error: ");
        }
        else
        {
            for (int i=0; i<ll_len(pArrayListEmployee) ; i++ )
            {

                auxEmp = (Employee*)ll_get(pArrayListEmployee,i);

                employee_getId(auxEmp,&id);
                employee_getHorasTrabajadas(auxEmp,&horasTrabajadas);
                employee_getNombre(auxEmp,nombre);
                employee_getSueldo(auxEmp,&sueldo);

                fprintf(f, "%d, %s, %d, %d \n", id, nombre,horasTrabajadas, sueldo);
            }
        }
        fclose(f);
        retorno = 1;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{

    int retorno = 0;
    int id;
    int sueldo;
    int horasTrabajadas;
    char nombre[128];
    Employee* auxEmp;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        FILE* f = fopen(path, "wb");
        if(f == NULL)
        {
            perror("Error: ");
        }
        else
        {
            for (int i=0; i<ll_len(pArrayListEmployee) ; i++ )
            {

                auxEmp = (Employee*)ll_get(pArrayListEmployee,i);

                employee_getId(auxEmp,&id);
                employee_getHorasTrabajadas(auxEmp,&horasTrabajadas);
                employee_getNombre(auxEmp,nombre);
                employee_getSueldo(auxEmp,&sueldo);

                fwrite(auxEmp,sizeof(Employee),1,f);
            }
        }
        fclose(f);
        retorno = 1;
    }
    return retorno;


}

