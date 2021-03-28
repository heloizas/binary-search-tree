#include "../include/TipoNo.h"

TipoNo::TipoNo()
{
    this->esquerdo = NULL;
    this->direito = NULL;
}

TipoNo::TipoNo(char simbolo, TipoNo *esquerdo, TipoNo *direito)
{
    this->simbolo = simbolo;
    this->esquerdo = esquerdo;
    this->direito = direito;
}

TipoNo::TipoNo(char simbolo)
{
    this->simbolo = simbolo;
}

char TipoNo::getSimbolo()
{
    return this->simbolo;
}

void TipoNo::setSimbolo(char simbolo)
{
    this->simbolo = simbolo;
}

TipoNo *TipoNo::getEsquerdo()
{
    return this->esquerdo;
}

void TipoNo::setEsquerdo(TipoNo *esquerdo)
{
    this->esquerdo = esquerdo;
}

TipoNo *TipoNo::getDireito()
{
    return this->direito;
}

void TipoNo::setDireito(TipoNo *direito)
{
    this->direito = direito;
}

string TipoNo::getCodigoCaminho(char letra)
{
    string codigoCaminho = "";
    TipoNo *aux;
    if (letra < getSimbolo())
    {
        codigoCaminho += (((rand() % 5) * 2) + 1) + '0';
        aux = getEsquerdo();
        return codigoCaminho + aux->getCodigoCaminho(letra);
    }
    else if (letra > getSimbolo())
    {
        codigoCaminho += (((rand() % 5) * 2)) + '0';
        aux = getDireito();
        return codigoCaminho + aux->getCodigoCaminho(letra);
    }
    else
    {
        return codigoCaminho;
    }
}