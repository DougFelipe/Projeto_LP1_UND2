#include "Livro.h"

Livro::Livro(){}

Livro::Livro(std::string titulo, int anoPublicacao, std::string editora, std::string autor,
          std::string genero){
            this->titulo = titulo;
            this->anoPublicacao = anoPublicacao;
            this->editora = editora;
            this->autor = autor;
            this->genero = genero;
          }

Livro::~Livro(){}

std::string Livro::getTitulo(){
  return titulo;
}

void Livro::setTitulo(std::string titulo){
  this->titulo = titulo;
}

int Livro::getAnoPublicacao(){
  return anoPublicacao;
}

void Livro::setAnoPublicacao(int ano){
  this->anoPublicacao = ano;
}

std::string Livro::getEditora(){
  return editora;
}

void Livro::setEditora(std::string editora){
  this->editora = editora;
}

std::string Livro::getAutor(){
  return autor;
}

void Livro::setAutor(std::string autor){
  this->autor = autor;
}

std::string Livro::getGenero(){
  return genero;
}

void Livro::setGenero(std::string genero){
  this->genero = genero;
}

std::string Livro::toString(){
  std::string retorno = this->titulo + ";" + std::to_string(this->anoPublicacao) + ";" + this->editora + ";" + this->autor + ";" + this->genero + "\n";

  return retorno;
}
