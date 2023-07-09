/**
 * @file Biblioteca.h
 * @brief Declaração da Classe Biblioteca
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
#include <string>
#include <fstream>

#include "Autor.h"
#include "Leitor.h"
#include "Livro.h"
#include "Editora.h"
#include "ListaSequencial.hpp"
/**
 * @brief Classe que representa uma Biblioteca.
 *
 * Essa classe contém funcionalidades relacionadas a uma Biblioteca, como cadastrar um livro, autor, editora, alem de fazer buscas se existe ou não. *  
 */
class Biblioteca {

public:

  
  /**
   * @brief Função template que retorna o ultimo id do objeto cadastrato.
   *
   * @tparam E A classe a ser utilizada na operação.
   * @param nomeArquivo O nome do arquivo onde será feito o cadastro.
   * @return o ultimo id cadastrado ou 1, caso seja o primeiro cadastro.
   */
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
   * @brief Função template para realizar a leitura do arquivo e imprimir todos.
   *
   * @tparam E A classe a ser utilizada na operação.
   * @param nomeArquivo O nome do arquivo onde será feito o cadastro.
   */
  template <class E>
  void ler(std::string nomeArquivo);

  /**
   * @brief Função template para realizar a alteração do arquivo.
   *
   * @tparam E A classe a ser utilizada na operação.
   * @param nomeArquivo O nome do arquivo onde será feito o cadastro.
   * @param op Codigo da operação: 1 - Alterar | 2 - Remover
   */
  template <class E>
  void modificarArquivo(std::string nomeArquivo, int op);

   /**
   * @brief Função template para realizar uma verificação se o objeto passado existe no arquivo.
   *
   * @tparam E A classe a ser utilizada na operação.
   * @param nomeArquivo O nome do arquivo onde será feito o cadastro.
   * @param valor Conteudo a ser usado na verificação
   */
  template <class E>
  bool existe(std::string nomeArquivo, std::string valor);

  template <class E>
  void filtro(std::string nomeArquivo, int op);


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
