/** O Radix Sort é um algoritmo de ordenação que pensa "fora da caixa". Enquanto a maioria dos algoritmos (como o Quick Sort ou o Heap Sort)
fica comparando se um número é maior que o outro, o Radix Sort nem olha para o valor total do número de uma vez. Ele prefere olhar para um dígito de cada vez.

A Lógica do Radix sort: O Método dos Baldes

Imagine que você tem uma pilha de notas fiscais e quer organizá-las por valor. Em vez de comparar cada uma, você faz o seguinte:

1. Olhe para a unidade: Você cria 10 baldes (0 a 9) e coloca cada nota no balde correspondente ao seu último dígito.
 Depois, recolhe todas na ordem dos baldes.
2. Olhe para a dezena: Agora, você olha para o segundo dígito (as dezenas) e repete o processo, 
 mantendo a ordem que você já tinha conseguido no passo anterior.
3. Continue subindo: Você faz isso para as centenas, milhares, e assim por diante, até o maior número acabar.

A mágica: Como você mantém a ordem relativa dos números a cada passo (isso se chama "ordenação estável"), 
ao terminar o último dígito, a lista inteira estará perfeitamente ordenada!
*/

//Para o Radix Sort funcionar, ele geralmente usa o Counting Sort como uma função auxiliar para organizar os baldes de cada dígito.
#include <stdio.h>

// Função para obter o maior valor no vetor (para saber quantos dígitos processar)
int obterMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Uma versão modificada do Counting Sort para ordenar os dígitos baseados em 'exp' (1, 10, 100...)
void countingSort(int arr[], int n, int exp) {
    int saida[n]; 
    int i, count[10] = {0};

    // Armazena a contagem de ocorrências de cada dígito em count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Muda count[i] para que ele contenha a posição real do dígito na saída
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Constrói o vetor de saída (de trás para frente para manter a estabilidade)
    for (i = n - 1; i >= 0; i--) {
        saida[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copia o vetor de saída para o original, para que o vetor esteja ordenado por esse dígito
    for (i = 0; i < n; i++)
        arr[i] = saida[i];
}

// Função principal do Radix Sort
void radixSort(int arr[], int n) {
    int m = obterMax(arr, n);

    // Faz o counting sort para cada dígito. 
    // 'exp' é 10^i onde i é o dígito atual (unidade, dezena, centena...)
    for (int exp = 1; m / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

void imprimirVetor(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Vetor original: ");
    imprimirVetor(arr, n);

    radixSort(arr, n);

    printf("Vetor ordenado: ");
    imprimirVetor(arr, n);
    return 0;
}
