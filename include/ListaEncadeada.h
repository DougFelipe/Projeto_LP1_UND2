#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include "No.h"
#include <iostream>

template <class P>
class ListaEncadeada {
private:
    No<P>* cabeca;
    No<P>* cauda;
    int tamanho;

public:
    // Construtor
    ListaEncadeada();

    // Verifica se a lista está vazia
    bool vazia() const;

    // Retorna o tamanho da lista
    int tamanhoLista() const;

    // Insere um elemento no início da lista
    void adicionarInicio(P valor);

    // Insere um elemento no final da lista
    void adicionarFim(P valor);

    // Insere um elemento em uma posição específica da lista
    void adicionarPorPosicao(P valor, int posicao);

    // Remove o elemento do início da lista
    void removerInicio();

    // Remove o elemento do final da lista
    void removerFim();

    // Remove o elemento de uma posição específica da lista
    void removerPorPosicao(int posicao);

    // Imprime os elementos da lista
    void imprimir() const;
};



#endif  // LISTA_ENCADEADA_HPP
