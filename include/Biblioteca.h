#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H


#include <iostream>
#include <string>
#include <fstream>

#include "../include/Autor.h"
#include "../include/Leitor.h"
#include "../include/Livro.h"
#include "../include/Editora.h"

class Biblioteca {

public:
  template <class E>
  void cadastrar(E obj, std::string nomeArquivo);

  void escreverAutor();
  void escreverLeitor();
  void escreverEditora();
  void escrevreLivro();
};



#endif
