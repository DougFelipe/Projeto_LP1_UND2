#include <iostream>
#include "../include/Autor.h"
#include "../include/Leitor.h"
#include "../include/Livro.h"
#include "../include/Editora.h"

template <class E>
void cadastrar(E obj, std::string nomeArquivo){

}

int main() {

  int op;

  do{
    std::cout<<"Digite o numero da operacao que deseja fazer:"<<std::endl;
    std::cout<<"1 - Cadastrar um Autor\n2 - Cadastrar um Leitor\n3 - Cadastrar um Livro"<<std::endl;
    std::cout<<"4 - Cadastrar uma Editora\n5 - Alugar um Livro\n6 - Buscar"<<std::endl;


    std::cin>>op;

    if(op == 1){

    } else if(op == 2){

    } else if(op ==3){

    } else if(op == 4){

    } else if(op == 5){

    } else if(op == 6){

    } else if(op != -1){
      std::cout<<"\n----------OPCAO INVALIDA!!!----------\n"<<std::endl;
    }

  } while(op != -1);

  std::cout<<"Finalizou!";
  return 0;
}