#include "Menu.h"

void Menu::menuPrincipal(const char* in, const char* output)
{
    Grafo* grafo = new Grafo();
    menuSubConjuntoDominante(grafo, in, output);
}

void Menu::menuSubConjuntoDominante(Grafo* grafo, const char* in, const char* output)
{
    grafo->leituraGrafo(in);

    string x = "";
    while (true)
    {
        cout << "\n\n   =====   MENU: SUBCONJUNTO DOMINANTE MÍNIMO   =====\n\n"
            << "Entre com a opção que deseja executar:\n"
            << "1 - Imprimir o Grafo\n"
            << "2 - Algoritmo Guloso\n"
            << "3 - Algoritmo Inducao\n"
            << "                       0 - Retornar\n"
            << "Sua opção: ";
        cin >> x;
        if (x == "0" || x == "1" || x == "2" || x == "3" || x == "4")
        {
            int opcao = stoi(x);
            switch (opcao)
            {
                case 0:
                    {
                        cout << "\nRetornando...\n";
                        return;
                    }

                case 1:
                    {
                        cout << endl;
                        grafo->visualizarListaNos();
                        break;
                    }

                case 2:
                    {
                        cout << endl;
                        grafo->Subconjunto_Dominante_Guloso(output);
                        break;
                    }

                case 3:
                    {
                        cout << endl;
                        grafo->Subconjunto_Dominante_Inducao(output);
                        break;
                    }
            }
        }
        else
        {
            cout << "\nOpção inválida!\n";
        }
    }
}