# Relatório - Bubblesort x Quicksort
Nesse trabalho, foram comparados dois algoritmos de ordenação em relação ao seu tempo de execução
>**Bubblesort:**
>Complexidade temporal: O(n^2)
>Complexidade espacial: O(1)

>**Quicksort:**
> Complexidade temporal: O(n*logn)
> Complexidade espacial: O(1)

### Resultados:
O algoritmo Quicksort apresentou uma performance muito superior ao Bubblesort, o que já era esperado.

Bubblesort: ≈14min
Quicksort: ≈0.12s

### Escolha dos pivôs
Na implementação usada, o pivô é sempre o último elemento da partição, mas se um vetor já ordenado for inserido nessas condições de escolha do pivô, o algoritmo irá performar em O(n^2), que é péssimo. Uma das estratégias que podem ser aplicadas para mitigar essa redução na eficiência do algoritmo é escolher um pivô aleatoriamente ou até escolher k valores aleatórios da partição e usar a mediana deles como pivô.
