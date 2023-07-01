#include <iostream>
#include <fstream>
#include <Windows.h> 
#include "../include/Biblioteca.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    
    int mainMenuOp;
    
    Biblioteca biblioteca;

    std::cout << ">>>>>>>> SISTEMA DE GERENCIAMENTO DE BIBLIOTECA <<<<<<<<" << std::endl;
    std::cout << "Digite 1 para: Continuar" << std::endl;
    std::cout << "Pressione qualquer tecla diferente de 1 para sair" << std::endl;

    std::cin >> mainMenuOp;

  if (mainMenuOp != 1){
    std::cout<<"Voce encerrou o programa!"<<std::endl;
    return 0; 
  } // Encerra o programa se a entrada for diferente de 1


    do // EM LOOPING ATÉ QUE O USUÁRIO DIGITE 9 PARA SAIR DO PROGRAMA
    {
    std::cout << ">>>>>>>> MENU DO SISTEMA DE GERENCIAMENTO DE BIBLIOTECA <<<<<<<<\n" << std::endl;
    std::cout << ">>>>>>>>                ESCOLHA UMA OPÇÃO               <<<<<<<<\n" << std::endl;

        std::cout << "---------------------------------" << std::endl;
        std::cout << "\nDigite 1 para: Cadastrar Livro" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "Digite 2 para: Cadastrar Editora" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "Digite 3 para: Cadastrar Autor" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "Digite 4 para: Cadastrar Leitor" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "Digite 5 para: Buscar Livro" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "Digite 6 para: Buscar Editora" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "Digite 7 para: Buscar Autor" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "Digite 8 para: Buscar Leitor" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "Digite 9 para: Sair" << std::endl;
        std::cout << "---------------------------------" << std::endl;

        std::cin >> mainMenuOp;

        switch (mainMenuOp)
        {
        case 1:
            biblioteca.escrevreLivro();
            break;

        case 2:
            biblioteca.escreverEditora();
            break;

        case 3:
            biblioteca.escreverAutor();
            break;

        case 4: 
            biblioteca.escreverLeitor();
            break;

        case 5://buscando livro
            biblioteca.buscarLivro();
        break;

        case 6://buscando editora
            biblioteca.buscarEditora();
        break;

        case 7://buscando autor
            biblioteca.buscarAutor(); 
        break;

        case 8://buscando leitor
            biblioteca.buscarLeitor();
        break;

        case 9:
         std::cout<<"Voce encerrou o programa!"<<std::endl;
         break;

        default:
            std::cout << "Opção Inválida" << std::endl;
            break;
        }
    } while (mainMenuOp != 9);
    return 0;
}
 