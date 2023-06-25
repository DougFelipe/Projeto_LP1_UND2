#include <iostream>
using namespace std;
#include "../include/Autor.h"
#include "../include/Leitor.h"
#include "../include/Livro.h"
#include "../include/Editora.h"

template <class E>
void cadastrar(E obj, std::string nomeArquivo){

}

int main()
{
    int mainMenuOp, sample;

    cout << ">>>>>>>> SISTEMA DE GERENCIAMENTO DE BIBLIOTECA <<<<<<<<" << endl;
    cout << "Digite 1 para: Continuar" << endl;
    cin >> sample;

    while (sample < 2) // EM LOOPING ATÉ QUE O USUÁRIO DIGITE 2 PARA SAIR DO PROGRAMA
    {
        cout << "\nDigite 1 para: Cadastrar Livro" << endl;
        cout << "---------------------------------" << endl;
        cout << "Digite 2 para: Cadastrar Editora" << endl;
        cout << "---------------------------------" << endl;
        cout << "Digite 3 para: Cadastrar Autor" << endl;
        cout << "---------------------------------" << endl;
        cout << "Digite 4 para: Cadastrar Leitor" << endl;
        cout << "---------------------------------" << endl;
        cout << "Digite 5 para: Buscar Livro" << endl;
        cout << "---------------------------------" << endl;
        cout << "Digite 6 para: Buscar Editora" << endl;
        cout << "---------------------------------" << endl;
        cout << "Digite 7 para: Buscar Autor" << endl;
        cout << "---------------------------------" << endl;
        cout << "Digite 8 para: Buscar Leitor" << endl;
        cout << "---------------------------------" << endl;

        cin >> mainMenuOp;

        switch (mainMenuOp)
        {
        case 1:
            // Lógica para cadastrar livro
            break;

        case 2:
            // Lógica para cadastrar editora
            break;

        case 3:
            // Lógica para cadastrar autor
            break;

        case 4:
            // Lógica para cadastrar leitor
            break;

        case 5:
        {
            // Lógica para buscar livro
            int optionMenu;
            cout << "Escolha uma opção no menu de livros:\n" << endl;
            cout << "1. Alterar livro\n" << endl;
            cout << "2. Remover livro\n" << endl;
            cout << "3. Alugar livro\n" << endl;
            cin >> optionMenu;

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
                cout << "Opção Inválida" << endl;
                break;
            }
        }
        break;

        case 6:
        {
            // Lógica para buscar editora
            int optionMenu;
            cout << "Escolha uma opção no menu de editora:\n" << endl;
            cout << "1. Alterar editora\n" << endl;
            cout << "2. Remover editora\n" << endl;
            cin >> optionMenu;

            switch (optionMenu)
            {
            case 1:
                // Lógica para alterar editora
                break;

            case 2:
                // Lógica para remover editora
                break;

            default:
                cout << "Opção Inválida" << endl;
                break;
            }
        }
        break;

        case 7:
        {
            // Lógica para buscar autor
            int optionMenu;
            cout << "Escolha uma opção no menu de autor:\n" << endl;
            cout << "1. Alterar autor\n" << endl;
            cout << "2. Remover autor\n" << endl;
            cin >> optionMenu;

            switch (optionMenu)
            {
            case 1:
                // Lógica para alterar autor
                break;

            case 2:
                // Lógica para remover autor
                break;

            default:
                cout << "Opção Inválida" << endl;
                break;
            }
        }
        break;

        case 8:
        {
            // Lógica para buscar leitor
            int optionMenu;
            cout << "Escolha uma opção para buscar leitor:\n" << endl;
            cout << "1. Alterar leitor\n" << endl;
            cout << "2. Remover leitor\n" << endl;
            cin >> optionMenu;

            switch (optionMenu)
            {
            case 1:
                // Lógica para alterar leitor
                break;

            case 2:
                // Lógica para remover leitor
                break;

            default:
                cout << "Opção Inválida" << endl;
                break;
            }
        }
        break;

        default:
            cout << "Opção Inválida" << endl;
            break;
        }
    }
    return 0;
}
 