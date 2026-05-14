/** Conceito de Heap Sort:
O Heap Sort é um algoritmo de ordenação eficiente que utiliza a estrutura de dados chamada "heap". 
 Ele é baseado na ideia de construir uma "montanha" (heap) a partir dos elementos do vetor e, em seguida, extrair o maior elemento (o topo da montanha) repetidamente para ordenar o vetor.
Ele transforma o seu vetor (array) em uma estrutura chamada Heap, que nada mais é do que uma árvore binária organizada.

A Lógica do Heap Sort (O Conceito da Montanha)
Imagine que o seu vetor é uma montanha russa de números. O Heap Sort faz o seguinte:

1. Construir a Montanha (Max-Heap): Ele reorganiza os números de forma que o maior valor esteja sempre no topo (a raiz).
 Em um "Max-Heap", cada "pai" é sempre maior que seus "filhos".
2. O Rei sai do Trono: Como o maior número está no topo, nós o trocamos com o último elemento da lista. 
 Agora, o maior número está na posição correta (o final do vetor).
3. Reajuste: A montanha ficou bagunçada porque o novo topo é um número pequeno. 
 Chamamos uma função (o heapify) para "peneirar" esse número para baixo até que o próximo maior assuma o topo.
4. Repetição: Repetimos o processo até que todos os números tenham passado pelo topo e sido colocados em suas posições finais.

Exemplo: [12, 11, 13, 5, 6, 7]
Passo 1: Construir o Max-Heap → [13, 12, 7, 5, 6, 11]
Passo 2: Trocar o topo com o último elemento → [11, 12, 7, 5, 6, 13]
Passo 3: Reajustar a montanha → [12, 11, 7, 5, 6, 13]
Passo 4: Repetir o processo → [11, 6, 7, 5, 12, 13] → [7, 6, 11, 5, 12, 13] → [6, 5, 7, 11, 12, 13] → [5, 6, 7, 11, 12, 13]
Fim: [5, 6, 7, 11, 12, 13] ✓ Vetor Pronto!

Eficiência do Heap Sort:
- Tempo de execução: O(n log n) no pior, médio e melhor caso.
- Espaço: O(1) - ordenação in-place.
- Estabilidade: Não estável (pode mudar a ordem de elementos iguais).
- Uso: É eficiente para grandes conjuntos de dados e é amplamente utilizado em sistemas de ordenação interna.

Comparação de eficiência com outros algoritmos de ordenação:
- Bubble Sort: O(n^2) - Heap Sort é muito mais eficiente, pois o tempo de execução heap sort é O(n log n) enquanto o Bubble Sort é O(n^2).
- Insertion Sort: O(n^2) - Heap Sort é mais eficiente para grandes conjuntos de dados.
- Merge Sort: O(n log n) - Ambos têm a mesma eficiência, mas o Merge Sort é estável e requer espaço adicional, enquanto o Heap Sort é in-place.
- Quick Sort: O(n log n) no melhor e médio caso, O(n^2) no pior caso - Heap Sort é mais consistente em termos de tempo de execução, mas o Quick Sort é geralmente mais rápido na prática devido a melhor localidade de referência.
- Radix Sort: O(n * k) onde k é o número de dígitos - Heap Sort é mais eficiente para dados com muitos dígitos ou quando a comparação de chaves é cara.
- Selection Sort: O(n^2) - Heap Sort é muito mais eficiente.
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