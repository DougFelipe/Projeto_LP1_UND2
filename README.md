# Projeto Biblioteca
 O projeto consiste em um gerenciador dos livros de uma biblioteca, onde se pode cadastrar um livro, alterar, remover e buscar. Armazena quem pegou o livro para ler, quais os autores que se tem no acervo da biblioteca, quais editoras se tem parceria.

 ### Detalhes tecnicos sobre o projeto

 #### Sobre o TADS
- Os livros durante as buscas serão armazenados em uma lista encadeada;
- Autores ultilizaremos o conceito de pilhas para manipular suas informações;

#### Busca
Será feita uma busca binaria quando for preciso fazer uma consulta nos livros, Autor, Editora e Leitor. Para isso ultilizaremos de templates genericos para ter uma melhor economia de codigo, evitando que fique verboso.
   ```
   template <class T>
   T buscarElemento(std::vector<T>, std::string campo){
        [...]
   }
   ```
Onde o 'T' será a entidade que esta buscando (Livro, autor, leitor, etc...), assim evita que se crie um metodo de busca para cada classe.

#### Ordenação
Ordenaremos da seguinte maneira:
- Os livros poderão ser ordenados de forma alfabetica, por ordem de lançamento. Para isso ultilizaremos o algoritmo Bubble Sort para a ordenação;
- Os autores serão ordenados de forma alfabetica, ou por ordem temporal. Ultilizaremos o Selection Sort;
- Editora e Leitor tambem usarão do Selectioon sort;

## Diagrama de Classes

![diagrama de classes](https://github.com/Leandro208/Leandro208/assets/81039247/f711df68-0f7b-432b-8c46-d5b91501a320)


## Diagrama de Caso de Uso
![Caso de Uso UML](https://github.com/Leandro208/Leandro208/assets/81039247/f589f9fc-e3f4-470a-9d2a-6623455bf4e5)
