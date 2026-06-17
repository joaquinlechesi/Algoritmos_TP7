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
    if (T != NULL)
    {
        return T->izq;
    }
    else
    {
        return NULL;
    }
}

itemAB RAIZ(AB T){
    if (T != NULL)
    {
        return T->raiz;
    }
    else
    {
        return indefinido;
    }
}

AB DERECHO(AB T){
    if (T != NULL)
    {
        return T->der;
    }
    else
    {
        return NULL;
    }
}

bool IGUALES(AB arbol1, AB arbol2){
    if (ESABVACIO(arbol1) && ESABVACIO(arbol2))
    {
        return true;
    }
    else
    {
        if (!ESABVACIO(arbol1) && !ESABVACIO(arbol2))
        {
            return RAIZ(arbol1) == RAIZ(arbol2) && IGUALES(IZQUIERDO(arbol1), IZQUIERDO(arbol2)) && IGUALES(DERECHO(arbol1), DERECHO(arbol2));
        }
        else
        {
            return false;
        }
        
    }
    
}

AB PODARHOJAS(AB arblol1){
    if (ESABVACIO(arblol1))
    {
        return ABVACIO();
    }
    else
    {
        if (ESABVACIO(IZQUIERDO(arblol1)) && ESABVACIO(DERECHO(arblol1)))
        {
            liberarAB(arblol1);
            return ABVACIO();
        }
        else
        {
            return ARMARAB(PODARHOJAS(IZQUIERDO(arblol1)), RAIZ(arblol1), PODARHOJAS(DERECHO(arblol1)));
        }
    }
}

int ALTURA(AB arbol1){
    if (ESABVACIO(arbol1))
    {
        return 0;
    }
    else
    {
        if (!ESABVACIO(IZQUIERDO(arbol1)) || !ESABVACIO(DERECHO(arbol1)))
        {
            int maximo, a, b;
            a = 1 + ALTURA(IZQUIERDO(arbol1));
            b = 1 + ALTURA(DERECHO(arbol1));
            if (a >= b)
            {
                maximo = a;
            }
            else
            {
                maximo = b;
            }
            return maximo;
        }
        else
        {
            return 1;
        }
        
    }
    
}

bool ESBALANCEADO(AB arbol1){
    if (ESABVACIO(arbol1))
    {
        return true;
    }
    else
    {
        if (-1 <= (ALTURA(IZQUIERDO(arbol1)) - ALTURA(DERECHO(arbol1))) && (ALTURA(IZQUIERDO(arbol1)) - ALTURA(DERECHO(arbol1))) <= 1)
        {
            return ESBALANCEADO(IZQUIERDO(arbol1)) && ESBALANCEADO(DERECHO(arbol1));
        }
        else
        {
            return false;
        }
        
    }
}

//EXTRA
void liberarAB(AB T1){
    if (!ESABVACIO(T1))
    {
        liberarAB(IZQUIERDO(T1));
        liberarAB(DERECHO(T1));
        delete(T1);
    }
}