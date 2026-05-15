## Algoritmos de ordenação.

### Bubble Sort

**Conceito & lógica:**

Dado um vetor de tamanho **n** cada elemento de posição **i** será comparado com o elemento de posição **i + 1** quando a ordenação procurada é encontrada a troca de posição entre os elementos é feita. 

 **Eficiência:**

O algoritmo é simples de implementar, não há situações melhores ou piores, qualquer que seja o tamanho do vetor de entrada ele realizará todas as comparações, mesmo que desnecessárias.

**Código:**

[BubbleSort Algoritmo](BubbleSort-C.c)

### Selection Sort

**Conceito & lógica:**

O selection sort ordena um vetor encontrando repetidamente o menor elemento da parte ainda não ordenada e colocando-o no início dessa parte.
Ele vai pegando o primeiro valor que não tiver ordenado e ordena-o, depois repete isso para todos os elementos.

A lógica do Selection Sort:
 
 O Selection Sort funciona dividindo o vetor em duas partes:
 
 1. Parte ORDENADA (à esquerda)

    -> é a parte onde ele já verificou os elementos e realizou as trocas
 2. Parte NÃO ORDENADA (à direita)
    
    -> a parte onde ele ainda não verificou os elementos, ou seja, onde ele ainda não fez as trocas
 
A cada iteração:

 - Procura o MENOR elemento na parte não ordenada/parte não vista
 - Troca esse elemento com o primeiro elemento não ordenado
 - O elemento encontrado passa para a parte ordenada

**Eficiência:**

- Tempo de execução: O(n^2) no pior, médio e melhor caso.
- Espaço: O(1) - ordenação in-place.
- Estabilidade: Não estável (pode mudar a ordem de elementos iguais).
- Uso: É eficiente para pequenos conjuntos de dados ou quando a memória é limitada, mas geralmente

Comparação de eficiência com outros algoritmos de ordenação:

- Bubble Sort: O(n^2) - Ambos têm a mesma eficiência, mas o Selection Sort geralmente faz menos trocas do que o Bubble Sort.
- Insertion Sort: O(n^2) - Ambos têm a mesma eficiência, mas o Insertion Sort é mais eficiente para conjuntos de dados que já estão parcialmente ordenados.
- Merge Sort: O(n log n) - O Merge Sort é muito mais eficiente para grandes conjuntos de dados, mas requer espaço adicional para as operações de mesclagem.
- Quick Sort: O(n log n) no melhor e médio caso, O(n^2) no pior caso - O Quick Sort é geralmente mais rápido na prática devido a melhor localidade de referência, mas o Selection Sort é mais consistente em termos de tempo de execução.
- Heap Sort: O(n log n) - O Heap Sort é mais eficiente para grandes conjuntos de dados, mas o Selection Sort é mais simples e pode ser preferido para conjuntos de dados muito pequenos.
- Radix Sort: O(n * k) onde k é o número de dígitos - O Radix Sort é mais eficiente para dados com muitos dígitos ou quando a comparação de chaves é cara, mas o Selection Sort é mais simples e pode ser preferido para conjuntos de dados muito pequenos.

**Código:**

[Selection Sort Algoritmo](selection_sort.c)

### Insertion Sort

**Conceito & lógica:**

Dado um vetor de tamanho **n** será eleito para iniciar as comparações o segundo elemento deste vetor que está na posição **i** enquanto existir número à esquerda dos eleitos **i - 1** para comparação ele será comparado e trocado quando atender ao critério de ordenação (crescente/decrescente)

**Eficiência:**

**Codigo:**

[Insertion Sort Algoritmo](InsertionSort-C.c)

### Quick Sort 

**Conceito e Lógica**

Usa a técnica de "Dividir para Conquistar". Escolhe um "pivô", coloca os menores à esquerda e os maiores à direita, repetindo o processo recursivamente.

**Eficiência:**

Ele é super rápido, elém de que ordena os itens dentro do próprio vetor, sem precisar de memória extra ou cópias.

**Codigo:**

[QuickSort Algoritmo](quick.c).

### Merge Sort

**Conceito & lógica:**

**Eficiência:**

**Codigo:**


### Heap Sort

