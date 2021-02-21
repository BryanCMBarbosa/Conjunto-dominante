#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <fstream>

#include "No.h"
#include "Aresta.h"

class Grafo
{
	public:
	Grafo();
	~Grafo();

	No* get_listaNos();
	/**
	 * * OBJETIVO:
	 *    Retornar a lista de nos que representam os vertices do grafo.
	 *
	 * * RETORNO:
	 *     Um ponteiro para a lista de vertices.
	*/

	void set_listaNos(No* listaNos);
	/**
	 * * OBJETIVO:
	 *     Definir a lista de nos que representam os vertices do grafo.
	 *
	 * * PARAMETROS:
	 * @param listaNos Lista de vertices.
	 *
	*/

	int get_ordem();
	/**
	 * * OBJETIVO:
	 *     Retornar a ordem do grafo.
	 *
	 * * RETORNO:
	 *     Ordem do grafo, tipo int.
	*/

	void set_ordem(int ordem);
	/**
	 * * OBJETIVO:
	 *     Definir a ordem do grafo.
	 *
	 * * PARAMETROS:
	 * @param ordem Ordem do grafo.
	 *
	*/

	int get_numArestas();
	/**
	 * * OBJETIVO:
	 *     Retornar o número de arestas que o grafo possui.
	 *
	 * * RETORNO:
	 *     Número de arestas do grafo, tipo int.
	*/

	void set_numArestas(int numArestas);
	/**
	 * * OBJETIVO:
	 *     Definir o numero de arestas que o grafo possui.
	 *
	 * * PARAMETROS:
	 * @param numArestas Número de arestas.
	 *
	*/

	void leituraGrafo(const char* input);
	/**
	 * * OBJETIVO:
	 *     Fazer a leitura do arquivo armazenado na variável input e guardar as informações na estrutura do grafo.
	 *
	 * * PARAMETROS:
	 * @param input Nome do arquivo de entrada passado por linha de comando
	*/

	unsigned int calculaNumArestas();
	/**
	 * * OBJETIVO:
	 *     Calcular o número total de arestas presentes no grafo.
	 *
	 * * RETORNO:
	 *     Número total de arestas presentes no grafo.
	*/

	void escritaInfGrafo(const char *output, int verticesNaSolucao,int iteracoes, double tempo);
	/**
	 * * OBJETIVO:
	 *     Fazer a escrita das informações do grafo no arquivo armazenado na variável output.
	 *
	 * * PARAMETROS:
	 * @param output Nome do arquivo de saida passado por linha de comando
	*/

	void visualizarListaNos();
	/**
	 * * OBJETIVO:
	 *     Imprimir na tela uma visualização da estrutura do grafo.
	*/

	int get_maior();
	/**
	 * * OBJETIVO:
	 *     Encontrar o vértice com maior valor para alocar corretamente o vetor de visitado.
	 *
	 * * RETORNO:
	 *     Um inteiro com o ID do vértice com maior valor.
	*/

	No* busca(int id);
	/**
	 * * OBJETIVO:
	 *     Percorrer o grafo até encontrar o vértice com valor requerido.
	 *
	 * * PARAMETROS:
	 * @param id Valor do vértice procurado.
	 *
	 * * RETORNO:
	 *     Retorna o vértice que se encontra o valor requerido.
	 *     Retorna NULL, caso não encontre o valor no grafo.
	*/

	void Subconjunto_Dominante_Inducao(const char* output);
	/**
	 * * OBJETIVO:
	 * 	  Encontrar o conjunto dominante minimo do grafo utilizando um algoritmo concebido por indução. 
	*/

	void Chamada_Inducao(std::list<No*>  &solucao, std::list<No*> &listaCandidatos, std::vector<int> &verticesadj_solucao, bool * solucao_ehdominante, int * iteracoes);
	/**
	 * * OBJETIVO:
	 * 	  Encontrar o conjunto dominante minimo do grafo utilizando um algoritmo concebido por indução. 
	 * 
	 * * PARAMETROS:
	 * @param solucao ponteiro para a lista de nos da solucao
	 * @param listaCandidatos ponteiro para lista de vértices que são candidatos a entrarem na solução
	 * @param verticesadj_solucao ponteiro para um vetor de ids de vertices na solucao
	 * @param solucao_ehdominante ponteiro para a flag que sinaliza se a solucao é dominante ou não
	 * @param iteracoes ponteiro para a variável indicando a quantidade de iteracoes
	*/

	void Subconjunto_Dominante_Guloso(const char* output);
	/**
	 * * OBJETIVO:
	 *     Encontrar o conjunto dominante minimo do grafo utilizando do algoritmo guloso.
	*/

	void iteracao_Solucao(std::list<No*> &solucao, std::list<No*> &listaCandidatos, std::vector<int> &verticesadj_solucao, bool * solucao_ehdominante);
	/**
	 * * OBJETIVO:
	 * 	  Encontrar o conjunto dominante minimo do grafo utilizando um algoritmo concebido por indução. 
	 * 
	 * * PARAMETROS:
	 * @param solucao ponteiro para a lista de nos da solucao
	 * @param listaCandidatos ponteiro para lista de vértices que são candidatos a entrarem na solução
	 * @param verticesadj_solucao ponteiro para um vetor de ids de vertices na solucao
	 * @param solucao_ehdominante ponteiro para a flag que sinaliza se a solucao é dominante ou não
	*/

	private:
	No* listaNos;	 // ponteiro para o primeiro no do grafo
	int ordem;		 // armazena o numero de nos presentes no grafo
	int numArestas;  // armazena o numero de arestas presentes no grafo

	std::list <Aresta> arestas;
};

#endif // GRAFO_H