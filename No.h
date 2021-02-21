#ifndef NO_H
#define NO_H

#include "Aresta.h"

class No
{
    public:
    No();
    No(int id);
    ~No();
    int get_id();
    /**
     * * OBJETIVO:
     *     Retornar a id do no.
     *
     * * RETORNO:
     *     Id do no, tipo int
    */

    void set_id(int id);
    /**
     * * OBJETIVO:
     *     Definir um novo valor para a id do no.
     *
     * * PARAMETROS:
     * @param id Id do no.
     *
    */
    int get_grau();
    /**
     * * OBJETIVO:
     *     Retornar o grau do vertice.
     *
     * * RETORNO:
     *     Grau do vertice, tipo int.
    */

    void set_grau(int grau);
    /**
     * * OBJETIVO:
     *     Definir o grau do vertice.
     *
     * * PARAMETROS:
     * @param grau Valor do grau do vertice.
     *
    */

    float get_peso();
    /**
     * * OBJETIVO:
     *     Retornar o peso do vertice.
     *
     * * RETORNO:
     *     Peso do vertice, tipo float.
    */

    void set_peso(float peso);
    /**
     * * OBJETIVO:
     *     Definir o peso do vertice.
     *
     * * PARAMETROS:
     * @param peso Peso da vertice.
     *
    */

    No* get_proxNo();
    /**
     * * OBJETIVO:
     *     Retornar o proximo no da lista de vertices.
     *
     * * RETORNO:
     *     Um ponteiro para o próximo no da lista de vertices, se for NULL quer dizer que não possui mais vertices na lista.
    */

    void set_proxNo(No* proxNo);
    /**
     * * OBJETIVO:
     *     Definir o próximo no na lista de vertices.
     *
     * * PARAMETROS:
     * @param proxNo No a ser inserido como o proximo na lista de vertices.
     *
    */

    Aresta* get_proxAdj();
    /**
     * * OBJETIVO:
     *     Retornar a primeira aresta da lista de adjacencia do no.
     *
     * * RETORNO:
     *     Um ponteiro para a primeira aresta adicionada ao no, se for NULL quer dizer que aquele vertice não possui aresta.
    */

    void set_flagGrupo(int flagGrupo);
    /**
     * OBJETIVO:
     *   Definir a flag do grupo ao qual um dado no pertence.
     *
     * PARAMETROS:
     * @param flagGrupo flag de identificacao do grupo ao qual o no esta sendo inserido.
    */

    int get_flagGrupo();
    /**
     * OBJETIVO:
     *   Retornar a flag do grupo que o no dado pertence.
     *
     * RETORNO:
     *   Valor inteiro da flag do grupo do qual o no dado pertence.
    */

    Aresta* adicionarAresta(int id, float peso);
    /**
     * * OBJETIVO:
     *     Adicionar uma nova aresta ao nó com extremidades no id do no e na variável id passada por parâmetro na função.
     *
     * * PARAMETROS:
     * @param id Id do nó que é conectado ao nó da estrutura por meio da aresta a ser inserida.
     * @param peso Peso da aresta.
     *
     * * RETORNO:
     *     Um ponteiro para a aresta adicionado, se for NULL quer dizer que a aresta já foi adicionada
    */

    bool operator<(No const& n);

    private:
    int id;            // armazena o id do no
    int grau;          // armazena o grau do no
    float peso;        // armazena o peso do no, o que nao foi utilizado para este trabalho pois so
                       // eh utilizado peso nas arestas
    int flagGrupo;

    No* proxNo;        // ponteiro para o proximo no do grafo
    Aresta* proxAdj;   // ponteiro para a primeira aresta incidente ao no
};

#endif // NO_H