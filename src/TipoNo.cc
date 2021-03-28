#include "../include/TipoNo.h"

TipoNo::TipoNo()
{
    esq = NULL;
    dir = NULL;
}

TipoNo::TipoNo(char auxSym)
{
    sym = auxSym;
}

TipoNo::TipoNo(char auxSym, TipoNo *auxEsq, TipoNo *auxDir)
{
    sym = auxSym;
    esq = auxEsq;
    dir = auxDir;
}

char TipoNo::getSimbolo()
{
    return sym;
}

void TipoNo::setSimbolo(char auxSym)
{
    sym = auxSym;
}

TipoNo *TipoNo::getEsquerdo()
{
    return esq;
}

void TipoNo::setEsquerdo(TipoNo *auxEsq)
{
    esq = auxEsq;
}

TipoNo *TipoNo::getDireito()
{
    return dir;
}

void TipoNo::setDireito(TipoNo *auxDir)
{
    dir = auxDir;
}

string TipoNo::getPatch(char letra)
{
    string codigoCaminho = "";
    TipoNo *aux;

    if (letra < getSimbolo())
    {
        codigoCaminho += (((rand() % 5) * 2) + 1) + '0';
        aux = getEsquerdo();
        return codigoCaminho + aux->getPatch(letra);
    }
    else if (letra > getSimbolo())
    {
        codigoCaminho += (((rand() % 5) * 2)) + '0';
        aux = getDireito();
        return codigoCaminho + aux->getPatch(letra);
    }
    else
    {
        return codigoCaminho;
    }
}

TipoNo::~TipoNo()
{
}