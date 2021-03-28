#include <iostream>
#include <fstream>

#include "../include/Processar.h"

using namespace std;

Processar::Processar(char *file)
{
    caractere = ' ';
    caractereAnterior = ' ';
    qtdComandos = 0;
    ContarLinhas(file);
    ProcessarArquivo(file);
}

void Processar::ContarLinhas(char *file)
{
    FILE *arquivo = fopen(file, "r");
    while ((caractere = fgetc(arquivo)) != EOF)
    {
        if (caractere == '\n')
        {
            qtdComandos++;
        }
        caractereAnterior = caractere;
    }
    if (caractereAnterior != '\n')
    {
        qtdComandos++;
    }
    fclose(arquivo);
}

void Processar::ProcessarArquivo(char *file)
{
    FILE *arquivo = fopen(file, "r");
    for (int i = 0; i < qtdComandos; i++)
    {
        string texto = "";
        fscanf(arquivo, "%c", &auxTipo);
        fscanf(arquivo, "%c ", &auxChar);
        auxChar = fgetc(arquivo);
        while (auxChar != '\n' && auxChar != EOF)
        {
            texto += auxChar;
            auxChar = fgetc(arquivo);
        }
        comandos[i] = new Vetor();
        comandos[i]->setTipo(auxTipo);
        comandos[i]->setTexto(texto);
    }
    fclose(arquivo);
    Imprimir();
}

void Processar::Imprimir()
{
    for (int i = 0; i < qtdComandos; i++)
    {
        cout << comandos[i]->getTipo() << " " << comandos[i]->getTexto() << endl;
    }
}

Processar::~Processar()
{
}
