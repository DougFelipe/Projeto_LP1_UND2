/**
 * @file Ordenacao.hpp
 * @brief Declaração e implementação das funções de ordenação.
 */

#ifndef ORDENACAO_HPP
#define ORDENACAO_HPP

#include <algorithm>
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

#endif 
