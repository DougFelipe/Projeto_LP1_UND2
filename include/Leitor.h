/**
 * @file Leitor.h
 * @brief Declaração da Classe Leitor
 */

#ifndef Leitor_H
#define Leitor_H

#include <iostream>
#include "Livro.h"
#include "Pessoa.h"


/**
 * @brief Classe que representa um autor.
 *
 * Essa classe contém informações e funcionalidades relacionadas a um Leitor, como o livro alugado,
 * data do aluguel, geters e setters, além de metodos que fazem as conversões como o toString e toModel. Ela herda da classe Pessoa.
 */
class Leitor : public Pessoa {
  private:
    int rg;
    std::string livro;
    std::string dataAluguel;

  public:

  /**
   * @brief Construtor vazio da classe Leitor.
   */
    Leitor();

  /**
   * @brief Construtor com alguns parametros da classe Leitor.
   *
   * @param nome O nome do Autor.
   * @param rg O RG do Autor.
   */
    Leitor(int id, std::string nome, int rg);

  /**
   * @brief Destrutor da classe Leitor.
   */
    ~Leitor();
  
  /**
   * @brief Obtém o livro alugado pelo Leitor.
   *
   * @return livro alugado pelo Leitor.
   */
    std::string getLivro();

  /**
   * @brief Define o livro alugado pelo Leitor.
   *
   * @param livro O novo livro alugado pelo Leitor.
   */
    void setLivro(std::string livro);

  /**
   * @brief Obtém a data em que o Leitor alugou o livro.
   *
   * @return data do aluguel do livro.
   */
    std::string getDataALuguel();

  /**
   * @brief Define a data do aluguel do livro pelo Leitor.
   *
   * @param data A nova data do aluguel.
   */
    void setDataAluguel(std::string data);
    
  /**
   * @brief Retorna uma string com os valores separados por ';' para poder salvar em uma linha do arquivo. 
   *
   * @return string com os atributos separados por ';'.
   */
    std::string toString();

  /**
   * @brief Responsavel por converter a string que vem do arquivo em um Leitor*, pegando os valores e salvando em seus atributos. 
   *
   * @param linha A string com todos os valores separados por ';'.
   * 
   * @return o Leitor* preenchido com as informações recebidas.
   */
    Leitor* toModel(std::string linha);

  /**
   * @brief Imprime todos os valores do Leitor. 
   */
    void printDetails() override;

    bool comparar(std::string valor);

    /**
   * @brief Altera os dados do Leitor. 
   */
    void alterar();
};

#endif