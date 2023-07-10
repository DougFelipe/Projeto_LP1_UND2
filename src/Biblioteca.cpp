#include "Biblioteca.h"

template <class E>
int Biblioteca::pegarUltimoId(std::string nomeArquivo){
   
   ListaEncadeada<E> lista = arquivo.criarListaEncadeada<E>(nomeArquivo);

    if(lista.vazia()){
        return 1;
    } else return lista.getCauda()->valor.getId() + 1;
}

template <class E>
void Biblioteca::cadastrar(E obj, std::string nomeArquivo){

       arquivo.salvar(obj, nomeArquivo);
}

template <class E>
void Biblioteca::ler(std::string nomeArquivo){
   
   ListaEncadeada<E> lista = arquivo.criarListaEncadeada<E>(nomeArquivo);
    
    std::cout << "\n---------------------------" << std::endl;
    lista.imprimir();
        
    std::cout<<"[Enter] Voltar ";
        
    std::cin.ignore();
    getchar();
        
}

template <class E>
void Biblioteca::modificarArquivo(std::string nomeArquivo, int op){
  
   ListaEncadeada<E> lista = arquivo.criarListaEncadeada<E>(nomeArquivo);

    std::cout<<"Digite o codigo para buscar: ";
    int valor;
    std::cin>>valor;

    arquivo.reescreverArquivo<E>(nomeArquivo, lista.alterar(valor, op));

}

template <class E>
bool Biblioteca::existe(std::string nomeArquivo, std::string valor){
    //incrementa autor e editora
   ListaEncadeada<E> lista = arquivo.criarListaEncadeada<E>(nomeArquivo);
   
    std::string campo = "";
    if(lista.existe(valor, &campo)){
        arquivo.reescreverArquivo<E>(nomeArquivo, campo);
        return true;
    }
    return false;

}

template <class E>
void Biblioteca::filtro(std::string nomeArquivo, int op){

    Vetor<E> lista(1);
    std::string valor;
    char c = ' ';

    arquivo.criarListaSequencial<E>(nomeArquivo, &lista);
    
    std::cout<<"De quem você quer filtrar?:  ";
    std::cin.ignore();
    std::getline(std::cin, valor);
    lista.filtra(valor,op);

    do{
        std::cout << "\n---------------------------" << std::endl;
        lista.imprime();
        std::cout<<"[q] Voltar  [n] Ordenar pelo nome  [i] Ordenar pelo ano : ";
        
        std::cin>>c;

        if(c=='n'){
            lista.ordenarPorTitulo();
        } else if(c=='i'){
            lista.ordenarPorAnoPublicacao();
        }
    
    }while(c!='q');
}

template <class E>
void Biblioteca::buscaElemento(std::string nomeArquivo){
    Vetor<E> lista(1);
    arquivo.criarListaSequencial<E>(nomeArquivo, &lista);

    int id;
    std::cout<<"Digite o id para buscar: ";
    std::cin>>id;

    lista.findById(id);
    std::cout<<"\n[Enter] Voltar\n";
        
    std::cin.ignore();
    getchar();
}


void Biblioteca::alugarLivro(){
    Vetor<Livro> listaLivro(1);
    arquivo.criarListaSequencial<Livro>("data/livro.txt", &listaLivro);

    Vetor<Leitor> listaLeitor(1);
    arquivo.criarListaSequencial<Leitor>("data/leitor.txt", &listaLeitor);

    int idLivro, idLeitor;

    std::cout<<"Digite o id do Leitor para buscar: ";
    std::cin>>idLeitor;

    std::cout<<"Digite o id do Livro para buscar: ";
    std::cin>>idLivro;

    std::string campo = listaLeitor.alugar(
        listaLivro.buscaBinariaRecursiva(idLivro, 0, listaLivro.sizeOf()),
        listaLeitor.buscaBinariaRecursiva(idLeitor, 0, listaLeitor.sizeOf()),
        listaLivro.getValor(idLivro).getTitulo()
        );
    arquivo.reescreverArquivo<Leitor>("data/leitor.txt", campo);
    
}


void Biblioteca::escreverAutor(){
    std::string nome;
    std::string nacion;
    int ano;

    std::cout<<"Digite o nome: ";
    std::cin.ignore(); 
    std::getline(std::cin, nome);
    
    std::cout<<"Digite onde ele nasceu: ";
    std::getline(std::cin, nacion);

    std::cout<<"Digite seu ano de nascimento: ";
    std::cin>>ano;

    Autor autor(pegarUltimoId<Autor>("data/autor.txt"), nome, nacion, ano);
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

    Leitor leitor(pegarUltimoId<Leitor>("data/leitor.txt"), nome, rg);
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

    Editora editora(pegarUltimoId<Editora>("data/editora.txt"),nome, ano);
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
    //verifica se existe esse autor
    while(!existe<Autor>("data/autor.txt", autor)){
        std::cout<<"Esse autor não existe!\nDigite novamente: ";
        std::getline(std::cin, autor);
    }

    std::cout<<"Digite a editora do livro: ";
    std::getline(std::cin, editora);
    //verifica se existe essa editora
    while(!existe<Editora>("data/editora.txt", editora)){
        std::cout<<"Essa editora não existe!\nDigite novamente: ";
        std::getline(std::cin, editora);
    }

    std::cout<<"Qual o genero do livro: ";
    std::getline(std::cin, genero);

    Livro livro(pegarUltimoId<Livro>("data/livro.txt"),titulo, ano, editora, autor, genero);
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
            std::cout << "5. Ver todos os livros da editora\n"<<std::endl;
            
            std::cin >> optionMenu;

            switch (optionMenu)
            {
            case 1:
                modificarArquivo<Editora>("data/editora.txt", 1);
                break;

            case 2:
                 modificarArquivo<Editora>("data/editora.txt", 2);
                break;
            case 3:
                ler<Editora>("data/editora.txt");
                break;
            case 4:
                buscaElemento<Editora>("data/editora.txt");
                break;
            case 5:
                filtro<Livro>("data/livro.txt", 2);
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
            std::cout << "5. Ver todos os livros do autor\n"<<std::endl;
            std::cin >> optionMenu;

            switch (optionMenu)
            {
            case 1:
                modificarArquivo<Autor>("data/autor.txt", 1);
                break;

            case 2:
                modificarArquivo<Autor>("data/autor.txt", 2);
                break;
            case 3:
                ler<Autor>("data/autor.txt");
                break;
            case 4:
                buscaElemento<Autor>("data/autor.txt");
                break;
            case 5:
                filtro<Livro>("data/livro.txt", 1);
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
                modificarArquivo<Leitor>("data/leitor.txt", 1);
                break;

            case 2:
                modificarArquivo<Leitor>("data/leitor.txt", 2);
                break;
            case 3:
                ler<Leitor>("data/leitor.txt");
                break;
            case 4:
                buscaElemento<Leitor>("data/leitor.txt");
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
            std::cout << "5. Procurar por um Livro \n"<<std::endl;
            std::cin >> optionMenu;

            switch (optionMenu)
            {
            case 1:
               modificarArquivo<Livro>("data/livro.txt",1);
                break;

            case 2:
                 modificarArquivo<Livro>("data/livro.txt",2);
                break;
            case 3:
                alugarLivro();
                break;
            case 4:
                ler<Livro>("data/livro.txt");
                break;
            case 5:
                buscaElemento<Livro>("data/livro.txt");
                break;
            default:
                std::cout << "Opção Inválida\n" << std::endl;
                break;
            }
}