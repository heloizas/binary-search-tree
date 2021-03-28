#include "../include/Arvore.h"

Arvore::Arvore()
{
    raiz = NULL;
}

Arvore::Arvore(TipoNo *auxRaiz)
{
    raiz = auxRaiz;
}

void Arvore::insereValor(char valor)
{
    insereRecursivo(raiz, valor);
}

void Arvore::insereRecursivo(TipoNo *&ref, char valor)
{
    if (ref == NULL)
    {
        ref = new TipoNo();
        ref->setSimbolo(valor);
    }
    else
    {
        if (valor < ref->getSimbolo())
        {
            if (ref->esq == NULL)
            {
                ref->esq = new TipoNo();
                ref->esq->setSimbolo(valor);
            }
            else
            {
                insereRecursivo(ref->esq, valor);
            }
        }
        else
        {
            if (ref->dir == NULL)
            {
                ref->dir = new TipoNo();
                ref->dir->setSimbolo(valor);
            }
            else
            {
                insereRecursivo(ref->dir, valor);
            }
        }
    }
}

TipoNo *Arvore::getRaiz()
{
    return raiz;
}

Arvore::~Arvore()
{
}