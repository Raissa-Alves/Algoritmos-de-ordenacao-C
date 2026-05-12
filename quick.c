#include <stdio.h>
#include <stdlib.h>

void quick(int v[], int inicio, int fim) {
    if (inicio < fim) { //condição de parada (se o pedaço for maior que 1)
        int pivo = v[fim]; //escolhe o último como pivô
        int i = inicio - 1; //ponto de divisão
        for (int j = inicio; j < fim; j++) { //percorre o pedaço atual
            if (v[j] <= pivo) { //se o valor for menor ou igual ao pivô
                i++; //avança a barreira dos menores
                int aux = v[i]; //troca o valor atual com a barreira
                v[i] = v[j];
                v[j] = aux;
            }
        }
        int aux = v[i + 1]; //coloca o pivô no meio (posição correta)
        v[i + 1] = v[fim];
        v[fim] = aux;
        int p = i + 1; //posição final do pivô

        quick(v, inicio, p - 1); //ordena o lado esquerdo do pivô
        quick(v, p + 1, fim); //ordena o lado direito do pivô
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int *v = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);

    quick(v, 0, n - 1); //chama a função começando do primeiro ao último índice

    for (int i = 0; i < n; i++) printf("%d ", v[i]);
    free(v);
    return 0;
}