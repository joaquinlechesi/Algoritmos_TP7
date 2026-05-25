#include "ADT_AB.h"

int main()
{
    puts("ADT AB");
    puts("Defino un nuevo arbol binario vacio 'T1'");
    AB T1;
    T1 = ABVACIO();
    puts("Es 'T1' arbol vacio?");
    if (ESABVACIO(T1))
    {
        puts("Si.");
    }
    else
    {
        puts("No.");
    }
    puts("Defino dos arboles AB, uno llamado 'I' y otro llamado 'D'. Tambien defino un nuevo itemAB 'r' con el valor 'a'");
    AB I = ABVACIO();
    AB D = ABVACIO();
    itemAB r = 'a';
    puts("Agrego ambos arboles y el item a 'T1'");
    puts("'T1 = ARMARAB(I, r, D)'");
    T1 = ARMARAB(I, r, D);
    puts("Es 'T1' arbol vacio?");
    if (ESABVACIO(T1))
    {
        puts("Si.");
    }
    else
    {
        puts("No.");
    }
    
    puts("\nPresione la tecla enter para finalizar.");
    fflush(stdin);
    getchar();
    return 0;
}
