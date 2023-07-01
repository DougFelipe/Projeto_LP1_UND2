#ifndef LIVRO_H
#define LIVRO_H

#include <string>
#include <iostream>
class Livro {
  private:
    std::string titulo;
    int anoPublicacao;
    std::string editora;
    std::string autor;
    std::string genero;
  
  public:
    Livro();
    Livro(std::string titulo, int anoPublicacao, std::string editora, std::string autor,
          std::string genero);
    ~Livro();
  
    std::string getTitulo();
    void setTitulo(std::string titulo);
    int getAnoPublicacao();
    void setAnoPublicacao(int ano);
    std::string getEditora();
    void setEditora(std::string editora);
    std::string getAutor();
    void setAutor(std::string autor);
    std::string getGenero();
    void setGenero(std::string genero);

    std::string toString();
    void printDetails();
    Livro* toModel(std::string linha);
};



#endif