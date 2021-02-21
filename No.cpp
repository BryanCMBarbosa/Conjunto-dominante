#include <iostream>

#include "No.h"

using namespace std;

No::No()
{
    this->id = -1;
    this->grau = 0;
    this->peso = 0;
    this->proxNo = NULL;
    this->proxAdj = NULL;
}

No::No(int id)
{
    this->id = id;
    this->grau = 0;
    this->peso = 0;
    this->proxNo = NULL;
    this->proxAdj = NULL;
}

No::~No()
{
    Aresta* p = proxAdj;
    Aresta* pAnt;

    while (p != NULL)
    {
        pAnt = p;
        p = p->get_proxAresta();

        delete pAnt;
    }
}

int No::get_id()
{
    return this->id;
}

void No::set_id(int id)
{
    this->id = id;
}

int No::get_grau()
{
    return this->grau;
}

void No::set_grau(int grau)
{
    this->grau = grau;
}

float No::get_peso()
{
    return this->peso;
}

void No::set_peso(float peso)
{
    this->peso = peso;
}

No* No::get_proxNo()
{
    return this->proxNo;
}

void No::set_proxNo(No* proxNo)
{
    if (proxNo == NULL)
    {
        cout << "ERRO: PARAMETRO NULO\n";
        exit(1);
    }

    No* p = this->proxNo;

    if (p != NULL)
        proxNo->set_proxNo(p);

    this->proxNo = proxNo;
}

Aresta* No::get_proxAdj()
{
    return this->proxAdj;
}

void No::set_flagGrupo(int flagGrupo)
{
    this->flagGrupo = flagGrupo;
}

int No::get_flagGrupo()
{
    return this->flagGrupo;
}

Aresta* No::adicionarAresta(int id, float peso)
{
    Aresta* novaAresta = new Aresta(id);
    novaAresta->set_pesoAresta(peso);

    if (grau == 0)
    {
        this->proxAdj = novaAresta;
        grau++;
    } // caso esteja sendo adicionada a primeira adjacência do vertice
    else
    {
        Aresta* p = this->proxAdj;
        Aresta* pAnt = p;

        // bool arestaJaAdicionada = false;
        while (p != NULL)
        {
            if (p->get_idAdjacente() == id)
            {
                delete novaAresta;
                return NULL;
            } // ou seja, aresta já adicionada, logo deletamos a que foi criada e retornamos NULL

            pAnt = p;
            p = p->get_proxAresta();
        }

        pAnt->set_proxAresta(novaAresta);
        (this->grau)++;
    }

    novaAresta->set_idNo(this->id);
    return novaAresta;
}

bool No::operator<(No const& n)
{
    return grau < n.grau;
}