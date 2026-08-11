/*Uma agência de viagens tem um vetor com os preços de 8 pacotes turísticos
desordenados. Implemente o algoritmo Bubble Sort para ordenar esses preços do mais barato para
o mais caro.*/
#include <stdio.h>

#define TAM 8

// Função auxiliar para trocar dois elementos de posição
void troca(float* a, float* b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

// Função para imprimir os elementos do vetor
void imprime(int n, float* v) {
    for (int i = 0; i < n; i++) {
        printf("R$ %.2f ", v[i]);
    }
    printf("\n");
}

/* Função de ordenação bolha (Bubble Sort)
   n: número de elementos
   v: ponteiro para o vetor de preços */
void bolha(int n, float* v) {
    int i, j;
//Laço externo controlando o limite da parte não ordenada
    for (i = n - 1; i >= 1; i--) {
        int houve_troca = 0;
//Laço interno comparando elementos adjacentes
        for (j = 0; j < i; j++) {
            if (v[j] > v[j + 1]) {
// Chama a função auxiliar para trocar os elementos
                troca(&v[j], &v[j + 1]);
                houve_troca = 1;
            }
        }
//Otimização: se nenhuma troca ocorreu nesta passada, o vetor já está ordenado
        if (houve_troca == 0) break;
    }
}

int main(void) {
    float precos[TAM];
    int i;

    printf("::: ORDENACAO DE PACOTES :::\n");
    printf("Por favor, digite o preco de %d pacotes turisticos:\n", TAM);

    for (i = 0; i < TAM; i++) {
        printf("Pacote %d: R$ ", i + 1);
        if (scanf("%f", &precos[i]) != 1) {
            printf("Entrada invalida! Por favor, insira um numero.\n");
            return 1;
        }
    }

    printf("\nPrecos antes da ordenacao:\n");
    imprime(TAM, precos);

// Chama a função bolha para ordenar os elementos
    bolha(TAM, precos);

    printf("\nPrecos ordenados (do mais barato para o mais caro):\n");
    imprime(TAM, precos);

    return 0;
}
