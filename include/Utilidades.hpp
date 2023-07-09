/**
 * @file Utilidades.hpp
 * @brief Declaração e implementação das funções de ordenação.
 */

#ifndef UTILIDADES_HPP
#define UTILIDADES_HPP

#include <algorithm>
#include <string>
#include "Livro.h"
#include "Autor.h"
#include "Editora.h"
#include "Leitor.h"


/**
 * @brief Função que ordena um array de livros por título.
 * 
 * Algoritmo Bubble Sort para ordenar um array de Livros em ordem alfabética pelo título.
 *
 * @param livros O array de Livro a ser ordenado.
 * @param n A quantidade de livros no array.
 */
void ordenarPorTitulo(Livro* livros, int n) //bubble sort
{
    for (int i = 0; i < n-1; i++) 
    {
        for (int j = 0; j < n-i-1; j++) 
        {
            if (livros[j].getTitulo() > livros[j+1].getTitulo()) 
            {
                // Troca livros[j] e livros[j+1]
                Livro temp = livros[j];
                livros[j] = livros[j+1];
                livros[j+1] = temp;
            }
        }
    }
}

/**
 * @brief Função que ordena um array de livros por ano de publicação.
 * 
 * Algoritmo Bubble Sort para ordenar um array de Livros pelo ano de publicação.
 *
 * @param livros O array de Livro a ser ordenado.
 * @param n A quantidade de livros no array.
 */
void ordenarPorAnoPublicacao(Livro* livros, int n) //bubble sort
{
    for (int i = 0; i < n-1; i++) 
    {
        for (int j = 0; j < n-i-1; j++) 
        {
            if (livros[j].getAnoPublicacao() > livros[j+1].getAnoPublicacao()) 
            {
                // Troca livros[j] e livros[j+1]
                Livro temp = livros[j];
                livros[j] = livros[j+1];
                livros[j+1] = temp;
            }
        }
    }
}

/**
 * @brief Ordenação por selection sort.
 * 
 * Ordena um array de elementos do tipo T de acordo com o nome.
 * 
 * @tparam T O tipo dos elementos do array.
 * 
 * @param arr Referência para o array a ser ordenado.
 * @param n O número de elementos no array.
 */

template<typename T>
void selectionSort(T& arr, int n) 
{
    int min_idx;
  
    for (int i = 0; i < n-1; i++) 
    {
        min_idx = i;
        for (int j = i+1; j < n; j++)
            if (arr[j]->getNome() < arr[min_idx]->getNome())
                min_idx = j;
        std::swap(arr[min_idx], arr[i]);
    }
}

/**
* @brief Função que realiza uma busca iterativa em uma lista encadeada de Livros.
*
* @param cabeca O primeiro Livro na lista encadeada.
* @param atributo O atributo do Livro a ser comparado.
* @param valor O valor(chave) do atributo a ser encontrado.
*
* @return O Livro que corresponde ao valor do atributo buscado ou nullptr se não for encontrado.
*/
Livro* buscaIterativa(Livro* cabeca, std::string atributo, std::string valor) 
{
    Livro* temp = cabeca;
    while (temp != nullptr) 
    {
        if (atributo == "id" && std::to_string(temp->getId()) == valor) 
        {
            return temp;
        }
        else if (atributo == "titulo" && temp->getTitulo() == valor) 
        {
            return temp;
        }
        else if (atributo == "anoPublicacao" && std::to_string(temp->getAnoPublicacao()) == valor)
         {
            return temp;
        }
        else if (atributo == "editora" && temp->getEditora() == valor) 
        {
            return temp;
        }
        else if (atributo == "autor" && temp->getAutor() == valor)
         {
            return temp;
        }
        else if (atributo == "genero" && temp->getGenero() == valor) 
        {
            return temp;
        }
        temp = temp->proximo;
    }
    return nullptr; // Retorna nullptr se o livro não for encontrado.
}

/**
* @brief Função que realiza uma busca recursiva em uma lista encadeada de Livros.
*
* @param cabeca O primeiro Livro na lista encadeada.
* @param atributo O atributo do Livro a ser comparado.
* @param valor O valor(chave) do atributo a ser encontrado.
*
* @return O Livro que corresponde ao valor do atributo buscado ou nullptr se não for encontrado.
*/
Livro* buscaRecursiva(Livro* cabeca, std::string atributo, std::string valor) 
{
    if (cabeca == nullptr) 
    {
        return nullptr; // Retorna nullptr se o livro não for encontrado.
    }

    if (atributo == "id" && std::to_string(cabeca->getId()) == valor) 
    {
        return cabeca;
    }
    else if (atributo == "titulo" && cabeca->getTitulo() == valor) 
    {
        return cabeca;
    }
    else if (atributo == "anoPublicacao" && std::to_string(cabeca->getAnoPublicacao()) == valor) 
    {
        return cabeca;
    }
    else if (atributo == "editora" && cabeca->getEditora() == valor) 
    {
        return cabeca;
    }
    else if (atributo == "autor" && cabeca->getAutor() == valor) 
    {
        return cabeca;
    }
    else if (atributo == "genero" && cabeca->getGenero() == valor) 
    {
        return cabeca;
    }

    return buscaRecursiva(cabeca->proximo, atributo, valor);
}

#endif 
