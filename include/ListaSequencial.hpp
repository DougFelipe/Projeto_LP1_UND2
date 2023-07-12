/**
 * @file ListaSequencial.hpp
 * @brief Declaração da Classe ListaSequencial.
 */

#ifndef LISTA_H
#define LISTA_H

#include "iostream"
#include <chrono>
#include <ctime>


/**
 * @brief Classe que representa uma Lista Encadeada.
 *
 * Essa classe contém informações e funcionalidades relacionadas a uma lista sequencial, como seu valor, seu tamanho e quantidade de elementos, assim como os metodos de adicionar no inicio e fim, remover no inicio e fim e outros que voce pode ver abaixo.
 * @tparam E a classe que sera trabalhada na lista.
 */
template <class E>
class Vetor {
private:
  int length;
  int qtd;
  E* list;

public:

/**
 * @brief Construtor da lista.
 * 
 * @param l Tamanho(length) inicial da lista.
 */
  Vetor(int l);

/**
 * @brief Destrutor da lista.
 */
  ~Vetor();

/**
 * @brief Função que imprime toda a lista.
 */
  void imprime();

  /**
 * @brief Função zera a lista, zerando a variavel qtd
 * 
 * @return 0 se tiver elementos e -1 se não existir nenhum.
 */
  int delet();

  /**
 * @brief Função que retorna a quantidade de elementos.
 * 
 * @return quantidade de elementos existentes na lista.
 */
  int sizeOf();

/**
 * @brief Função que retorna o limete da lista.
 * 
 * @return limite de capacidade da lista
 */
  int sizeOfLimit();

/**
 * @brief Função que adiciona um elemento no inicio da lista.
 * 
 * @tparam valor É o elemento a ser adicionado
 */
  int push_front(E valor);

/**
 * @brief Função que adiciona um elemento no fim da lista.
 * 
 * @tparam valor É o elemento a ser adicionado
 */
  int push_back(E valor);

  /**
 * @brief Função que remove um elemento da lista.
 */
  int insert(int index, E valor);

/**
 * @brief Função que remove o primeiro elemento da lista.
 */
  int pop_front();

/**
 * @brief Função que remove o ultimo elemento da lista.
 */
  int pop_back();

/**
 * @brief Função que remove um elemento da lista.
 * 
 * @param index é o indice do elemento
 */
  int removeAt(int index);

/**
 * @brief Função aumenta o tamanho da lista em +1.
 */
  void ampliar();

/**
 * @brief Função que filtra os livros com o  valor passado
 * 
 * @param valor Valor usado para filtrar
 * @param op Operação a ser feita, 1 = filtra para autor 2 = filtra para editora
 */
  void filtra(std::string valor, int op);

/**
 * @brief Função responsavel pelo aluguel dos livros
 * 
 * @param leitor ID do leitor que vai alugar
 * @param titulo Titulo do livro escolhido
 * 
 * @return string com todos os dados para reescrever o arquivo
 */
  std::string alugar(int leitor, std::string titulo);

  /**
 * @brief Função responsavel pelo aluguel dos livros
 * 
 * @param leitor ID do leitor que vai alugar
 * 
 * @return string com todos os dados para reescrever o arquivo
 */
  std::string entregar(int leitor);

/**
 * @brief Função que retorna um objeto buscado.
 * 
 * Ele chama o metodo buscaBinariaRecursiva para achar pelo id
 * 
 * @param id ID do objeto
 * 
 * @return O objeto encontrado
 */
  E getValor(int id);

/**
 * @brief Função que compara dusa strings.
 * 
 * @param str1 1º texto
 * @param str2 2º texto
 * 
 * @return true se forem iguais ou false se forem diferentes.
 */
  bool equalsIgnoreCase(const std::string &str1, const std::string &str2);

/**
 * @brief Função que converte string para minuscula.
 * 
 * @param str Texto para conversão
 * 
 * @return texto em minusculo
 */
  std::string minuscula(std::string str);

