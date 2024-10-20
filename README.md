Atividade Acadêmica Avaliativa:
Estrutura de Dados em C

Atividade realizada pelo grupo:

1. Charles Fabiano Batista da Silva Filho, Matricula: 202302374913
2. Jose Xukre Ferreira, Matricula: 201851444271
3. Edinaldo Gomes dos Santos Junior, Matricula: 202208716067
4. Pedro Henrique Bonfim Amorim, Matricula: 202203963503


Ordenação e Árvore Binária de números inteiros
Objetivo: Desenvolver um sistema em C que realiza a ordenação de um vetor e a construção de
uma árvore binária de números inteiros.
Requisitos:

1. Início do sistema:
○ O sistema deverá imprimir o nome e a matrícula de cada aluno do grupo.
-
2. Processamento da Matrícula:
○ Capturando o último dígito da matrícula de cada aluno.
○ Esses dígitos serão somados e o sistema realizará a operação de módulo 3 sobre o
valor total.
○ O resultado dessa operação determinará o algoritmo de ordenação e de varredura
a ser utilizado.
-
3. Geração e Ordenação de Vetor:
○ O sistema deverá gerar aleatoriamente um vetor com 100 números inteiros não
repetidos entre 1 e 1000.
○ Com base no resultado da operação de módulo 3:
■ Se o resultado for 0: Ordenar o vetor utilizando o algoritmo Bubble Sort.
■ Se o resultado for 1: Ordenar o vetor utilizando o algoritmo Selection Sort.
■ Se o resultado for 2: Ordenar o vetor utilizando o algoritmo Insertion Sort.
○ O sistema deverá apresentar:
■ O vetor ordenado.
■ A quantidade de comparações realizadas durante a ordenação.
■ O tempo gasto na execução da ordenação.
-
4. Construção e Impressão de Árvore Binária:
○ Utilizando os 100 números gerados, o sistema deverá construir uma árvore
binária de busca utilizando struct.
○ A árvore deverá ser percorrida e impressa em uma das formas de varredura, com
base no resultado do módulo 3:
■ Se o resultado for 0: Percorrer a árvore em pré-ordem.
■ Se o resultado for 1: Percorrer a árvore em ordem.
■ Se o resultado for 2: Percorrer a árvore em pós-ordem.
-
