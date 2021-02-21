#include <iostream>

#include "Grafo.h"
#include <algorithm>
#include <list>
#include <time.h>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

Grafo::Grafo()
{
    listaNos = NULL;
    ordem = 0;
    numArestas = 0;
}

Grafo::~Grafo()
{
    arestas.clear();
    No* p = listaNos;
    No* pAnt;

    while (p != NULL)
    {
        pAnt = p;
        p = p->get_proxNo();

        delete pAnt;
    }
}

No* Grafo::get_listaNos()
{
    return listaNos;
}

void Grafo::set_listaNos(No* listaNos)
{
    if (listaNos == NULL)
    {
        cout << "ERRO: PARAMETRO NULO\n";
        exit(1);
    }

    if (this->listaNos != NULL)
    {
        delete listaNos;
    }

    this->listaNos = listaNos;
}

int Grafo::get_ordem()
{
    return ordem;
}

void Grafo::set_ordem(int ordem)
{
    this->ordem = ordem;
}

int Grafo::get_numArestas()
{
    return numArestas;
}

void Grafo::set_numArestas(int numArestas)
{
    this->numArestas = numArestas;
}

void Grafo::visualizarListaNos()
{
    No* p = listaNos;
    if (p == NULL)
        cout << "LISTA VAZIA!\n";
    else
    {
        cout << "=====  Impressão do grafo  =====\n\n";
        while (p != NULL)
        {
            cout << p->get_id() << " -> ";
            int i = 0;
            Aresta* pAresta = p->get_proxAdj();
            while (pAresta != NULL)
            {
                i++;
                if (i == 1)
                    cout << pAresta->get_idAdjacente() << " (" << pAresta->get_pesoAresta() << ")";
                else
                    cout << " | " << pAresta->get_idAdjacente() << "(" << pAresta->get_pesoAresta() << ")";
                pAresta = pAresta->get_proxAresta();
            }

            cout << endl;
            p = p->get_proxNo();
        }
    }
}

No* Grafo::busca(int id)
{
    No* p = this->listaNos;
    while (p != NULL)
    {
        if (p->get_id() == id)
        {
            return p;
        }
        p = p->get_proxNo();
    }
    return NULL;
}

int Grafo::get_maior()
{
    No* q = this->listaNos;
    int maior = 0;

    while (q != NULL)
    {
        if (q->get_id() > maior)
            maior = q->get_id();

        q = q->get_proxNo();
    }

    return maior;
}

void funcaoCriterio(Grafo* grafo, list<No*> &listaCandidatos)
{
    listaCandidatos.sort([ ] (No* n1, No* n2){return n1->get_grau() > n2->get_grau();});
    // ordenando a lista de candidatos pelos graus dos nos
}

void Grafo::Subconjunto_Dominante_Inducao(const char* output)
{      
    list<No*> solucao;         // solucao final do algoritmo
    list<No*> listaCandidatos; // lista de candidatos à entrarem na solucao
    vector<int> verticesadj_solucao(ordem); // vetor que indica quais vertices estao na solucao
    fill(&verticesadj_solucao[0], &verticesadj_solucao[ordem], 0);

    high_resolution_clock::time_point inicio;
    high_resolution_clock::time_point fim;
    long double tempo;

    No* p = listaNos;
    
    for (int i = 0; i < ordem; i++)
    {
        listaCandidatos.push_back(p);
        p = p->get_proxNo();
    }

    bool solucao_ehdominante = false;
    int iteracoes = 0;

    Chamada_Inducao(solucao, listaCandidatos, verticesadj_solucao, addressof(solucao_ehdominante), addressof(iteracoes));

    fim = high_resolution_clock::now(); // tempo final

    unsigned int solucao_size = solucao.size();
        cout << "Conjunto Dominante: " << solucao_size << endl;

    tempo = (duration_cast<duration<double>>(fim - inicio).count()) * 1000; // duracao entre tempo inicial e final em ms

    escritaInfGrafo(output, solucao.size(), iteracoes, tempo);
}

