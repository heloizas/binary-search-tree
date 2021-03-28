#include "../include/Vetor.h"

Vetor::Vetor()
{
    tipo = ' ';
    texto = "";
}

char Vetor::getTipo()
{
    return tipo;
}

void Vetor::setTipo(char t)
{
    tipo = t;
}

string Vetor::getTexto()
{
    return texto;
}

void Vetor::setTexto(string txt)
{
    texto = txt;
}

Vetor::~Vetor()
{
}