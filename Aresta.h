#ifndef ARESTA_H
#define ARESTA_H

class Aresta
{
    public:
    Aresta(int idAdjacente);
    Aresta();
    ~Aresta();

    int get_idAdjacente();
    /**
     * * OBJETIVO:
     *     Retornar o id do no adjacente.
     *
     * * RETORNO:
     *     O id do no adjacente do tipo int.
    */

    void set_idAdjacente(int idAdjacente);
    /**
     * * OBJETIVO:
     *     Definir o id do no adjacente.
     *
     * * PARAMETROS:
     * @param idAdjacente um valor inteiro que representa o id do no de interesse.
     *
    */

    float get_pesoAresta();
    /**
     * * OBJETIVO:
     *     Retornar o peso da aresta
     *
     * * RETORNO:
     *     Peso da aresta do tipo float.
    */

    void set_pesoAresta(float pesoAresta);
    /**
     * * OBJETIVO:
     *     Definir o peso da aresta.
     *
     * * PARAMETROS:
     * @param pesoAresta Peso da aresta.
     *
    */

    Aresta* get_proxAresta();
    /**
     * * OBJETIVO:
     *     Retornar a aresta apontada.
     *
     * * RETORNO:
     *     Um ponteiro para a próxima aresta, se for NULL quer dizer que não existe a aresta.
    */

    void set_proxAresta(Aresta* proxAresta);
    /**
     * * OBJETIVO:
     *     Define a próxima aresta a ser inserida.
     *
     * * PARAMETROS:
     * @param proxAresta ponteiro não nulo para a aresta a ser inserida.
    */

    int get_idNo();
    /**
      * * OBJETIVO:
      *     Retornar o id do No (classe No) que a aresta incide.
      *
      * * RETORNO:
      *     O id do no do tipo int.
     */

    void set_idNo(int idNo);
    /**
      * * OBJETIVO:
      *     Definir o id do No (classe No) que a aresta incide.
      *
      * * PARAMETROS:
      * @param idNo um valor inteiro que representa o id do no de interesse.
      *
     */



    private:
    int idAdjacente;     // armazena o id do no adjacente
    int idNo;            // armazena o id do no ao qual aponta a essa aresta (this)
    float pesoAresta;    // armazena o peso referente a aresta
    Aresta* proxAresta;  // ponteiro para a proxima aresta incidente ao no que aponta para essa aresta (this)
};

#endif // ARESTA_H