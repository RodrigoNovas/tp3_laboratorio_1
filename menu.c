#include "menu.h"
int showMenuEdit()
{
    int r;

    do
    {
        system("cls");
        printf("***********************************\n");
        printf("     Seleccione un campo a editar: \n");
        printf("     1. Nombre.                    \n");
        printf("     2. Horas Trabajadas.          \n");
        printf("     3. Sueldo                     \n");
        printf("***********************************\n");
        scanf("%d", &r);
    }
    while(r < 1 || r > 3);

    return r;
}
