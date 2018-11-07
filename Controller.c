#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "Employee.h"
#include "menu.h"
#include "Controller.h"
#define FLAGMAC 1
#define FLAGERR 0


//cargar desde texto
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int r = FLAGERR;
    FILE* pFile = fopen(path, "r");

    if(pFile == NULL)
    {
        printf("El archivo a cargar es inexistente ingrese un archivo.");
    }
    else
    {

        r = parser_EmployeeFromText(pFile, pArrayListEmployee);
    }

    return r;
}

//cargar binario
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int r = FLAGERR;
    FILE* pFile = fopen(path, "rb");

    if(pFile == NULL)
    {
        printf("El archivo no existe.");
    }
    else
    {

        r = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
    }

    return r;
}

//carga empleados
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* e = employee_new();
    int id;
    char nombre[20];
    int horasTrabajadas;
    int sueldo;
    int r = FLAGERR;

    if(pArrayListEmployee == NULL)
    {
        printf("No hay datos en la lista.\n");
    }
    else
    {
        printf("Ingrese un ID \n");
        scanf("%d", &id);
        r = employee_setId(e,id);

        printf("Ingrese un Nombre \n");
        scanf("%s", nombre);
        r = employee_setNombre(e,nombre);

        printf("Ingrese Horas Trabajadas \n");
        scanf("%d", &horasTrabajadas);
        r = employee_setHorasTrabajadas(e, horasTrabajadas);

        printf("Ingrese un Sueldo \n");
        scanf("%d", &sueldo);
        r = employee_setSueldo(e, sueldo);

        r = ll_add(pArrayListEmployee, e);
    }

    return r;
}

//Edicion empleados
int controller_editEmployee(LinkedList* pArrayListEmployee)
{   int i;
    int r = FLAGERR;
    int idEmployee = 0;
    int idEmployeeEdit = 0;
    Employee* aux = employee_new();
    char name[20];
    int ht = 0;
    int sueldo = 0;

    if(pArrayListEmployee != NULL)
    {
        printf("Ingrese un ID\n");
        scanf("%d", &idEmployeeEdit);

        for( i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            aux = (Employee*) ll_get(pArrayListEmployee, i);

            r = employee_getId(aux, &idEmployee);

            if(r == FLAGMAC)
            {
                if(idEmployee == idEmployeeEdit)
                {
                    switch(mostrarMenuEdit())
                    {
                    case 1:

                        printf("Ingrese un nombre.\n");
                        scanf("%s", name);
                        strcpy(aux->nombre, name);
                        break;
                    case 2:

                        do
                        {
                            printf("Ingrese Horas Trabajadas\n");
                            scanf("%d", &ht);
                            aux->horasTrabajadas = ht;
                        }
                        while(ht < 0);
                        break;
                    case 3:

                        do
                        {
                            printf("Ingrese Sueldo\n");
                            scanf("%d", &sueldo);
                            aux->sueldo = sueldo;
                        }
                        while(sueldo < 0);
                        break;
                    default:
                        break;
                    }
                    r = ll_set(pArrayListEmployee, i, aux);
                    break;
                }
            }
        }
    }
    else
    {
        printf("No hay datos en la lista.\n");
    }

    return 1;
}

//Baja de empleados
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int r = FLAGERR;
    int idEmployee;
    int idEmployeeRemove;
    int i;
    Employee* aux = employee_new();

    if(pArrayListEmployee != NULL)
    {
        printf("Ingrese un ID\n");
        scanf("%d", &idEmployeeRemove);

        for(i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            aux = (Employee*) ll_get(pArrayListEmployee, i);

            r = employee_getId(aux, &idEmployee);

            if(r == FLAGMAC)
            {
                if(idEmployee == idEmployeeRemove)
                {
                    r = ll_remove(pArrayListEmployee, i);
                    break;
                }
            }
        }
    }
    else
    {
        printf("No hay datos en la lista.\n");
    }

    return r;
}

//listar empleados
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{   int i;
    int control = 0;
    int r = FLAGERR;
    Employee* emp = employee_new();
    int l = ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL)
    {
        printf("TENGA EN CUENTA QUE LA LISTA SE DETENDRA EN EL ID 273 PARA VER LOS IDS POSTERIORES PRESIONAR ENTER LUEGO DE LISTARLOS\n\n");
        printf("ID    Nombre        Hs Trab.  Sueldo\n");
        for( i = 0; i < l; i++)
        {
            emp = (Employee*) ll_get(pArrayListEmployee, i);
            employee_show(emp);
            control=control + 1;
           if(control== 271){
            system("pause");
           }
        }
    }

    else
    {
        printf("No hay datos en la lista.\n");
    }


    return r;
}

//ordenar empleados
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{


    if(pArrayListEmployee == NULL)
    {
        printf("No hay datos en la lista.\n");
    }
    else
    {

    }

    return 1;
}

//Guarda los datos modo texto
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{   int i;
    int r = FLAGERR;
    //int lon = 0;
    //int qty = 0;

    FILE *pFile = fopen(path,"w");

    if(pArrayListEmployee == NULL)
    {
        printf("No hay datos en la lista.\n");
    }
    else
    {
        Employee* pEmployee = employee_new();
        if(pFile==NULL)
        {
            printf("Archivo inexistente\n");
        }
        else
        {
            //lon = ll_len(pArrayListEmployee);
            for( i = 0; i < ll_len(pArrayListEmployee); i++)
            {
                pEmployee = (Employee*) ll_get(pArrayListEmployee, i);

                //if(r == FLAGMAC)
                //{

                fprintf(pFile, "%d,%s, %d, %d\n", pEmployee->id, pEmployee->nombre, pEmployee->horasTrabajadas, pEmployee->sueldo);

                /*if(qty < strlen((char*)pEmployee))
                {
                    printf("\nError al escribir el archivo");
                }*/
            }
            r = FLAGMAC;
            fclose(pFile);
        }
    }

    return r;
}

//Guardar datos modo binario
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{   int i;
    int r = FLAGERR;
    //int lon = 0;
    int qty = 0;

    FILE *pFile = fopen(path,"wb");

    if(pArrayListEmployee == NULL)
    {
        printf("No hay datos en la lista.\n");
    }
    else
    {
        Employee* pEmployee = employee_new();
        if(pFile==NULL)
        {
            printf("Archivo inexistente\n");
        }
        else
        {
            //lon = ll_len(pArrayListEmployee);
            for( i = 0; i < ll_len(pArrayListEmployee); i++)
            {
                pEmployee = (Employee*) ll_get(pArrayListEmployee, i);

                //if(r == FLAGMAC)
                //{
                qty=fwrite (pEmployee, sizeof(Employee), 1/*strlen((char*)pEmployee)*/, pFile );    //Se escribe al archivo
                //}
                if(qty < strlen((char*)pEmployee))
                {
                    printf("\nError al escribir el archivo");
                }
            }
            r = FLAGMAC;
            fclose(pFile);
        }
    }

    return r;
}

