/** Conceito de Heap Sort:
O Heap Sort é um algoritmo de ordenação eficiente que utiliza a estrutura de dados chamada "heap". Ele é baseado na ideia de construir uma "montanha" (heap) 
a partir dos elementos do vetor e, em seguida, extrair o maior elemento (o topo da montanha) repetidamente para ordenar o vetor.
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Função para trocar dois elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// A função "peneira" (heapify) para manter a propriedade de Max-Heap
void heapify(int arr[], int tam, int i) {
    int maior = i;          // Inicializa o maior como a raiz
    int esquerda = 2 * i + 1; 
    int direita = 2 * i + 2; 

    // Se o filho da esquerda for maior que a raiz
    if (esquerda < tam && arr[esquerda] > arr[maior])
        maior = esquerda;

    // Se o filho da direita for maior que o maior até agora
    if (direita < tam && arr[direita] > arr[maior])
        maior = direita;

    // Se o maior não for a raiz, troca e continua peneirando
    if (maior != i) {
        swap(&arr[i], &arr[maior]);
        heapify(arr, tam, maior); // Recursão para ajustar a subárvore
    }
}

// Função principal do Heap Sort
void heapSort(int arr[], int tam) {
    // 1. Constrói o Max-Heap (rearranja o vetor)
    for (int i = tam / 2 - 1; i >= 0; i--)
        heapify(arr, tam, i);

    // 2. Extrai um por um os elementos do heap
    for (int i = tam - 1; i > 0; i--) {
        // Move a raiz atual (o maior) para o fim do vetor
        swap(&arr[0], &arr[i]);

        // Chama o heapify na árvore reduzida
        heapify(arr, i, 0);
    }
}

// Função auxiliar para imprimir o vetor
void printArray(int arr[], int tam) {
    for (int i = 0; i < tam; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int arr[] = {12, 11, 13, 5, 6, 7};
    int tam = sizeof(arr) / sizeof(arr[0]);

    printf("Vetor original:\n");
    printArray(arr, tam);

    heapSort(arr, tam);

    printf("Vetor ordenado:\n");
    printArray(arr, tam);
    
    return 0;
}
