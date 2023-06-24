#include "Leitor.h"

Leitor::Leitor(){}

Leitor::Leitor(std::string nome, int rg, Livro livro, int dia, int mes, int ano) : Pessoa(nome, rg){
  this->livro = livro;
  this->dia = dia;
  this->mes = mes;
  this->ano = ano;
}

Leitor::~Leitor(){}

Livro Leitor::getLivro(){
  return livro;
}

void Leitor::setLivro(Livro livro){
  this->livro = livro;
}

int Leitor::getDia(){
  return dia;
}

void Leitor::setDia(int dia){
  this->dia = dia;
}

int Leitor::getMes(){
  return mes;
}

void Leitor::setMes(int mes){
  this->mes = mes;
}

int Leitor::getAno(){
  return ano;
}

void Leitor::setAno(int ano){
  this->ano = ano;
}

void Leitor::printDetails(){
  std::cout<<"Nome: "<<getNome()<<"\nData do aluguel: "<<getDia()<<"/"<<getMes()<<"/"<<getAno()<<"\nLivro alugado: "<<livro.getTitulo()<<std::endl;
}