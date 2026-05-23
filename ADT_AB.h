#include <stdio.h>
#include <stdlib.h>

typedef char itemAB;

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