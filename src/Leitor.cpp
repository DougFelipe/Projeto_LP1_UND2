#include "Leitor.h"

Leitor::Leitor(){}

Leitor::Leitor(std::string nome, int rg) : Pessoa(nome, rg){
  this->livro = "Nenhum livro alugado";
  this->dataAluguel = "00/00/0000";
}

Leitor::~Leitor(){}

std::string Leitor::getLivro(){
  return livro;
}

void Leitor::setLivro(std::string livro){
  this->livro = livro;
}

std::string Leitor::getDataALuguel(){
  return dataAluguel;
}

void Leitor::setDataAluguel(std::string data){
  this->dataAluguel = data;
}

std::string Leitor::toString(){
  std::string retorno = this->nome + ";" + std::to_string(this->rg) + ";" + dataAluguel + ";" + livro + "\n";
  return retorno;
}

void Leitor::printDetails(){
  std::cout<<"Nome: "<<getNome()<<"\nData do aluguel: "<<getDataALuguel()<<"\nLivro alugado: "<<getLivro()<<std::endl;
}