#include <iostream>
#include <fstream>
#include <Windows.h> 
#include "../include/Biblioteca.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    
    int mainMenuOp;
    
    Biblioteca *biblioteca = new Biblioteca();

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
            biblioteca->escrevreLivro();
            break;

        case 2:
            biblioteca->escreverEditora();
            break;

        case 3:
            biblioteca->escreverAutor();
            break;

        case 4:
            biblioteca->escreverLeitor();
            break;

        case 5:
        {
            // Lógica para buscar livro
            int optionMenu;
            std::cout << "Escolha uma opção no menu de livros:\n" << std::endl;
            std::cout << "1. Alterar livro\n" << std::endl;
            std::cout << "2. Remover livro\n" << std::endl;
            std::cout << "3. Alugar livro\n" << std::endl;
            std::cin >> optionMenu;

            switch (optionMenu)
            {
            case 1:
                // Lógica para alterar livro
                break;

            case 2:
                // Lógica para remover livro
                break;

            case 3:
                // Lógica para alugar livro
                break;

            default:
                std::cout << "Opção Inválida\n" << std::endl;
                break;
            }
        }
        break;

        case 6:
        {
            // Lógica para buscar editora
            int optionMenu;
            std::cout << "Escolha uma opção no menu de editora:\n" << std::endl;
            std::cout << "1. Alterar editora\n" << std::endl;
            std::cout << "2. Remover editora\n" << std::endl;
            std::cin >> optionMenu;

            switch (optionMenu)
            {
            case 1:
                // Lógica para alterar editora
                break;

            case 2:
                // Lógica para remover editora
                break;

            default:
                std::cout << "Opção Inválida" << std::endl;
                break;
            }
        }
        break;

        case 7:
        {
            // Lógica para buscar autor
            int optionMenu;
            std::cout << "Escolha uma opção no menu de autor:\n" << std::endl;
            std::cout << "1. Alterar autor\n" << std::endl;
            std::cout << "2. Remover autor\n" << std::endl;
            std::cin >> optionMenu;

            switch (optionMenu)
            {
            case 1:
                // Lógica para alterar autor
                break;

            case 2:
                // Lógica para remover autor
                break;

            default:
                std::cout << "Opção Inválida" << std::endl;
                break;
            }
        }
        break;

        case 8:
        {
            // Lógica para buscar leitor
            int optionMenu;
            std::cout << "Escolha uma opção para buscar leitor:\n" << std::endl;
            std::cout << "1. Alterar leitor\n" << std::endl;
            std::cout << "2. Remover leitor\n" << std::endl;
            std::cin >> optionMenu;

            switch (optionMenu)
            {
            case 1:
                // Lógica para alterar leitor
                break;

            case 2:
                // Lógica para remover leitor
                break;

            default:
                std::cout << "Opção Inválida" << std::endl;
                break;
            }
        }
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
 