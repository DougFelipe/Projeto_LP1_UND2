#include "Editora.h"

Editora::Editora(){}

Editora::Editora(int id, std::string nome, int anoFundacao){
  this->id = id;
  this->nome = nome;
  this->anoFundacao = anoFundacao;
  this->qtdLivrosCadastrados = 0;
}

Editora::~Editora(){}

int Editora::getId(){
  return this->id;
}

void Editora::setId(int id){
  this->id = id;
}
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

int Editora::getQtdLivrosCadastrados(){
  return this->qtdLivrosCadastrados;
}

void Editora::setQtdLivrosCadastrados(int qtd){
  this->qtdLivrosCadastrados = qtd;
}

std::string Editora::toString(){
  std::string retorno = std::to_string(this->id) + ";" + this->nome + ";" + std::to_string(this->anoFundacao)
   + ";" + std::to_string(this->qtdLivrosCadastrados) + "\n";
  return retorno;
}

void Editora::printDetails(){
  std::cout<<"Codigo: "<<id
  <<"\nNome: "<<this->nome
  <<"\nAno de Fundação: "<<this->anoFundacao
  <<"\nTotal de livros cadastrados: "<<this->qtdLivrosCadastrados<<std::endl;
}

Editora* Editora::toModel(std::string linha){
         
            size_t pos = 0;
  
            // Separando os atributos por vírgula
            pos = linha.find(";");
            this->id = stoi(linha.substr(0, pos));
            linha.erase(0, pos + 1);

            pos = linha.find(";");
            this->nome = linha.substr(0, pos);
            linha.erase(0, pos + 1);

            pos = linha.find(";");
            this->anoFundacao = stoi(linha.substr(0, pos));
            linha.erase(0, pos + 1);
            
             this->qtdLivrosCadastrados = stoi(linha);

            return this;
}

bool Editora::comparar(std::string valor){
  if (valor.size() != nome.size())
        return false;

    for (size_t i = 0; i < valor.size(); ++i) {
        if (std::toupper(valor[i]) != std::toupper(nome[i]))
            return false;
    }

    return true;
}

void Editora::alterar(){
  std::cout<<"Digite o novo nome da Editora: ";
  std::cin.ignore();
    std::getline(std::cin, nome);
}

void Editora::incrementarLivro(){
  this->qtdLivrosCadastrados++;
}