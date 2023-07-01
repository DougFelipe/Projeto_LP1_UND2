#ifndef EDITORA_H
#define EDITORA_H

#include <string>
#include <iostream>

class Editora{
  private:
    std::string nome;
    int anoFundacao;
  public:
    Editora();
    Editora(std::string nome, int anoFundacao);
    ~Editora();

    std::string getNome();
    void setNome(std::string nome);
    int getAnoFundacao();
    void setAnoFundacao(int ano);
    std::string toString();
    void printDetails();
    Editora* toModel(std::string linha);
};


#endif