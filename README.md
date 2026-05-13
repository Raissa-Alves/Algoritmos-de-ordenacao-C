### Algoritmos de ordenação.

#### Bubble Sort

**Conceito & lógica:**

Dado um vetor de tamanho **n** cada elemento de posição **i** será comparado com o elemento de posição **i + 1** quando a ordenação procurada é encontrada a troca de posição entre os elementos é feita. 

 **Eficiência:**

O algoritmo é simples de implementar, não há situações melhores ou piores, qualquer que seja o tamanho do vetor de entrada ele realizará todas as comparações, mesmo que desnecessárias.

**Código:**

[BubbleSort Algoritmo](BubbleSort-C.c)

#### Selection Sort

**Conceito & lógica:**

O selection sort ordena um vetor encontrando repetidamente o menor elemento da parte ainda não ordenada e colocando-o no início dessa parte.
Ele vai pegando o primeiro valor que não tiver ordenado e ordena-o, depois repete isso para todos os elementos.

LÓGICA SIMPLIFICADA:
 
 O Selection Sort funciona dividindo o vetor em duas partes:
 
 1. Parte ORDENADA (à esquerda)

    -> é a parte onde ele já verificou os elementos e realizou as trocas
 2. Parte NÃO ORDENADA (à direita)
    
    -> a parte onde ele ainda não verificou os elementos, ou seja, onde ele ainda não fez as trocas
 
A CADA ITERAÇÃO:

 - Procura o MENOR elemento na parte não ordenada/parte não vista
 - Troca esse elemento com o primeiro elemento não ordenado
 - O elemento encontrado passa para a parte ordenada

**Eficiência:**

 COMPLEXIDADE: O(n²) - não é o mais eficiente, mas é fácil de entender

**Código:**

[Selection Sort Algoritmo](selection_sort.c)

#### Insertion Sort

**Conceito & lógica:**

Dado um vetor de tamanho **n** será eleito para iniciar as comparações o segundo elemento deste vetor que está na posição **i** enquanto existir número à esquerda dos eleitos **i - 1** para comparação ele será comparado e trocado quando atender ao critério de ordenação (crescente/decrescente)

**Eficiência:**

#### Quick Sort 

**Conceito e Lógica**

Usa a técnica de "Dividir para Conquistar". Escolhe um "pivô", coloca os menores à esquerda e os maiores à direita, repetindo o processo recursivamente.

**Eficiência:**

Ele é super rápido, elém de que ordena os itens dentro do próprio vetor, sem precisar de memória extra ou cópias.

[QuickSort Algoritmo](quick.c).

#### Merge Sort
#### Heap Sort
#### Radix Sort
