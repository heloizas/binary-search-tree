#include <iostream>
#include <fstream>

#include "../include/Processar.h"
#include "../include/Vetor.h"
#include "../include/Interpretar.h"
#include "../include/Arvore.h"
#include "../include/TipoNo.h"

using namespace std;

int main(int argc, char *argv[])
{
    char *file(argv[1]);

    Processar processar(file);

    return 0;
}