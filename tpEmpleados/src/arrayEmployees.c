#include "arrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesVarias.h"

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len)
{
int retorno = -1;
if(list != NULL && len > 0){
 for(int i=0; i<len; i++){
	list[i].isEmpty = 1;
	retorno  = 0;
 }

}
return retorno;
}

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int*
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/

int addEmployee(Employee* list, int len, int* id)
{

Employee auxEmployee;
int retorno = -1;
int posicionLibre = findFreePosition(list, len);

if(list != NULL && len >0){
	if(posicionLibre != -1){

 printf("Ingresa el nombre: ");
 fflush(stdin);
 fgets(auxEmployee.name, sizeof(auxEmployee.name), stdin);
 auxEmployee.name[strcspn(auxEmployee.name, "\n")] = '\0';

 printf("Ingresa el apellido: ");
 fflush(stdin);
 fgets(auxEmployee.lastName, sizeof(auxEmployee.lastName), stdin);
 auxEmployee.lastName[strcspn(auxEmployee.lastName, "\n")] = '\0';

 validateSalary(&auxEmployee.salary);

 validateSector(&auxEmployee.sector);


 auxEmployee.id = *id;
 (*id)++;

 auxEmployee.isEmpty = 0;
 list[posicionLibre] = auxEmployee;

}else{

	printf("No hay lugares disponibles. ");
}
retorno = 0;

}

return retorno;
}


