#include "Biblioteca.h"
#include "ListaEncadeada.hpp"


template <class E>
void Biblioteca::cadastrar(E obj, std::string nomeArquivo){
 std::ofstream arquivo;
        // continua a escrita sem apagar o conteudo
        arquivo.open(nomeArquivo, std::ios::app);
        if (arquivo.is_open()) {
            arquivo << obj.toString();

            arquivo.close();
        }
}

template <class E>
void Biblioteca::ler(std::string nomeArquivo){
   ListaEncadeada<E> lista;
    // Lendo o arquivo de texto e imprimindo na tela
    std::ifstream arquivoLeitura(nomeArquivo);
    if (arquivoLeitura.is_open()) {
        std::string linha;
        while (std::getline(arquivoLeitura, linha)) {
            E objeto;
           lista.adicionarFim(*objeto.toModel(linha));
        }
        arquivoLeitura.close();
    } else {
        std::cout << "Erro ao abrir o arquivo " <<nomeArquivo<< std::endl;
        return;
    }

    std::cout << "\n-------------------------" << std::endl;
    lista.imprimir();
        
        std::cout<<"[Enter] Voltar ";
        
        std::cin.ignore();
        getchar();
        
}

template <class E>
void Biblioteca::alterar(std::string nomeArquivo){
    ListaEncadeada<E> lista;
    // Lendo o arquivo de texto e imprimindo na tela
    std::ifstream arquivoLeitura(nomeArquivo);
    if (arquivoLeitura.is_open()) {
        std::string linha;
        while (std::getline(arquivoLeitura, linha)) {
            E objeto;
           lista.adicionarFim(*objeto.toModel(linha));
        }
        arquivoLeitura.close();
    } else {
        std::cout << "Erro ao abrir o arquivo " <<nomeArquivo<< std::endl;
        return;
    }


    std::cout<<"Digite o nome para buscar: ";
    std::string valor;
    std::cin.ignore(); 
    std::getline(std::cin, valor);



    
    std::ofstream file;
    file.open(nomeArquivo);
    if(file.is_open()){
        file << lista.alterar(valor);
    }

}



void Biblioteca::escreverAutor(){
    std::string nome;
    int rg;
    std::string nacion;
    int ano;

    std::cout<<"Digite o nome: ";
    std::cin.ignore(); 
    std::getline(std::cin, nome);

    std::cout<<"Digite o RG: ";
    std::cin>>rg;
    
    std::cout<<"Digite onde ele nasceu: ";
    std::cin.ignore(); 
    std::getline(std::cin, nacion);

    std::cout<<"Digite seu ano de nascimento: ";
    std::cin>>ano;

    Autor autor(nome, rg, nacion, ano);
    cadastrar(autor, "data/autor.txt");
}

void Biblioteca::escreverLeitor(){
    std::string nome;
    int rg;

    std::cout<<"Digite o nome: ";
    std::cin.ignore(); 
    std::getline(std::cin, nome);

    std::cout<<"Digite o RG: ";
    std::cin>>rg;

    Leitor leitor(nome, rg);
    cadastrar(leitor, "data/leitor.txt");
    
}

void Biblioteca::escreverEditora(){
    std::string nome;
    int ano;

    std::cout<<"Digite o nome da empresa: ";
    std::cin.ignore(); 
    std::getline(std::cin, nome);

    std::cout<<"Digite o ano de sua fundacao: ";
    std::cin>>ano;

    Editora editora(nome, ano);
    cadastrar(editora, "data/editora.txt");
    
}

void Biblioteca::escrevreLivro(){
    std::string titulo, autor, editora, genero;
    int ano;

    std::cout<<"Digite o Titulo do livro: ";
    std::cin.ignore(); 
    std::getline(std::cin, titulo);

    std::cout<<"Digite o ano do seu lançamento: ";
    std::cin>>ano;

    std::cout<<"Digite o autor do livro: ";
    std::cin.ignore(); 
    std::getline(std::cin, autor);

    //verifica se existe autor

    std::cout<<"Digite a editora do livro: ";
    std::getline(std::cin, editora);

    //verifica se existe editora

    std::cout<<"Qual o genero do livro: ";
    std::getline(std::cin, genero);

    Livro livro(titulo, ano, editora, autor, genero);
    cadastrar(livro, "data/livro.txt");
}


