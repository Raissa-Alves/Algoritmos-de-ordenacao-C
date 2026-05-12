/** O selection sort ordena um vetor encontrando repetidamente o menor elemento da parte ainda não ordenada/ajeitada e colocando-o no início dessa parte.
Ele vai pegando o primeiro valor que não tiver ordenado e ordena-o, dps repete isso para todos os elementos
 
Passo a passo:
 1. Comece com o primeiro elemento do vetor
 2. Procure pelo menor elemento no restante do vetor
 3. Troque o menor elemento encontrado com o primeiro elemento
 4. Mova para o próximo elemento e repita os passos 2-3
 5. Continue até que todo o vetor esteja ordenado

 Exemplo: [64, 25, 12, 22, 11]
  Passo 1: Menor é 11 → [11, 25, 12, 22, 64]
    -> O selection sort primeiro procura o menor elemento de todo o vetor e troca ele com o primeiro elemento
  Passo 2: Menor é 12 → [11, 12, 25, 22, 64]
  Passo 3: Menor é 22 → [11, 12, 22, 25, 64]
  Passo 4: Menor é 25 → [11, 12, 22, 25, 64] ✓ Pronto!
  

LÓGICA SIMPLIFICADA:
 O Selection Sort funciona dividindo o vetor em duas partes:
 1. Parte ORDENADA (à esquerda)
    -> é a parte onde ele já 'passou' pelos elementos e fez as trocas
 2. Parte NÃO ORDENADA (à direita)
    -> a parte onde ele ainda não 'passou' pelos elementos, ou seja, onde ele ainda não fez as trocas
 
A CADA ITERAÇÃO:
 - Procura o MENOR elemento na parte não ordenada/parte não vista
 - Troca esse elemento com o primeiro elemento não ordenado
 - O elemento encontrado passa para a parte ordenada
 COMPLEXIDADE: O(n²) - não é o mais eficiente, mas é fácil de entender
 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Função para trocar dois elementos
void trocar(int *a, int *b) { 
    int temp = *a; //variável temporária recebe a
    *a = *b; // a recebe b
    *b = temp; //b recebe a (que estava na temp)
}

// Protótipo para a função de impressão usada no passo a passo
void imprimirVetor(int arr[], int tamanho);

void selectionSort(int arr[], int n) { //vetor e tamanho do vetor
    int i, j, min_idx;

    // A cada iteração do for, o elemento que foi encontrado como o menor passa para a parte ordenada, então o limite do subvetor não ordenado diminui.
    // O "limite do subvetor" quer dizer à divisão entre a parte ordenada e a parte não ordenada do vetor. 
    for (i = 0; i < n - 1; i++) {
        //O 1 for começa com n-1, porque o último elemento segundo a lógica do selection já está ordenado, então não precisa verificar ele

        //O 2 for encontra o menor número no vetor não ordenado
        min_idx = i;
        //variável min_idx recebe o índice do elemento atual, pois ele vai comparar esse elemento com os próximos elementos para encontrar o menor número.
        // O 2 for começa com i+1, porque ele vai comparar o elemento atual (i) com os próximos elementos (j) para encontrar o menor número.
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Troca o menor número encontrado com o primeiro elemento
        if (min_idx != i) { //enquanto o menor número for diferente do elemento atual, ele faz a troca
            printf("Passo %d: trocando arr[%d] (= %d) com arr[%d] (= %d)\n", i + 1, i, arr[i], min_idx, arr[min_idx]);
            //função que troca um elemento com outro
            trocar(&arr[min_idx], &arr[i]);
            printf("Vetor após a troca: ");
            imprimirVetor(arr, n);
            printf("\n");
        } else {
            printf("Passo %d: nenhum troca necessária, o menor já está na posição %d\n", i + 1, i);
            printf("Vetor atual: ");
            imprimirVetor(arr, n);
            printf("\n");
        }
    }
}

// Função auxiliar para imprimir o vetor durante a ordenação
void imprimirVetor(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int dados[] = {64, 25, 12, 22, 11};
    int tamanho = sizeof(dados) / sizeof(dados[0]);
    // tamanho_bytes de TODO o vetor/ tamanho_bytes de um elemento do vetor, e isso vai retornar o número total de elementos do vetor

    printf("Vetor original: \n");
    imprimirVetor(dados, tamanho);

    selectionSort(dados, tamanho);

    printf("Vetor ordenado: \n");
    imprimirVetor(dados, tamanho);
    
    return 0;
}
