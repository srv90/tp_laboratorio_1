#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"


/****************************************************
    Menu:
/////1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
/////2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
/////3. Alta de empleado
/////4. Modificar datos de empleado
/////5. Baja de empleado
/////6. Listar empleados
/////7. Ordenar empleados
/////8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
/////10. Salir
*****************************************************/

int main()
{
    setbuf(stdout, NULL);

    char respuesta;
    int id = 1001;
    int flag =0;


    LinkedList* listaEmpleados = ll_newLinkedList();


    if(listaEmpleados == NULL)
    {
        printf("No se pudo crear la lista");
    }

    do
    {

        switch(menu())
        {
        case 1:
            system("cls");

            if(!flag)
            {
                if(controller_loadFromText("data.csv",listaEmpleados))
                {
                    printf("Listado cargado con exito.\n");
                    flag = 1;
                }
                else
                {
                    printf("Ocurrio un error.\n");
                }
            }
            else if(flag)
            {
                printf("Deseas sobreescribir el listado actual? Presiona 'y' para confirmar o cualquier tecla para salir.\n");
                fflush(stdin);
                scanf("%c", &respuesta);
                if(respuesta == 'y')
                {

                    ll_clear(listaEmpleados);

                    if(controller_loadFromText("data.csv",listaEmpleados))
                    {
                        printf("Listado cargado con exito.\n");
                        flag = 1;
                    }
                    else
                    {
                        printf("Ocurrio un error.\n");
                    }
                }
            }
            break;
        case 2:
            system("cls");

            if(!flag)
            {
                if(controller_loadFromBinary("data.bin",listaEmpleados))
                {
                    printf("Listado cargado con exito.\n");
                    flag =1;
                }
                else
                {
                    printf("Ocurrio un error.\n");
                }
            }
            else if(flag)
            {
                printf("Deseas sobreescribir el listado actual? Presiona 'y' para confirmar o cualquier tecla para salir.\n");
                fflush(stdin);
                scanf("%c", &respuesta);
                if(respuesta == 'y')
                {
                    ll_clear(listaEmpleados);
                    if(controller_loadFromBinary("data.bin",listaEmpleados))
                    {
                        printf("Listado cargado con exito.\n");
                    }
                    else
                    {
                        printf("Ocurrio un error.\n");
                    }

                }
                else break;
            }
            break;
        case 3:
            system("cls");
            if(!controller_addEmployee(listaEmpleados,&id))
            {
                printf("Ocurrio un error\n");
            };
            break;
        case 4:
            system("cls");
            if(ll_isEmpty(listaEmpleados)== 0)
            {
                if(!controller_editEmployee(listaEmpleados))
                {
                    printf("Ocurrio un error\n");
                }
            }
            else if(ll_isEmpty(listaEmpleados) == 1)
            {
                printf("La lista se encuentra vacia\n");
            }
            else
            {
                printf("Ocurrio un error.\n");
            }
            break;
        case 5:
            system("cls");
            if(ll_isEmpty(listaEmpleados)== 0)
            {
                if(!controller_removeEmployee(listaEmpleados))
                {
                    printf("Ocurrio un error.\n");
                }
            }
            else if(ll_isEmpty(listaEmpleados) == 1)
            {
                printf("La lista se encuentra vacia\n");
            }
            else
            {
                printf("Ocurrio un error.\n");
            }
            break;
        case 6:
            system("cls");
            if(ll_isEmpty(listaEmpleados)== 0)
            {
                if(!controller_ListEmployee(listaEmpleados))
                {
                    printf("Ocurrio un error");
                }
            }
            else if(ll_isEmpty(listaEmpleados) == 1)
            {
                printf("La lista se encuentra vacia\n");
            }
            else
            {
                printf("Ocurrio un error\n");
            }
            break;
        case 7:
            system("cls");
            if(ll_isEmpty(listaEmpleados)== 0)
            {
                if(!controller_sortEmployee(listaEmpleados))
                {
                    printf("Ocurrio un error");
                }
                else printf("\nEl listado ha sido ordenado por nombre.\n");
            }
            else if(ll_isEmpty(listaEmpleados) == 1)
            {
                printf("La lista se encuentra vacia\n");
            }
            else
            {
                printf("Ocurrio un error\n");
            }
            break;
        case 8:
            system("cls");
            if(controller_saveAsText("data.csv",listaEmpleados))
            {
                printf("Listado guardado con exito.\n");
            }
            else
            {
                printf("Ocurrio un error\n");
            }
            break;
        case 9:
            system("cls");
            if(controller_saveAsBinary("data.bin",listaEmpleados))
            {
                printf("Listado guardado con exito.\n");
            }
            else
            {
                printf("Ocurrio un error\n");
            }
            break;

        case 10:
            printf("\nSeguro que deseas salir? s/n \n");
            fflush(stdin);
            respuesta = getchar();
            while (respuesta != 's' && respuesta != 'n')
            {
                printf("\nIngresa s o n \n");
                respuesta = getchar();
            }
            break;
        }
        system("pause");
        system("cls");

    }
    while (respuesta != 's' );
    return 0;


}
