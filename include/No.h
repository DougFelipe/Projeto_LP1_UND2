/**
 * @file No.h
 * @brief Declaração da Classe No.
 */

#ifndef NO_H
#define NO_H

/**
 * @brief Classe que representa um No.
 *
 * Essa classe contém informações e funcionalidades relacionadas a uma lista encadeada, como seu valor, seu inicio e fim, assim como os metodos de adicionar no inicio e fim, remover no inicio e fim e outros que voce pode ver abaixo.
 * @tparam O A classe que sera armazenada no No.
 */
template <class O>
class No {
public:
    O valor; /**< O valor do No */
    No<O>* proximo; /**< O proximo Nó. */

    No(O valor) : valor(valor), proximo(nullptr) {}
};

#endif  
