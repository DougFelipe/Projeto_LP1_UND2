/**
 * @file ListaEncadeada.hpp
 * @brief Declaração da Classe ListaEncadeada.
 */

#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include "No.h"
#include <iostream>

/**
 * @brief Classe que representa uma Lista Encadeada.
 *
 * Essa classe contém informações e funcionalidades relacionadas a uma lista encadeada, como seu valor, seu inicio e fim, assim como os metodos de adicionar no inicio e fim, remover no inicio e fim e outros que voce pode ver abaixo.
 * @tparam P A classe que sera trabalhada na lista.
 */
template <class P>
class ListaEncadeada {
private:
    No<P>* cabeca;
    No<P>* cauda;
    int tamanho;

public:
  /**
   * @brief Construtor vazio
   */
    ListaEncadeada();

  /**
   * @brief Verifica se a lista esta vazia 
   */
    bool vazia() const;

  /**
   * @brief Retorna o tamanho da lista. 
   */
    int tamanhoLista() const;

  /**
   * @brief Insere um elemento no início da lista. 
   */
    void adicionarInicio(P valor);

  /**
   * @brief Insere um elemento no final da lista.
   */
    void adicionarFim(P valor);

  /**
   * @brief Insere um elemento em uma posição específica da lista.
   */
    void adicionarPorPosicao(P valor, int posicao);

  /**
   * @brief Remove o elemento do início da lista.
   */
    void removerInicio();

  /**
   * @brief Remove o elemento do final da lista.
   */
    void removerFim();

  /**
   * @brief Remove o elemento de uma posição específica da lista.
   */
    void removerPorPosicao(int posicao);

  /**
   * @brief Imprime os elementos da lista.
   */
    void imprimir() const;

    /**
   * @brief Retorna uma string com a alteração feita na lista.
   * @param valor É o valor que sera usado na busca
   * @param op Codigo da operação: 1 - Alterar | 2 - Remover
   * @return string com as alterações feita
   */
    std::string alterar(int valor, int op);

  /**
   * @brief Verifica se autor ou editora existe
   * 
   * @param valor Valor a ser buscado
   * @param *campo Ponteiro da variavel que armazena o conteudo para reescrever o arquivo.
   * 
   * @return true se existe e falso se não
   */
    bool existe(std::string valor, std::string *campo);

  /**
   * @brief Retorna o ultimo nó da lista
   * 
   * @return ultimo nó.
   */
    No<P>* getCauda();
};

template <class P>
ListaEncadeada<P>::ListaEncadeada() : cabeca(nullptr), cauda(nullptr), tamanho(0) {}


template <class P>
bool ListaEncadeada<P>::vazia() const {
    return tamanho == 0;
}


template <class P>
int ListaEncadeada<P>::tamanhoLista() const {
    return tamanho;
}


template <class P>
void ListaEncadeada<P>::adicionarInicio(P valor) {
    No<P>* novo = new No<P>(valor);
    if (vazia()) {
        cabeca = novo;
        cauda = novo;
    } else {
        novo->proximo = cabeca;
        cabeca = novo;
    }
    tamanho++;
}


template <class P>
void ListaEncadeada<P>::adicionarFim(P valor) {
    No<P>* novo = new No<P>(valor);
    if (vazia()) {
        cabeca = novo;
        cauda = novo;
    } else {
        cauda->proximo = novo;
        cauda = novo;
    }
    tamanho++;
}


template <class P>
void ListaEncadeada<P>::adicionarPorPosicao(P valor, int posicao) {
    if (posicao < 0 || posicao > tamanho) {
        std::cout << "Posição inválida" << std::endl;
        return;
    }
    if (posicao == 0) {
        adicionarInicio(valor);
    } else if (posicao == tamanho) {
        adicionarFim(valor);
    } else {
        No<P>* novo = new No<P>(valor);
        No<P>* atual = cabeca;
        for (int i = 0; i < posicao - 1; i++) {
            atual = atual->proximo;
        }
        novo->proximo = atual->proximo;
        atual->proximo = novo;
        tamanho++;
    }
}


template <class P>
void ListaEncadeada<P>::removerInicio() {
    if (vazia()) {
        std::cout << "Lista vazia" << std::endl;
        return;
    }
    No<P>* temp = cabeca;
    cabeca = cabeca->proximo;
    delete temp;
    tamanho--;
    if (cabeca == nullptr) {
        cauda = nullptr;
    }
}


template <class P>
void ListaEncadeada<P>::removerFim() {
    if (vazia()) {
        std::cout << "Lista vazia" << std::endl;
        return;
    }
    if (cabeca == cauda) {
        delete cabeca;
        cabeca = nullptr;
        cauda = nullptr;
    } else {
        No<P>* atual = cabeca;
        while (atual->proximo != cauda) {
            atual = atual->proximo;
        }
        delete cauda;
        cauda = atual;
        cauda->proximo = nullptr;
    }
    tamanho--;
}

template <class P>
void ListaEncadeada<P>::removerPorPosicao(int posicao) {
    if (posicao < 0 || posicao >= tamanho) {
        std::cout << "Posição inválida" << std::endl;
        return;
    }
    if (posicao == 0) {
        removerInicio();
    } else if (posicao == tamanho - 1) {
        removerFim();
    } else {
        No<P>* atual = cabeca;
        for (int i = 0; i < posicao - 1; i++) {
            atual = atual->proximo;
        }
        No<P>* temp = atual->proximo;
        atual->proximo = temp->proximo;
        delete temp;
        tamanho--;
    }
}

template <class P>
void ListaEncadeada<P>::imprimir() const {
    No<P>* atual = cabeca;
    while (atual != nullptr) {
        atual->valor.printDetails();
        std::cout << "\n------------------------" << std::endl;
        atual = atual->proximo;
    }
    std::cout << std::endl;
}

template <class P>
std::string ListaEncadeada<P>::alterar(int valor, int op){
     std::string retorno;
     No<P>* atual = cabeca;
    while (atual != nullptr) {
         if(atual->valor.getId() == valor){
            std::cout<<std::endl;
            atual->valor.printDetails();
            std::cout<<std::endl;
            if(op == 1){
            atual->valor.alterar();
            } else if(op == 2) {
                std::cout<<"Removido com sucesso!!\n"<<std::endl;
                atual = atual->proximo;
                continue;
            } else if(op == 3){
                atual->valor.incrementarLivro();
            }
            
        }
        retorno += atual->valor.toString();
        atual = atual->proximo;      
    }

    return retorno;
}

template <class P>
bool ListaEncadeada<P>::existe(std::string valor, std::string *campo){
    No<P>* atual = cabeca;
    while (atual != nullptr) {
        if(atual->valor.comparar(valor)){
            *campo = alterar(atual->valor.getId(), 3);
            return true;
        }
        
        atual = atual->proximo;  

    }

    return false;
}

template <class P>
No<P>* ListaEncadeada<P>::getCauda(){
    return this->cauda;
}


#endif  
