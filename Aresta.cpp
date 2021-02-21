#include <iostream>

#include "Aresta.h"

using namespace std;

Aresta::Aresta(int idAdjacente)
{
    this->idAdjacente = idAdjacente;
    this->proxAresta = NULL;
}

Aresta::Aresta()
{
    this->idAdjacente = -1;
    this->proxAresta = NULL;
}

Aresta::~Aresta()
{ } // deletamos todas as arestas incidentes ao no i no destrutor do no i

int Aresta::get_idAdjacente()
{
    return this->idAdjacente;
}

void Aresta::set_idAdjacente(int idAdjacente)
{
    this->idAdjacente = idAdjacente;
}

float Aresta::get_pesoAresta()
{
    return this->pesoAresta;
}

void Aresta::set_pesoAresta(float pesoAresta)
{
    this->pesoAresta = pesoAresta;
}

Aresta* Aresta::get_proxAresta()
{
    return proxAresta;
}

void Aresta::set_proxAresta(Aresta* proxAresta)
{
    if (proxAresta == NULL)
    {
        cout << "ERRO: PARAMETRO NULO\n";
        exit(1);
    }

    if (this->proxAresta != NULL)
    {
        Aresta* p = proxAresta;

        p->set_proxAresta(this->proxAresta);
        this->proxAresta = p;
    }
    else
    {
        this->proxAresta = proxAresta;
    }
}

int Aresta::get_idNo()
{
    return idNo;
}

void Aresta::set_idNo(int idNo)
{
    this->idNo = idNo;
}