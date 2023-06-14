#ifndef PESSOA_H
#define PESSOA_H

#include <string>

class Pessoa {
  protected:
    std::string nome;
    int rg;
  
  public:
    Pessoa();
    Pessoa(std::string nome);
    ~Pessoa();
    
    std::string getNome();
    void setNome(std::string nome);
    int getRg();
    void setRg(int rg);
  
    virtual void printDetail() = 0;
};

#endif