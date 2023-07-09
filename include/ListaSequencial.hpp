#ifndef LISTA_H
#define LISTA_H

#include "iostream"
 
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
  int find(E valor);
  void sort();
  void reverse();
  void ampliar();
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
int Vetor<E>::find(E valor) {
  for (int i = 0; i < qtd; i++) {
    if (list[i] == valor) {
      return i;
    }
  }

  return -1;
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

#endif