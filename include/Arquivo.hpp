#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <fstream>
#include <iostream>
#include "ListaEncadeada.hpp"
#include "ListaSequencial.hpp"
class Arquivo{

    public:
        template <class T>
        void salvar(T obj, std::string nomeArquivo);

        template <class T>
        ListaEncadeada<T> criarListaEncadeada(std::string nomeArquivo);

        template <class T>
        void criarListaSequencial(std::string nomeArquivo, Vetor<T> *lista);
};


template <class T>
 void Arquivo::salvar(T obj, std::string nomeArquivo){
        std::ofstream arquivo;
        
        arquivo.open(nomeArquivo, std::ios::app);
        if (arquivo.is_open()) {
            arquivo << obj.toString();

            arquivo.close();
        }
 }


template <class T>
ListaEncadeada<T> Arquivo::criarListaEncadeada(std::string nomeArquivo) {
    ListaEncadeada<T> lista;
    std::ifstream arquivoLeitura(nomeArquivo);
    if (arquivoLeitura.is_open()) {
        std::string linha;
        while (std::getline(arquivoLeitura, linha)) {
            T objeto;
           lista.adicionarFim(*objeto.toModel(linha));
        }
        arquivoLeitura.close();
    } else {
        std::cout << "Nenhum dado encontrado!"<<std::endl;
        std::cout<<"[Enter] Voltar ";
        
        std::cin.ignore();
        getchar();
    }
    return lista;
}

 template <class T>
 void Arquivo::criarListaSequencial(std::string nomeArquivo, Vetor<T> *lista){
    std::ifstream arquivoLeitura(nomeArquivo);
    if (arquivoLeitura.is_open()) {
        std::string linha;
        while (std::getline(arquivoLeitura, linha)) {
            T objeto;
            if(lista->sizeOf() == lista->sizeOfLimit()){
               lista->ampliar();
            }
             lista->push_back(*objeto.toModel(linha));

        }
        arquivoLeitura.close();
    } else {
        std::cout << "\nVocê precisa cadastrar primeiro!" <<nomeArquivo<< std::endl;
        return;
    }
 }


#endif