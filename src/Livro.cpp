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

Livro* Livro::toModel(std::string linha){
            size_t pos = 0;
  
            // Separando os atributos por ponto vírgula
            pos = linha.find(";");
            this->titulo = linha.substr(0, pos);
            linha.erase(0, pos + 1);

            pos = linha.find(";");
            this->anoPublicacao = stoi(linha.substr(0, pos));//convert int
            linha.erase(0, pos + 1);

            pos = linha.find(";");
            this->editora= linha.substr(0, pos);
            linha.erase(0, pos + 1);

            pos = linha.find(";");
            this->autor = linha.substr(0, pos);
            linha.erase(0, pos + 1);
            
            this->genero = linha;

            return this;
}

void Livro::printDetails(){
    std::cout<<"Titulo: "<<this->titulo
    <<"\nAno de publicação: "<<this->anoPublicacao
    <<"\nAutor: "<<this->autor
    <<"\nEditora: "<<this->editora
    <<"\nGenero: "<<this->genero<<std::endl;
}

bool Livro::comparar(std::string valor){
  if (valor.size() != titulo.size())
        return false;

    for (size_t i = 0; i < valor.size(); ++i) {
        if (std::toupper(valor[i]) != std::toupper(titulo[i]))
            return false;
    }

    return true;
}

void Livro::alterar(){
  std::cout<<"Digite o novo titulo: ";

    std::getline(std::cin, titulo);
}