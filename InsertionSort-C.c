#include<stdio.h>
#include<stdlib.h>

void InsertionSort(int *vet, int tam);
void PreencherVetor(int *vet, int tam);
void ImprimirVetor(int *vet, int tam);

int main(){
    int *vetor;
    int tam;
    
    printf("informe o tamanho do vetor:");
    scanf("%d",&tam);
    
    vetor = malloc(tam*sizeof(int));
    
    PreencherVetor(vetor,tam);
    printf("\nVetor desordenado:");
    ImprimirVetor(vetor,tam);
    
    printf("\nVetor com o uso do Insertion Sort:");
    InsertionSort(vetor,tam);
    ImprimirVetor(vetor,tam);
    
    free(vetor);
    return 0;
}   

void InsertionSort(int *vet, int tam){
  int eleito,j;
  for(int i = 1; i < tam; i ++){
      eleito = vet[i];
      j = i - 1;
      
      while( j >= 0 && vet[j] > eleito){
        vet[j + 1] = vet[j];
        j = j -1;
      }
      
      vet[j + 1] = eleito;
      
      
  }
}
 
void PreencherVetor(int *vet, int tam){
   for(int j = 0; j< tam; j++){
       printf("Digite o numero da %d posição:",j+1);
       scanf("%d",&vet[j]);
   }
}


void ImprimirVetor(int *vet, int tam){
   printf("\nVETOR:\n"); 
   for(int i=0;i<tam;i++){
        printf("%d ",vet[i]);
    }
    printf("\n");
  
}
