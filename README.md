# Projeto de Estruturas de Dados e Algoritmos de Ordenação em C

Este projeto implementa diferentes estruturas de dados (listas, pilhas e filas) e algoritmos de ordenação (Bubble Sort, Selection Sort, Insertion Sort e Shell Sort) em C.

## 🎯 Objetivo do Projeto
Este projeto visa explorar e comparar o comportamento das estruturas de dados e dos algoritmos de ordenação em diferentes cenários. Ele também permite a análise do desempenho dos algoritmos em termos de tempo de execução, ao comparar métodos de ordenação em listas de diferentes tamanhos.


# 🎆Features

## Estruturas de Dados Implementadas
- **Lista**: Implementação de listas encadeadas simples. São fornecidas funções para inserir no inicio, inserir no meio, inserir no fim, remover determinado valor da lista e exibir elementos.
- **Pilha**: Implementação de uma pilha, utilizando o conceito de LIFO (Last In, First Out). Permite operações como imprimir pilha, empilhar e desempilhar elementos.
- **Fila**: Implementação de uma fila, utilizando o conceito de FIFO (First In, First Out). Permite operações de imprimir fila, enfileiramento e desenfileiramento.

## Algoritmos de Ordenação

- **Bubble Sort**: Algoritmo de ordenação simples baseado na comparação e troca de elementos adjacentes. A ordenação é realizada em várias passagens pela lista.
- **Selection Sort**: Algoritmo de ordenação que seleciona repetidamente o menor (ou maior) elemento e o coloca na posição correta.
- **Insertion Sort**: Algoritmo de ordenação simples que constrói a lista ordenada gradualmente, inserindo um elemento de cada vez na posição correta, comparando-o com os elementos anteriores.
- **Shell Sort**: Algoritmo de ordenação que melhora o Insertion Sort, utilizando uma sequência de intervalos (gaps) para ordenar elementos distantes antes de refiná-los com gaps menores, acelerando o processo de ordenação.

## 🏅 Tecnologias Utilizadas

- C++;
## 💻 Pré-requisitos

O projeto inteiro foi implementado utilizando a IDE Embarcadero Dev-C++ que já tem suporte completo para a linguagem C/C++, recomendo que também utilize a mesma IDE para rodar o programa.

Caso não tenha a IDE, faça o [download aqui](https://www.embarcadero.com/br/free-tools/dev-cpp/free-download).
## 🚀 Rodando localmente

Clone o projeto

```bash
  git clone https://github.com/lipebianchi/estruturas-em-C.git
```

Após isso, entre no diretório do arquivo clonado, e rode o arquivo CPP

Caso já esteja utilizando o Dev-C++, basta clicar na tecla F11 para rodar o arquivo executavel.

## ⚠️MODIFICAÇÃO NO CÓDIGO

⚠️ **CUIDADO**: O código já inicia com um vetor de tamanho 100.000 (cem mil), isso pode ser alterado na linha de código 58 que está escrita da seguinte forma: 

```cpp
  int arr[100000];
```
Essa linha de código é responsável pelo vetor que será gerado, imprimido, ordenado e comparado na funcionalidade de Ordenação de dados.
Fique a vontade para modificar esse valor, porém, 170 Mil é um valor alto e pode ser que na execução ele demore um tempo muito alto a depender do seu processador, caso esteja dando erro no programa ou ele demore muito para ser executado, recomendo que abaixe o valor.

## 🦾 Melhorias

- [x]  Adicionar novos métodos de ordenação;
- [ ]  Quick Sort;
- [x]  Insertion Sort;
- [x]  Shell Sort;
- [ ]  Merge Sort;
- [ ]  Heap Sort;
- [ ]  Tamanho do array dinâmico.
