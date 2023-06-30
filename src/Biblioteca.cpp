#include "Biblioteca.h"
#include "ListaEncadeada.h"

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

void Biblioteca::escreverAutor(){
    std::string nome;
    int rg;
    std::string nacion;
    int ano;

    std::cout<<"Digite o nome:";
    std::cin.ignore(); 
    std::getline(std::cin, nome);

    std::cout<<"Digite o RG:";
    std::cin>>rg;
    
    std::cout<<"Digite onde ele nasceu:";
    std::cin.ignore(); 
    std::getline(std::cin, nacion);

    std::cout<<"Digite seu ano de nascimento:";
    std::cin>>ano;

    Autor autor(nome, rg, nacion, ano);
    cadastrar(autor, "data/autor.txt");
}

void Biblioteca::escreverLeitor(){
    std::string nome;
    int rg;

    std::cout<<"Digite o nome:";
    std::cin.ignore(); 
    std::getline(std::cin, nome);

    std::cout<<"Digite o RG:";
    std::cin>>rg;

    Leitor leitor(nome, rg);
    cadastrar(leitor, "data/leitor.txt");
    
}

void Biblioteca::escreverEditora(){
    std::string nome;
    int ano;

    std::cout<<"Digite o nome da empresa:";
    std::cin.ignore(); 
    std::getline(std::cin, nome);

    std::cout<<"Digite o ano de sua fundacao:";
    std::cin>>ano;

    Editora editora(nome, ano);
    cadastrar(editora, "data/editora.txt");
    
}

void Biblioteca::escrevreLivro(){
    std::string titulo, autor, editora, genero;
    int ano;

    std::cout<<"Digite o Titulo do livro:";
    std::cin.ignore(); 
    std::getline(std::cin, titulo);

    std::cout<<"Digite o ano do seu lançamento:";
    std::cin>>ano;

    std::cout<<"Digite o autor do livro:";
    std::cin.ignore(); 
    std::getline(std::cin, autor);

    //verifica se existe autor

    std::cout<<"Digite a editora do livro:";
    std::getline(std::cin, editora);

    //verifica se existe editora

    std::cout<<"Qual o genero do livro:";
    std::getline(std::cin, genero);

    Livro livro(titulo, ano, editora, autor, genero);
    cadastrar(livro, "data/livro.txt");
}