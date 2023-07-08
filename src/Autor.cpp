#include "Autor.h"

Autor::Autor() {}

Autor::Autor(int id, std::string nome, std::string nacionalidade,
             int anoNascimento) : Pessoa(id, nome){
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
  
  std::string retorno = std::to_string(this->id) + ";" + this->nome + ";" 
        + this->nacionalidade + ";" + std::to_string(this->anoNascimento)+"\n";

  return retorno;
}

Autor* Autor::toModel(std::string linha){
    // Separando os atributos por vírgula e imprimindo individualmente
            size_t pos = 0;
  
            // Separando os atributos por ponto vírgula
            pos = linha.find(";");
            this->id = stoi(linha.substr(0, pos));
            linha.erase(0, pos + 1);

            pos = linha.find(";");
            this->nome = linha.substr(0, pos);
            linha.erase(0, pos + 1);

            pos = linha.find(";");
            this->nacionalidade = linha.substr(0, pos);
            linha.erase(0, pos + 1);
            
            this->anoNascimento = stoi(linha);

            return this;
}

void Autor::printDetails() {
  std::cout<<"Codigo: "<<id
  <<"\nNome: "<<nome
  <<"\nNascionalidade: "<<nacionalidade
  <<"\nNascido no ano de: "<<anoNascimento<<std::endl;
}

bool Autor::comparar(std::string valor){
 if (valor.size() != nome.size())
        return false;

    for (size_t i = 0; i < valor.size(); ++i) {
        if (std::toupper(valor[i]) != std::toupper(nome[i]))
            return false;
    }

    return true;
}

void Autor::alterar(){
  std::cout<<"Digite o novo nome do autor: ";
  std::getline(std::cin, nome);
}