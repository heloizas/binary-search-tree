#include <string>
#include <iostream>

#include "TipoNo.h"

#ifndef ARVORE_H
#define ARVORE_H

using namespace std;

class Arvore
{
private:
    TipoNo *raiz;
    void insereRecursivo(TipoNo *&ref, char valor);

public:
    Arvore();
    Arvore(TipoNo *auxRaiz);
    void insereValor(char valor);
    TipoNo *getRaiz();
    ~Arvore();
};

#endif