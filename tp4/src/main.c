/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "../testing/inc/Employee.h"




int main(void)
{
    LinkedList* listaEmpleados = ll_newLinkedList();// creo una lista de empleados
    LinkedList* listaAuxiliar = ll_newLinkedList();

    Employee* emp1 = (Employee*)newEmployee(1, "juan", "perez", 2009, 1);
    Employee* emp2 = (Employee*)newEmployee(2, "tomas", "gonzalez", 4000, 3);
    Employee* emp3 = (Employee*)newEmployee(3, "jorge", "rodriguez", 6000, 4);
    Employee* emp4 = (Employee*)newEmployee(4, "ana", "gomez", 5000, 7);// creo punteros a empleado
    Employee* emp5 = (Employee*)newEmployee(5, "maria", "poloso", 7000, 5);
    Employee* emp6 = (Employee*)newEmployee(6, "pablo", "itrira", 1000, 4);

    ll_add(listaEmpleados, emp1);
    ll_add(listaEmpleados, emp2);
    ll_add(listaEmpleados, emp3);
    ll_add(listaEmpleados, emp4);
    ll_add(listaEmpleados, emp5);
    ll_add(listaEmpleados, emp6);// agrego los empleados

    printf("Listado de todos los empleados\n");
    for (int i=0; i<ll_len(listaEmpleados) ; i++ )    // rescato el largo de la lista con ll_len
    {
        printEmployee(ll_get(listaEmpleados,i));// rescato los datos de cada empleado

    }
    printf("\n");
    printf("\nModifico la cuarta posicion de la lista:\n ");
    ll_set(listaEmpleados,3, (Employee*)newEmployee(5, "isabel", "belaustegui", 5000, 9));// modifico una posicion de la lista
    for (int i=0; i<ll_len(listaEmpleados)  ; i++ )
    {
        printEmployee(ll_get(listaEmpleados,i));
    }

    printf("\nElimino la tercera posicion de la lista:\n ");
    ll_remove(listaEmpleados,2); //elimino un empleado en el indice especificado
    for (int i=0; i<ll_len(listaEmpleados)  ; i++ )
    {
        printEmployee(ll_get(listaEmpleados,i));
    }

    printf("\nLa posicion del empleado 1 es: %d\n", ll_indexOf(listaEmpleados,emp1));// rescato la posicion de un empleado

    if(!ll_isEmpty(listaEmpleados))  // verifico si la lista esta vacia o no
    {
        printf("\nLa lista tiene elementos.\n\n");
    }
    printf("Agrego un empleado en la posicion 3: \n");
    ll_push(listaEmpleados,2,newEmployee(10, "Carlos", "Solari", 1000, 12));// agrego un empleado en un indice especifico
    for (int i=0; i<ll_len(listaEmpleados)  ; i++ )
    {
        printEmployee(ll_get(listaEmpleados,i));
    }
    printf("\nElimino el empleado de la posicion 2\n");
    ll_pop(listaEmpleados,1);// elimino un empleado en el indice especifaco
    for (int i=0; i<ll_len(listaEmpleados)  ; i++ )
    {
        printEmployee(ll_get(listaEmpleados,i));
    }
    if(ll_contains(listaEmpleados,emp3)) // busco un empleado en la lista
    {
        printf("\nEl empleado %s se encuentra en la lista\n", emp3->name);
    }
    else
    {
        printf("\nEl empleado %s no se encuentra en la lista\n", emp3->name);

    }
    printf("\nHago una sublista con los dos primeros empleados:\n");
    listaAuxiliar = ll_subList(listaEmpleados,0,2);
    for (int i=0; i<ll_len(listaAuxiliar) ; i++ )
    {
        printEmployee(ll_get(listaAuxiliar,i));
    }

    ll_add(listaAuxiliar, newEmployee(12,"Ricardo","Perez", 1000,12));
    if(ll_containsAll(listaEmpleados, listaAuxiliar))
    {
        printf("\nAmbas listas tienen los mismos elementos");
    }
    else
    {
        printf("\nLas listas no contienen los mismos elementos\n");
    }

    printf("\nClono la primer lista en la segunda: \n");
    listaAuxiliar = ll_clone(listaEmpleados);// clono la lista
    for (int i=0; i<ll_len(listaAuxiliar) ; i++ )
    {
        printEmployee(ll_get(listaAuxiliar,i));
    }

    printf("\nOrdeno los empleados por salario:\n");
    ll_sort(listaEmpleados,compareEmployee,0);
    for (int i=0; i<ll_len(listaEmpleados) ; i++ )
    {
        printEmployee(ll_get(listaEmpleados,i));
    }


    if(!ll_clear(listaEmpleados)){// elimino todos los empleados
        printf("\nLos empleados han sido eliminados\n");
    }
    if(!ll_deleteLinkedList(listaEmpleados)){//elimino a los empleados y al linkedlist
        printf("Los empleados y la lista han sido eliminados\n\n");

    }



//     startTesting(1);  // ll_newLinkedList
//     startTesting(2);  // ll_len
//    startTesting(3);  // getNode - test_getNode
//        startTesting(4);  // addNode - test_addNode
//        startTesting(5);  // ll_add
//       startTesting(6);  // ll_get
//        startTesting(7);  // ll_set
//        startTesting(8);  // ll_remove
//        startTesting(9);  // ll_clear
//        startTesting(10); // ll_deleteLinkedList
//        startTesting(11); // ll_indexOf
//        startTesting(12); // ll_isEmpty
//        startTesting(13); // ll_push
//       startTesting(14); // ll_pop
//       startTesting(15); // ll_contains
//    startTesting(16); // ll_containsAll
//        startTesting(17); // ll_subList
//        startTesting(18); // ll_clone
//        startTesting(19); // ll_sort

    return 0;
}

































