#ifndef AUTOR_H
#define AUTOR_H

#include "Pessoa.h"
#include <iostream>
#include <string>

class Autor : public Pessoa {
private:
  std::string nacionalidade;
  int anoNascimento;

public:
  Autor();
  Autor(std::string nome, int rg, std::string nacionalidade, int anoNascimento) ;
  

  std::string getNacionalidade();
  void setNacionalidade(std::string nacionalidade);
  int getAnoNascimento();
  void setAnoNascimento(int ano);
  std::string toString();
  Autor* toModel(std::string linha);

  void printDetails() override;
};



#endif

