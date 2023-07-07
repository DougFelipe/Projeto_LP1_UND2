#include "OrdenacaoLivros.h"

// Ordenação pelo título 
void ordenarPorTitulo(Livro* livros, int n) 
{
    for (int i = 0; i < n-1; i++) 
    {
        for (int j = 0; j < n-i-1; j++)
         {
            if (livros[j].getTitulo() > livros[j+1].getTitulo()) 
            {
                // troca livros[j] e livros[j+1]
                Livro temp = livros[j];
                livros[j] = livros[j+1];
                livros[j+1] = temp;
            }
        }
    }
}

// Ordenação pelo ano de publicação 
void ordenarPorAnoPublicacao(Livro* livros, int n) 
{
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) 
        {
            if (livros[j].getAnoPublicacao() > livros[j+1].getAnoPublicacao())
            {
                // troca livros[j] e livros[j+1]
                Livro temp = livros[j];
                livros[j] = livros[j+1];
                livros[j+1] = temp;
            }
        }
    }
}
