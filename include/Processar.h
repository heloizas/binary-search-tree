#include <stdio.h>
#include <string>

#include "Vetor.h"
#include "Interpretar.h"

#ifndef PROCESSAR_H
#define PROCESSAR_H

using namespace std;

class Processar
{
private:
    char caractere;
    char caractereAnterior;
    char auxTipo;
    char auxChar;
    string auxTexto;
    int qtdComandos;

public:
    Processar(char *file);
    void ContarLinhas(char *file);
    void ProcessarArquivo(char *file);
    static const int MAXTAM = 100;
    Vetor *comandos[MAXTAM];
    void Imprimir();
    void InterpretarArquivo();
    Interpretar *interpretar;
    ~Processar();
};

#endif