  /**
  * @brief Função que realiza uma busca recursiva em uma lista sequencial.
  *
  * @param chave O valor(chave) do atributo a ser encontrado.
  * @param inicio O indice inicial.
  * @param fim O indice final.
  *
  * @return a posição do valor encontrado.
  */
  int buscaBinariaRecursiva(int chave, int inicio, int fim);

/**
* @brief Função que realiza uma busca iterativa em uma lista encadeada de Livros.
*
* @param chave O valor(chave) do atributo a ser encontrado.
*
* @return a posição do valor encontrado.
*/
  int buscaBinariaIterativa(int chave);

/**
 * @brief Função que imprime um objeto buscado.
 */
  void findById(int chave);

/**
 * @brief Função que ordena um array de livros por título.
 * 
 * Algoritmo Bubble Sort para ordenar um array de Livros em ordem alfabética pelo título.
 */
  void ordenarPorTitulo();

/**
 * @brief Função que ordena um array de livros por ano de publicação.
 * 
 * Algoritmo Selection Sort para ordenar um array de Livros pelo ano de publicação.
 */
  void ordenarPorAnoPublicacao();
};

template <class E>
Vetor<E>::Vetor(int l) {
  list = new E[l];
  qtd = 0;
  length = l;
}

template <class E>
Vetor<E>::~Vetor(){
  delete[] list;
}

template <class E>
void Vetor<E>::imprime() {
  if(qtd == 0){
    std::cout<<"A lista esta Vazia!"<<std::endl;
  } else {
    for (int i = 0; i < qtd; i++) {
      list[i].printDetails();
      std::cout << "\n---------------------------" << std::endl;
    }
  }
  
}

template <class E>
int Vetor<E>::delet() { 
  if(qtd==0){
    return -1;
  }
  qtd=0;
  return 0;
}

template <class E>
int Vetor<E>::sizeOf() { return qtd; }

template <class E>
int Vetor<E>::sizeOfLimit(){
  return length;
}

template <class E>
int Vetor<E>::push_front(E valor) {
  if (qtd == length) {
    std::cout << "A lista está cheia, não é possível adicionar mais valores!"<< std::endl;
    return -1;
  }

  for (int i = qtd - 1; i >= 0; i--) {
    list[i + 1] = list[i];
  }
  list[0] = valor;
  qtd++;

  return 1;
}

template <class E>
int Vetor<E>::push_back(E valor) {

  if (qtd == length) {
    std::cout << "A lista está cheia, não é possível adicionar mais valores!"
              << std::endl;
    return -1;
  }

  list[qtd] = valor;
  qtd++;
  return 1;
}

template <class E>
int Vetor<E>::insert(int index, E valor) {
  if(index >= length || index < 0){
    std::cout << "A posição "<<index<<" é invalida!"<< std::endl;
    return -1;
  }
  if (qtd == length) {
    std::cout << "A lista está cheia, não é possível adicionar mais valores!"<< std::endl;
    return -1;
  }

  for (int i = qtd - 1; i >= index; i--) {
    list[i + 1] = list[i];
  }
  list[index] = valor;
  qtd++;

  return 1;
}

template <class E>
int Vetor<E>::pop_front() {
  if (qtd == 0 || qtd == 0) {
    std::cout << "Não existe elementos para remover!" << std::endl;
    return -1;
  }

  for (int i = 0; i < qtd - 1; i++) {
    list[i] = list[i + 1];
  }
  qtd--;
  return 1;
}

template <class E>
int Vetor<E>::pop_back() {
  if (qtd == 0 || qtd == 0) {
    std::cout << "Não existe elementos para remover!" << std::endl;
    return -1;
  }

  qtd--;
  return 1;
}

template <class E>
int Vetor<E>::removeAt(int index) {
  
  if (qtd == 0) {
    std::cout << "Não existe elementos para remover!" << std::endl;
    return -1;
  }
  if(index >= length || index < 0){
    std::cout << "A posição "<<index<<" é invalida!"<< std::endl;
    return -1;
  }

  for (int i = index; i < qtd - 1; i++) {
    list[i] = list[i + 1];
  }
  qtd--;
  return 1;
}


template <class E>
void Vetor<E>::ampliar(){
  length++;
  E* aux = new E [length];
  for (int i = 0; i < qtd; i++) {
        aux[i] = list[i];
      }
  delete[] list;
  list = aux;
 
}


