#ifndef EDITORA_H
#define EDITORA_H

#include <string>

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
};

#endif