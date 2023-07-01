#include "ListaEncadeada.h"

template <class P>
ListaEncadeada<P>::ListaEncadeada() : cabeca(nullptr), cauda(nullptr), tamanho(0) {}

// Verifica se a lista está vazia
template <class P>
bool ListaEncadeada<P>::vazia() const {
    return tamanho == 0;
}

// Retorna o tamanho da lista
template <class P>
int ListaEncadeada<P>::tamanhoLista() const {
    return tamanho;
}

// Insere um elemento no início da lista
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

// Insere um elemento no final da lista
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

// Insere um elemento em uma posição específica da lista
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

// Remove o elemento do início da lista
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

// Remove o elemento do final da lista
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

// Remove o elemento de uma posição específica da lista
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

// Imprime os elementos da lista
template <class P>
void ListaEncadeada<P>::imprimir() const {
    No<P>* atual = cabeca;
    while (atual != nullptr) {
        std::cout << atual->valor << "\n";
        atual = atual->proximo;
    }
    std::cout << std::endl;
}
