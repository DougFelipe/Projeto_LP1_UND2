#ifndef Leitor_H
#define Leitor_H

#include "Livro.h"
#include "Pessoa.h"

class Leitor : public Pessoa {
  private:
    Livro livro;
    int dia; // dia que alugou o livro
    int mes;
    int ano;

  public:
    Leitor();
    Leitor(Livro livro, int dia, int mes, int ano);
    ~Leitor();
  
    Livro getLivro();
    void setLivro(Livro livro);
    int getDia();
    void setDia(int dia);
    int getMes();
    void setMes(int mes);
    int getAno();
    void setAno(int ano);
  
    void printDetail() override;
};

#endif