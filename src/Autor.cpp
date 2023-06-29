#include "Autor.h"

Autor::Autor() {}

Autor::Autor(std::string nome, int rg, std::string nacionalidade,
             int anoNascimento) : Pessoa(nome, rg){
  this->nacionalidade = nacionalidade;
  this->anoNascimento = anoNascimento;
}

std::string Autor::getNacionalidade() { return nacionalidade; }

void Autor::setNacionalidade(std::string nacionalidade) {
  this->nacionalidade = nacionalidade;
}

int Autor::getAnoNascimento() { return anoNascimento; }

void Autor::setAnoNascimento(int ano) { this->anoNascimento = ano; }

std::string Autor::toString(){
  
  std::string retorno = this->nome + ";" + std::to_string(this->rg) + ";" 
        + this->nacionalidade + ";" + std::to_string(this->anoNascimento)+"\n";

  return retorno;
}

void Autor::printDetails() {
  std::cout<<"Nome: "<<nome<<"\nNatural de: "<<nacionalidade;
}