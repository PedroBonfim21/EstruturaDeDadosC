#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura de nó da árvore binária
struct Node {
    int data;
    struct Node *left, *right;
};

// Função para criar um novo nó da árvore binária
struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Função para inserir um nó na árvore binária
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    return node;
}

// Funções para percorrer a árvore binária
void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// Função para trocar dois valores de posição
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Funções de ordenação

// Bubble Sort
int bubbleSort(int arr[], int n) {
    int i, j, comparisons = 0;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            comparisons++;
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
    return comparisons;
}

// Selection Sort
int selectionSort(int arr[], int n) {
    int i, j, min_idx, comparisons = 0;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
    return comparisons;
}

// Insertion Sort
int insertionSort(int arr[], int n) {
    int i, key, j, comparisons = 0;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        comparisons++;
    }
    return comparisons;
}

// Função para gerar um vetor com 100 números inteiros não repetidos entre 1 e 1000
void generateRandomArray(int arr[], int n) {
    int used[1001] = {0};  // Para verificar se um número já foi usado
    for (int i = 0; i < n; i++) {
        int num;
        do {
            num = rand() % 1000 + 1;
        } while (used[num]);
        arr[i] = num;
        used[num] = 1;
    }
}

int main() {
    srand(time(0)); // Inicializa a semente para números aleatórios
    
    // Passo 1: Imprime o nome e a matrícula de cada aluno
    printf("Alunos do grupo:\n");
    printf("Nome: Charles Fabiano Batista da Silva Filho, Matricula: 202302374913\n");
    printf("Nome: Jose Xukre Ferreira, Matricula: 201851444271\n");
    printf("Nome: Edinaldo Gomes dos Santos Junior, Matricula: 202208716067\n");
    printf("Nome: Pedro Henrique Bonfim Amorim, Matricula: 202203963503\n");
    
    // Passo 2: Captura os últimos dígitos das matrículas e calcula o módulo 3
    long long int matriculas[] = {202302374913, 201851444271, 202208716067, 202203963503};
    int digitos_finais = 0;
    for (int i = 0; i < 4; i++) {
        digitos_finais += matriculas[i] % 10; // Captura o último dígito
    }
    int modulo = digitos_finais % 3; // Calcula o módulo 3
    printf("\nO resultado da operação de módulo 3 -> %d\n", modulo);
    
    // Passo 3: Gera um vetor de 100 números inteiros não repetidos
    int vetor[100];
    generateRandomArray(vetor, 100);
    
    // Variáveis para armazenar o número de comparações e o tempo gasto
    int comparacoes = 0;
    clock_t inicio, fim;
    
    // Ordena o vetor com base no resultado do módulo
    if (modulo == 0) {
        printf("\nUsando Bubble Sort para ordenar o vetor...\n");
        inicio = clock();
        comparacoes = bubbleSort(vetor, 100);
        fim = clock();

    } else if (modulo == 1) {
        printf("\nUsando Selection Sort para ordenar o vetor...\n");
        inicio = clock();
        comparacoes = selectionSort(vetor, 100);
        fim = clock();

    } else {
        printf("\nUsando Insertion Sort para ordenar o vetor...\n");
        inicio = clock();
        comparacoes = insertionSort(vetor, 100);
        fim = clock();
    }
    

    double tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    
    // Imprime o vetor ordenado
    printf("\nVetor ordenado:\n");
    for (int i = 0; i < 100; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n\nComparações realizadas: %d\n", comparacoes);
    printf("Tempo gasto na ordenação: %f segundos\n", tempo_gasto);
    
    // Passo 4: Construção da árvore binária de busca
    struct Node* root = NULL;
    for (int i = 0; i < 100; i++) {
        root = insert(root, vetor[i]);
    }
    
    // Varredura da árvore com base no resultado do módulo
    printf("\nVarredura da árvore binária:\n");
    if (modulo == 0) {
        printf("Percorrendo em pré-ordem:\n");
        preOrder(root);
    } else if (modulo == 1) {
        printf("Percorrendo em ordem:\n");
        inOrder(root);
    } else {
        printf("Percorrendo em pós-ordem:\n");
        postOrder(root);
    }
    
    printf("\n");
    return 0;
}