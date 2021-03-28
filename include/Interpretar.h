#include <iostream>
#include <string.h>

#include "Vetor.h"
#include "Arvore.h"

#ifndef INTERPRETAR_H
#define INTERPRETAR_H

using namespace std;

class Interpretar
{
private:
    Arvore *arvore;
    char tipo;
    string codificada;
    string decodificada;
    int aux;
    char letra;

public:
    Interpretar();
    void comandos(Vetor *comandos[], int qtdComandos);
    void interpretaComando(Vetor *comando);
    void montar(string comando);
    void codificar(string comando);
    void decodificar(string comando);
    void imprimir(string frase);
    ~Interpretar();
};

#endif