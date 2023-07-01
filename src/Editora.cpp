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

void Editora::printDetails(){
  std::cout<<"Nome: "<<this->nome
  <<"\nAno de Fundação: "<<this->anoFundacao<<std::endl;
}

Editora* Editora::toModel(std::string linha){
          // Separando os atributos por vírgula e imprimindo individualmente
            size_t pos = 0;
  
            // Separando os atributos por vírgula
            pos = linha.find(";");
            this->nome = linha.substr(0, pos);
            linha.erase(0, pos + 1);
            
            this->anoFundacao = stoi(linha);

            return this;
    }