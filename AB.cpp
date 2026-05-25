#include "ADT_AB.h"

int main()
{
    puts("ADT AB");
    puts("Defino un nuevo arbol binario 'T1'");
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
    
    
    puts("Presione la tecla enter para finalizar.");
    fflush(stdin);
    getchar();
    return 0;
}
