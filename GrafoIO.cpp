#include "Grafo.h"

using namespace std;

void Grafo::leituraGrafo(const char* input)
{
    ifstream in(input);

    if (!in.is_open())
    {
        cout << "ERRO: NAO FOI POSSÍVEL ABRIR O ARQUIVO" << endl;
        exit(1);
    }

    cout << "Lendo arquivo \"" << input << "\"..." << endl;

    string aux;

    in >> aux >> ordem;

    while(aux != "******************WEIGHTS*****************************")
    {
        in >> aux;
    }

    vector<float> pesos;
    float peso;
    while(true)
    {
        in >> aux;
        if(aux == "*****************CONNECTIONS****************")
            break;
        peso = stof(aux);
        pesos.push_back(peso);
    }

    No* p;
    No* pAnt;
    int cont1 = 0; // contador para a parte triangular inferior
    int cont2 = 0; // contador para a parte triangular superior
    for(int i = 0 ; i < ordem ; i++)
    {
        p = new No(i);
        if(i == 0)
            listaNos = p;
        else
            pAnt->set_proxNo(p);

        for(int j = 0 ; j < ordem ; j++)
        {
            int adj;
            in >> adj;

            if(adj == 1 && i < j)
            {
                p->adicionarAresta(j, pesos[cont1]);
                cont1++;
                pAnt = p;
            }
            else if (adj == 1 && i > j)
            {
                p->adicionarAresta(j, pesos[cont2]);
                cont2++;
                pAnt = p;
            }
        }
    }

    numArestas = calculaNumArestas();
}

void Grafo::escritaInfGrafo(const char *output, int verticesNaSolucao,int iteracoes, double tempo)
{
    cout << "Escrevendo informacoes no arquivo " << "\"" << output << "\" de saida.\n";
    ofstream out(output);

    out << "Vertices na solucao: " << verticesNaSolucao << endl;
    out << "Iteracoes ate a solucao: " << numArestas << endl;
    out << "Tempo: " << tempo << endl;

    cout << "Arquivo escrito com sucesso!\n";
}

unsigned int Grafo::calculaNumArestas()
{
    No* p = listaNos;

    unsigned int soma_graus = 0;

    if (listaNos != NULL)
    {
        while (p != NULL)
        {
            No* pAnt = p;
            soma_graus += pAnt->get_grau();
            p = p->get_proxNo();
        }
    }
    else
    {
        cout << "ERRO: GRAFO VAZIO\n";
    }

    return soma_graus / 2;
}