#include <string>

#ifndef TIPONO_H
#define TIPONO_H

using namespace std;

class TipoNo
{
private:
    TipoNo *esq;
    TipoNo *dir;
    char sym;

public:
    TipoNo();
    TipoNo(char auxSym);
    TipoNo(char auxSym, TipoNo *auxEsq, TipoNo *auxDir);
    char getSimbolo();
    void setSimbolo(char auxSym);
    TipoNo *getDireito();
    void setDireito(TipoNo *auxDir);
    TipoNo *getEsquerdo();
    void setEsquerdo(TipoNo *auxEsq);
    string getPatch(char letra);
    ~TipoNo();
    friend class Arvore;
};

#endif