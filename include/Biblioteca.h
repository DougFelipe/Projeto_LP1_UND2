/**
 * @file Biblioteca.h
 * @brief Declaração da Classe Biblioteca
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
#include <string>
#include <fstream>

#include "../include/Autor.h"
#include "../include/Leitor.h"
#include "../include/Livro.h"
#include "../include/Editora.h"

/**
 * @brief Classe que representa uma Biblioteca.
 *
 * Essa classe contém funcionalidades relacionadas a uma Biblioteca, como cadastrar um livro, autor, editora, alem de fazer buscas se existe ou não. *  
 */
class Biblioteca {

public:

  template <class E>
  int pegarUltimoId(std::string nomeArquivo);  

  /**
   * @brief Função template para realizar o cadastro de um objeto generico.
   *
   * @tparam E A classe a ser utilizada na operação.
   * @param obj O objeto que será armazenado no arquivo.
   * @param nomeArquivo O nome do arquivo onde será feito o cadastro.
   */
  template <class E>
  void cadastrar(E obj, std::string nomeArquivo);

   /**
   * @brief Função template para realizar a leitura do arquivo.
   *
   * @tparam E A classe a ser utilizada na operação.
   * @param nomeArquivo O nome do arquivo onde será feito o cadastro.
   */
  template <class E>
  void ler(std::string nomeArquivo);

  template <class E>
  void alterar(std::string nomeArquivo);

  /**
   * @brief Recebe os dados do Autor que serão armazenados. 
   */
  void escreverAutor();

  /**
   * @brief Recebe os dados do Leitor que serão armazenados. 
   */
  void escreverLeitor();

  /**
   * @brief Recebe os dados da Editora que serão armazenados. 
   */
  void escreverEditora();

  /**
   * @brief Recebe os dados do Livro que serão armazenados. 
   */
  void escrevreLivro();

  /**
   * @brief Responsavel pelo sub-menu da Editora, onde direciona para o metodo reponsavel pela operação
   */
  void buscarEditora();

  /**
   * @brief Responsavel pelo sub-menu do Autor onde direciona para o metodo reponsavel pela operação
   */
  void buscarAutor();

  /**
   * @brief Responsavel pelo sub-menu do Leitor, onde direciona para o metodo reponsavel pela operação
   */
  void buscarLeitor();

  /**
   * @brief Responsavel pelo sub-menu do Livro, onde direciona para o metodo reponsavel pela operação
   */
  void buscarLivro();
  
};

#endif
