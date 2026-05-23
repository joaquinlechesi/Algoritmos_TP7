#include <stdio.h>
#include <stdlib.h>

typedef char itemAB;
const itemAB indefinido = '@';

struct nodoAB{
    itemAB raiz;
    struct nodoAB *izq;
    struct nodoAB *der;
};

typedef struct nodoAB *AB;

AB ABVACIO(){
    return NULL;
}

AB ARMARAB(AB I, itemAB r, AB D){
    AB nuevoArbol = new(nodoAB);
    nuevoArbol->raiz = r;
    nuevoArbol->izq = I;
    nuevoArbol->der = D;
    return nuevoArbol;
}

bool ESABVACIO(AB T){
    return T == NULL;
}

bool PERTENECE(AB T, itemAB x){
    if (ESABVACIO(T))
    {
        return false;
    }
    else
    {
        if (T->raiz == x)
        {
            return true;
        }
        else
        {
            return PERTENECE(T->izq, x) || PERTENECE(T->der, x);
        }
    }
}

AB IZQUIERDO(AB T){
    return T->izq;
}

itemAB RAIZ(AB T){
    if (T == NULL)
    {
        return T->raiz;
    }
    else
    {
        return indefinido;
    }
}

AB DERECHO(AB T){
    return T->der;
}