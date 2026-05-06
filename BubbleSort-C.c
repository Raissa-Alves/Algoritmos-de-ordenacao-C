#include<stdio.h>
#include<stdlib.h>

void BubbleSort(int *vet, int tam);
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
    
    printf("\nVetor com o uso do Bubble Sort:");
    BubbleSort(vetor,tam);
    ImprimirVetor(vetor,tam);
    
    free(vetor);
    return 0;
}   

void BubbleSort(int *vet, int tam){
    int aux;
    for(int j = 1; j < tam; j++){
      for(int i = 0; i < tam-1; i++){
         if(vet[i] > vet[i+1]){
           aux = vet[i];
           vet[i] = vet[i+1];
           vet[i+1] = aux;
         }
      }
   
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
