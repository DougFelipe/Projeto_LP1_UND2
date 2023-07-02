/**
 * @file Editora.h
 * @brief Declaração da Classe Editora
 */

#ifndef EDITORA_H
#define EDITORA_H

#include <string>
#include <iostream>

/**
 * @brief Classe que representa uma Editora.
 *
 * Essa classe contém informações e funcionalidades relacionadas a uma editora, como seu nome,
 * ano de fundação, geters e setters, além de metodos que fazem as conversões como o toString e toModel.
 */
class Editora{
  private:
    std::string nome;
    int anoFundacao;
  public:
  /**
   * @brief Construtor vazio da classe Editora.
   */
    Editora();

  /**
   * @brief Construtor com parametros da classe Editora.
   *
   * @param nome O nome da editora.
   * @param anoFundacao O ano em que a editora foi fundada.
   */
    Editora(std::string nome, int anoFundacao);

  /**
   * @brief Destrutor da classe editora.
   *
   */
    ~Editora();

  /**
   * @brief Obtém o nome da editora.
   *
   * @return nome da editora.
   */
    std::string getNome();

  /**
   * @brief Define o nome da editora.
   *
   * @param nome O novo nome da editora.
   */
    void setNome(std::string nome);

  /**
   * @brief Obtém o ano de fundação da editora.
   *
   * @return ano de fundação da editora.
   */
    int getAnoFundacao();

  /**
   * @brief Define o ano de fundação da editora.
   *
   * @param ano O novo ano de fundação da editora.
   */
    void setAnoFundacao(int ano);

  /**
   * @brief Retorna uma string com os valores separados por ';' para poder salvar em uma linha do arquivo. 
   *
   * @return string com os atributos separados por ';'.
   */
    std::string toString();

  /**
   * @brief Imprime todos os valores da Editora. 
   */
    void printDetails();

  /**
   * @brief Responsavel por converter a string que vem do arquivo em uma Editora*, pegando os valores e salvando em seus atributos. 
   *
   * @param linha A string com todos os valores separados por ';'.
   * 
   * @return A Editora* preenchida com as informações recebidas.
   */
    Editora* toModel(std::string linha);
};

#endif