template <class E>
void Vetor<E>::filtra(std::string valor, int op){
  int pos = 0;
   for (int i = 0; i < qtd; i++) {
      if(equalsIgnoreCase(valor, list[i].getAutor()) && op == 1){
        list[pos] = list[i];
        pos++;
      } else if (equalsIgnoreCase(valor, list[i].getEditora()) && op == 2){
        list[pos] = list[i];
        pos++;
      }
    }
    qtd = pos;
}

template <class E>
void Vetor<E>::ordenarPorTitulo(){
  //bubble sort
  for (int i = 0; i < qtd; i++) {
        for (int j = 0; j < qtd-1; j++) {
            if (minuscula(list[j].getTitulo()) > minuscula(list[j+1].getTitulo())) {
                // Troca livros[j] e livros[j+1]
                E temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
}

template <class E>
void Vetor<E>::ordenarPorAnoPublicacao(){
  //selection sort
  int minimo;
  
    for (int i = 0; i < qtd-1; i++) {
        minimo = i;
        for (int j = i+1; j < qtd; j++)
            if (list[j].getAnoPublicacao() < list[minimo].getAnoPublicacao())
                minimo = j;
        std::swap(list[minimo], list[i]);
    }
}



template<class E>
int Vetor<E>::buscaBinariaRecursiva(int chave, int inicio, int fim) {
    if (fim >= inicio) {
        int meio = inicio + (fim - inicio) / 2;

        if (list[meio].getId() == chave)
            return meio;

        if (list[meio].getId() > chave)
            return buscaBinariaRecursiva(chave, inicio, meio - 1);

        return buscaBinariaRecursiva(chave, meio + 1, fim);
    }

    return -1;
}

template <class E>
int Vetor<E>::buscaBinariaIterativa(int chave) {
    int inicio = 0;
    int fim = qtd - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (list[meio].getId() == chave)
            return meio;

        if (list[meio].getId() < chave)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    return -1;
}

template<class E>
void Vetor<E>::findById(int chave){
  if(buscaBinariaRecursiva(chave, 0, qtd) == -1){
    std::cout<<"Não exixte nenhum com esse id";
    return;
  }
  list[buscaBinariaRecursiva(chave, 0, qtd)].printDetails();
}

template<class E>
E Vetor<E>::getValor(int id){
  return list[buscaBinariaRecursiva(id, 0, qtd)];
}

template<class E>
std::string Vetor<E>::alugar(int leitor, std::string titulo){
  list[leitor].setLivro(titulo);
  


  //pegando data atual
  std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

  // Convertendo o tempo atual em um formato legível
  std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

  // Convertendo o tempo em uma estrutura tm (para acessar os componentes da data)
  std::tm* ptm = std::localtime(&currentTime);

  std::string dataAtual = std::to_string(ptm->tm_mday) + "/" + std::to_string( ptm->tm_mon + 1) + "/" + std::to_string(ptm->tm_year + 1900);


  list[leitor].setDataAluguel(dataAtual);

  std::string retorno;
  for(int i = 0; i<qtd; i++){
      retorno += list[i].toString();
  }
  return retorno;
}

template<class E>
std::string Vetor<E>::entregar(int leitor){
  list[leitor].setLivro("Nenhum livro alugado");
  list[leitor].setDataAluguel("00/00/0000");
  

  std::string retorno;
  for(int i = 0; i<qtd; i++){
      retorno += list[i].toString();
  }
  return retorno;
}

template<class E>
bool Vetor<E>::equalsIgnoreCase(const std::string &str1, const std::string &str2) {
  // criei essa função somente para ficar melhor de comparar as strings
  if (str1.length() != str2.length()) {
    return false;
  }

  for (size_t i = 0; i < str1.length(); i++) {
    if (std::tolower(str1[i]) != std::tolower(str2[i])) {
      return false;
    }
  }

  return true;
}


template<class E>
std::string Vetor<E>::minuscula(std::string str) {
    std::string result;
    for (char c : str) {
        result += std::tolower(c);
    }
    return result;
}

#endif