/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id)
{
	if(list != NULL && len > 0){

		  for (int i=0; i<len ; i++ ){
			  if(list[i].id == id){
				  return i;
		}
	  }
	}

return -1;

}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id)
{
	int retorno = -1;
	if(list != NULL && len > 0){

		  for (int i=0; i<len ; i++ ){
			  if(list[i].id == id){
				  list[i].isEmpty = 1;
				  retorno = 0;
		}
	  }
	}

return retorno;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int length, int order)
{
	  int retorno = -1;
	  Employee auxEmpleado;

	 for (int i=0; i<length-1 ; i++ )
		        {
		            if(!list[i].isEmpty)
		            {
		                for (int j=i+1; j<length ; j++ )
		                {
		                	if(order == 1){
		                    if(list[i].sector > list[j].sector || (list[i].sector == list[j].sector &&
		                    									  (strcmp(list[i].lastName, list[j].lastName) > 0)))
		                    {
		                        auxEmpleado= list[i];
		                        list[i] = list[j];
		                        list[j] = auxEmpleado;
		                    }
		                }else{
		                    if(list[i].sector < list[j].sector || (list[i].sector == list[j].sector &&
		                    									  (strcmp(list[i].lastName, list[j].lastName) > 0)))
		                    {
		                        auxEmpleado= list[i];
		                        list[i] = list[j];
		                        list[j] = auxEmpleado;
		                    }

		                }
		                }
		            }
	            	retorno = 0;
		        }
	            printf("LISTADO DE EMPLEADOS ORDENADOS POR APELLIDO Y SECTOR: \n");
		        printEmployees(list, length);

return retorno;
}

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee list[], int length)
{
	int flag = 1;
	int retorno = 0;
	if(list != NULL && length > 0){
    printf("Id     Nombre     Apellido    Sueldo    Sector");
    for (int i = 0; i < length; i++) {
      if(!list[i].isEmpty){
    	  printEmployee(list[i]);
    	  flag = 0;
      }
	}

    if(flag){

	printf("\nNo hay empleados que mostrar.\n");

    }
    	retorno = 1;
	}
return retorno;
}
/** \brief print the content of a single employee
*    \param Employee
*
*/
void printEmployee(Employee empleado){


    printf("\n%d   %-10s   %-10s   %.2f   %d  ", empleado.id,empleado.name,empleado.lastName,empleado.salary,empleado.sector);

}
/** \brief allows the user to choose between two options: sort the array and print salaries average
*
* \param list Employee*
* \param length int
* \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
*
*/
int inform(Employee list[], int length){

	  int opcion;
	  int retorno = 0;
	  int order;
	  int empleados = 0;
	  float promedio;
	  int empleadosMayorAPromedio = 0;
	  float totalSalarios = 0;
	  int flag = 0;

	  if(list != NULL && length > 0){

	  printf("1) LISTA EMPLEADOS ORDENADOS POR SECTOR Y APELLIDO\n2) TOTAL Y PROMEDIO DE LOS SALARIOS.\n");
	  printf("\nElije la opcion deseada: ");
	  scanf("%d",&opcion);

	  while(opcion != 1 && opcion !=2){
		  printf("La opcion debe ser 1 o 2. Intenta nuevamente: ");
		  scanf("%d",&opcion);
	  }

	  if(opcion == 1){
		   printf("Inresa el orden: 1(ascendente) / 0(descendente)\n ");
		   scanf("%d", &order);
	       if(sortEmployees(list, length, order) == 0){
	    	   retorno = 1;
	       }
	    }

	  else{
	       for (int i=0; i<length ; i++ ){
	         if(!list[i].isEmpty){
	    	   totalSalarios += list[i].salary;
	    	   empleados++;
	    	   flag = 1;
	         }
            if(i == length-1){
		    promedio = totalSalarios/empleados;
	        }
	       }

	       for (int i=0; i<length ; i++ ){
	    	  if(list[i].salary > promedio && !list[i].isEmpty){
	    		  empleadosMayorAPromedio++;
	    	  }
	       }

	       if(flag){
	       printf("El total de los salarios es: %.2f $", totalSalarios);
	       printf("\nEl promedio de los salarios es: %.2f $", promedio);
	       printf("\nLa cantidad de empleados con sueldos mayor al promedio es: %d  \n", empleadosMayorAPromedio);
	       }else{
	    	   printf("No hay empleados que mostrar.\n");
	       }
	       retorno = 1;
	  }
}

	  return retorno;
}
/** \brief delete the employee chosen by the user
*
* \param list Employee*
* \param length int
* \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
*
*/
int deleteEmployee(Employee* list, int len){

	int retorno = 0;
	int idEmpleado;
	if(list != NULL && len > 0){
		printf("Ingresa id del empleado: ");
		scanf("%d", &idEmpleado);

		while(findEmployeeById(list, len, idEmpleado) == -1){
			printf("Ingresa un id valido: ");
			scanf("%d", &idEmpleado);
		}

		if(removeEmployee(list, len, idEmpleado) == 0){

			retorno = 1;
		}

	}

	return retorno;

}
/** \brief allows the user to modify any aspect of the employee except for the id
*
* \param list Employee*
* \param length int
* \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
*
*/
int modifyEmployee(Employee* list, int len){

	int retorno = 0;
	int idEmpleado;
    char respuesta;
    Employee empleado;
    int indiceEmpleado;

	if(list != NULL && len >0){

        printf("Empleados disponibles: \n\n");

        printEmployees(list, len);

		printf("\n\nIngresa id del empleado que deseas modficar: ");
		scanf("%d", &idEmpleado);
		indiceEmpleado = findEmployeeById(list, len, idEmpleado);
		if(!empleado.isEmpty){

			printf("Este empleado no esta activo.\n");
		}

		while(indiceEmpleado == -1){
			printf("Ingresa un id valido: ");
			scanf("%d", &idEmpleado);
		}
		empleado = list[indiceEmpleado];


        printf("\nSeguro que deseas modificarlo? Presiona s para Si o n para No  ");
        fflush(stdin);
        scanf("%c", &respuesta);

        if(respuesta == 's')
        {
            do
            {
                switch (menuModify(empleado))
                {
                case 1:
                    printf("Nombre actual: %s\n", empleado.name);
                    printf("Nuevo nombre: ");
                    fflush(stdin);
                    fgets(empleado.name, sizeof(empleado.name), stdin);
                    empleado.name[strcspn(empleado.name, "\n")] = '\0';
                    strcpy(list[indiceEmpleado].name, empleado.name);
                    break;
                case 2:
                    printf("Apellido actual: %s\n", empleado.lastName);
                    printf("Nueva apellido: ");
                    fflush(stdin);
                    fgets(empleado.lastName, sizeof(empleado.lastName), stdin);
                    empleado.lastName[strcspn(empleado.lastName, "\n")] = '\0';
                    strcpy(list[indiceEmpleado].lastName, empleado.lastName);
                    break;
                case 3:
                    printf("Sector actual: %d\n", empleado.sector);
                    validateSector(&empleado.sector);
				    list[indiceEmpleado].sector =  empleado.sector;
                    break;
                case 4:
                    printf("Salario actual: %f\n", empleado.salary);
                    validateSalary(&empleado.salary);
                    list[indiceEmpleado].salary=  empleado.salary;
                    break;
                case 5:
                {
                    printf("Seguro que deseas salir? s/n \n");
                    fflush(stdin);
                    respuesta = getchar();
                }
                while (respuesta != 's' && respuesta != 'n' );
                break;
                }
                system("pause");
                retorno = 1;

            }
            while (respuesta != 's');
        }
	}


	return retorno;
}
/** \brief finds and returns the first free position in the array
*
* \param list Employee*
* \param length int
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (free position) if Ok
*
*/
int findFreePosition(Employee list[], int length){

int retorno = -1;
if(list != NULL && length > 0){
  for(int i=0;i<length;i++){
	  if(list[i].isEmpty){
		  retorno = i;
		  break;
	  }
  }

}
return retorno;
}


