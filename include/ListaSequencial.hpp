#ifndef LISTA_H
#define LISTA_H

#include "iostream"
#include "Utilidades.hpp"
template <class E>
class Vetor {
private:
  int length;
  int qtd;
  E* list;

public:
  Vetor(int l);
  ~Vetor();
  void imprime();
  int delet();
  int sizeOf();
  int sizeOfLimit();
  int push_front(E valor);
  int push_back(E valor);
  int insert(int index, E valor);
  int pop_front();
  int pop_back();
  int removeAt(int index);
  void sort();
  void reverse();
  void ampliar();
  void filtra(std::string valor, int op);

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
void Vetor<E>::sort() {
  for (int i = 0; i < qtd - 1; i++) {
    int aux = 0;
    for (int j = 0; j < qtd - 1; j++) {
      if (list[j] > list[j + 1]) {
        aux = list[j];
        list[j] = list[j + 1];
        list[j + 1] = aux;
      }
    }
  }
}

template <class E>
void Vetor<E>::reverse() {
  for (int i = 0; i < qtd - 1; i++) {
    int aux = 0;
    for (int j = 0; j < qtd - 1; j++) {
      if (list[j] < list[j + 1]) {
        aux = list[j];
        list[j] = list[j + 1];
        list[j + 1] = aux;
      }
    }
  }
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
template<class E>
void Vetor<E>::findById(int chave){
  if(buscaBinariaRecursiva(chave, 0, qtd) == -1){
    std::cout<<"Não exixte nenhum com esse id";
    return;
  }
  list[buscaBinariaRecursiva(chave, 0, qtd)].printDetails();
}
#endif