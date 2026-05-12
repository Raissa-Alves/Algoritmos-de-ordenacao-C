### Algoritmos de ordenação.

#### Bubble Sort

**Conceito & lógica:**

Dado um vetor de tamanho **n** cada elemento de posição **i** será comparado com o elemento de posição **i + 1** quando a ordenação procurada é encontrada a troca de posição entre os elementos é feita. 

 **Eficiência:**

O algoritmo é simples de implementar, não há situações melhores ou piores, qualquer que seja o tamanho do vetor de entrada ele realizará todas as comparações, mesmo que desnecessárias.

**Código:**

[BubbleSort Algoritmo](BubbleSort-C.c)

#### Selection Sort
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