**Conceito & lógica:**

 O Heap Sort é um algoritmo de ordenação eficiente que utiliza a estrutura de dados chamada "heap". 
 Ele é baseado na ideia de construir uma "montanha" (heap) a partir dos elementos do vetor e, em seguida, extrair o maior elemento (o topo da montanha) repetidamente para ordenar o vetor.
 Ele transforma o seu vetor (array) em uma estrutura chamada Heap, que nada mais é do que uma árvore binária organizada.

A Lógica do Heap Sort (O Conceito da Montanha):

Imagine que o seu vetor é uma montanha russa de números. O Heap Sort faz o seguinte:
1. Construir a Montanha (Max-Heap): Ele reorganiza os números de forma que o maior valor esteja sempre no topo (a raiz).
 
  -> Em um "Max-Heap", cada "pai" é sempre maior que seus "filhos".
 
2. O Rei sai do Trono: Como o maior número está no topo, nós o trocamos com o último elemento da lista. 
 
  -> Agora, o maior número está na posição correta (o final do vetor).
 
3. Reajuste: A montanha ficou bagunçada porque o novo topo é um número pequeno. 
 
  -> Chamamos uma função (o heapify) para "peneirar" esse número para baixo até que o próximo maior assuma o topo.
 
4. Repetição: Repetimos o processo até que todos os números tenham passado pelo topo e sido colocados em suas posições finais.

**Eficiência:**

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

**Código:**

[Heap Sort Algoritmo](heap_sort.c)

### Radix Sort

**Conceito & lógica:**

 O Radix Sort é um algoritmo de ordenação que pensa "fora da caixa". Enquanto a maioria dos algoritmos (como o Quick Sort ou o Heap Sort)
fica comparando se um número é maior que o outro, o Radix Sort nem olha para o valor total do número de uma vez. Ele prefere olhar para um dígito de cada vez.

A Lógica do Radix sort: O Método dos Baldes

Imagine que você tem uma pilha de notas fiscais e quer organizá-las por valor. Em vez de comparar cada uma, você faz o seguinte:

1. Olhe para a unidade: Você cria 10 baldes (0 a 9) e coloca cada nota no balde correspondente ao seu último dígito.
 Depois, recolhe todas na ordem dos baldes.
2. Olhe para a dezena: Agora, você olha para o segundo dígito (as dezenas) e repete o processo, 
 mantendo a ordem que você já tinha conseguido no passo anterior.
3. Continue subindo: Você faz isso para as centenas, milhares, e assim por diante, até o maior número acabar.

 -> A mágica: Como você mantém a ordem relativa dos números a cada passo (isso se chama "ordenação estável"), 
ao terminar o último dígito, a lista inteira estará perfeitamente ordenada.

**Eficiência:**

- Tempo de execução: O(n * k) onde n é o número de elementos e k é o número de dígitos no maior número.
- Espaço: O(n + k) - requer espaço adicional para os baldes e o vetor de saída.
- Estabilidade: Estável (mantém a ordem de elementos iguais).
- Uso: É eficiente para ordenar números inteiros ou strings, especialmente quando o número de dígitos é pequeno em comparação com o número de elementos.

Comparação de eficiência com outros algoritmos de ordenação:

- Bubble Sort: O(n^2) - Radix Sort é muito mais eficiente, especialmente para grandes conjuntos de dados.
- Insertion Sort: O(n^2) - Radix Sort é mais eficiente para grandes conjuntos de dados, especialmente quando os números têm poucos dígitos.
- Merge Sort: O(n log n) - Radix Sort pode ser mais eficiente para dados com muitos dígitos ou quando a comparação de chaves é cara, mas o Merge Sort é mais geral e estável.
- Quick Sort: O(n log n) no melhor e médio caso, O(n^2) no pior caso - Radix Sort é mais eficiente para dados com muitos dígitos ou quando a comparação de chaves é cara, mas o Quick Sort é geralmente mais rápido na prática devido a melhor localidade de referência.
- Heap Sort: O(n log n) - Radix Sort é mais eficiente para dados com muitos dígitos ou quando a comparação de chaves é cara, mas o Heap Sort é mais eficiente para grandes conjuntos de dados.
- Selection Sort: O(n^2) - Radix Sort é muito mais eficiente.

**Código:**

[Radix Sort Algoritmo](radix_sort.c)








