#include "Pessoa.h"

Pessoa::Pessoa() {}

Pessoa::Pessoa(std::string nome, int rg) {
  this->nome = nome;
  this->rg = rg;
}

std::string Pessoa::getNome(){
  return nome;
}

void Pessoa::setNome(std::string nome){
  this->nome = nome;
}

int Pessoa::getRg(){
  return rg;
}

void Pessoa::setRg(int rg){
  this->rg=rg;
}
