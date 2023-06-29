#include "Editora.h"

Editora::Editora(){}

Editora::Editora(std::string nome, int anoFundacao){
  this->nome = nome;
  this->anoFundacao = anoFundacao;
}

Editora::~Editora(){}

std::string Editora::getNome(){
  return nome;
}

void Editora::setNome(std::string nome){
  this->nome = nome;
}

int Editora::getAnoFundacao(){
  return anoFundacao;
}

void Editora::setAnoFundacao(int ano){
  this->anoFundacao = ano;
}

std::string Editora::toString(){
  std::string retorno = this->nome + ";" + std::to_string(this->anoFundacao) + "\n";
  return retorno;
}