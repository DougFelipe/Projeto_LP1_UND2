/**
 * @file Livro.h
 * @brief Declaração da Classe Livro.
 */

#ifndef LIVRO_H
#define LIVRO_H

#include <string>
#include <iostream>


/**
 * @brief Classe que representa um Livro.
 *
 * Essa classe contém informações e funcionalidades relacionadas a um Livro, como seu titulo,
 * ano de publicação, editora, autor, genero,  geters e setters, além de metodos que fazem as conversões como o toString e toModel.
 */
class Livro {
  private:
    std::string titulo;
    int anoPublicacao;
    std::string editora;
    std::string autor;
    std::string genero;
  
  public:

  /**
   * @brief Construtor vazio da classe Livro.
   */
    Livro();

  /**
   * @brief Construtor com parametros da classe Livro.
   *
   * @param titulo O titulo do Livro.
   * @param anoPublicacao O ano da publicação do livro.
   * @param editora A editora do Livro.
   * @param autor O autor que escreveu o Livro.
   * @param genero O gênero do livro.
   */
    Livro(std::string titulo, int anoPublicacao, std::string editora, std::string autor,
          std::string genero);

  /**
   * @brief Destrutor da classe Livro.
   */
    ~Livro();
  
  /**
   * @brief Obtém o titulo do livro.
   *
   * @return titulo do Livro.
   */
    std::string getTitulo();

  /**
   * @brief Define o titulo do livro.
   *
   * @param titulo O novo titulo do Livro.
   */
    void setTitulo(std::string titulo);

  /**
   * @brief Obtém o ano de publicação do livro.
   *
   * @return ano de publicação do Livro.
   */
    int getAnoPublicacao();

  /**
   * @brief Define o ano de publicação do livro.
   *
   * @param ano O novo ano de publicação do Livro.
   */
    void setAnoPublicacao(int ano);

  /**
   * @brief Obtém o ano de publicação do livro.
   *
   * @return ano de publicação do Livro.
   */
    std::string getEditora();

  /**
   * @brief Define a editora do livro.
   *
   * @param editora A nova editora do Livro.
   */
    void setEditora(std::string editora);

  /**
   * @brief Obtém o autor do livro.
   *
   * @return autor do Livro.
   */
    std::string getAutor();

  /**
   * @brief Define o autor do livro.
   *
   * @param autor O novo autor do Livro.
   */
    void setAutor(std::string autor);

  /**
   * @brief Obtém o genero do livro.
   *
   * @return genero do Livro.
   */
    std::string getGenero();

  /**
   * @brief Define o genero do livro.
   *
   * @param genero O novo genero do Livro.
   */
    void setGenero(std::string genero);

  /**
   * @brief Retorna uma string com os valores separados por ';' para poder salvar em uma linha do arquivo. 
   *
   * @return string com os atributos separados por ';'.
   */
    std::string toString();

  /**
   * @brief Imprime todos os valores do Livro. 
   */
    void printDetails();

  /**
   * @brief Responsavel por converter a string que vem do arquivo em um Livro*, pegando os valores e salvando em seus atributos. 
   *
   * @param linha A string com todos os valores separados por ';'.
   * 
   * @return o Livro* preenchido com as informações recebidas.
   */
    Livro* toModel(std::string linha);

    bool comparar(std::string valor);

    void alterar();
};

#endif