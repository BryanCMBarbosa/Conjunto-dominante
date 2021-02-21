#include <iostream>
#include <string>

#include "Menu.h"

using namespace std;

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        cout << "ERRO: FORMATO ERRADO DE EXECUÇÃO" << endl;
        cout << "./arquivoExecucao <arquivo_entrada> <arquivo_saida>" << endl;
    } // tratamento do caso em que a execução esta sendo feita da forma errada
    else
        Menu::menuPrincipal(argv[1], argv[2]);

    return 0;
}