void Biblioteca::buscarEditora(){
     // Menu das opções para editora
            int optionMenu;
            std::cout << "Escolha uma opção no menu de editora:\n" << std::endl;
            std::cout << "1. Alterar editora\n" << std::endl;
            std::cout << "2. Remover editora\n" << std::endl;
            std::cout << "3. Ver todos os dados\n"<<std::endl;
            std::cout << "4. Procurar por uma editora\n"<<std::endl;

            std::cin >> optionMenu;

            switch (optionMenu)
            {
            case 1:
                alterar<Editora>("data/editora.txt");
                break;

            case 2:
                // Lógica para remover editora
                break;
            case 3:
                ler<Editora>("data/editora.txt");
                break;
            case 4:
                //logica para buscar uma editora
                break;
            default:
                std::cout << "Opção Inválida" << std::endl;
                break;
            }
} 

void Biblioteca::buscarAutor(){
     // Lógica para buscar autor
            int optionMenu;
            std::cout << "Escolha uma opção no menu de autor:\n" << std::endl;
            std::cout << "1. Alterar autor\n" << std::endl;
            std::cout << "2. Remover autor\n" << std::endl;
            std::cout << "3. Ver todos os dados\n"<<std::endl;
            std::cout << "4. Procurar por um Autor\n"<<std::endl;
            std::cin >> optionMenu;

            switch (optionMenu)
            {
            case 1:
                alterar<Autor>("data/autor.txt");
                break;

            case 2:
                // Lógica para remover autor
                break;
            case 3:
                ler<Autor>("data/autor.txt");
                break;
            case 4:
                //logica para buscar um autor
                break;
            default:
                std::cout << "Opção Inválida" << std::endl;
                break;
            }
} 

void Biblioteca::buscarLeitor(){
     // Lógica para buscar leitor
            int optionMenu;
            std::cout << "Escolha uma opção para buscar leitor:\n" << std::endl;
            std::cout << "1. Alterar leitor\n" << std::endl;
            std::cout << "2. Remover leitor\n" << std::endl;
            std::cout << "3. Ver todos os dados\n"<<std::endl;
            std::cout << "4. Procurar por um Leitor\n"<<std::endl;
            std::cin >> optionMenu;

            switch (optionMenu)
            {
            case 1:
                alterar<Leitor>("data/leitor.txt");
                break;

            case 2:
                // Lógica para remover leitor
                break;
            case 3:
                ler<Leitor>("data/leitor.txt");
                break;
            case 4:
                //logica para buscar um Leitor
                break;
            default:
                std::cout << "Opção Inválida" << std::endl;
                break;
            }
}

void Biblioteca::buscarLivro(){
     // Lógica para buscar livro
            int optionMenu;
            std::cout << "Escolha uma opção no menu de livros:\n" << std::endl;
            std::cout << "1. Alterar livro\n" << std::endl;
            std::cout << "2. Remover livro\n" << std::endl;
            std::cout << "3. Alugar livro\n" << std::endl;
            std::cout << "4. Ver todos os dados\n"<<std::endl;
            std::cout << "5. Procurar por um Leitor\n"<<std::endl;
            std::cin >> optionMenu;

            switch (optionMenu)
            {
            case 1:
               alterar<Livro>("data/livro.txt");
                break;

            case 2:
                // Lógica para remover livro
                break;
            case 3:
            // Lógica para alugar livro
                break;
            case 4:
                ler<Livro>("data/livro.txt");
                break;
            case 5:
                
                break;

            default:
                std::cout << "Opção Inválida\n" << std::endl;
                break;
            }
}