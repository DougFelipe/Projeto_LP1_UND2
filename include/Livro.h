#ifndef LIVRO_H
#define LIVRO_H

#include "Autor.h"
#include <string>

class Livro {
  private:
    std::string titulo;
    int anoPublicacao;
    std::string editora;
    Autor autor;
    std::string genero;
  
  public:
    Livro();
    Livro(std::string titulo, int anoPublicacao, std::string editora, Autor autor,
          std::string genero);
    ~Livro();
  
    std::string getTitulo();
    void setTitulo(std::string titulo);
    int getAnoPublicacao();
    void setAnoPublicacao(int ano);
    std::string getEditora();
    void setEditora(std::string editora);
    Autor getAutor();
    void setAutor();
    std::string getGenero();
    void setGenero(std::string genero);
};

#endif