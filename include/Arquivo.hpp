/**
 * @file Arquivo.hpp
 * @brief Declaração da Classe Arquivo.
 */

#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <fstream>
#include <iostream>
#include "ListaEncadeada.hpp"
#include "ListaSequencial.hpp"

/**
 * @brief Classe que representa um Aquivo.
 *
 * Essa classe é responsavel pelos acessos aos arquivos
 */
class Arquivo{

    public:
        /**
         * @brief Metodo para salvar uma nova linha no arquivo
         * 
         * @tparam T A classe que sera trabalhada.
         * @param nomeArquivo o nome do arquivo que será acessado.
         */
        template <class T>
        void salvar(T obj, std::string nomeArquivo);

        /**
         * @brief Metodo para ler um arquivo e retornar uma lista encadeada com todos os dados lidos
         * 
         * @tparam T A classe que sera trabalhada.
         * @param nomeArquivo o nome do arquivo que será acessado.
         * 
         * @return lista encadeada com todos os elementos
         */
        template <class T>
        ListaEncadeada<T> criarListaEncadeada(std::string nomeArquivo);

        /**
         * @brief Metodo para ler um arquivo e salvar em uma lista sequencial com todos os dados lidos.
         * 
         * @tparam T A classe que sera trabalhada.
         * @param nomeArquivo o nome do arquivo que será acessado.
         * @param *lista o ponteiro da lista que será armazenado
         */
        template <class T>
        void criarListaSequencial(std::string nomeArquivo, Vetor<T> *lista);

        /**
         * @brief Metodo reescrever um arquivo com as alterações
         * 
         * @tparam T A classe que sera trabalhada.
         * @param nomeArquivo o nome do arquivo que será acessado.
         * @param conteudo O conteudo que será salvo no arquivo
         */
        template <class T>
        void reescreverArquivo(std::string nomeArquivo, std::string conteudo);
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


 template <class T>
void Arquivo::reescreverArquivo(std::string nomeArquivo, std::string conteudo){
    std::ofstream file;
    file.open(nomeArquivo);
    if(file.is_open()){
        file << conteudo;
        file.close();
    }
}

#endif