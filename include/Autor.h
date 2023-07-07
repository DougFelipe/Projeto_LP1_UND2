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

public:
  /**
   * @brief Construtor vazio da classe Autor.
   */
  Autor();

  /**
   * @brief Construtor com parametros da classe Autor.
   *
   * @param nome O nome do Autor.
   * @param rg O RG do Autor.
   * @param nacionalidade O país onde o Autor nasceu.
   * @param anoNascimento O ano que o autor nasceu.
   */
  Autor(std::string nome, int rg, std::string nacionalidade, int anoNascimento) ;
  
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

  bool comparar(std::string valor);

  void alterar();
};

#endif

