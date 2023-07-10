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



Livro* buscaIterativa(Livro* cabeca, std::string atributo, std::string valor);
Livro* buscaRecursiva(Livro* cabeca, std::string atributo, std::string valor);
bool equalsIgnoreCase(const std::string &str1, const std::string &str2);
std::string minuscula(std::string str);


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
        //temp = temp->proximo;
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
    return nullptr;
    //return buscaRecursiva(cabeca->proximo, atributo, valor);
}

bool equalsIgnoreCase(const std::string &str1, const std::string &str2) {
  // criei essa função somente para ficar melhor de comparar as strings
  if (str1.length() != str2.length()) {
    return false;
  }

  for (size_t i = 0; i < str1.length(); i++) {
    if (std::tolower(str1[i]) != std::tolower(str2[i])) {
      return false;
    }
  }

  return true;
}

std::string minuscula(std::string str) {
    std::string result;
    for (char c : str) {
        result += std::tolower(c);
    }
    return result;
}

#endif 
