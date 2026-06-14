#include "ADT_AB.h"

bool estaLleno(AB arbol1);
void preOrden(AB T1);

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
    printf("Uso la operacion RAIZ en 'T1' para mostrar el item: %c\n", RAIZ(T1));
    puts("Defino dos arboles AB, uno llamado 'I' con el item llamado B y otro como AB vacio.\nTambien defino un nuevo itemAB 'r' con el valor 'a'");
    AB I = ARMARAB(ABVACIO(), 'B', ABVACIO());
    AB D = ABVACIO();
    itemAB r = 'a';
    puts("Agrego ambos arboles y el item 'a' al AB 'T1'");
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
    printf("Uso la operacion RAIZ en 'T1' para mostrar el item: %c\n", RAIZ(T1));
    puts("Es IZQUIERDO de 'T1' arbol vacio?");
    if (ESABVACIO(IZQUIERDO(T1)))
    {
        puts("Si.");
    }
    else
    {
        puts("No.");
    }
    puts("Es DERECHO de 'T1' arbol vacio?");
    if (ESABVACIO(DERECHO(T1)))
    {
        puts("Si.");
    }
    else
    {
        puts("No.");
    }
    puts("Uso la funcion 'estaLleno' en con el 'T1'");
    puts("Es 'T1' un arbol binario lleno?");
    if (estaLleno(T1))
    {
        puts("Si.");
    }else
    {
        puts("No.");
    }
    puts("Defino un nuevo arbol binario llamado 'T2'");
    AB T2;
    T2 = ABVACIO();
    puts("Agrego a IZQUIERDO de 'T2' un arbol binario no vacio, a DERECHO de 'T2' un arbol binario no vacio y un item '*'");
    T2 = ARMARAB(ARMARAB(ABVACIO(), '1', ABVACIO()), '*', ARMARAB(ABVACIO(), '2', ABVACIO()));
    puts("Es 'T2' un arbol binario lleno?");
    if (estaLleno(T2))
    {
        puts("Si.");
    }else
    {
        puts("No.");
    }
    puts("Uso la operacion 'IGUALES' con los arboles 'T1' y 'T2'");
    puts("Los arboles 'T1' y 'T2' son iguales?");
    if (IGUALES(T1, T2))
    {
        puts("Si.");
    }else
    {
        puts("No.");
    }
    puts("Defino un nuevo arbol llamado 'T3' (igual a 'T1')");
    AB T3 = ABVACIO();
    T3 = T1 = ARMARAB(I, r, D);
    puts("Uso la operacion 'IGUALES' con los arboles 'T1' y 'T3'");
    puts("Los arboles 'T1' y 'T3' son iguales?");
    if (IGUALES(T1, T3))
    {
        puts("Si.");
    }else
    {
        puts("No.");
    }
    puts("Uso la operacion 'ALTURA'");
    printf("La altura del arbol 'T1' es: %d\n", ALTURA(T1));
    printf("La altura del arbol 'T2' es: %d\n", ALTURA(T2));
    puts("Defino un nuevo arbol 'T3'.");
    puts("'AB T4 = ARMARAB(ARMARAB(ABVACIO(), '1', ABVACIO()), '*', ARMARAB(ABVACIO(), '2', ARMARAB(ABVACIO(), '3', ABVACIO())))'");
    AB T4 = ARMARAB(ARMARAB(ABVACIO(), '1', ABVACIO()), '*', ARMARAB(ABVACIO(), '2', ARMARAB(ABVACIO(), '3', ABVACIO())));
    printf("La altura del arbol 'T4' es: %d\n", ALTURA(T4));

    puts("\nPresione la tecla enter para finalizar.");
    fflush(stdin);
    getchar();
    return 0;
}

//2 funcion recursiva como usuario 'estaLleno'
bool estaLleno(AB arbol1){
    if (ESABVACIO(arbol1) || (ESABVACIO(IZQUIERDO(arbol1)) && ESABVACIO(DERECHO(arbol1))))
    {
        return true;
    }
    else
    {
        if (!ESABVACIO(IZQUIERDO(arbol1)) && !ESABVACIO(DERECHO(arbol1)))
        {
            return estaLleno(IZQUIERDO(arbol1)) && estaLleno(DERECHO(arbol1));
        }
        else
        {
            return false;
        }
    }
}

void preOrden(AB T1){
    if (!ESABVACIO(T1))
    {
        printf("%c", RAIZ(T1));
        preOrden(IZQUIERDO(T1));
        preOrden(DERECHO(T1));
    }
}