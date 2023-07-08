#include "Leitor.h"

Leitor::Leitor(){}

Leitor::Leitor(int id, std::string nome, int rg) : Pessoa(id, nome){
  this->rg = rg;
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
  std::string retorno = std::to_string(this->id) + ";" + this->nome + ";" + std::to_string(this->rg) + ";" + dataAluguel + ";" + livro + "\n";
  return retorno;
}

Leitor* Leitor::toModel(std::string linha){
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
            this->rg = stoi(linha.substr(0, pos));//convert int
            linha.erase(0, pos + 1);

            pos = linha.find(";");
            this->dataAluguel = linha.substr(0, pos);
            linha.erase(0, pos + 1);
            
            this->livro = linha;

            return this;
}

void Leitor::printDetails(){
  std::cout<<"Codigo: "<<id
  <<"\nNome: "<<this->nome
  <<"\nRG: "<<this->rg
  <<"\nData do aluguel: "<<this->dataAluguel
  <<"\nLivro alugado: "<<this->livro
  <<std::endl;
}

bool Leitor::comparar(std::string valor){
 if (valor.size() != nome.size())
        return false;

    for (size_t i = 0; i < valor.size(); ++i) {
        if (std::toupper(valor[i]) != std::toupper(nome[i]))
            return false;
    }

    return true;
}

void Leitor::alterar(){
  std::cout<<"Digite o novo nome do Leitor: ";
 std::cin.ignore();
    std::getline(std::cin, nome);
}