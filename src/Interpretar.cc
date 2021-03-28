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
        arvore->insereValor(comando.at(i));
    }
}

void Interpretar::codificar(string comando)
{
    TipoNo *caracterNo = arvore->getRaiz();
    codificada = "";

    for (int i = 0; i < comando.length(); i++)
    {
        codificada += "x";
        codificada += caracterNo->getPatch(comando.at(i));
    }

    imprimir(codificada);
}

void Interpretar::decodificar(string comando)
{
    TipoNo *caracterNo = arvore->getRaiz();
    decodificada = "";

    for (int i = 1; i < comando.length(); i++)
    {
        if (comando.at(i) == 'x')
        {
            letra = caracterNo->getSimbolo();
            decodificada += letra;
            caracterNo = arvore->getRaiz();
        }
        else
        {
            aux = comando.at(i) - '0';
            if (aux % 2 == 0)
            {
                caracterNo = caracterNo->getDireito();
            }
            else
            {
                caracterNo = caracterNo->getEsquerdo();
            }
        }
    }
    char letra = caracterNo->getSimbolo();
    decodificada += letra;

    imprimir(decodificada);
}

void Interpretar::imprimir(string frase)
{
    cout << frase << endl;
}

Interpretar::~Interpretar()
{
}
