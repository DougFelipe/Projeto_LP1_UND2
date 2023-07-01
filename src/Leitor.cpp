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

Leitor* Leitor::toModel(std::string linha){
   // Separando os atributos por vírgula e imprimindo individualmente
            size_t pos = 0;
  
            // Separando os atributos por ponto vírgula
            pos = linha.find(";");
            this->nome = linha.substr(0, pos);
            linha.erase(0, pos + 1);

            pos = linha.find(";");
            this->rg = stoi(linha.substr(0, pos));//convert int
            linha.erase(0, pos + 1);

            pos = linha.find(";");
            this->dataAluguel = linha.substr(0, pos);
            linha.erase(0, pos + 1);
            
            this->livro = linha;

            return this;
}

void Leitor::printDetails(){
  std::cout<<"Nome: "<<this->nome
  <<"\nRG: "<<this->rg
  <<"\nData do aluguel: "<<this->dataAluguel
  <<"\nLivro alugado: "<<this->livro
  <<std::endl;
}