void Grafo::Chamada_Inducao(list<No*> &solucao, list<No*> &listaCandidatos, vector<int> &verticesadj_solucao, bool * solucao_ehdominante, int * iteracoes)
{
    funcaoCriterio(this, listaCandidatos);
    *iteracoes++;

    if(listaCandidatos.front()->get_grau() == (listaCandidatos.size() - 1))
    {
        iteracao_Solucao(solucao, listaCandidatos, verticesadj_solucao, solucao_ehdominante);
        // conta a quantidade de vertices na solucao
        *solucao_ehdominante = true;
    }
    else
    {
        iteracao_Solucao(solucao, listaCandidatos, verticesadj_solucao, solucao_ehdominante);

        if (listaCandidatos.empty() && *solucao_ehdominante == false)
            cout << "----- GRAFO DESCONEXO -----" << endl;
            /* Se a lista de candidatos esta vazia e a solucao continua nao sendo dominante, quer dizer
               que foram verificados todos os vertices do grafo, mas nao existe solucao para conjunto dominante,
               logo, o grafo e desconexo */
        else
            Chamada_Inducao(solucao, listaCandidatos, verticesadj_solucao, solucao_ehdominante, iteracoes);
    }
}

void Grafo::iteracao_Solucao(list<No*> &solucao, list<No*> &listaCandidatos, vector<int> &verticesadj_solucao, bool * solucao_ehdominante)
{
    solucao.push_back(listaCandidatos.front()); // adicionando o melhor candidato a solucao
    listaCandidatos.pop_front(); // removendo da lista de candidatos o nó que acabou de entrar para a solução

    list<No*> aux = solucao;
    for (int i = 0; i < solucao.size(); i++)
    {
        verticesadj_solucao.at(aux.front()->get_id()) = 1; // indicando que os vertices solucao[i] estao na solucao
        aux.pop_front();
    }
    aux.clear();

    aux = solucao;
    for (int i = 0; i < solucao.size(); i++)
    {
        Aresta* pAresta = aux.front()->get_proxAdj();
        while (pAresta != NULL)
        {
            verticesadj_solucao.at(pAresta->get_idAdjacente()) = 1; // indicando que os vertices adjacentes ao solucao[i] estao na solucao
            pAresta = pAresta->get_proxAresta();
        }

        aux.pop_front();
    } // verificar se a solucao ja é dominante
    aux.clear();
}

void Grafo::Subconjunto_Dominante_Guloso(const char* output)
{
    list<No*> solucao;         // solucao final do algoritmo
    list<No*> listaCandidatos; // lista de candidatos à entrarem na solucao
    vector<int> verticesadj_solucao(ordem); // vetor que indica quais vertices estao na solucao
    fill(&verticesadj_solucao[0], &verticesadj_solucao[ordem], 0);

    high_resolution_clock::time_point inicio;
    high_resolution_clock::time_point fim;
    long double tempo;
    int iteracoes = 0;

    No* p = listaNos;
    
    for (int i = 0; i < ordem; i++)
    {
        listaCandidatos.push_back(p);
        p = p->get_proxNo();
    }

    bool solucao_ehdominante = false;

    // inicio = high_resolution_clock::now(); // tempo inicial
    while (!listaCandidatos.empty() && solucao_ehdominante == false)
    {
        iteracoes++;
        funcaoCriterio(this, listaCandidatos);

        iteracao_Solucao(solucao, listaCandidatos, verticesadj_solucao, addressof(solucao_ehdominante));

        if (listaCandidatos.empty() && solucao_ehdominante == false)
            cout << " ----- GRAFO DESCONEXO -----" << endl;
        /* Se a lista de candidatos esta vazia e a solucao continua nao sendo dominante, quer dizer
        que foram verificados todos os vertices do grafo, mas nao existe solucao para conjunto dominante,
        logo, o grafo e desconexo */

        int cont = count(&verticesadj_solucao[0], &verticesadj_solucao[ordem], 1);
        // conta a quantidade de vertices na solucao

        if (cont == ordem)
            solucao_ehdominante = true;
    } // é rodado o algoritmo enquanto a lista de candidatos nao é vazia ou ainda nao tem
      // uma solucao dominante
    fim = high_resolution_clock::now(); // tempo final

    unsigned int solucao_size = solucao.size();
    cout << "Conjunto Dominante: " << solucao_size << endl;

    tempo = (duration_cast<duration<double>>(fim - inicio).count()) * 1000; // duracao entre tempo inicial e final em ms

    escritaInfGrafo(output, solucao.size(), iteracoes, tempo);
}