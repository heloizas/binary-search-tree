#include "../include/Interpretar.h"
#include "../include/Arvore.h"

Interpretar::Interpretar()
{
    arvore = new Arvore;
}

void Interpretar::comandos(Vetor *comandos[], int qtdComandos)
{
    for (int i = 0; i < qtdComandos; i++)
    {
        interpretaComando(comandos[i]);
    }
}

void Interpretar::interpretaComando(Vetor *comando)
{
    tipo = comando->getTipo();
    if (tipo == 'A')
    {
        montar(comando->getTexto());
    }
    else if (tipo == 'C')
    {
        codificar(comando->getTexto());
    }
    else if (tipo == 'D')
    {
        decodificar(comando->getTexto());
    }
}

void Interpretar::montar(string comando)
{
    for (int i = 0; i < comando.length(); i++)
    {
        arvore->insere(comando.at(i));
    }
}

void Interpretar::codificar(string comando)
{
    TipoNo *noLetra = arvore->getRaiz();
    string fraseCodificada = "";
    for (int i = 0; i < comando.length(); i++)
    {
        fraseCodificada += "x";
        fraseCodificada += noLetra->getCodigoCaminho(comando.at(i));
    }
    cout << fraseCodificada << endl;
}

void Interpretar::decodificar(string comando)
{
    TipoNo *noLetra = arvore->getRaiz();
    string fraseDecodificada = "";
    for (int i = 1; i < comando.length(); i++)
    {
        if (comando.at(i) == 'x')
        {
            char letra = noLetra->getSimbolo();
            fraseDecodificada += letra;
            noLetra = arvore->getRaiz();
        }
        else
        {
            int aux = comando.at(i) - '0';
            if (aux % 2 == 0)
            {
                noLetra = noLetra->getDireito();
            }
            else
            {
                noLetra = noLetra->getEsquerdo();
            }
        }
    }
    char letra = noLetra->getSimbolo();
    fraseDecodificada += letra;
    cout << fraseDecodificada << endl;
}
