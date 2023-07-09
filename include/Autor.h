/**
 * @file Autor.h
 * @brief Declaração da Classe Autor
 */

#ifndef AUTOR_H
#define AUTOR_H

#include "Pessoa.h"
#include <iostream>
#include <string>

/**
 * @brief Classe que representa um autor.
 *
 * Essa classe contém informações e funcionalidades relacionadas a um autor, como sua nacionalidade,
 * ano de nascimento, geters e setters, além de metodos que fazem as conversões como o toString e toModel. Ela herda da classe Pessoa.
 */
class Autor : public Pessoa {
private:
  std::string nacionalidade; 
  int anoNascimento; 
  int livrosCadastrados;

public:
  /**
   * @brief Construtor vazio da classe Autor.
   */
  Autor();

  /**
   * @brief Construtor com parametros da classe Autor.
   *
   * @param id O ID do autor.
   * @param nome O nome do Autor.
   * @param rg O RG do Autor.
   * @param nacionalidade O país onde o Autor nasceu.
   * @param anoNascimento O ano que o autor nasceu.
   */
  Autor(int id, std::string nome, std::string nacionalidade, int anoNascimento) ;
  
  /**
   * @brief Obtém a nacionalidade do autor.
   *
   * @return nacionalidade do autor.
   */
  std::string getNacionalidade();

  /**
   * @brief Define a nacionalidade do autor.
   *
   * @param nacionalidade A nova nacionalidade do autor.
   */
  void setNacionalidade(std::string nacionalidade);

  /**
   * @brief Obtém o ano de nascimento do autor.
   *
   * @return ano de nascimento do autor.
   */
  int getAnoNascimento();

  /**
   * @brief Define o ano em que nasceu o autor.
   *
   * @param ano O novo ano de nascimento do autor.
   */
  void setAnoNascimento(int ano);

   /**
   * @brief Obtém a quantidade de livros cadastrados desse autor.
   *
   * @return quantidade de livros cadastrados desse autor.
   */
  int getLivrosCadastrados();

  /**
   * @brief Define a quantidade de livros cadastrados desse autor.
   *
   * @param qtd A nova quantidade de livros cadastrados desse autor.
   */
  void setLivrosCadastrados(int qtd);

  /**
   * @brief Retorna uma string com os valores separados por ';' para poder salvar em uma linha do arquivo. 
   *
   * @return string com os atributos separados por ';'.
   */
  std::string toString();

  /**
   * @brief Responsavel por converter a string que vem do arquivo em um Autor*, pegando os valores e salvando em seus atributos. 
   *
   * @param linha A string com todos os valores separados por ';'.
   * 
   * @return o Autor* preenchido com as informações recebidas.
   */
  Autor* toModel(std::string linha);

  /**
   * @brief Imprime todos os valores do Autor. 
   */
  void printDetails() override;

  /**
   * @brief Compara se o valor passado pelo parametro é igual ao nome do autor. 
   * @param valor Valor para a comparação.
   * @return true se forem iguais ou falso se forem diferentes.
   */
  bool comparar(std::string valor);

  /**
   * @brief Altera os dados do Autor.
   */
  void alterar();

  /**
   * @brief Incrementa mais um a cada livro que for cadastrado com essse autor.
   */
  void incrementarLivro();
};

#endif

