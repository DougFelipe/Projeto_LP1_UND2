#include "Pessoa.h"

Pessoa::Pessoa() {}

Pessoa::Pessoa(int id, std::string nome) {
  this->id = id;
  this->nome = nome;
}

int Pessoa::getId(){
  return this->id;
}

void Pessoa::setId(int id){
  this->id = id;
}

std::string Pessoa::getNome(){
  return nome;
}

void Pessoa::setNome(std::string nome){
  this->nome = nome;
}
