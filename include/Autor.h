#ifndef AUTOR_H
#define AUTOR_H

#include "Pessoa.h"

class Autor : public Pessoa {
  private:
    std::string nacionalidade;
    int anoNascimento;
  
  public:
    Autor();
    Autor(std::string nacionalidade, int anoNascimento);
    ~Autor();
  
    std::string getNacionalidade();
    void setNacionalidade(std::string nacionalidade);
    int getAnoNascimento();
    void setAnoNascimento(int ano);
  
    void printDetail() override;
};

#endif