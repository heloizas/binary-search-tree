#include <string>

#ifndef VETOR_H
#define VETOR_H

using namespace std;

class Vetor
{
private:
    char tipo;
    string texto;

public:
    Vetor();
    char getTipo();
    void setTipo(char t);
    string getTexto();
    void setTexto(string txt);
    ~Vetor();
};

#endif