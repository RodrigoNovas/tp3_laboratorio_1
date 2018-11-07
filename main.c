#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

int main()
{   int r;
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
     do
    {
        system("cls");
        printf("************************************************************************************\n");
        printf("     Menu:                                                                          \n");
        printf("     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).   \n");
        printf("     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario). \n");
        printf("     3. Alta de empleado                                                            \n");
        printf("     4. Modificar datos de empleado                                                 \n");
        printf("     5. Baja de empleado                                                            \n");
        printf("     6. Listar empleados                                                            \n");
        printf("     7. Ordenar empleados                                                           \n");
        printf("     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).     \n");
        printf("     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).   \n");
        printf("    10. Salir                                                                       \n");
        printf("************************************************************************************\n");
        scanf("%d", &r);
        option = r;
        switch(option)
        {
        case 1:
            controller_loadFromText("data.csv",listaEmpleados);
            break;
        case 2:
            controller_loadFromBinary("data.bin", listaEmpleados);
            break;
        case 3:
            controller_addEmployee(listaEmpleados);
            break;
        case 4:
           controller_editEmployee(listaEmpleados);
            break;
        case 5:
            controller_removeEmployee(listaEmpleados);
            break;
        case 6:
            controller_ListEmployee(listaEmpleados);
            break;
        case 7:
            controller_sortEmployee(listaEmpleados);
            break;
        case 8:
            controller_saveAsText("data.csv", listaEmpleados);
            break;
        case 9:
            controller_saveAsBinary("data.bin", listaEmpleados);
            break;
        case 10:
            ll_deleteLinkedList(listaEmpleados);
            exit(1);
            break;
        default:
            break;
        }

        if(option < 10)
        {
            system("pause");
        }
    }
    while(r!=10);
    return 0;
}

