#ifndef Leitor_H
#define Leitor_H

#include <iostream>
#include "Livro.h"
#include "Pessoa.h"

class Leitor : public Pessoa {
  private:
    std::string livro;
    std::string dataAluguel;

  public:
    Leitor();
    Leitor(std::string nome, int rg);
    ~Leitor();
  
    std::string getLivro();
    void setLivro(std::string livro);
    std::string getDataALuguel();
    void setDataAluguel(std::string data);
    
  
    std::string toString();
    void printDetails() override;
};



#endif