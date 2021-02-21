#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "Grafo.h"
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Menu
{
    public:
    static void menuPrincipal(const char* in, const char* output);
        // menu principal, a partir dele eh optado o menu para grafo simples utilizando
        // do primeiro tipo de instancias de grafos disponibilizados.

    private:
    static void menuGrafoSimples(Grafo* grafo, const char* in, const char* output);
        // menu para grafo simples utilizando do primeiro tipo de instancias de grafos
        // disponibilizados. A partir desse menu eh possivel utilizar dos algoritmos
        // de AGM Prim e Kruskal, e caminho minimo por Busca em Largura, Busca em Profundidade,
        // Floyd e Dijkstra. Além de ser possivel gerar arquivo de saida e imprimir na tela
        // a impressao do grafo com as informacoes dos nos, arestas e pesos. Exemplo:
        // no_1 -> aresta_1_x(peso_1_x) | aresta_1_y(peso_1_y) | ...
        // no_2 -> aresta_2_z(peso_2_z) | aresta_2_h(peso_2_h) | ...

    static void menuSubConjuntoDominante(Grafo* grafo, const char* in, const char* output);
        // menu para grafo simples utilizando do segundo tipo de instancias de grafos
        // disponibilizados. A partir desse menu eh possivel utilizar dos algoritmos
        // guloso e guloso randomizado. Além de ser possivel gerar arquivo de saida e imprimir na tela
        // a impressao do grafo com as informacoes dos nos, arestas e pesos. Exemplo:
        // no_1 -> aresta_1_x(peso_1_x) | aresta_1_y(peso_1_y) | ...
        // no_2 -> aresta_2_z(peso_2_z) | aresta_2_h(peso_2_h) | ...
};

#endif //MENU_H_INCLUDED