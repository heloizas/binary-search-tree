#include "../include/Arvore.h"

Arvore::Arvore()
{
    raiz = NULL;
}

Arvore::Arvore(TipoNo *raiz)
{
    raiz = raiz;
}

void Arvore::insere(char valor)
{
    insereRecursivo(raiz, valor);
}

void Arvore::insereRecursivo(TipoNo *&referencia, char valor)
{
    if (referencia == NULL)
    {
        referencia = new TipoNo();
        referencia->setSimbolo(valor);
    }
    else
    {
        if (valor < referencia->getSimbolo())
        {
            if (referencia->esquerdo == NULL)
            {
                referencia->esquerdo = new TipoNo();
                referencia->esquerdo->setSimbolo(valor);
            }
            else
            {
                insereRecursivo(referencia->esquerdo, valor);
            }
        }
        else
        {
            if (referencia->direito == NULL)
            {
                referencia->direito = new TipoNo();
                referencia->direito->setSimbolo(valor);
            }
            else
            {
                insereRecursivo(referencia->direito, valor);
            }
        }
    }
}

TipoNo *Arvore::getRaiz()
{
    return raiz;
}