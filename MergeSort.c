#include <stdio.h>
#include <stdlib.h>

void MergeSort(int *vet, int inicio, int fim);
void merge(int *vet, int inicio, int meio, int fim);
void PreencherVetor(int *vet, int tam);
void ImprimirVetor(int *vet, int tam);

int main(){
    int *vetor;
    int tam;
    
    printf("Informe o tamanho do vetor: ");
    scanf("%d",&tam);
    
    vetor = malloc(tam * sizeof(int));
    
    PreencherVetor(vetor, tam);

    printf("\nVetor desordenado:");
    ImprimirVetor(vetor, tam);
    
    printf("\nVetor com o uso do Merge Sort:");
    MergeSort(vetor, 0, tam - 1);
    ImprimirVetor(vetor, tam);
    
    free(vetor);
    return 0;
}

void MergeSort(int *vet, int inicio, int fim){
    if(inicio < fim){
        int meio = (inicio + fim) / 2;

        MergeSort(vet, inicio, meio);
        MergeSort(vet, meio + 1, fim);

        merge(vet, inicio, meio, fim);
    }
}

void merge(int *vet, int inicio, int meio, int fim){
    int i = inicio, j = meio + 1, k = 0;

    int *temp = malloc((fim - inicio + 1) * sizeof(int));

    while(i <= meio && j <= fim){
        if(vet[i] <= vet[j]){
            temp[k++] = vet[i++];
        } else {
            temp[k++] = vet[j++];
        }
    }

    while(i <= meio){
        temp[k++] = vet[i++];
    }

    while(j <= fim){
        temp[k++] = vet[j++];
    }

    for(i = inicio, k = 0; i <= fim; i++, k++){
        vet[i] = temp[k];
    }

    free(temp);
}

void PreencherVetor(int *vet, int tam){
   for(int j = 0; j < tam; j++){
       printf("Digite o numero da %d posição: ", j+1);
       scanf("%d",&vet[j]);
   }
}

void ImprimirVetor(int *vet, int tam){
   printf("\nVETOR:\n"); 
   for(int i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}