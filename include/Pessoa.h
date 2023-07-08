/**
 * @file Pessoa.h
 * @brief Declaração da Classe Pessoa.
 */

#ifndef PESSOA_H
#define PESSOA_H

#include <string>

/**
 * @brief Classe base que representa uma Pessoa.
 */
class Pessoa {
protected:
  int id;
  std::string nome;

public:

  /**
   * @brief Construtor vazio da classe Pessoa.
   */
  Pessoa();

  /**
   * @brief Construtor com parametros da classe Livro.
   *
   * @param nome O nome da Pessoa.
   * @param rg O RG da Pessoa.
   */
  Pessoa(int id, std::string nome);
  
  int getId();

  void setId(int id);

  /**
   * @brief Obtém o nome da Pessoa.
   *
   * @return nome da Pessoa.
   */
  std::string getNome();

  /**
   * @brief Define o nome da Pessoa.
   *
   * @param nome O novo nome da Pessoa.
   */
  void setNome(std::string nome);

  /**
   * @brief Função virtual pura que precisa ser implementada pelas classes derivadas.
   */
  virtual void printDetails() = 0;  
};



#endif